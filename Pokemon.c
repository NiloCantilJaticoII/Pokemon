#include <stdio.h>

/*
	FUNCTION: printEndingMessage
	PURPOSE: The function prints a message to the user that the program will terminate.
	PRE-CONDITION: The user must have exited the game from the main menu.
	POST-CONDITION: None
	PARAMETERS: None
*/

void printEndingMessage() {
	printf("\t\t\t\t   Thank you for playing! The program will terminate. \n");
}

/*
	FUNCTION: printMainMenu
	PURPOSE: The function prints two options for the user to choose in the main menu.
	PRE-CONDITION: None
	POST-CONDITION: This will determine whether the game will start or not.
	PARAMETERS: None
*/

int printMainMenu() {
	int answer;
	
	printf("\t\t\t\t\t\t\t Main Menu \n");
	printf("\t\t\t\t\t\t      Press 1 to Play \n");
	printf("\t\t\t\t\t\t      Press 2 to Exit \n");
	
	do {
		printf("Input: ");
		scanf("%d", &answer);
		fflush(stdin);
	} while(answer != 1 && answer != 2);
	
	return answer;
}

/*
	FUNCTION: printPokemonLogo
	PURPOSE: The function prints the ASCII version of the Pokemon logo.
	PRE-CONDITION: None
	POST-CONDITION: None
	PARAMETERS: None
*/

void printPokemonLogo() {
	printf("\t\t\t                                  ,'\\ \n");
	printf("\t\t\t    _.----.        ____         ,'  _\\   ___    ___     ____ \n");
	printf("\t\t\t_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`. \n");
	printf("\t\t\t\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  | \n");
	printf("\t\t\t \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  | \n");
	printf("\t\t\t   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  | \n");
	printf("\t\t\t    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     | \n");
	printf("\t\t\t     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    | \n");
	printf("\t\t\t      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\     /  | |   | \n");
	printf("\t\t\t       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   | \n");
	printf("\t\t\t        \\_.-'       |__|    `-._ |              '-.|     '-.| |   | \n");
	printf("\t\t\t                                `'                            '-._| \n");
}

int main() {
	int gameMode;
	
	printPokemonLogo();
	gameMode = printMainMenu();
	
	if(gameMode == 1) {
		// Insert code here
	}
	else {
		printEndingMessage();
	}
	
	return 0;
}
