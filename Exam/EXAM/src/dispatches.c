#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include"structures.h"
#include"display.h"

int getCityIndexByName (GAME* game, char* name) {
	int j = 0;
	while (j < game->numCities) {
		if (strcmp(game->cities[j].name, name) == 0) {
			break;
		}
		j++;
	}
	return j;
}

double distance(struct city *a, struct city *b){
	// QUESTION 1-3 GOES HERE
	double result = 0;
	result = pow(((b->lattitude - a->lattitude)*(b->lattitude - a->lattitude) + (b->longitude - a->longitude)*(b->longitude - a->longitude)),(1/2));
	return result; // delete this line
}

void tick(GAME* game) {
	// train update logic
	int j;
	int k;
	for (int i = 0; i < game->numTrains; i++ ) {
		game->trains[i].age ++;
		if (game->trains[i].direction) {
			game->trains[i].currentPosition += game->trains[i].speed / game->trains[i].totalDistance;
			if (game->trains[i].currentPosition >= 1.0) {
				game->trains[i].currentPosition = 1.0;
				game->trains[i].direction = false;
				printf(">> %s %d has arrived at %s <<\n", game->trains[i].model, i, game->trains[i].destination);
				j = getCityIndexByName(game, game->trains[i].destination);
				k = 0;
				while (k < game->cities[j].numDemands) {
					//printf("%s = %s?\n", game->trains[i].goodHeld, game->cities[j].demands[k].name);
					if (strcmp(game->cities[j].demands[k].name, game->trains[i].goodHeld) == 0) {
						//printf("Yes!\n");
						break;
					} else {
						//printf("No!\n");
					}
					k++;
				}			
				printf("%s pays %d for each %s.\n", game->cities[j].name, game->cities[j].demands[k].price, game->cities[j].demands[k].name);
				printf("Cargo sold for %d!\n", game->trains[i].numberHeld*game->cities[j].demands[k].price);
				game->money += game->trains[i].numberHeld*game->cities[j].demands[k].price;
				printf("Heading back to %s!\n", game->trains[i].origin);
			}  
		} else {
 			game->trains[i].currentPosition -= game->trains[i].speed / game->trains[i].totalDistance;
			if (game->trains[i].currentPosition <= 0.0) {
				game->trains[i].currentPosition = 0.0;
				game->trains[i].direction = true;
				printf(">> %s %d has arrived at %s <<\n", game->trains[i].model, i, game->trains[i].origin);
				j = getCityIndexByName(game, game->trains[i].destination);
				k = 0;
				while (k < game->cities[j].numSupplies) {
					if (strcmp(game->cities[j].supplies[k].name, game->trains[i].goodHeld) == 0) {
						break;
					} 
					k++;
				}
				if (game->cities[j].supplies[k].price >= 0) {
					printf("Available Stock of %s is %d.\n", game->trains[i].goodHeld, game->cities[j].supplies[k].stock);
					
					int purchaseable = (int)(game->money / game->cities[j].supplies[k].price);
					if (purchaseable > game->cities[j].supplies[k].stock) {
						purchaseable = game->cities[j].supplies[k].stock;
					}
					
					if (purchaseable >= game->trains[i].capacity) {
						printf("Purchased full load of %d for $%d.\n", game->trains[i].capacity, game->trains[i].capacity * game->cities[j].supplies[k].price);
						game->trains[i].numberHeld = game->trains[i].capacity;
						game->cities[j].supplies[k].stock -= game->trains[i].capacity;
						game->money -= game->trains[i].capacity * game->cities[j].supplies[k].price;
					} else {
						printf("Purchased %d for $%d.\n", purchaseable, purchaseable * game->cities[j].supplies[k].price);
						game->trains[i].numberHeld = purchaseable;
						game->cities[j].supplies[k].stock -= purchaseable;
						game->money -= purchaseable * game->cities[j].supplies[k].price;
					}
					printf("Setting off for %s!\n", game->trains[i].destination);
				} else {
					printf("Available Stock of %s is %d.\n", game->trains[i].goodHeld, game->cities[j].supplies[k].stock);	
					
					printf("Took a full load of %d off their hands and received $%d.\n", game->trains[i].capacity, -1 * game->trains[i].capacity * game->cities[j].supplies[k].price);
					game->trains[i].numberHeld = game->trains[i].capacity;
					game->cities[j].supplies[k].stock -= game->trains[i].capacity;
					game->money += -1 * game->trains[i].capacity * game->cities[j].supplies[k].price;
					printf("Setting off for %s!\n", game->trains[i].destination);
				}
			} //*/
		}
	} 
	// City stock update logic
	for (int i = 0; i < game->numCities; i++ ) {
		for (int j = 0; j < game->cities[i].numSupplies; j++) {
			game->cities[i].supplies[j].stock += game->cities[i].supplies[j].regenRate;
		}
	}

	printf("One day passes...\n");
} // end tick

void wait(GAME* game) {
	printf("Wait how many days? (limit 100)\n");
	printf(">> ");
	int choice;
	scanf("%d", &choice);
	printf("\n");
	for (int i = 0; i < choice; i++) {
		tick(game);
	}
}

void buyTrain(GAME* game) {
	// initialize new train

	game->trains = (TRAIN*)realloc(game->trains, (game->numTrains + 1)*sizeof(TRAIN));
	if (game->trains == NULL) {
		printf("Error! Out of Memory!");
		abort();
	}
	int this = game->numTrains;
	int origIndex;
	int destIndex;
	game->numTrains ++;
	fgets(game->trains[this].origin,19,stdin);
	
	// Get origin city
	bool success = false;
	while (!success) {
		printf("Select a city of origin\n");
		
		for (int i = 0; i < game->numCities; i ++) {
			printf("> %s \n", game->cities[i].name);
		}
		printf(">> ");

		fgets(game->trains[this].origin,19,stdin);
		//remove newlines...
		int i = 0;
		while (i < 40) {
			if (game->trains[this].origin[i] == '\n') {
				game->trains[this].origin[i] = '\0';
			}
			i++;
		}
		for (int j = 0; j < game->numCities; j ++) {
			if (strcmp(game->cities[j].name, game->trains[this].origin) == 0) {
				success = true;
				origIndex = j;
				break;
			}
		}
		if (!success) {
			printf("I'm sorry, the city you have selected does not appear in my list.\n\n");
		}
	}
	success = false;
	
	// Prompt for destination city
	while (!success) {
		printf("Select a destination\n");
		for (int j = 0; j < game->numCities; j ++) {
			if (strcmp(game->cities[j].name, game->trains[this].origin) != 0) {
				printf("> %s \n", game->cities[j].name);
			}
		}	
		printf(">> ");
		fgets(game->trains[this].destination,19,stdin);
		//remove newlines...
		int i = 0;
		while (i < 40) {
			if (game->trains[this].destination[i] == '\n') {
				game->trains[this].destination[i] = '\0';
			}
			i++;
		}	
		for (int j = 0; j < game->numCities; j ++) {
			if (strcmp(game->cities[j].name, game->trains[this].destination) == 0) {
				success = true;
				destIndex = j;
				break;
			}
		}
		if (!success) {
			printf("I'm sorry, the city you have selected does not appear in my list.\n\n");
		}
		
	}
	printf("Creating a new train route from %s to %s\n", game->trains[this].origin, game->trains[this].destination);
	printf("Distance: %f\n", distance(&(game->cities[origIndex]),&(game->cities[destIndex])));
	
	// Prompt for type of goods
	success = false;
	while (!success) {
		printf("What kind of goods would you like to transport?\n");
		
		for (int i = 0; i < game->cities[origIndex].numSupplies; i ++) {
			printf("> %s \n", game->cities[origIndex].supplies[i].name);
		}
		
		printf(">> ");

		fgets(game->trains[this].goodHeld,19,stdin);
		//remove newlines...
		int i = 0;
		while (i < 40) {
			if (game->trains[this].goodHeld[i] == '\n') {
				game->trains[this].goodHeld[i] = '\0';
			}
			i++;
		}
		for (int j = 0; j < game->cities[origIndex].numSupplies; j ++) {
			if (strcmp(game->cities[origIndex].supplies[j].name, game->trains[this].goodHeld) == 0) {
				success = true;
				break;
			}
		}
		if (!success) {
			printf("I'm sorry, the goods you have selected do not appear in my list.\n\n");
		}
	}
	
	// Check that destination city receives it
	success = false;
	for (int j = 0; j < game->cities[destIndex].numDemands; j ++) {
		if (strcmp(game->cities[destIndex].demands[j].name, game->trains[this].goodHeld) == 0) {
			success = true;
			break;
		}
	}
	if (!success) {
		printf("The destination city does not demand this good.\n\n");
		game->trains = (TRAIN*)realloc(game->trains, (game->numTrains - 1)*sizeof(TRAIN));
		game->numTrains --;
		return;
	}
	
	// Select type of train
	printf("The following trains are available for purchase:\n");
	if (VERSION == 0) {
		printf("Unicode!\n");
		print_train_options_u();
	} else if (VERSION == 1) {
		printf("Ascii!\n");
		print_train_options_a();
	}
	

	
	char response[50] = ""; 
	while (response[0] != 'A' && response[0] != 'B' && response[0] != 'C') {
		printf("Which would you like to purchase?\n");
		printf("> (A) LNER Peppercorn A1\n");
		printf("> (B) WD Austerity 2-8-0\n");
		printf("> (C) BR Britannia\n");
		printf("(A/B/C)? >> ");
		fgets(response,2,stdin);
		printf("\n");
		if (response[0] != 'A' && response[0] != 'B' && response[0] != 'C') {
			printf("Incorrect input, please try again!");
		}
	}
	
	int flatRate;
	int perKmRate;
	char whichTrain = response[0];
	switch (whichTrain) {
		case 'A' :
			flatRate = 450;
			perKmRate = 2;
			break;
		case 'B' :
			flatRate = 1650;
			perKmRate = 4;
			break;
		case 'C' :
			flatRate = 2475;
			perKmRate = 7;
			break;
	} 
	
	int cost = (int)(flatRate + perKmRate * distance(&(game->cities[origIndex]),&(game->cities[destIndex])));
	
	printf("This new route will cost $%d to build.\n", cost);
	printf("Your available funds are $%d\n", game->money);
	
	if (cost > game->money) {
		printf("You are too poor to build this railway.\n");
		printf("But take heart!  Many important wealthy people started\n");
		printf("out as penniless shmucks like you!\n");
		game->trains = (TRAIN*)realloc(game->trains, (game->numTrains - 1)*sizeof(TRAIN));
		game->numTrains --;
		return;
	} 
	
	while (response[0] != 'Y' && response[0] != 'N') {
		printf("Do you wish to proceed?\n");
		printf("(Y/N)? >> ");
		fgets(response,2,stdin);
		fgets(response,2,stdin);
		printf("\n");
		if (response[0] != 'Y' && response[0] != 'N') {
			printf("Incorrect input, please try again!\n");
		}
	}
	
	if (response[0] == 'N') {
		game->trains = (TRAIN*)realloc(game->trains, (game->numTrains - 1)*sizeof(TRAIN));
		game->numTrains --;
		return;
	}
	
	printf("So let it be written, so let it be done.\n\n");
	game->money -= cost;
	game->trains[this].age				= 0;
	game->trains[this].totalDistance	= distance(&(game->cities[origIndex]),&(game->cities[destIndex]));
	game->trains[this].currentPosition	= 0;
	game->trains[this].numberHeld		= 0;
	game->trains[this].direction		= false;
	switch (whichTrain) {
		case 'A' :
			game->trains[this].model 			= "LNER Peppercorn A1";
			game->trains[this].speed			= 15.5;
			game->trains[this].capacity			= 8;
			break;
		case 'B' :
			game->trains[this].model 			= "WD Austerity 2-8-0";
			game->trains[this].speed			= 32.9;
			game->trains[this].capacity			= 24;
			break;
		case 'C' :
			game->trains[this].model 			= "BR Britannia";
			game->trains[this].speed			= 28.1;
			game->trains[this].capacity			= 54;
			break;
	}

	tick(game);
} // end buyTrain

void killTrain(GAME* game) {
	printf("Which train would you like to decommission?\n");
	printf("Select train by route number.\n>> ");
	int choice;
	scanf("%d", &choice);
	printf("\n");
	if (choice >= game->numTrains) {
		printf("I can't decommission a train that doesn't exist!\n");
		return;
	}
	
	int flatRate;
	int perKmRate;
	if (strcmp(game->trains[choice].model, "LNER Peppercorn A1") == 0 ) {
		flatRate = 450;
		perKmRate = 2;
	} else if (strcmp(game->trains[choice].model, "WD Austerity 2-8-0") == 0 ) {
		flatRate = 1650;
		perKmRate = 4;	
	} else if (strcmp(game->trains[choice].model, "BR Britannia") == 0 ) {
		flatRate = 2475;
		perKmRate = 7;		
	}
	
	int salePrice = (int)((flatRate + perKmRate*game->trains[choice].totalDistance) / (1 + (game->trains[choice].age/7)));
	
	char response[10];
	printf("Selling this line will recoup $%d.\n", salePrice);
	while (response[0] != 'Y' && response[0] != 'N') {
		printf("Do you wish to proceed?\n");
		printf("(Y/N)? >> ");
		fgets(response,2,stdin);
		fgets(response,2,stdin);
		printf("\n");
		if (response[0] != 'Y' && response[0] != 'N') {
			printf("Incorrect input, please try again!\n");
		}
	}
	if (response[0] == 'N') {
		printf("Well stop bothering me then!\n");
		return;
	}

	// QUESTION 1-4 GOES HERE
	game->money+=salePrice;
	

	tick(game);
} // end killTrain

void dispatch1(char *option, GAME* game) {
	if (strcmp(option, "new") == 0) {
		buyTrain(game);
	} else if (strcmp(option, "cities") == 0) {
		if (VERSION == 0) {
			print_cities_u(game);
		} else if (VERSION == 1) {
			print_cities_a(game);
		}
	} else if (strcmp(option, "kill") == 0) {
		killTrain(game);
	} else if (strcmp(option, "wait") == 0) {
		wait(game);
	}
} // end dispatch1
