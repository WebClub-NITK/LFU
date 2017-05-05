use structs::frequency_node::FrequencyNode;
use std::cell::RefCell;
use std::rc::Rc;

#[derive(Clone)]
pub struct ItemNode<T> {
    value: T,
    parent: Option<Rc<RefCell<FrequencyNode<T>>>>,
}
impl<T> ItemNode<T> {
    pub fn new(value: T, parent: Rc<RefCell<FrequencyNode<T>>>) -> ItemNode<T> {
        ItemNode {
            value: value,
            parent: Some(parent),
        }
    }
}
pub type ItemNodeList<T> = Vec<ItemNode<T>>;
