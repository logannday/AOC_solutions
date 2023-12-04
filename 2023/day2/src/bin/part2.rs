use std::fs::File;
use std::io::BufRead;
use std::io::BufReader;
fn main() -> std::io::Result<()> {
    let file = File::open("input2.txt")?;
    let reader = BufReader::new(file);
    let mut sum = 0;
    for game in reader.lines() {
        let mut min_red = 0;
        let mut min_green = 0;
        let mut min_blue = 0;
        // Trim up to colon
        let game = game?;
        let game = &game[game.find(':').unwrap() + 2..game.len()];
        for round in game.split(';') {
            for counts in round.split(',') {
                println!("{}", counts.trim());
                let counts: Vec<_> = counts.trim().split(' ').collect();
                let count: u32 = counts[0].parse().unwrap();
                match counts[1] {
                    "red" => {
                        if count > min_red {
                            min_red = count;
                        }
                    }
                    "green" => {
                        if count > min_green {
                            min_green = count;
                        }
                    }
                    "blue" => {
                        if count > min_blue {
                            min_blue = count;
                        }
                    }
                    _ => println!("did not match"),
                }
            }
        }
        sum += min_red * min_green * min_blue;
    }
    println!("Sum: {}", sum);

    Ok(())
}
