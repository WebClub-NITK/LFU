use structs::FrequencyNode;

pub struct ItemNode {
    // Assuming integer value of variables.
    pub value: i32,
    pub frequency_parent: FrequencyNode,
    pub next: Option<Box<ItemNode>>,
    pub previous: Option<Box<ItemNode>>,
}
