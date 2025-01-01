// 004_functions.rs
// Rust에서 함수 정의 및 호출을 연습합니다.

fn main() {
    greet("Rust");

    let result = add(3, 5);
    println!("3 + 5 = {}", result);
}

fn greet(name: &str) {
    println!("Hello, {}!", name);
}

fn add(a: i32, b: i32) -> i32 {
    a + b
}
