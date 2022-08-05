gcc -pg ./src/TradingGame.c -o ./src/TradingGame
./src/TradingGame.c
#gprof > test_1.txt

gcc -fprofile-arcs -ftest-coverage -o ./src/TradingGame.c ./src/TradingGame
./src/TradingGame.c
gcov ./src/TradingGame.c