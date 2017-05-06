use std::fmt::{Display, Formatter, Result};
use std::fmt::Debug;
use std::collections::HashMap;
use structs::item_node::ItemNodeList;

#[derive(Clone, Debug)]
pub struct Siblings {
    pub next: Option<i32>,
    pub prev: Option<i32>,
}

impl Siblings {
    pub fn new() -> Siblings {
        Siblings {
            next: None, 
            prev: None,
        }
    }
}

#[derive(Clone, Debug)]
pub struct FrequencyNode<T> where T: Display + Debug {
    pub item_nodes: ItemNodeList<T>,
    pub freq: i32,
    pub siblings: Siblings, 
}

impl<T> FrequencyNode<T> where T: Display + Debug {
    pub fn new(freq: i32) -> FrequencyNode<T> {
        FrequencyNode {
            item_nodes: ItemNodeList::new(),
            freq: freq, 
            siblings: Siblings::new(), 
        }
    }
}

impl<T> Display for FrequencyNode<T> where T: Display + Debug {
    fn fmt(&self, f: &mut Formatter) -> Result {
        write!(f, "{:?} {:?} {:?} {:?}", self.freq, self.item_nodes, self.siblings.next, self.siblings.prev)
    }
}

pub type FrequencyNodeArena<T> = HashMap<i32, FrequencyNode<T>>;

