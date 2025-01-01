// 006_enums.rs
// Rust에서 열거형을 정의하고 사용하는 방법을 연습합니다.

enum Direction {
    Up,
    Down,
    Left,
    Right,
}

fn main() {
    let dir = Direction::Up;

    match dir {
        Direction::Up => println!("위로 이동합니다."),
        Direction::Down => println!("아래로 이동합니다."),
        Direction::Left => println!("왼쪽으로 이동합니다."),
        Direction::Right => println!("오른쪽으로 이동합니다."),
    }
}
