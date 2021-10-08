#include <stdio.h>
#include <string.h>

typedef char String[21];

typedef struct pokemonTag {
	String name;
	int type, hp, ap;
} Pokemon;

typedef struct playerTag {
	String name;
	Pokemon pokemon[3];
} Player;

/*
	FUNCTION: setPlayerNames
	PURPOSE: The function asks the user the name of the user and the name of the user's opponent
	PRE-CONDITION: The user must accept that he or she must play the game.
	POST-CONDITION: The user will then set the names of the user and the opponent.
	PARAMETERS:
		1. *user - Player struct that pertains to the user.
		2. *cpu - Player struct that pertains to the opponent.
*/

void setPlayerNames(Player *user, Player *cpu) {
	char answer;
	
	do {
		system("@cls||clear");
		printf("Hello there! What is your name? \n");
		printf("Input: ");
		scanf("%s", user->name);
		printf("Hello, %s! What is the name of your opponent? \n", user->name);
		printf("Input: ");
		scanf("%s", cpu->name);
		printf("To confirm, your name is %s and the opponent's name is %s? \n", user->name, cpu->name);
		
		do {
			printf("Input (y/n): ");
			scanf(" %c", &answer);
			fflush(stdin);
		} while(answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n');
		
	} while(answer != 'Y' && answer != 'y');
}

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
	Player user, cpu;
	
	printPokemonLogo();
	gameMode = printMainMenu();
	
	if(gameMode == 1) {
		setPlayerNames(&user, &cpu);
	}
	else {
		printEndingMessage();
	}
	
	return 0;
}
