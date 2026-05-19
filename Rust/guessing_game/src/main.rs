// Guessing Game using RUST in Terminal

use std::cmp::Ordering;
use std::io;

use rand::Rng;

fn main() {
    println!("< GUESS THE NUMBER!! >");
	
	let secret_number = rand::thread_rng().gen_range(1..=100);
	
	//println!("The secret number is: {secret_number}");  // ERROR Checking
	
	loop {
		println!("Please input a whole number between 1 and 100:");
	
		let mut guess = String::new();
	
		io::stdin()
			.read_line(&mut guess)
			.expect("Failed to read line.");
		let guess: u32 = match guess.trim().parse() {
			Ok(num) => num,
			Err(_) => continue,
		};
		
		println!("You guessed: {guess}");
	
		match guess.cmp(&secret_number) {
			Ordering::Less => println!("Too Small!"),
			Ordering::Greater => println!("Too Big!"),
			Ordering::Equal => {
				println!("You Win!!!");
				break;
			}
		}
	}
}
