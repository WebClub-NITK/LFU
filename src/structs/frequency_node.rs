use structs::item_node::ItemNodeList;

#[derive(Clone)]
pub struct FrequencyNode<T> {
    pub item_nodes: ItemNodeList<T>,
    pub value: i32,
}

impl<T> FrequencyNode<T> {
    pub fn new(value: i32) -> FrequencyNode<T> {
        FrequencyNode {
            value: value,
            item_nodes: ItemNodeList::new(),
        }
    }
}

impl<T> PartialEq for FrequencyNode<T> {
    fn eq(&self, other: &FrequencyNode<T>) -> bool {
        self.value == other.value
    }
}

impl<T> Eq for FrequencyNode<T> {}

pub type FrequencyNodeList<FrequencyNode> = Vec<FrequencyNode>;
