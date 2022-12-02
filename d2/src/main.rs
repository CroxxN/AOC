use std::fs::read_to_string;

fn calc(value: (&str, &str)) -> i32 {
    match value {
        ("A", "Y") => 8,
        ("B", "Z") => 9,
        ("C", "X") => 7,
        ("A", "X") => 4,
        ("B", "Y") => 5,
        ("C", "Z") => 6,
        (_, value) => {
            if value == "X" {
                1
            } else if value == "Y" {
                2
            } else {
                3
            }
        }
    }
}

fn part_one() {
    let mut total = 0_i32;
    let things = read_to_string("./input.txt").unwrap();
    things
        .lines()
        .map(|line| line.trim())
        .for_each(|line| match line.split_once(" ") {
            Some(value) => total += calc(value),
            None => {}
        });
    println!("{total}");
}

fn main() {
    part_one();
}
