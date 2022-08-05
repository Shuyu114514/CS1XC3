/* TradingGame: A small trading game developed for the COMPSCI 1XC3 final exam in the summer of 2022. 
 * 
 * NOTE: structures.h contains a macro defining VERSION.  If your display can't render unicode characters, 
 * change VERSION to 1.
 * 
 */


#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include"structures.h"
#include"display.h"
#include"config.h"
#include"dispatches.h"


int main() {
	print_welcome();
	char response[50] = ""; 
	while (response[0] != 'A' && response[0] != 'B') {
		printf("\nPlease select game \"A\" or game \"B\" >> " );
		fgets(response,2,stdin);
		if (response[0] != 'A' && response[0] != 'B') {
			printf("Incorrect input, please try again!");
		}
	}
	
	GAME *game;
	
	if (response[0] == 'A') {
		printf("\nInitializing Game A, a small game with two cities...\n");
		setupGameA(&game);
	} else if (response[0] == 'B') {
		printf("\nInitializing Game B, a large game with four cities...\n");
		setupGameB(&game);		
	} else {
		printf("Fatal Error!\n");
		return -1;
	}

	//printf("%d", game->numCities);

	printf("\nPlease choose a company name >> ");
	fgets(game->companyName,39,stdin);	
	fgets(game->companyName,39,stdin); // doesn't work without this repetition for some reason...
	//remove newlines...
	int i = 0;
	while (i < 40) {
		if (game->companyName[i] == '\n') {
			game->companyName[i] = '\0';
		}
		i++;
	}
	printf("\n\n");

	if (VERSION == 0) {
		print_story_u(game);
	} else if (VERSION == 1) {
		print_story_a(game);
	}	
	
	// Main Game Loop
	
	while (true) {
		if (VERSION == 0) {
			print_main_u(game);
		} else if (VERSION == 1) {
			print_main_a(game);
		}
		
		scanf("%49s", response);
		printf("\n");
		
		//printf("Selected \"%s\"\n", response);
		
		if (strcmp(response,"quit") == 0) {
			break;
		}
		dispatch1(response, game);	
	}

	printf("Terminating Transport Tycoon Mini...\n");
	free_everything(&game);
	return 0;
} // end main
