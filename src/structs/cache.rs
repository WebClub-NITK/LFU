use std::collections::HashMap;
use structs::FrequencyNode;
use structs::FrequencyNodeList;

enum CacheError {
    InsertError
}

// Let's assume that we will be having a maximum of 50 elements in the cache?
// That allows us to implement the least frequently used removal algorithm,
// along with the cache implementation.
pub struct Cache<'a, T: 'a> {
    pub fnode_list: FrequencyNodeList<'a, FrequencyNode<'a, T>>,
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

    pub fn insert_element(mut self, element_val: T) -> Result<(), CacheError> {
        // FIXME:
        // Let us assume that the element does not already exist in the cache(for now)
        // Add a function which checks if node with freq 1 exists?
        
        let f: FrequencyNode<T> = FrequencyNode::new(1);
        let s = self.fnode_list.push_front(f);

        Ok(())
    }
}
