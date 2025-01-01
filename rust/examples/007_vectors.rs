// 007_vectors.rs
// Rust에서 벡터를 사용하는 방법을 연습합니다.

fn main() {
    let mut numbers = vec![1, 2, 3];
    numbers.push(4);

    for num in &numbers {
        println!("{}", num);
    }

    println!("벡터의 길이: {}", numbers.len());
}
