use std::fs;

fn bits(line: &str) -> u64 {
    line.chars()
        .map(|c| match c {
            'a'..='z' => c as u32 - 'a' as u32,
            'A'..='Z' => c as u32 - 'A' as u32 + 26,
            _ => panic!("{c}"),
        })
        .fold(0, |bits, bit| bits | 1 << bit)
}

fn part_two() {
    let mut result = 0;
    let content = fs::read_to_string("./input.txt").unwrap();
    let mut lines = content.lines().peekable();
    while lines.peek().is_some() {
        let bits1 = bits(lines.next().unwrap());
        let bits2 = bits(lines.next().unwrap());
        let bits3 = bits(lines.next().unwrap());

        let common = bits1 & bits2 & bits3;
        result += u64::BITS - common.leading_zeros();
    }
    println!("{result}");
}

#[allow(dead_code)]
fn part_one() {
    let input = fs::read_to_string("./input.txt").unwrap();
    let mut holder: Vec<char> = vec![];
    input.lines().for_each(|line| {
        let first_half = line[0..line.len() / 2].to_string();
        let second_half = line[line.len() / 2..line.len()].to_string();
        for chars in second_half.chars() {
            if first_half.contains(chars) {
                holder.push(chars);
                break;
            }
        }
    });

    let mut total = 0;
    holder
        .iter()
        .map(|c| c.to_owned() as u32)
        .for_each(|chars| {
            if chars > 96 {
                total += (chars - 96) as i32;
            } else {
                total += (chars - 38) as i32;
            }
        });
    println!("{total}");
}

fn main() {
    part_two();
}
