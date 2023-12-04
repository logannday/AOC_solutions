use std::fs::File;
use std::io::BufRead;
use std::io::BufReader;
fn main() -> std::io::Result<()> {
    let file = File::open("input.txt")?;
    let reader = BufReader::new(file);
    let mut possible_games: Vec<u32> = Vec::new();
    for (mut i, game) in reader.lines().enumerate() {
        println!("game {}", i);
        // Trim up to colon
        let game = game?;
        let game = &game[game.find(':').unwrap() + 2..game.len()];
        let mut is_valid: bool = true;
        for round in game.split(';') {
            // println!("{}:{}", i, round);
            for counts in round.split(',') {
                println!("{}", counts.trim());
                let counts: Vec<_> = counts.trim().split(' ').collect();
                let count: u32 = counts[0].parse().unwrap();
                match counts[1]{
                    "red" => {
                        if count > 12 {
                            is_valid = false;
                        }
                    }, 
                    "green" => {
                        if count > 13 {
                            is_valid = false;
                        }
                    }, 
                    "blue" => {
                        if count > 14 {
                            is_valid = false;
                        }
                    }, 
                    _ => println!("did not match"), 
                }
            }
        }
        println!("is valid: {}", is_valid);

        if is_valid {
            i += 1;
            possible_games.push(i.try_into().unwrap());
        }
    }
    let sum: u32 = possible_games.iter().sum();
    println!("Sum: {}", sum);

    Ok(())
}

