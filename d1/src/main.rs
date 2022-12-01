use std::fs;

#[allow(dead_code)]
fn part_one() {
    let mut max = (0, 0);
    let mut local = 0;
    let file = fs::read_to_string("./input.txt").expect("Unable to find");
    file.lines().enumerate().for_each(|line| {
        if line.1.is_empty() {
            max = if local > max.0 {
                (local, line.0 as i32)
            } else {
                max
            };
            local = 0;
        } else {
            local += line.1.trim().parse::<i32>().expect("Unable to parse");
        }
    });
    println!("{:?}", max);
}

fn part_two() {
    let mut max: [(usize, u64); 3] = [(0, u64::MIN); 3];
    let mut local = 0;
    let file = fs::read_to_string("./input.txt").expect("Unable to find");
    file.lines().enumerate().for_each(|line| {
        if line.1.is_empty() {
            if local > max[0].1 {
                max[0] = (line.0, local)
            } else if local > max[1].1 {
                max[1] = (line.0, local);
            } else if local > max[2].1 {
                max[2] = (line.0, local);
            }
            local = 0;
        } else {
            local += line.1.trim().parse::<u64>().expect("Unable to parse");
        }
    });
    let result = (max[0].1) + (max[1].1) + (max[2].1);
    println!("{:?} {} {} {} ", result, max[0].1, max[1].1, max[2].1);
}

fn main() {
    part_two();
}
