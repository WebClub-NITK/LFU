use std::collections::HashMap;

use structs::ItemNode;

use structs::FrequencyNode;
use structs::FrequencyNodeList;

use std::rc::Rc;
use std::cell::RefCell;

enum CacheError {
    InsertError
}

// Let's assume that we will be having a maximum of 50 elements in the cache?
// That allows us to implement the least frequently used removal algorithm,
// along with the cache implementation.
pub struct Cache<T> {
    pub fnode_list: FrequencyNodeList<FrequencyNode<T>>,
    pub lookup_table: HashMap<i32, Option<Rc<RefCell<T>>>>,
}

// TODO: Add functionality to load existing data onto cache?
impl<T> Cache<T> {
    pub fn new() -> Cache<T> {
        let fnode_list = FrequencyNodeList::new();
        let lookup_table = HashMap::new();

        Cache {
            fnode_list: fnode_list,
            lookup_table: lookup_table
        }
    }

    pub fn insert_element(mut self, value: T) -> Result<(), CacheError> {
        // FIXME:
        // Let us assume that the element does not already exist in the cache(for now)
        // Add a function which checks if node with freq 1 exists?
        
        let f = RefCell::new(FrequencyNode::new(1));
        self.fnode_list.push_front(f.into_inner());

        let i = ItemNode::new(value, Rc::new(f));

        Ok(())
    }
}
