# CODEBREAKER
## Introduction
This is a program in C++ that demonstrates a basic method for guessing a 4 digit sequence of numbers. 
The game is run via command console. This was an assignment done in class as a way to test our ability to work with random 
number generation.
## Getting Started
The program is run via an executable and will display in the command console with instructions on how to play. 
### Playing the Game
The game will ask for a sequence of 4 digits and there will be two columns for correct and misplaced. The two columns indicate the number correct and the number wrong. If the correct number cannot be guessed within 12 tries you lose and have to start over.
## Code Walkthrough
### Constant Definitions are declared
The maximum code length is four digits and the digits are between 1 and 6. The maximum number of guesses is 12.
```
const int CODE_SPAN = 6;
const int CODE_LENGTH = 4;
const int MAX_GUESSES = 12;
```
### Main Function
A random number is generated using the empty code string. New numbers are appended to it using a for loop to generate each digit.
This will build random code of length CODE_LENGTH, with digits within range specified by CODE_SPAN. 
```
string code = "0000"

while (digit < CODE_LENGTH) {
		
	code[digit] += randint(min,max);
		
	++digit;	
}
```
Local variables are declared for storing the secret code and player code as well as the copies of the code 
among variables for correct and incorrect digits.

The welcome message explaining the game is then printed.

### Main Loop
This is the loop that will keep track of the number of guesses, the correct guesses, misplaced guesses, and
the number of the round.
In a for loop there are 2 nested if statements with the following arrays: 
```
player_code_copy[i] = 'x';
secret_code_copy[j] = 'y';
```
These arrays govern the counters for the correct_digits and misplaced_digits counters.
If the correct number is guessed while below the maximum guess number a message displays showing that the player has won.
Similarly if the player fails to guess the correct code a message displaying that the player failed shows up.

### Inputs
The game will query for your code input which is just a 4 digit number.
```
Enter Code: 
```
When you win you will be asked to play again. The case of the digit does not matter.
```
Would you like to play again (Y/N)? 
```

### Error handling
There are certain built in methods for error handling.
If the code length is too long an error for matching the specific code length will appear.
```
ERROR: Code must be exactly " << CODE_LENGTH << " digits long!\n\n
```
If characters are entered instead of numbers the following message will appear:
```
Please type numbers between 1 and 6
```

