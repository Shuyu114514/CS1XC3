#include<stdlib.h>
#include<stdio.h>
#include"structures.h"

void setupGameA (GAME **gameA) {
	*gameA = (GAME*)malloc(sizeof(GAME));
	if (gameA == NULL) {
		printf("Error! Out of Memory!");
		abort();
	}
	(*gameA)->money  = 10000;
	(*gameA)->numTrains = 0;
	(*gameA)->trains = NULL;
	(*gameA)->cities = (CITY*)malloc(2*sizeof(CITY));
	if ((*gameA)->cities == NULL) {
		printf("Error! Out of Memory!");
		abort();
	} 
	(*gameA)->cities[0].name      = "New Pork City";
	(*gameA)->cities[0].lattitude = 345.24;
	(*gameA)->cities[0].longitude = 129.4;
	(*gameA)->cities[0].numSupplies = 1;
	(*gameA)->cities[0].supplies  = (SUPPLY*)malloc(1*sizeof(SUPPLY));
	if ((*gameA)->cities[0].supplies == NULL) {
		printf("Error! Out of Memory!");
		abort();
	} 
	(*gameA)->cities[0].numDemands = 1;
	(*gameA)->cities[0].demands   = (DEMAND*)malloc(1*sizeof(DEMAND));
	if ((*gameA)->cities[0].demands == NULL) {
		printf("Error! Out of Memory!");
		abort();
	} 
		(*gameA)->cities[0].supplies[0].name      = "Happy Boxes";
		(*gameA)->cities[0].supplies[0].stock     = 100;
		(*gameA)->cities[0].supplies[0].regenRate = 8;
		(*gameA)->cities[0].supplies[0].price     = 100; 

		(*gameA)->cities[0].demands[0].name       = "Claymen";
		(*gameA)->cities[0].demands[0].price      = 250;

	(*gameA)->cities[1].name      = "Tazmily Village";
	(*gameA)->cities[1].lattitude = 198.07;
	(*gameA)->cities[1].longitude = 734.02;
	(*gameA)->cities[1].numSupplies = 1;	
	(*gameA)->cities[1].supplies  = (SUPPLY*)malloc(1*sizeof(SUPPLY));
	if ((*gameA)->cities[1].supplies == NULL) {
		printf("Error! Out of Memory!");
		abort();
	} 	
	(*gameA)->cities[1].numDemands = 1;
	(*gameA)->cities[1].demands   = (DEMAND*)malloc(1*sizeof(DEMAND));
	if ((*gameA)->cities[0].demands == NULL) {
		printf("Error! Out of Memory!");
		abort();
	} 
		(*gameA)->cities[1].supplies[0].name      = "Claymen";
		(*gameA)->cities[1].supplies[0].stock     = 8;
		(*gameA)->cities[1].supplies[0].regenRate = 4;
		(*gameA)->cities[1].supplies[0].price     = 135; 

		(*gameA)->cities[1].demands[0].name       = "Happy Boxes";
		(*gameA)->cities[1].demands[0].price      = 120;
	(*gameA)->numCities = 2;
}


GAME* setupGameB (GAME **gameB) {
	*gameB = (GAME*)malloc(sizeof(GAME));
	if (gameB == NULL) {
		printf("Error! Out of Memory!");
		abort();
	} 
	(*gameB)->money  = 10000;
	(*gameB)->numTrains = 0;
	(*gameB)->trains = NULL;
	(*gameB)->numCities = 4;
	(*gameB)->cities = (CITY*)malloc((*gameB)->numCities*sizeof(CITY));
	if ((*gameB)->cities == NULL) {
		printf("Error! Out of Memory!");
		abort();
	} 
	(*gameB)->cities[0].name      = "Onett";
	(*gameB)->cities[0].lattitude = 452.0;
	(*gameB)->cities[0].longitude = 113.0;
	(*gameB)->cities[0].numSupplies = 2;
	(*gameB)->cities[0].supplies  = (SUPPLY*)malloc((*gameB)->cities[0].numSupplies*sizeof(SUPPLY));
	if ((*gameB)->cities[0].supplies == NULL) {
		printf("Error! Out of Memory!");
		abort();
	} 
	(*gameB)->cities[0].numDemands = 4;
	(*gameB)->cities[0].demands   = (DEMAND*)malloc((*gameB)->cities[0].numDemands*sizeof(DEMAND));
	if ((*gameB)->cities[0].demands == NULL) {
		printf("Error! Out of Memory!");
		abort();
	}
		(*gameB)->cities[0].supplies[0].name      = "Traffic Cop";
		(*gameB)->cities[0].supplies[0].stock     = 5;
		(*gameB)->cities[0].supplies[0].regenRate = 1;
		(*gameB)->cities[0].supplies[0].price     = 95; 
		(*gameB)->cities[0].supplies[1].name      = "ManiManiStatue";
		(*gameB)->cities[0].supplies[1].stock     = 1;
		(*gameB)->cities[0].supplies[1].regenRate = 0;
		(*gameB)->cities[0].supplies[1].price     = 250000; 

		(*gameB)->cities[0].demands[0].name       = "Insane Cultist";
		(*gameB)->cities[0].demands[0].price      = 85;
		(*gameB)->cities[0].demands[1].name       = "Saturn Coffee";
		(*gameB)->cities[0].demands[1].price      = 30;
		(*gameB)->cities[0].demands[2].name       = "Mach Pizza";
		(*gameB)->cities[0].demands[2].price      = 36;
		(*gameB)->cities[0].demands[3].name       = "LifenoodlesCup";
		(*gameB)->cities[0].demands[3].price      = 945;		

	(*gameB)->cities[1].name      = "Twoson";
	(*gameB)->cities[1].lattitude = 167.3;
	(*gameB)->cities[1].longitude = 94.2;
	(*gameB)->cities[1].numSupplies = 2;
	(*gameB)->cities[1].supplies  = (SUPPLY*)malloc((*gameB)->cities[1].numSupplies*sizeof(SUPPLY));
	if ((*gameB)->cities[1].supplies == NULL) {
		printf("Error! Out of Memory!");
		abort();
	}
	(*gameB)->cities[1].numDemands = 4;
	(*gameB)->cities[1].demands   = (DEMAND*)malloc((*gameB)->cities[1].numDemands*sizeof(DEMAND));
	if ((*gameB)->cities[1].demands == NULL) {
		printf("Error! Out of Memory!");
		abort();
	}
		(*gameB)->cities[1].supplies[0].name      = "Runaway Five";
		(*gameB)->cities[1].supplies[0].stock     = 1;
		(*gameB)->cities[1].supplies[0].regenRate = 0;
		(*gameB)->cities[1].supplies[0].price     = 10000;
		(*gameB)->cities[1].supplies[1].name      = "Insane Cultist";
		(*gameB)->cities[1].supplies[1].stock     = 100;
		(*gameB)->cities[1].supplies[1].regenRate = 10;
		(*gameB)->cities[1].supplies[1].price     = 45;  

		(*gameB)->cities[1].demands[0].name       = "Zombie";
		(*gameB)->cities[1].demands[0].price      = 10;
		(*gameB)->cities[1].demands[1].name       = "Saturn Coffee";
		(*gameB)->cities[1].demands[1].price      = 25;
		(*gameB)->cities[1].demands[2].name       = "Mach Pizza";
		(*gameB)->cities[1].demands[2].price      = 32;
		(*gameB)->cities[1].demands[3].name       = "LifenoodlesCup";
		(*gameB)->cities[1].demands[3].price      = 1055;		

	(*gameB)->cities[2].name      = "Threed";
	(*gameB)->cities[2].lattitude = 98.14;
	(*gameB)->cities[2].longitude = 434.02;
	(*gameB)->cities[2].numSupplies = 3;	
	(*gameB)->cities[2].supplies  = (SUPPLY*)malloc((*gameB)->cities[2].numSupplies*sizeof(SUPPLY));
	if ((*gameB)->cities[2].supplies == NULL) {
		printf("Error! Out of Memory!");
		abort();
	}	
	(*gameB)->cities[2].numDemands = 4;
	(*gameB)->cities[2].demands   = (DEMAND*)malloc((*gameB)->cities[2].numDemands*sizeof(DEMAND));
	if ((*gameB)->cities[2].demands == NULL) {
		printf("Error! Out of Memory!");
		abort();
	}
		(*gameB)->cities[2].supplies[0].name      = "Zombie";
		(*gameB)->cities[2].supplies[0].stock     = 240;
		(*gameB)->cities[2].supplies[0].regenRate = 30;
		(*gameB)->cities[2].supplies[0].price     = -20; 
		(*gameB)->cities[2].supplies[1].name      = "Fly Honey";
		(*gameB)->cities[2].supplies[1].stock     = 75;
		(*gameB)->cities[2].supplies[1].regenRate = 10;
		(*gameB)->cities[2].supplies[1].price     = 240;
		(*gameB)->cities[2].supplies[2].name      = "Saturn Coffee";
		(*gameB)->cities[2].supplies[2].stock     = 350;
		(*gameB)->cities[2].supplies[2].regenRate = 20;
		(*gameB)->cities[2].supplies[2].price     = 20;

		(*gameB)->cities[2].demands[0].name       = "Traffic Cop";
		(*gameB)->cities[2].demands[0].price      = 175;
		(*gameB)->cities[2].demands[1].name       = "Insane Cultist";
		(*gameB)->cities[2].demands[1].price      = 105;
		(*gameB)->cities[2].demands[2].name       = "Mach Pizza";
		(*gameB)->cities[2].demands[2].price      = 36;
		(*gameB)->cities[2].demands[3].name       = "LifenoodlesCup";
		(*gameB)->cities[2].demands[3].price      = 945;
		
		
	
	(*gameB)->cities[3].name      = "Fourside";	
	(*gameB)->cities[3].lattitude = 204.8;
	(*gameB)->cities[3].longitude = 812.4;
	(*gameB)->cities[3].numSupplies = 2;
	(*gameB)->cities[3].supplies  = (SUPPLY*)malloc((*gameB)->cities[3].numSupplies*sizeof(SUPPLY));
	if ((*gameB)->cities[3].supplies == NULL) {
		printf("Error! Out of Memory!");
		abort();
	}
	(*gameB)->cities[3].numDemands = 5;
	(*gameB)->cities[3].demands   = (DEMAND*)malloc((*gameB)->cities[3].numDemands*sizeof(DEMAND));
	if ((*gameB)->cities[3].supplies == NULL) {
		printf("Error! Out of Memory!");
		abort();
	}
		(*gameB)->cities[3].supplies[0].name      = "Mach Pizza";
		(*gameB)->cities[3].supplies[0].stock     = 1000;
		(*gameB)->cities[3].supplies[0].regenRate = 12;
		(*gameB)->cities[3].supplies[0].price     = 14; 
		(*gameB)->cities[3].supplies[1].name      = "LifenoodlesCup";
		(*gameB)->cities[3].supplies[1].stock     = 50;
		(*gameB)->cities[3].supplies[1].regenRate = 2;
		(*gameB)->cities[3].supplies[1].price     = 625; 


		(*gameB)->cities[3].demands[0].name       = "Runaway Five";
		(*gameB)->cities[3].demands[0].price      = 50000;
		(*gameB)->cities[3].demands[1].name       = "ManiManiStatue";
		(*gameB)->cities[3].demands[1].price      = 999999;		
		(*gameB)->cities[3].demands[2].name       = "Traffic Cop";
		(*gameB)->cities[3].demands[2].price      = 250;
		(*gameB)->cities[3].demands[3].name       = "Saturn Coffee";
		(*gameB)->cities[3].demands[3].price      = 50;
		(*gameB)->cities[3].demands[4].name       = "Zombie";
		(*gameB)->cities[3].demands[4].price      = 5;
}

void free_everything(GAME **game) {
	for (int i = 0; i < (*game)->numCities; i++) {
		free((*game)->cities[i].supplies);
		free((*game)->cities[i].demands);
	} 
	free((*game)->trains);
	free((*game)); 
}
