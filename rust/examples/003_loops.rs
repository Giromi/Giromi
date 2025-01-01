// 003_loops.rs
// Rust에서 다양한 반복문을 연습합니다.

fn main() {
    // for 반복문
    for i in 1..5 {
        println!("for 반복문: {}", i);
    }

    // while 반복문
    let mut count = 3;
    while count > 0 {
        println!("while 반복문: {}", count);
        count -= 1;
    }

    // loop 반복문
    let mut num = 0;
    loop {
        if num == 3 {
            break;
        }
        println!("loop 반복문: {}", num);
        num += 1;
    }
}
