use structs::frequency_node::FrequencyNode;

pub struct ItemNodeList<'a, T: 'a> {
    items: Option<Vec<T>>,
    parent: &'a FrequencyNode<'a, T>,
}

impl<'a, T> ItemNodeList<'a, T> {
    pub fn new(value: i32, parent: &'a FrequencyNode<T>) -> ItemNodeList<'a, T> {
        ItemNodeList {
            items: Some(Vec::new()),
            parent: parent,
        }
    }
}
