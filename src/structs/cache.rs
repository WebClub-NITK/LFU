use std::collections::HashMap;
use std::fmt::Display;
use std::fmt::Debug;

use std::hash::Hash;

use structs::item_node::ItemNode;
use structs::frequency_node::{FrequencyNode, FrequencyNodeArena};

const MIN_FREQ: i32 = 1;

#[derive(Debug)]
pub enum CacheError {
    InsertError,
    AccessError,
    EvictError,
}

pub struct Cache<T> where T: Hash + Display + Debug {
    pub fnode_arena: FrequencyNodeArena<T>,
    pub lookup_table: HashMap<T, i32>,
    // Additional bookkeeping for improving performance.
    pub lowest_freq: i32,
}

// TODO: Add functionality to load existing data onto cache
impl<T> Cache<T> where T: Hash + Eq + Clone + Copy + Display + Debug {
    pub fn new() -> Cache<T> {
        let fnode_arena = FrequencyNodeArena::new();
        let lookup_table = HashMap::new();

        Cache {
            lowest_freq: -1,
            fnode_arena: fnode_arena,
            lookup_table: lookup_table,
        }
    }

    pub fn is_empty(&self) -> bool {
        self.fnode_arena.is_empty()
    }

    pub fn insert_element(&mut self, value: T) -> Result<(), CacheError> {
        if self.lookup_table.contains_key(&value) {
            Err(CacheError::InsertError)
        } else { 
            if self.lowest_freq == MIN_FREQ {
                if let Some(fnode) = self.fnode_arena.get_mut(&MIN_FREQ) {
                    fnode.item_nodes.push(ItemNode::new(value, MIN_FREQ));
               }
            } else if self.is_empty() {
                let mut new_node = FrequencyNode::new(MIN_FREQ);
                new_node.item_nodes.push(ItemNode::new(value, MIN_FREQ));

                self.fnode_arena.insert(1, new_node);
                self.lowest_freq = MIN_FREQ;
            } else {
                let mut new_node = FrequencyNode::new(MIN_FREQ);
                new_node.siblings.next = Some(self.lowest_freq);

                if let Some(curr_low) = self.fnode_arena.get_mut(&self.lowest_freq) {
                    curr_low.siblings.prev = Some(MIN_FREQ);
                }
                
                self.fnode_arena.insert(1, new_node); 
                self.lowest_freq = MIN_FREQ;
            }
            
            self.lookup_table.insert(value, MIN_FREQ);
            Ok(())
        }
    }

    pub fn access_element(&mut self, value: T) -> Result<(), CacheError> {
        if !self.lookup_table.contains_key(&value) {
            Err(CacheError::AccessError)
        } else {
            let parent = *self.lookup_table.get(&value).unwrap();
            let new_parent = parent + 1;

            let mut is_empty = false;
            let mut old_prev = None;
            let mut old_next = None;
            
            if let Some(fnode) = self.fnode_arena.get_mut(&parent) {
                fnode.item_nodes.retain(|ref x| x.value != value);
                if fnode.item_nodes.is_empty() {
                    is_empty = true;
                    old_prev = fnode.siblings.prev;
                    old_next = fnode.siblings.next;
                }
            }

            if is_empty && old_next.unwrap_or(-1) == new_parent {
                if let Some(prev_node) = self.fnode_arena.get_mut(&old_prev.unwrap_or(-1)) {
                    prev_node.siblings.next = Some(new_parent);
                }

                if let Some(next_node) = self.fnode_arena.get_mut(&old_next.unwrap_or(-1)) {
                    next_node.siblings.prev = old_prev;
                    next_node.item_nodes.push(ItemNode::new(value, new_parent));
                }

                self.lowest_freq = new_parent;
                self.fnode_arena.remove(&parent);
            } else if is_empty && old_next.unwrap_or(-1) != new_parent {
                let mut new_node = FrequencyNode::new(new_parent);
                new_node.siblings.prev = old_prev;
                new_node.siblings.next = old_next;

                new_node.item_nodes.push(ItemNode::new(value, new_parent));
                self.fnode_arena.insert(new_parent, new_node);

                if let Some(prev_node) = self.fnode_arena.get_mut(&old_prev.unwrap_or(-1)) {
                    prev_node.siblings.next = Some(new_parent);
                } 

                if let Some(next_node) = self.fnode_arena.get_mut(&old_next.unwrap_or(-1)) {
                    next_node.siblings.prev = Some(new_parent);
                }

                if new_parent == self.lowest_freq + 1 {
                    self.lowest_freq = new_parent;
                    if let Some(fnode) = self.fnode_arena.get_mut(&new_parent) {
                        fnode.siblings.prev = None;
                    }
                }

                self.fnode_arena.remove(&parent);
            } else if !is_empty && old_next.unwrap_or(-1) == new_parent {
                if let Some(existing_node) = self.fnode_arena.get_mut(&old_next.unwrap_or(-1)) {
                    existing_node.item_nodes.push(ItemNode::new(value, new_parent));
                }
            } else {
                let mut new_node = FrequencyNode::new(new_parent);
                new_node.siblings.prev = Some(parent);
                new_node.siblings.next = old_next;

                new_node.item_nodes.push(ItemNode::new(value, new_parent));
                self.fnode_arena.insert(new_parent, new_node);

                if let Some(prev_node) = self.fnode_arena.get_mut(&parent) {
                    prev_node.siblings.next = Some(new_parent);
                } 

                if let Some(next_node) = self.fnode_arena.get_mut(&old_next.unwrap_or(-1)) {
                    next_node.siblings.prev = Some(new_parent);
                }
            }
            
            self.lookup_table.remove(&value);
            self.lookup_table.insert(value, new_parent);

            Ok(())
        }
    }

    pub fn evict(&mut self) -> Result<T, CacheError> {
        if self.is_empty() {
            Err(CacheError::EvictError)
        } else {
            let mut is_empty = false;
            let mut next = Some(-1);
            
            let mut popped = None;
            
            if let Some(fnode) = self.fnode_arena.get_mut(&self.lowest_freq) {
                popped = fnode.item_nodes.pop();

                if fnode.item_nodes.is_empty() {
                    is_empty = true;
                    next = fnode.siblings.next;
                }
            }

            if is_empty {
                self.fnode_arena.remove(&self.lowest_freq);
                if next.is_some() {
                    self.lowest_freq = next.unwrap();
                } else {
                    self.lowest_freq = -1;
                }

                if let Some(fnode) = self.fnode_arena.get_mut(&self.lowest_freq) {
                    fnode.siblings.prev = None;
                }
            }

            Ok(popped.unwrap().value)
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn cache_check() {
        let mut c = Cache::new();
        c.insert_element(12);
        c.insert_element(23);
        c.access_element(23);
        c.access_element(12);
        assert_eq!(c.evict().ok(), Some(12));
        assert_eq!(c.evict().ok(), Some(23));
    }
}

