pub struct FrequencyNode {
    pub value: i32,
    pub next: i32,
    pub previous: Option<Box<FrequencyNode>>,
}
