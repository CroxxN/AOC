use std::fs;

fn main() {
    let input = fs::read_to_string("./input.txt").unwrap();
    let (boxes, _instr) = input.split_once("\n\n").unwrap();
    let inp = boxes.lines().collect::<Vec<_>>();
    let length = input.chars().nth_back(1).unwrap();
}
