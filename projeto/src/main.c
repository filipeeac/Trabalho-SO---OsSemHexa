#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/input.h>

#define TAM_MAX 50


int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Deu erro, lek\n");
        exit(EXIT_FAILURE);
    }
    
    int fin = open(argv[1], O_RDONLY);
    if(!(fin > -1)){
       perror("Deu merda, menor");
       exit(EXIT_FAILURE);
    }
    
    char buffer[TAM_MAX];
    struct input_event ie;

    long int count = 0;
    while(1){
        read(fin, &ie, sizeof(ie));
        if(ie.type != EV_KEY) continue;
        printf("Count=%ld\n", count++);
        printf("Tecla Type: %d\n", ie.type);
        printf("Tecla Code: %d\n", ie.code);
        printf("Tecla Value: %d\n\n", ie.value);
    }

    return 0;
}
