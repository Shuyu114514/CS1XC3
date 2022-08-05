#include<stdio.h>
#include<stdbool.h>
#include"structures.h"


void print_welcome() {
	printf(">><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<\n\n");
	printf("         Welcome to Transport Tycoon Mini!\n\n");
	printf(">><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<\n\n");
}

// Ascii Version
void print_story_a(GAME *game) {
	printf("------------------------------------------------------------\n");
	printf("Since childhood, it has always been your dream to own a mod-\n");
	printf("erately successful logistics company.   Four years ago, your\n");
	printf("great aunt Prudence died, leaving you a tidy sum of $10,000.\n");
	printf("Owing  to the painfully protracted settlement of her estate,\n");
	printf("you only received your inheritance last week.   Immediately,\n");
	printf("you founded the %s\n", game->companyName);
	printf("------------------------------------------------------------\n");
}

// Unicode Version
void print_story_u(GAME *game) {
	printf("┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
	printf("│Since childhood, it has always been your dream to own a mod-│\n");
	printf("│erately successful logistics company.   Four years ago, your│\n");
	printf("│great aunt Prudence died, leaving you a tidy sum of $10,000.│\n");
	printf("│Owing  to the painfully protracted settlement of her estate,│\n");
	printf("│you only received your inheritance last week.   Immediately,│\n");
	printf("│you found the %-39s       │\n", game->companyName);
	printf("┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙\n");
}

// ASCII Version
void print_main_a(GAME *game) {
	printf("+-----------------------------------------+--------------+\n");
	printf("| %39s | $ %10d |\n", game->companyName, game->money);
	printf("+--------+--------------------------------+--------------+\n");
	printf("| Trains |                                               |\n");
	printf("+--------+                                               |\n");			
	
	int i = 0;
	while (i < game->numTrains) {
		printf("| %d : %-20s                               |\n", i, game->trains[i].goodHeld);

		bool flag = false;
		float divisions = 52.0;
		printf("|  ");
		for (float q = 0; q < 1; q += 1.0/divisions) {
			if (q + 1.0/divisions < game->trains[i].currentPosition) {
				printf(" ");
			} else {
				if (!flag) {
					printf("O");
					flag = true;
				} else {
					printf(" ");
				}
			}
		}
		printf("  |\n");
		printf("|  X==================================================X  |\n");
		printf("| %-20s              %20s |\n", game->trains[i].origin, game->trains[i].destination);
		if (i != game->numTrains-1) {
			printf("|   --------------------------------------------------   |\n");
		}
		
		i ++;
	}
	printf("+--------------------------------------------------------+\n\n");
	printf("Options\n");
	printf("> (cities) Display City Information\n");
	printf("> (new) Buy new train\n");
	printf("> (kill) Decommission train\n");
	printf("> (wait) Wait one day\n"); 
	printf("> (quit) Exit the game\n");
	printf("What would you like to do?\n >> ");	

} // end print_main_a



// Unicode Version 
void print_main_u(GAME *game) {
	printf("┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┯━━━━━━━━━━━━━━┑\n");
	printf("│ %39s │ $ %10d │\n", game->companyName, game->money);
	printf("┝━━━━━━━━┯━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┷━━━━━━━━━━━━━━┥\n");
	printf("│ Trains │                                               │\n");
	printf("┝━━━━━━━━┙                                               │\n");			
	
	int i = 0;
	while (i < game->numTrains) {
		printf("│ %d : %-20s                               │\n", i, game->trains[i].goodHeld);

		bool flag = false;
		float divisions = 52.0;
		printf("│  ");
		for (float q = 0; q < 1; q += 1.0/divisions) {
			if (q + 1.0/divisions < game->trains[i].currentPosition) {
				printf(" ");
			} else {
				if (!flag) {
					printf("⛟");
					flag = true;
				} else {
					printf(" ");
				}
			}
		}
		printf("  │\n");
		printf("│  ╳╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╳  │\n");
		printf("│ %-20s              %20s │\n", game->trains[i].origin, game->trains[i].destination);
		if (i != game->numTrains-1) {
			printf("│   ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━   │\n");
		}
		
		i ++;
	}
	printf("┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙\n\n");
	printf("Options\n");
	printf("> (cities) Display City Information\n");
	printf("> (new) Buy new train\n");
	printf("> (kill) Decommission train\n");
	printf("> (wait) Wait one day\n"); 
	printf("> (quit) Exit the game\n");
	printf("What would you like to do?\n >> ");	
} // end print_main_u

void print_cities_a(GAME *game) {
	printf("+--------+-----------------------------------------------+\n");
	printf("| Cities |                                               |\n");
	printf("+--------+                                               |\n");	
	
	for (int i = 0; i < game->numCities; i ++) {
		printf("|+=====================+                                 |\n");
		printf("|| %d : %-15s |                                 |\n", i, game->cities[i].name);
		printf("|+--------------------------+--------------------------+ |\n");
		printf("|| Supplies (%d)             | Demands (%d)              | |\n", game->cities[i].numSupplies, game->cities[i].numDemands);
		printf("|+--------------------------+--------------------------+ |\n");
	
	
	
		for (int j = 0; j < game->cities[i].numSupplies || j < game->cities[i].numDemands; j++) {	
			if (j < game->cities[i].numSupplies ) {
				printf("||> %-15s($%6d)|", game->cities[i].supplies[j].name, game->cities[i].supplies[j].price );
			} else {
				printf("||                          |");
			}
			if (j < game->cities[i].numDemands ) {
				printf("> %-15s($%6d)| |\n", game->cities[i].demands[j].name, game->cities[i].demands[j].price );	
			} else {
		    	printf("                           | |\n");	
			}
			if (j < game->cities[i].numSupplies ) {
				printf("||   %-10d     in stock|                          | |\n", game->cities[i].supplies[j].stock);	
			} else {
				printf("||                          |                          | |\n");	
			}
		}
		printf("|+--------------------------+--------------------------+ |\n");
		printf("|| Location : (%7.2f,%7.2f)                        | |\n",game->cities[i].lattitude, game->cities[i].longitude);		
		printf("|+-----------------------------------------------------+ |\n");
	}
	printf("+--------------------------------------------------------+\n\n");
} // end print_cities_a

void print_cities_u(GAME *game) {
	printf("┍━━━━━━━━┯━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
	printf("│ Cities │                                               │\n");
	printf("┝━━━━━━━━┙                                               │\n");	
	
	for (int i = 0; i < game->numCities; i ++) {
		printf("│╒═════════════════════╕                                 │\n");
		printf("││ %d : %-15s │                                 │\n", i, game->cities[i].name);
		printf("│┝━━━━━━━━━━━━━━━━━━━━━┷━━━━┯━━━━━━━━━━━━━━━━━━━━━━━━━━┑ │\n");
		printf("││ Supplies (%d)             │ Demands (%d)              │ │\n", game->cities[i].numSupplies, game->cities[i].numDemands);
		printf("│┝━━━━━━━━━━━━━━━━━━━━━━━━━━┿━━━━━━━━━━━━━━━━━━━━━━━━━━┥ │\n");
	
	
	
		for (int j = 0; j < game->cities[i].numSupplies || j < game->cities[i].numDemands; j++) {	
			if (j < game->cities[i].numSupplies ) {
				printf("││> %-15s($%6d)│", game->cities[i].supplies[j].name, game->cities[i].supplies[j].price );
			} else {
				printf("││                          │");
			}
			if (j < game->cities[i].numDemands ) {
				printf("> %-15s($%6d)│ │\n", game->cities[i].demands[j].name, game->cities[i].demands[j].price );	
			} else {
		    	printf("                           │ │\n");	
			}
			if (j < game->cities[i].numSupplies ) {
				printf("││   %-10d     in stock│                          │ │\n", game->cities[i].supplies[j].stock);	
			} else {
				printf("││                          │                          │ │\n");	
			}
		}
		printf("│┝━━━━━━━━━━━━━━━━━━━━━━━━━━┷━━━━━━━━━━━━━━━━━━━━━━━━━━┥ │\n");
		printf("││ Location : (%7.2f,%7.2f)                        │ │\n",game->cities[i].lattitude, game->cities[i].longitude);		
		printf("│┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙ │\n");
	}
	printf("┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙\n\n");
} // end print_cities_u

// Ascii Version
void print_train_options_a() {
	// QUESTION 1-2 GOES HERE (Ascii Version)
    char inputfile[] = "../dat/traininfo_a.txt";
	FILE *fp = fopen(inputfile, "r");
	char temp_line[200];
	while(fscanf(fp, "%[^\n] ", temp_line) != EOF){
		printf("%s\n", temp_line);
	}
	
	fclose(fp);
	
}

// Unicode Version
void print_train_options_u() {
	// QUESTION 1-2 GOES HERE (Unicode Version)
}
