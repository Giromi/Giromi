
fn main() {
    let first_letter = 'A';
    let space = ' '; // A space inside ' ' is also a char
    let other_language_char = 'Ꮔ'; // Thanks to Unicode, other languages like Cherokee display just fine too
    let cat_face = '😺'; // Emojis are chars too
    
    // ASCII
    // casting = simple type change

    let my_number: u16 = 97;
    let second_number: u8 = 10;
    let thrid_number = my_number + second_number as u16;


    let my_num = 'a' as u8;

    // curly brackets
    println!("Hello, world! My number is {}", my_num);
}
