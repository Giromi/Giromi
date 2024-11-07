
fn main() {
    // println!("Size of a char: {}"); error

    println!("Size of a char: {}", std::mem::size_of::<char>()); // 4 bytes
    // .len => bytes
    println!("Size of string containing 1 char: {}", "A".len()); // 1
    println!("Size of string containing 1 char: {}", "⚠️".len()); // 1
    println!("Size of string containing 'a': {}", "a".len()); // .len() gives the size of the string in bytes
    println!("Size of string containing 'ß': {}", "ß".len());
    println!("Size of string containing '国': {}", "国".len());
    println!("Size of string containing '𓅱': {}", "𓅱".len());

    let slice = "Hello!";
    println!("Slice is {} bytes and also {} characters.", slice.len(), slice.chars().count());
    let slice2 = "안녕!";
    println!("Slice2 is {} bytes but only {} characters.", slice2.len(), slice2.chars().count());
}//rustc 05.rs && ./05
