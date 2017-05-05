// Well, let us assume that the parent is simply a frequency node.
#[derive(Clone)]
pub struct ItemNode<T> {
    pub value: T,
    pub parent: i32,
}

impl<T> ItemNode<T> {
    pub fn new(value: T, parent: i32) -> ItemNode<T> {
        ItemNode {
            value: value,
            parent: parent,
        }
    }
}
pub type ItemNodeList<T> = Vec<ItemNode<T>>;
