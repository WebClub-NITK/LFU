use std::fmt::{Display, Formatter, Result};
use std::fmt::Debug;

// Well, let us assume that the parent is simply a frequency node.
#[derive(Clone, Debug)]
pub struct ItemNode<T> where T: Display + Debug {
    pub value: T,
    pub parent: i32,
}

impl<T> ItemNode<T> where T: Display + Debug {
    pub fn new(value: T, parent: i32) -> ItemNode<T> {
        ItemNode {
            value: value,
            parent: parent,
        }
    }
}

impl<T> Display for ItemNode<T> where T: Display + Debug {
    fn fmt(&self, f: &mut Formatter) -> Result {
        write!(f, "{}", self.value)
    }
}

pub type ItemNodeList<T> = Vec<ItemNode<T>>;
