extern crate ixlist;
use std::collections::HashMap;

use frequency_node::{FrequencyNode};
use item_node::{ItemNode};

use self::ixlist::{List, Seek, Cursor};

pub struct Cache<'a> {
    pub AccessFrequencyList: List<FrequencyNode<'a>>,
    pub LookupTable: HashMap<i32, ItemNode<'a>>,
}
