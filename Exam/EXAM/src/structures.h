#include<stdbool.h>
// Version can be 0 for unicode or 1 for ascii
#define VERSION 1

struct supplying {
  char *name;    // name of the good supplied
  int stock;     // number of goods in stock
  int regenRate; // number of goods created per day
  int price;  // Price of buying one good
};

typedef struct supplying SUPPLY;

struct demanding {
  char *name;     // name of good under demand
  int price;  // Price the good is sold at
};

typedef struct demanding DEMAND;

// QUESTION 1-1 GOES HERE
struct city {
  char *name;
  struct SUPPLY *supplies;
  int numSupplies;
  struct demand *demands;
  int numDemands;
  double lattitude;
  double longitude;
};

typedef struct city CITY;

struct train {
	char *model;        // Name of type of train
	double speed;       // Distance travelled per day
	int capacity;       // Number of goods train can hold
	int age;			// Used to calculate sell price
	char goodHeld[20];  // Name of the particular good held
	int numberHeld;     // Number of goods currently held
	char origin[20];    // Point of origin
	char destination[20];   // Object of travel
	double totalDistance;	// Distance between origin and destination.
	double currentPosition; // Amount of route travelled, a number between 0 and 1.
	bool direction; // true for forward, false for backward
} ;

typedef struct train TRAIN;

struct game {
	char companyName[50];
	CITY *cities;
	int numCities; 
	TRAIN *trains;
	int numTrains;
	int money;
} ;

typedef struct game GAME;
