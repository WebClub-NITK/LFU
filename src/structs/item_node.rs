use std::fmt::{Display, Formatter, Result};
use std::fmt::Debug;

// Well, let us assume that the parent is simply a frequency node.
/// ItemNode used to represent each item inserted into the Cache.
#[derive(Clone, Debug)]
pub struct ItemNode<T> where T: Display + Debug {
    /// Value of a generic type T
    pub value: T,
    /// Parent Node is basically the frequency value of the FrequencyNode is belongs to.
    pub parent: i32,
}

impl<T> ItemNode<T> where T: Display + Debug {
    /// Used to create a new ItemNode.
    ///
    /// Returns a new ItemNode with provided value and parent.
    ///
    /// # Arguments
    ///
    /// `value`: Of any generic type
    /// `parent`: Value of the FrequencyNode it should be part of.
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

/// Type Alias for a Vec of ItemNodes of a generic type T
pub type ItemNodeList<T> = Vec<ItemNode<T>>;

