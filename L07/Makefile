CC=gcc
CFLAGS=-Wall
SRC_DIR=src
BUILD_DIR=build

library.o : ./$(SRC_DIR)/library.c
	./Build_Dir.sh $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o ./$(BUILD_DIR)/library.o $<

max: ./$(SRC_DIR)/max.c ./$(BUILD_DIR)/library.o
	./Build_Dir.sh
	$(CC) $(CFLAGS) -o ./$(BUILD_DIR)/$@ $^

square: ./$(SRC_DIR)/square.c ./$(BUILD_DIR)/library.o
	./Build_Dir.sh
	$(CC) $(CFLAGS) -o ./$(BUILD_DIR)/$@ $^

multiply: ./$(SRC_DIR)/multiply.c ./$(BUILD_DIR)/library.o
	./Build_Dir.sh
	$(CC) $(CFLAGS) -o ./$(BUILD_DIR)/$@ $^

targets = max multiply square
all : $(targets)
clean :
	rm -r -f $(BUILD_DIR)
	rm -r -f test

test : all
	./test.sh
	./$(BUILD_DIR)/square inches < ./test_data/square_input.txt > ./test/square_output.txt
	diff -bur ./test/square_output.txt ./test_data/square_expected.txt
	./$(BUILD_DIR)/max 4 3 2 1 5 7 8 10 6 > ./test/max_output.txt
	diff -bur ./test/max_output.txt ./test_data/max_expected.txt
	./$(BUILD_DIR)/multiply 2 < ./test_data/multiply_input.txt > ./test/multiply_output.txt
	diff -bur ./test/multiply_output.txt ./test_data/multiply_expected.txt
	rm -r -f test