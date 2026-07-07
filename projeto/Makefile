CC = gcc
CFLAGS = -Iinclude -g -Wall

BIN = bin

build: $(BIN)/out.out

$(BIN)/out.out: $(BIN)/main.o $(BIN)/logger.o
	$(CC) $(BIN)/main.o $(BIN)/logger.o -o $(BIN)/out.out

$(BIN)/main.o: src/main.c include/logger.h | $(BIN)
	$(CC) $(CFLAGS) -c src/main.c -o $(BIN)/main.o

$(BIN)/logger.o: src/logger.c include/logger.h | $(BIN)
	$(CC) $(CFLAGS) -c src/logger.c -o $(BIN)/logger.o

$(BIN):
	mkdir -p $(BIN)

clean:
	rm -rf $(BIN)/*
