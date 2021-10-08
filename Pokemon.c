#include <stdio.h>
#include <string.h>

typedef char String[21];

typedef struct attackTag {
	String name;
	int pp, accuracy;
} Attack;

typedef struct pokemonTag {
	Attack attackStyle[3];
	String name;
	int type, hp, ap;
} Pokemon;

typedef struct playerTag {
	String name;
	Pokemon pokemon[3];
} Player;

/*
	FUNCTION NAME: initializeAttackTypes
	DESCRIPTION: The function sets up the attack types for each Pokemon.
	PARAMETERS:
		1. type      (int) holds the type of Pokemon.
		2. attacks[] (Attack) is a struct variable that holds information on the attack.
	RETURN VALUE: None
*/

void initializeAttackTypes(int type, Attack attacks[]) {
	if(type == 1) {
		strcpy(attacks[0].name, "Leaf Storm");
		attacks[0].pp = 130;
		attacks[0].accuracy = 90;
		
		strcpy(attacks[1].name, "Mega Drain");
		attacks[1].pp = 50;
		attacks[1].accuracy = 100;
		
		strcpy(attacks[2].name, "Razor Leaf");
		attacks[2].pp = 55;
		attacks[2].accuracy = 95;
	}
	else if(type == 2) {
		strcpy(attacks[0].name, "Ember");
		attacks[0].pp = 60;
		attacks[0].accuracy = 100;
		
		strcpy(attacks[1].name, "Fire Punch");
		attacks[1].pp = 85;
		attacks[1].accuracy = 80;
		
		strcpy(attacks[2].name, "Flame Wheel");
		attacks[2].pp = 70;
		attacks[2].accuracy = 90;
	}
	else {
		strcpy(attacks[0].name, "Bubble");
		attacks[0].pp = 40;
		attacks[0].accuracy = 100;
		
		strcpy(attacks[1].name, "Hydro Pump");
		attacks[1].pp = 185;
		attacks[1].accuracy = 30;
		
		strcpy(attacks[2].name, "Surf");
		attacks[2].pp = 70;
		attacks[2].accuracy = 90;
	}
}

/*
	FUNCTION NAME: initializePokemons
	DESCRIPTION: The function sets up the Pokemons.
	PARAMETERS:
		1. pokemons[] (Pokemon) is a struct variable that holds information on the Pokemon.
	RETURN VALUE: None
*/

void initializePokemons(Pokemon pokemons[]) {
	int i;
	
	strcpy(pokemons[0].name, "Bulbasaur");
	pokemons[0].type = 1;
	pokemons[0].hp = 160;
	pokemons[0].ap = 40;
	
	strcpy(pokemons[1].name, "Bellsprout");
	pokemons[1].type = 1;
	pokemons[1].hp = 140;
	pokemons[1].ap = 60;
	
	strcpy(pokemons[2].name, "Oddish");
	pokemons[2].type = 1;
	pokemons[2].hp = 150;
	pokemons[2].ap = 50;
	
	strcpy(pokemons[3].name, "Charmander");
	pokemons[3].type = 2;
	pokemons[3].hp = 125;
	pokemons[3].ap = 70;
	
	strcpy(pokemons[4].name, "Ninetails");
	pokemons[4].type = 2;
	pokemons[4].hp = 130;
	pokemons[4].ap = 50;
	
	strcpy(pokemons[5].name, "Ponyta");
	pokemons[5].type = 2;
	pokemons[5].hp = 140;
	pokemons[5].ap = 60;
	
	strcpy(pokemons[6].name, "Squirtle");
	pokemons[6].type = 3;
	pokemons[6].hp = 180;
	pokemons[6].ap = 20;
	
	strcpy(pokemons[7].name, "Psyduck");
	pokemons[7].type = 3;
	pokemons[7].hp = 170;
	pokemons[7].ap = 40;
	
	strcpy(pokemons[8].name, "Seel");
	pokemons[8].type = 3;
	pokemons[8].hp = 150;
	pokemons[8].ap = 50;
	
	for(i = 0; i < 9; i++) {
		initializeAttackTypes(pokemons[i].type, pokemons[i].attackStyle);
	}
}

/*
	FUNCTION NAME: displayPokemonList
	DESCRIPTION: The function displays the information on the available Pokemon.
	PARAMETERS:
		1. pokemons[] (Pokemon) is a struct variable that contains the information of the Pokemon.
	RETURN VALUE: None
*/

void displayPokemonList(Pokemon pokemons[]) {
	int i;
	
	for(i = 0; i < 9; i++) {
		printf("Name: %s\n", pokemons[i].name);
		printf("Health Points: %d \t Attack Points: %d \n\n", pokemons[i].hp, pokemons[i].ap);
	}
}

/*
	FUNCTION NAME: chooseUserPokemon
	DESCRIPTION: The function asks the user for their choice of Pokemon.
	PARAMETERS:
		1. user *(Player) is the struct variable containing the information of the player.
		2. cpu   (Pokemon) is the struct variable containing the information of the Pokemon.
	RETURN VALUE: None
*/

void chooseUserPokemon(Player *player, Pokemon pokemons[]) {
	system("@cls||clear");
	printf("There are nine Pokemons in total.\n");
	printf("Please choose three out of the nine.\n\n");
	displayPokemonList(pokemons);
}

/*
	FUNCTION NAME: setPlayerNames
	DESCRIPTION: The function asks the user for the names.
	PARAMETERS:
		1. user *(Player) is the struct variable containing the information of the player.
		2. cpu  *(Player) is the struct variable containing the information of the opponent.
	RETURN VALUE: None
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
	FUNCTION NAME: printEndingMessage
	DESCRIPTION: The function prints out the message before terminating the program.
	PARAMETERS: None
	RETURN VALUE: None
*/

void printEndingMessage() {
	printf("\t\t\t\t   Thank you for playing! The program will terminate. \n");
}

/*
	FUNCTION NAME: printMainMenu
	DESCRIPTION: The function prints out the main menu for the user.
	PARAMETERS: None
	RETURN VALUE: 1 - Play || 2 - Exit
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
	FUNCTION NAME: printPokemonLogo
	DESCRIPTION: The function prints out the ASCII Pokemon logo.
	PARAMETERS: None
	RETURN VALUE: None
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
	Pokemon pokemons[9];
	
	printPokemonLogo();
	gameMode = printMainMenu();
	
	if(gameMode == 1) {
		setPlayerNames(&user, &cpu);
		initializePokemons(pokemons);
		chooseUserPokemon(&user, pokemons);
	}
	else {
		printEndingMessage();
	}
	
	return 0;
}
