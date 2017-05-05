use std::collections::HashMap;

use std::hash::Hash;

use structs::item_node::ItemNode;
use structs::frequency_node::{FrequencyNode, FrequencyNodeList};


pub enum CacheError {
    InsertError
}

// Let's assume that we will be having a maximum of 50 elements in the cache?
// That allows us to implement the least frequently used removal algorithm,
// along with the cache implementation.
pub struct Cache<T> where T: Hash {
    pub fnode_list: FrequencyNodeList<FrequencyNode<T>>,
    pub lookup_table: HashMap<T, i32>,
}

// TODO: Add functionality to load existing data onto cache?
impl<T> Cache<T> where T: Hash + Eq + Clone {
    pub fn new() -> Cache<T> {
        let fnode_list = FrequencyNodeList::new();
        let lookup_table = HashMap::new();

        Cache {
            fnode_list: fnode_list,
            lookup_table: lookup_table
        }
    }

    pub fn insert_element(&mut self, value: T) -> Result<(), CacheError> {
        // Check if item already in cache. We will assume that it is an access in that case.
        if self.lookup_table.contains_key(&value) {
            let parent = *self.lookup_table.get(&value).unwrap();
            let new_parent = parent + 1;

            let temp_node = FrequencyNode::new(parent);
            let idx = self.fnode_list.iter().position(|ref r| **r == temp_node).unwrap();

            if let Some(fnode) = self.fnode_list.get_mut(idx) {
                fnode.item_nodes.retain(|ref x| x.value != value);
                // TODO: Delete the vec entirely if empty
            }

            let mut new_node = FrequencyNode::new(new_parent);
            let new_idx = self.fnode_list.iter().position(|ref r| **r == new_node);

            match new_idx {
                Some(i) => {
                    if let Some(fnode) = self.fnode_list.get_mut(i) {
                        fnode.item_nodes.push(ItemNode::new(value, new_parent));
                    }
                },
                None => {
                    new_node.item_nodes.push(ItemNode::new(value, new_parent));
                    self.fnode_list.push(new_node);
                }
            }
        }

        Ok(())
    }

    pub fn access_element(&mut self, value: T) -> Result<(), CacheError> {
        Ok(())
    }
}
