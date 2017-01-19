extern crate ixlist;
use self::ixlist::List;

use structs::ItemNodeList;

pub struct FrequencyNode<'a, T: 'a> {
    items_nodes: ItemNodeList<'a, T>,
    value: i32,
}

pub type FrequencyNodeList<'a, T> = List<FrequencyNode<'a, T>>;
