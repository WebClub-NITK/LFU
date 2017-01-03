pub struct FrequencyNode<'a> {
    pub Value: i32,
    pub Next: Option<&'a FrequencyNode>,
    pub Previous: Option<&'a FrequencyNode>,
}
