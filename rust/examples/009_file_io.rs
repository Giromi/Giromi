// 009_file_io.rs
// Rust에서 파일 읽기와 쓰기를 연습합니다.

use std::fs;

fn main() -> std::io::Result<()> {
    let filename = "example.txt";

    // 파일 쓰기
    fs::write(filename, "Rust 파일 입출력 예제")?;

    // 파일 읽기
    let content = fs::read_to_string(filename)?;
    println!("파일 내용: {}", content);

    Ok(())
}
