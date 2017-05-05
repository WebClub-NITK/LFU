extern crate ixlist;
use self::ixlist::List;

use structs::ItemNodeList;
use structs::ItemNode;

#[derive(Clone)]
pub struct FrequencyNode<T> {
    item_nodes: ItemNodeList<T>,
    value: i32,
}

impl<T> FrequencyNode<T> {
    pub fn new(value: i32) -> FrequencyNode<T> {
        FrequencyNode {
            value: value,
            item_nodes: ItemNodeList::new(),
        }
    }
}

pub type FrequencyNodeList<FrequencyNode> = List<FrequencyNode>;
