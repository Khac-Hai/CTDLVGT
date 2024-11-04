#include<stdio.h>
#include<stdbool.h>

#define MAX 10
int list[MAX] = {1,8,4,6,0,3,5,2,7,9};

void display(){
    int i;
    printf("[");

    for(i=0; i < MAX; i++){
        printf("[");
    }

    printf("]\n");
}

void bubbleSort(){
    int temp;
    int i,j;

    bool swapped = false;

    for(i=0; i < MAX - 1; i++){
        swapped = false;

    for(j=0; j < MAX - 1 -i; j++){
        printf(" so sanh cach ptu: [%d,%d]", list[j], list[j+1]);

        if(list[j] > list[j+1]){
            temp = list[j];
            list[j] = list[j+1];
            list[j+1] = temp;

            swapped = true;
            printf ("trao doi [%d,%d]\n", list[j], list[j+1]);
        }
        else{
            printf("khong can trao doi\n");
        }
    }
    if(!swapped){
        break;
    }

    printf("vong lap thu %d#: ", (i+1));
    display();
    }
}

int main(){
    printf("mang du lieu dau vao: ");
    display();
    printf("\n");

    bubbleSort();
    printf("\n mang sau khi da sap xep: ");
    display();
}