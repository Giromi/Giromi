// 008_error_handling.rs
// Rust에서 에러 처리를 연습합니다.

fn divide(a: i32, b: i32) -> Result<i32, String> {
    if b == 0 {
        Err(String::from("0으로 나눌 수 없습니다."))
    } else {
        Ok(a / b)
    }
}

fn main() {
    match divide(10, 2) {
        Ok(result) => println!("결과: {}", result),
        Err(e) => println!("에러 발생: {}", e),
    }

    match divide(10, 0) {
        Ok(result) => println!("결과: {}", result),
        Err(e) => println!("에러 발생: {}", e),
    }
}
