use std::fs;

fn part_one(input: String) -> i32 {
    let mut answer = 0;
    let _ = input
        .split(&['-', ',', '\n'])
        .take(4)
        .map(|x| x.parse::<u8>().unwrap_or_default())
        .collect::<Vec<_>>()
        .chunks_exact(4)
        .for_each(|x| {
            println!("{:?}", x);
            if (x[0] <= x[2] && x[1] >= x[3]) || (x[0] >= x[2] && x[1] <= x[3]) {
                answer += 1;
            }
        });
    answer
}

fn part_two(input: String) -> i32 {
    let mut answer = 0;
    let _ = input
        .split(&['-', ',', '\n'])
        .map(|x| x.parse::<u8>().unwrap_or_default())
        .collect::<Vec<_>>()
        .chunks_exact(4)
        .for_each(|x| {
            println!("{:?}", x);
            if (x[0] <= x[2] && x[1] >= x[3]) || (x[0] >= x[2] && x[1] <= x[3]) {
                answer += 1;
            } else if (x[0] <= x[2] && x[0] >= x[3])
                || (x[0] >= x[2] && x[0] <= x[3])
                || (x[1] >= x[2] && x[1] <= x[3])
                || (x[1] <= x[2] && x[1] >= x[3])
            {
                answer += 1;
            }
        });
    answer
}

fn main() {
    let input = fs::read_to_string("./input.txt").unwrap();
    println!("{}", part_two(input));
}
