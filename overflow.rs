fn overflow(input_str: String) {
    let output_str: String;
    output_str = input_str.clone();
    println!("{}", output_str);
}

fn main() {
    let rand_str: String = String::from("aaaabbbb\x6c\x73\x20\x2d\x6c\x61ddeeee");
    overflow(rand_str);
}
