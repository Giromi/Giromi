// 002_conditions.rs
// Rust의 조건문을 연습합니다.

fn main() {
    let number = 10;

    if number > 0 {
        println!("{}는 양수입니다.", number);
    } else if number < 0 {
        println!("{}는 음수입니다.", number);
    } else {
        println!("숫자는 0입니다.");
    }
}
