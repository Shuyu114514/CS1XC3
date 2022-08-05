# QUESTION 2-1-b GOES HERE
FLAGS=-Wall

TradingGame : src/TradingGame.c src/config.h src/dispatches.h src/display.h src/structures.h tmp/display.o tmp/config.o tmp/dispatches.o 
	gcc $(FLAGS) -o TradingGame src/TradingGame.c tmp/display.o tmp/config.o tmp/dispatches.o -lm
	
tmp/display.o : src/display.c
	gcc -c $(FLAGS) -o tmp/display.o src/display.c 

# QUESTION 2-1-a GOES HERE
config.o: ./src/config.c
	gcc -c $(FLAGS) -o ./tmp/$@ $<
dispatches.o: ./src/dispatches.c
	gcc -c $(FLAGS) -o ./tmp/$@ $<

# QUESTION 2-1-c GOES HERE
targets = A B C
	
# QUESTION 2-1-d GOES HERE
clean: 
	rm -f ./tmp/*
