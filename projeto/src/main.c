#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <linux/input.h>

// #define TAM_MAX 50

typedef struct{
    char normal;
    char shift;
    bool alfabetico;
} keymap_entry;

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Deu erro, lek\n");
        exit(EXIT_FAILURE);
    }
    
    int fin = open(argv[1], O_RDONLY);
    if(fin < 0){
       perror("Deu merda, menor");
       exit(EXIT_FAILURE);
    }

    bool shift = false;
    bool caps = false;

    
    keymap_entry keymap[KEY_MAX+1] = { 
        [KEY_A] = {'a', 'A', true},
        [KEY_B] = {'b', 'B', true},
        [KEY_C] = {'c', 'C', true},
        [KEY_D] = {'d', 'D', true},
        [KEY_E] = {'e', 'E', true},
        [KEY_F] = {'f', 'F', true},
        [KEY_G] = {'g', 'G', true},
        [KEY_H] = {'h', 'H', true},
        [KEY_I] = {'i', 'I', true},
        [KEY_J] = {'j', 'J', true},
        [KEY_K] = {'k', 'K', true},
        [KEY_L] = {'l', 'L', true},
        [KEY_M] = {'m', 'M', true},
        [KEY_N] = {'n', 'N', true},
        [KEY_O] = {'o', 'O', true},
        [KEY_P] = {'p', 'P', true},
        [KEY_Q] = {'q', 'Q', true},
        [KEY_R] = {'r', 'R', true},
        [KEY_S] = {'s', 'S', true},
        [KEY_T] = {'t', 'T', true},
        [KEY_U] = {'u', 'U', true},
        [KEY_V] = {'v', 'V', true},
        [KEY_W] = {'w', 'W', true},
        [KEY_X] = {'x', 'X', true},
        [KEY_Y] = {'y', 'Y', true},
        [KEY_Z] = {'z', 'Z', true},

        [KEY_1] = {'1', '!', false},
        [KEY_2] = {'2', '@', false},
        [KEY_3] = {'3', '#', false},
        [KEY_4] = {'4', '$', false},
        [KEY_5] = {'5', '%', false},
        [KEY_6] = {'6', '\0', false},
        [KEY_7] = {'7', '&', false},
        [KEY_8] = {'8', '*', false},
        [KEY_9] = {'9', '(', false},
        [KEY_0] = {'0', ')', false}
    };
    
    // char buffer[TAM_MAX];
    struct input_event ie;
    bool upper = false;

    // long int count = 0;
    while(read(fin, &ie, sizeof(ie)) == sizeof(ie)){
        if(ie.type != EV_KEY) continue;
        if(ie.code == KEY_LEFTSHIFT || ie.code == KEY_RIGHTSHIFT){
            if(ie.value == 1) shift = true;
            else if (ie.value == 0) shift = false;
            continue;
        }
        if(ie.code == KEY_CAPSLOCK){
            if(ie.value == 1) caps = !(caps);
            continue;
        }

        if(ie.value != 1) continue;

        keymap_entry entry = keymap[ie.code];
        
        if(entry.alfabetico) upper = shift ^ caps;
        else upper = shift;

        if(entry.normal == '\0') continue;
        putchar(upper ? entry.shift : entry.normal);
        fflush(stdout);
    }

    return 0;
}
