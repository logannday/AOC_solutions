use std::fs::File;
use std::io::BufRead;
use std::io::BufReader;

fn main() -> std::io::Result<()> {
    let mut sum = 0;
    let f = File::open("input.txt")?;
    let reader = BufReader::new(f);

    for line in reader.lines() {
        // println!("{}", first_num(&line.unwrap()));
        let line = line?;
        let first = first_digit(&line).unwrap();
        let last = last_digit(&line).unwrap();
        let mut num_string = String::new();
        num_string.push(first);
        num_string.push(last);
        let num: u32 = num_string.parse().unwrap();
        sum += num;
    }

    println!("Sum: {}", sum);

    Ok(())
}

fn last_digit(line: &str) -> Result<char, &'static str> {
    // index of last digit in word
    let mut i = line.len() - 1;
    for c in line.chars().rev() {
        if c.is_numeric() {
            return Ok(c);
        }
        let n = ends_num(String::from(line), i);
        if n != 'f' {
            return Ok(n);
        }
        i -= 1;
    }
    return Err("did not find first number");
}

fn first_digit(line: &str) -> Result<char, &'static str> {
    let mut i = 0;
    for c in line.chars() {
        if c.is_numeric() {
            return Ok(c);
        }
        let n = begins_num(String::from(line), i);
        if n != 'f' {
            return Ok(n);
        }
        i += 1;
    }
    return Err("did not find first number");
}

// Returns a char representation of the number if the substring, and
fn ends_num(line: String, index: usize) -> char {
    if index >= 2 && &line[index - 2..index + 1] == "one" {
        return '1';
    }
    if index >= 2 && &line[index - 2..index + 1] == "two" {
        return '2';
    }
    if index >= 4 && &line[index - 4..index + 1] == "three" {
        return '3';
    }
    if index >= 3 && &line[index - 3..index + 1] == "four" {
        return '4';
    }
    if index >= 3 && &line[index - 3..index + 1] == "five" {
        return '5';
    }
    if index >= 2 && &line[index - 2..index + 1] == "six" {
        return '6';
    }
    if index >= 4 && &line[index - 4..index + 1] == "seven" {
        return '7';
    }
    if index >= 4 && &line[index - 4..index + 1] == "eight" {
        return '8';
    }
    if index >= 3 && &line[index - 3..index + 1] == "nine" {
        return '9';
    }
    if index >= 3 && &line[index - 3..index + 1] == "zero" {
        return '0';
    }

    return 'f';
}
// Returns a char representation of the number if the substring, and
fn begins_num(line: String, index: usize) -> char {
    if line.len() >= index + 3 && &line[index..index + 3] == "one" {
        return '1';
    }
    if line.len() >= index + 3 && &line[index..index + 3] == "two" {
        return '2';
    }
    if line.len() >= index + 5 && &line[index..index + 5] == "three" {
        return '3';
    }
    if line.len() >= index + 4 && &line[index..index + 4] == "four" {
        return '4';
    }
    if line.len() >= index + 4 && &line[index..index + 4] == "five" {
        return '5';
    }
    if line.len() >= index + 3 && &line[index..index + 3] == "six" {
        return '6';
    }
    if line.len() >= index + 5 && &line[index..index + 5] == "seven" {
        return '7';
    }
    if line.len() >= index + 5 && &line[index..index + 5] == "eight" {
        return '8';
    }
    if line.len() >= index + 4 && &line[index..index + 4] == "nine" {
        return '9';
    }
    if line.len() >= index + 4 && &line[index..index + 4] == "zero" {
        return '0';
    }

    return 'f';
}

