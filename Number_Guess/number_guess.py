
import random

def main():
    print("Welcome to Number Guessing Game!")
    lower = 1
    upper = 100
    number = random.randint(lower, upper)
    attempts = 0
    print(f"I've picked a number between {lower} and {upper}. Can you guess it?")

    while True:
        guess = input("Enter your guess: ")
        if not guess.isdigit():
            print("Please enter a valid number.")
            continue
        guess = int(guess)
        attempts += 1
        if guess < number:
            print("Too low! Try again.")
        elif guess > number:
            print("Too high! Try again.")
        else:
            print(f"Congratulations! You guessed it in {attempts} attempts.")
            break

if __name__ == "__main__":
    main()
