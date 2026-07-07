#include <stdio.h>
#include <stdlib.h>

int main() {
    int p;

    while(1){
        p+=3;
        if(p >= 10000000){
            p-=1090;
        }    
    }
    
    return 0;
}