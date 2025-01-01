// 010_class_basics.rs
// Rust에서 구조체와 메서드를 사용해 C++의 클래스처럼 구현합니다.

struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn new(width: u32, height: u32) -> Self {
        Self { width, height }
    }

    fn area(&self) -> u32 {
        self.width * self.height
    }
}

fn main() {
    let rect = Rectangle::new(10, 20);
    println!("사각형의 면적: {}", rect.area());
}
