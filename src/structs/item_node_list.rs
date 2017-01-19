use structs::frequency_node::FrequencyNode;

pub struct ItemNodeList<'a, T: 'a> {
    items: Option<Vec<T>>,
    parent: Option<&'a FrequencyNode<'a, T>>,
}

impl<'a, T> ItemNodeList<'a, T> {
    pub fn new() -> ItemNodeList<'a, T> {
        ItemNodeList {
            items: Some(Vec::new()),
            parent: None,
        }
    }

    pub fn set_parent(&mut self, parent: &'a FrequencyNode<T>) -> () {
        self.parent = Some(parent);
    }
}
