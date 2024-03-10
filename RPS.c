/*Author: <Mark Daoud>
Date : <10/11/23>
Purpose : <The program uses a enum type choice and a Choice get_choice function to get a chracter inpu from the player and then uses variables 
of the enumerated type in the rest of the program and the function determine_winner prints the result based on the input as well as the condition 
of the result>
	Time Spent : <An hour >
*/




#include <stdio.h>
#include <ctype.h>

enum choice {ROCK, PAPER, SCISSORS};
typedef enum choice Choice;

void clear_keyboard_buffer(void);
Choice get_choice(void);
void determine_winner(Choice player1_choice, Choice player2_choice);

int main(int argc, char* argv[])
{
	char play_again; 
	do
	{
		printf("Player 1 it is your turn!\n");
		Choice player1_choice = get_choice();
		printf("Player 2 it is your turn!\n");
		Choice player2_choice = get_choice();
		determine_winner(player1_choice, player2_choice); 
		
		printf("Do you want to play again? (y/n): "); 
		scanf(" %c", &play_again); 
		clear_keyboard_buffer();
		play_again = toupper(play_again); 


	} while (play_again == 'Y');
	return 0;
}

void clear_keyboard_buffer(void)
{
	char c;
	scanf("%c", &c);
	while (c != '\n')
	{
		scanf("%c", &c);
	}
}

 Choice get_choice(void)
{
	char choice_rps;
	Choice get_choice;

	do
	{
		printf("Please enter your choice (p)aper, (r)ock, or (s)cissors: ");
		scanf("%c", &choice_rps);
		clear_keyboard_buffer();
		choice_rps = toupper(choice_rps);



		switch (choice_rps)
		{
		case 'P':
			get_choice = PAPER;
			break;
		case 'R':
			get_choice = ROCK;
			break;
		case 'S':
			get_choice = SCISSORS;
			break;
		default:
			printf("I'm sorry, I do not understand \n");
			break;
		}
	} while (!(choice_rps == 'P' || choice_rps == 'R' || choice_rps == 'S'));

	return get_choice;
 }
 void determine_winner(Choice player1_choice, Choice player2_choice) 
 {
	 if (player1_choice == player2_choice) 
	 {
		 printf("Draw, nobody wins\n");
	 }
	 else if ((player1_choice == 0 && player2_choice == 2) ||
		 (player1_choice == 1 && player2_choice == 0) ||
		 (player1_choice == 2 && player2_choice == 1)) 
	 {
		 printf("Player 1 wins!\n");
		 switch (player1_choice) 
		 {
		 case 0: 
			 printf("Rock breaks ");
			 break;
		 case 1: 
			 printf("Paper covers ");
			 break;
		 case 2: 
			 printf("Scissors cut ");
			 break;
		 }
		 switch (player2_choice)
		 {
		 case 0: 
			 printf("Rock\n");
			 break; 
		 case 1: 
			 printf("Paper\n");
			 break;
		 case 2: 
			 printf("Scissors\n");
			 break;
		 }
	 }
	 else 
	 {
		 printf("Player 2 wins!\n");
		 switch (player2_choice) 
		 {
		 case 0: 
			 printf("Rock breaks "); 
			 break; 
		 case 1: 
			 printf("Paper covers "); 
			 break;
		 case 2: 
			 printf("Scissors cut "); 
			 break;
		 }

		 switch (player1_choice) 
		 {
		 case 0: 
			 printf("Rock\n"); 
			 break;
		 case 1:
			 printf("Paper\n"); 
			 break; 
		 case 2:
			 printf("Scissors\n"); 
			 break;
		 }
	 }

 }

