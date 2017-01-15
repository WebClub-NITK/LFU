use structs::Cache;
use structs::ItemNode;
use structs::AccessFrequencyList;
mod structs;

use std::collections::HashMap;

fn main() {
    println!("Hello, world");
    let h: HashMap<i32, Box<ItemNode>> = HashMap::new();
    let a = AccessFrequencyList::Nil;
    let c = Cache::new(a, h);
}

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
    }
}
