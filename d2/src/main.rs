use std::fs::read_to_string;

fn calc(value: (&str, &str)) -> i32 {
    match value {
        (value, "Z") => match value {
            "A" => 8,
            "B" => 9,
            "C" => 7,
            _ => 0,
        },
        (value, "Y") => match value {
            "A" => 4,
            "B" => 5,
            "C" => 6,
            _ => 0,
        },

        (value, "X") => match value {
            "A" => 3,
            "B" => 1,
            "C" => 2,
            _ => 0,
        },
        _ => 0,
    }
}

fn solve() {
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
    solve();
}
