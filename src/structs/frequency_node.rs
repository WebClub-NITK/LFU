use std::fmt::{Display, Formatter, Result};
use std::fmt::Debug;
use std::collections::HashMap;
use structs::item_node::ItemNodeList;

/// A Node in the arena can have neighbors which are being represented here.
/// We may or may not have a Sibling and hence using Option<> here.
/// Sibling Nodes are tracked using previous and next tags.
#[derive(Clone, Debug)]
pub struct Siblings {
    pub next: Option<i32>,
    pub prev: Option<i32>,
}

impl Siblings {
    /// Creates a new Siblings element with both prev and next as None.
    pub fn new() -> Siblings {
        Siblings {
            next: None, 
            prev: None,
        }
    }
}

/// FrequencyNode represents a single frequency value and contains a vec of ItemNodes.
#[derive(Clone, Debug)]
pub struct FrequencyNode<T> where T: Display + Debug {
    /// ItemNodeList contained as a part of the FrequencyNode.
    pub item_nodes: ItemNodeList<T>,
    /// Frequency represented by the Node.
    pub freq: i32,
    /// For easier navigation.
    pub siblings: Siblings, 
}

impl<T> FrequencyNode<T> where T: Display + Debug {
    /// Creates a new FrequencyNode with an empty ItemNodeList.
    ///
    /// # Arguments
    ///
    /// * `freq`: Representative element of the Node.
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

/// FrequencyNodeArena is a HashMap of a frequency and its FrequencyNode.
pub type FrequencyNodeArena<T> = HashMap<i32, FrequencyNode<T>>;

