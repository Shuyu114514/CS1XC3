CC=gcc
CFLAGS=-Wall
SRC_DIR=src
BUILD_DIR=build

main: ./$(SRC_DIR)/main.c documentation/docs
	./scripts/Build_Dir.sh $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o ./$(BUILD_DIR)/$@ $<

course.o: ./$(SRC_DIR)/course.c
	./scripts/Build_Dir.sh $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o ./$(BUILD_DIR)/$@ $^

student.o: ./$(SRC_DIR)/student.c
	./scripts/Build_Dir.sh $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o ./$(BUILD_DIR)/$@ $^

documentation:
	./scripts/Build_Dir2.sh

docs: Doxyfile
	doxygen Doxyfile

Doxyfile:
	doxygen -g

clean:
	rm -rf $(BUILD_DIR)