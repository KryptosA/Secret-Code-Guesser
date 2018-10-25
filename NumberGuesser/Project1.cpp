#include <iostream>
#include <cstdlib>
#include "Project1.h"
#include <vector>

using namespace std;

// FUNCTION DEFINITIONS

string player_code = "0000";
int digit_value;

// GET PLAYER CODE

string get_player_code() {
	
	/* Prompts the user to enter a four-digit code, then checks code length and whether digits are in bounds */
	
	/* Local Variables */

	string player_code = string(CODE_LENGTH, '0');  /* Player's validated code (initially filled with zeros) */
	
	string player_input;                            /* Player's input */
	
	char digit;                                     /* Next digit from player's input (for code validation) */
	
	bool valid_code = false;                        /* "Valid code" flag, initially set to false (for code validation) */
	bool invalid_digit_entered;                     /* "Invalid digit entered" flag (for code validation) */
	
	/* Repeat the input loop until we have validated every digit of the player's input */

	while ( !valid_code ) {

		/* Reset "invalid digit entered" flag */

		invalid_digit_entered = false;

		/* Prompt player for code */

		cout << "Enter Code: ";
		cin >> player_input;

		/* Is code too short or too long? */

		if ( player_input.size() != CODE_LENGTH ) {

			cout << "ERROR: Code must be exactly " << CODE_LENGTH << " digits long!\n\n";

		}

		/* If not, loop through player_input and check each digit, copying validated digits into player_code */

		else {
			
			while (digit < CODE_LENGTH) {
		
				digit_value = player_input[digit] - '0';
		
				if (digit_value < 1 || digit_value > CODE_SPAN) {
					cout << "Please type numbers between 1 and 6" << '\n';
				}
				
				else { 
					player_code[digit] = player_input[digit];
				
				}
		
				++digit;
		}
		
			/* If all digits in player_input checked out, flip "valid code" flag to true to exit validation loop */
			
			valid_code =  true;

		}

	} // End while()

	/* Return player's validated code */

	return player_code;

} // End get_player_code()



// GENERATE SECRET CODE

string generate_code() {
	
	/* Generates a four-digit secret code at random using randint() helper functions */
	
	/* Local variables */

	int min = 1;
	int max = 6;
	int random_var;
	string rand_num;
	string gen_code;
	string secret_code;

	char digit;                                     /* Next digit of secret code */
	
	string code = "0000";                               /* Secret code, initially empty (append new digits using +=) */
	
	/* Build random code of length CODE_LENGTH, with digits within range specified by CODE_SPAN */
	
	
	
	while (digit < CODE_LENGTH) {
		
		code[digit] += randint(min,max);
		
		++digit;	
	}
	
	
	/* Return newly generated secret code */
	
	return code;

} // End generate_code()

	

// PRINT INSTRUCTIONS

void print_instructions() {
	
	/* Print welcome message and instructions */
	
	cout << "WELCOME TO CODEBREAKER!\n\n";
	cout << "The computer has created the secret code, and your mission is to guess\n";
	cout << "it! After you register your guesses with the computer, it will respond\n";
	cout << "with numbers that analyze your guesses: 'CORRECT' indicates the number\n";
	cout << "of digits that are the correct identity AND in the correct places, and\n";
	cout << "'MISPLACED' indicates the number of digits of the correct identity\n";
	cout << "that are NOT in the correct places.\n\n";
	cout << "See if you can get all of the digits correct within twelve guesses!\n\n";
	return;
	
}



// RANDOM NUMBER GENERATOR ( Returns random integer N where 0 <= N < MAX )

int randint(int max) {

	return ( rand() % max );
	

} // End randint()



// RANDOM NUMBER GENERATOR ( Returns random integer N where MIN <= N < MAX )

int randint(int min, int max) {

	return ( randint( max - min ) + min );

} // End randint()
