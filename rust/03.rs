#![allow(unused_variables)]

fn main() {
    /*
     * + plus sign
     * - minus sign
     * i8, i16, i32, i64, i128 and isize
     * u8, u16, u32, u64, u128 and usize
     */

    /*
     * bits 8 
     * bytes 1
     */


    /* computer achitecture
     * isize -> 32 bit -> i32
     * isize -> 64 bit -> i64
     */
    let number = 10; // 제일 많이 사용하는 타입

    let my_number: u8 = 10;
    let my_other_number = 200;
    let thrid_number = my_number + my_other_number;

    println!("The result is {}", thrid_number);

    let a: i8 = 10;
    let b: i16 = 10;
    // let c = a + b.into(); // i16로 변환
    let c = a as i16 + b; // i8 -> i16로 변환
    println!("The result is {}", c);
}
