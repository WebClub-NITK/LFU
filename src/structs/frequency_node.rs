extern crate ixlist;
use self::ixlist::List;

use structs::ItemNodeList;

pub struct FrequencyNode<'a, T: 'a> {
    item_nodes: ItemNodeList<'a, T>,
    value: i32,
}

impl<'a, T> FrequencyNode<'a, T> {
    pub fn new(value: i32) -> FrequencyNode<'a, T> {
        FrequencyNode {
            value: value,
            item_nodes: ItemNodeList::new(),
        }
    }
}

pub type FrequencyNodeList<'a, FrequencyNode> = List<FrequencyNode>;
