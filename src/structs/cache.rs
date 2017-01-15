extern crate ixlist;
use std::collections::HashMap;

use structs::FrequencyNode;
use structs::ItemNode;

// use self::ixlist::{List, Seek, Cursor};

pub enum AccessFrequencyList {
    Cons(Box<AccessFrequencyList>, FrequencyNode),
    Nil
}

pub struct Cache {
    pub af_list: AccessFrequencyList,
    pub lookup_table: HashMap<i32, Box<ItemNode>>,
}

impl Cache {
    pub fn new(af_list: AccessFrequencyList, lookup_table: HashMap<i32, Box<ItemNode>>) -> Cache {
        Cache {
            af_list: af_list,
            lookup_table: lookup_table
        }
    }
}
