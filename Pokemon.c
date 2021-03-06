#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef char String[21];

typedef struct attackTag {
	String name;
	int pp, accuracy;
} Attack;

typedef struct pokemonTag {
	Attack attackStyle[3];
	String name;
	int type, hp, currentHP, ap, taken;
} Pokemon;

typedef struct playerTag {
	String name;
	Pokemon pokemon[3];
	int potions;
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
		pokemons[i].taken = 0;
		pokemons[i].currentHP = pokemons[i].hp;
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
		printf("%d.\n", i+1);
		printf("Name: %s\n", pokemons[i].name);
		printf("Health Points: %d \t Attack Points: %d \n\n", pokemons[i].hp, pokemons[i].ap);
	}
}

/*
	FUNCTION NAME: chooseUserPokemon
	DESCRIPTION: The function asks the user for their choice of Pokemon.
	PARAMETERS:
		1. user        *(Player) is the struct variable containing the information of the player.
		2. cpu          (Player) is the struct variable containing the information of the CPU.
		3. pokemons[]   (Pokemon) is the struct variable containing the information of the Pokemon.
	RETURN VALUE: None
*/

void chooseUserPokemon(Player *player, Player *cpu, Pokemon pokemons[]) {
	int input, userCounter = 0, cpuCounter = 0, i;
	String dump;
	
	system("@cls||clear");
	printf("There are nine Pokemons in total.\n");
	printf("Please choose three out of the nine.\n\n");
	displayPokemonList(pokemons);
	
	while(userCounter != 3) {
		printf("Input: ");
		scanf("%d", &input);
		
		if(input < 1 || input > 9) {
			printf("Invalid input. Please try again.\n");
		}
		else {
			if(pokemons[input-1].taken == 0) {
				printf("You have chosen %s.\n", pokemons[input-1].name);
				pokemons[input-1].taken = 1;
				player->pokemon[userCounter] = pokemons[input-1];
				userCounter = userCounter + 1;	
			}
			else {
				printf("Pokemon is taken. Please choosen another.\n");
			}
		}
		
		fflush(stdin);
	}
	
	printf("You have chosen the following Pokemons...\n");
	for(i = 0; i < 3; i++) {
		printf("Pokemon: %s\n", player->pokemon[i].name);
	}
	
	printf("The CPU will pick its Pokemons.\n");
	
	while(cpuCounter != 3) {
		input = (rand() % 9) + 1;
		
		if(input < 1 || input > 9) {
			// Do nothing
		}
		else {
			if(pokemons[input-1].taken == 0) {
				pokemons[input-1].taken = 1;
				cpu->pokemon[cpuCounter] = pokemons[input-1];
				cpuCounter = cpuCounter + 1;
			}
		}
	}
	
	printf("The CPU has chosen the following Pokemons...\n");
	for(i = 0; i < 3; i++) {
		printf("Pokemon: %s\n", cpu->pokemon[i].name);
	}
	
	printf("The battle will commence. Please press Enter to proceed.\n");
	printf("Input: ");
	gets(dump);
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
		gets(user->name);
		printf("Hello, %s! What is the name of your opponent? \n", user->name);
		printf("Input: ");
		gets(cpu->name);
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

/*
	FUNCTION NAME: calculateDamage
	DESCRIPTION: The function calculates the damage inflicted by a Pokemon to another Pokemon.
	PARAMETERS:
		1. attacker       (Pokemon) is a struct variable containing the information of the attacking Pokemon.
		2. defender       (Pokemon) is a struct variable containing the information of the defending Pokemon.
		3. attackerOption (Integer) is a variable containing the choice of the attack.
	RETURN VALUE: An integer value containing how much damage is inflicted.
*/

int calculateDamage(Pokemon attacker, Pokemon defender, int attackerOption) {
	double effectiveness;
	int damage, attack, hit, chance, accuracy;
	int finalAttack;

	// Attack
	attack = attacker.ap;
	if(attacker.ap > attacker.attackStyle[attackerOption].pp) {
		attack = attacker.attackStyle[attackerOption].pp;
	}
	
	finalAttack = (rand() % 21) + attack;
	
	// Hit
	chance = rand() % 101;
	accuracy = attacker.attackStyle[attackerOption].accuracy;
	if(chance <= accuracy) {
		hit = 1;
	}
	else {
		hit = 0;
	}
	
	// Effectiveness
	effectiveness = 1.0;
	if(attacker.type == 1 && defender.type == 3)
		effectiveness = 1.5;
	else if(attacker.type == 2 && defender.type == 1)
		effectiveness = 1.5;
	else if(attacker.type == 3 && defender.type == 2)
		effectiveness = 1.5;
		
	if(effectiveness == 1.5 && hit == 1)
		printf("It was quite effective!\n\n");
	else if(hit == 0)
		printf("The attack missed!\n\n");
		
	damage = finalAttack * hit * effectiveness;
	
	return damage;
}

/*
	FUNCTION NAME: switchPokemon
	DESCRIPTION: The function allows a person or cpu to switch to another Pokemon.
	PARAMETERS:
		1. player (Player) is a struct variable that contains the information of the player.
		2. user   (Integer) is a variable to indicate if the player swapping is a user or a cpu.
	RETURN VALUE: An integer value that contains the index of the next Pokemon.
*/

int switchPokemon(Player player, int user) {
	int i, userChoice, cpuChoice, valid;
	
	printf("Which Pokemon will you pick?\n");
	for(i = 0; i < 3; i++) {
		printf("[%d] %s - ", i+1, player.pokemon[i].name);
		if(player.pokemon[i].currentHP > 0) {
			printf("Ready");
		}
		else {
			printf("Incapacitated");
		}
		printf("\n");
	}
	
	printf("\n");
	
	if(user) {
		do {
			printf("Input: ");
			scanf("%d", &userChoice);
			if(player.pokemon[userChoice-1].currentHP < 0) {
				printf("The chosen Pokemon is incapacitated. Pick another.\n");
				valid = 0;
			}
			else {
				valid = 1;
				return userChoice-1;
			}
		} while((userChoice != 1 && userChoice != 2 && userChoice != 3) || valid == 0);
	}
	else {
		valid = 0;
		while(valid == 0) {
			cpuChoice = rand() % 3;
			if(player.pokemon[cpuChoice].currentHP > 0) {
				valid = 1;
				return cpuChoice;
			}
		}
	}
}

/*
	FUNCTION NAME: startGame
	DESCRIPTION: The function allows the user to battle with the CPU.
	PARAMETERS:
		1. user (Player) is a struct variable that contains the information of the user and the three Pokemons the user chose.
		2. cpu  (Player) is a struct variable that contains the information of the cpu and the three Pokemons the cpu chose.
	RETURN VALUE: Integer to indicate if the user wins or not.
*/

int startGame(Player user, Player cpu) {
	int result = 1;
	int game = 1, userCurrentPokemon, cpuCurrentPokemon, userOption, attackOption, i, damage;
	int cpuOption, incapacitated;
	String userPokemon, cpuPokemon;
	
	system("@cls||clear");
	
	userCurrentPokemon = 0;
	cpuCurrentPokemon = 0;
	user.potions = 5;
	cpu.potions = 5;
	
	strcpy(userPokemon, user.pokemon[userCurrentPokemon].name);
	strcpy(cpuPokemon, cpu.pokemon[cpuCurrentPokemon].name);
	
	printf("-------------------------------------------------------------\n");
	printf("%s brings out %s!\n", user.name, userPokemon);
	printf("%s brings out %s!\n\n", cpu.name, cpuPokemon);
	
	while(game == 1) {
		printf("-------------------------------------------------------------\n");
		
		printf("%s - HP: %d\n", userPokemon, user.pokemon[userCurrentPokemon].currentHP);
		printf("%s - HP: %d\n\n", cpuPokemon, cpu.pokemon[cpuCurrentPokemon].currentHP);
		
		printf("What will you do?\n");
		printf("[1] Attack  [2] Potion  [3] Switch\n\n");
		
		do {
			printf("Input: ");
			scanf("%d", &userOption);
		} while(userOption != 1 && userOption != 2 && userOption != 3);
		
		fflush(stdin);
		
		if(userOption == 1) {
			printf("\n");
			printf("Which attack will you go for?\n");
			for(i = 0; i < 3; i++) {
				printf("[%d] %s  ", i+1, user.pokemon[userCurrentPokemon].attackStyle[i]);
			}
			printf("\n\n");
			
			do {
				printf("Input: ");
				scanf("%d", &attackOption);
			} while(attackOption != 1 && attackOption != 2 && attackOption != 3);
			
			fflush(stdin);
			
			damage = calculateDamage(user.pokemon[userCurrentPokemon], cpu.pokemon[cpuCurrentPokemon], attackOption-1);
			
			printf("%s has taken %d damage!\n", cpuPokemon, damage);
			
			cpu.pokemon[cpuCurrentPokemon].currentHP -= damage;
			
			// Check Pokemon statuses
			incapacitated = 0;
			for(i = 0; i < 3; i++) {
				if(cpu.pokemon[i].currentHP <= 0) {
					incapacitated += 1;
				}
			}
			
			if(incapacitated == 3) {
				break;
			}
			
			if(cpu.pokemon[cpuCurrentPokemon].currentHP <= 0) {
				cpuCurrentPokemon = switchPokemon(cpu, 0);
				strcpy(cpuPokemon, cpu.pokemon[cpuCurrentPokemon].name);
				printf("%s brings out %s!\n\n", cpu.name, cpuPokemon);
			}
		}
		else if(userOption == 2) {
			user.potions -= 1;
			user.pokemon[userCurrentPokemon].currentHP += 20;
			if(user.pokemon[userCurrentPokemon].currentHP >= user.pokemon[userCurrentPokemon].hp)
				user.pokemon[userCurrentPokemon].currentHP = user.pokemon[userCurrentPokemon].hp;
			printf("%s uses potion! %s has HP %d!\n", user.name, userPokemon, user.pokemon[userCurrentPokemon].currentHP);
			printf("%s has %d potions left.\n", user.name, user.potions);
		}
		else {
			userCurrentPokemon = switchPokemon(user, 1);
			strcpy(userPokemon, user.pokemon[userCurrentPokemon].name);
			printf("%s brings out %s!\n\n", user.name, userPokemon);
		}
		
		printf("-------------------------------------------------------------\n");
		printf("%s - HP: %d\n", userPokemon, user.pokemon[userCurrentPokemon].currentHP);
		printf("%s - HP: %d\n\n", cpuPokemon, cpu.pokemon[cpuCurrentPokemon].currentHP);
		
		cpuOption = (rand() % 100) + 1;
		
		if(cpuOption > 0 && cpuOption < 67) {
			attackOption = rand() % 3;
			damage = calculateDamage(cpu.pokemon[userCurrentPokemon], user.pokemon[cpuCurrentPokemon], attackOption);
			
			printf("%s has taken %d damage!\n", userPokemon, damage);
			
			user.pokemon[cpuCurrentPokemon].currentHP -= damage;
			
			// Check Pokemon statuses
			incapacitated = 0;
			for(i = 0; i < 3; i++) {
				if(user.pokemon[i].currentHP <= 0) {
					incapacitated += 1;
				}
			}
			
			if(incapacitated == 3) {
				result = 0;
				break;
			}
			
			if(user.pokemon[cpuCurrentPokemon].currentHP <= 0) {
				userCurrentPokemon = switchPokemon(user, 1);
				strcpy(userPokemon, user.pokemon[userCurrentPokemon].name);
				printf("%s brings out %s!\n\n", user.name, userPokemon);
			}
		}
		else if(cpuOption > 66 && cpuOption < 84) {
			cpu.potions -= 1;
			cpu.pokemon[cpuCurrentPokemon].currentHP += 20;
			if(cpu.pokemon[cpuCurrentPokemon].currentHP >= cpu.pokemon[cpuCurrentPokemon].hp)
				cpu.pokemon[cpuCurrentPokemon].currentHP = cpu.pokemon[cpuCurrentPokemon].hp;
			printf("%s uses potion! %s has HP %d!\n", cpu.name, cpuPokemon, cpu.pokemon[cpuCurrentPokemon].currentHP);
			printf("%s has %d potions left.\n", cpu.name, cpu.potions);
		}
		else if(cpuOption > 83) {
			cpuCurrentPokemon = switchPokemon(user, 0);
			strcpy(cpuPokemon, cpu.pokemon[cpuCurrentPokemon].name);
			printf("%s brings out %s!\n\n", cpu.name, cpuPokemon);
		}
		
		fflush(stdin);
	}
	
	return result;
}

int main() {
	int gameMode, winner;
	Player user, cpu;
	Pokemon pokemons[9];
	
	srand(time(NULL));
	
	printPokemonLogo();
	gameMode = printMainMenu();
	
	if(gameMode == 1) {
		setPlayerNames(&user, &cpu);
		initializePokemons(pokemons);
		chooseUserPokemon(&user, &cpu, pokemons);
		winner = startGame(user, cpu);
	}
	else {
		printEndingMessage();
		exit(1);
	}
	
	system("@cls||clear");
	if(winner) {
		printf("User wins!\n");
	}
	else {
		printf("Computer wins!\n");
	}
	
	printf("Thank you for playing.\n");
	
	return 0;
}
