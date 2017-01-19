use structs::*;
mod structs;

use std::collections::HashMap;

fn main() {
    let mut c = Cache::<i32>::new();
    c.insert_element(23);
}

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
    }
}
