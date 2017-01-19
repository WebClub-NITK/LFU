use std::collections::HashMap;

use structs::FrequencyNodeList;
use structs::ItemNodeList;

pub struct Cache<'a, T: 'a> {
    pub fnode_list: FrequencyNodeList<'a, T>,
    pub lookup_table: HashMap<i32, &'a T>,
}

// TODO: Add functionality to load existing data onto cache?
impl<'a, T> Cache<'a, T> {
    pub fn new() -> Cache<'a, T> {
        let fnode_list = FrequencyNodeList::new();
        let lookup_table = HashMap::new();

        Cache {
            fnode_list: fnode_list,
            lookup_table: lookup_table
        }
    }
}
