// 005_structs.rs
// Rust에서 구조체를 정의하고 사용하는 방법을 연습합니다.

struct Rectangle {
    width: u32,
    height: u32,
}

fn main() {
    let rect = Rectangle { width: 10, height: 20 };
    println!("사각형의 크기: {} x {}", rect.width, rect.height);
}
