use frequency_node::{FrequencyNode};

pub struct ItemNode<'a> {
    // Assuming integer value of variables.
    pub Value: i32,
    pub FrequencyParent: FrequencyNode<'a>,
    pub Next: Option<ItemNode<'a>>,
    pub Previous: Option<ItemNode<'a>>,
}
