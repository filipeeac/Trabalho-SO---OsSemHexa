CC = gcc
CFLAGS = -Iinclude -g -Wall

BIN = bin

build: $(BIN)/out.out

$(BIN)/out.out: $(BIN)/main.o $(BIN)/logger.o $(BIN)/findKeyboard.o
	$(CC) $(BIN)/main.o $(BIN)/logger.o $(BIN)/findKeyboard.o -o $(BIN)/out.out

$(BIN)/main.o: src/main.c include/logger.h | $(BIN)
	$(CC) $(CFLAGS) -c src/main.c -o $(BIN)/main.o

$(BIN)/logger.o: src/logger.c include/logger.h | $(BIN)
	$(CC) $(CFLAGS) -c src/logger.c -o $(BIN)/logger.o

$(BIN)/findKeyboard.o:
	$(CC) $(CFLAGS) -c src/findKeyboard.c -o $(BIN)/findKeyboard.o

$(BIN):
	mkdir -p $(BIN)

run:
	sudo ./bin/out.out

clean:
	rm -rf $(BIN)/*
