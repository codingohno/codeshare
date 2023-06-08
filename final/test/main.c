#include <stdio.h>
#include <stdlib.h>


typedef struct Complex{
    int real;
    int virt;
}complex;

int main(void){

    complex a={10,20};

    printf("%d %d",a.real,a.virt);


    return 0;
}
