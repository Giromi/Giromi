// 001_variables.rs
// Rust에서 변수 선언과 가변성을 다룹니다.

fn main() {
    let x = 5; // 기본적으로 불변 변수
    println!("x의 값: {}", x);

    let mut y = 10; // 가변 변수
    println!("y의 값: {}", y);
    y = 15; // 값 변경 가능
    println!("변경된 y의 값: {}", y);
}
