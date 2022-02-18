#include <stdio.h>
#include <time.h>

typedef struct Knot Knot;

struct Knot{
    int data;
    Knot *next;
}*last_insert = NULL;

int menu(){
    int op;
    printf("Choose: \n1 - Stack. \n2 - Unstack. \n3 - Show. \n0 - Finish. \nOption: ");
    scanf("%d", &op);
    return op;
}

void push(int num){
    Knot *new;
    new = (Knot*) malloc(sizeof(Knot));

    new->data = num;

    new->next = last_insert;
    last_insert = new;
    printf("\nNUMBER SUCCESSFULLY ENTERED.\n\n");
}

void pop(){
    if(check_list()){
        Knot *aux = last_insert;
        last_insert = aux->next;
        free(aux);
        aux = NULL;
        printf("\nNUMBER SUCCESSFULLY DISPILATED.\n\n");
    }
}

void show(){
    if(check_list()){
        Knot *aux = last_insert;
        printf("\n+----------------------------------------------------------------------+\n| Stack:");
        while (aux != NULL){
            printf(" %d ", aux->data);
            aux = aux->next;
        }
        printf("\n+----------------------------------------------------------------------+\n\n");
    }
}

int check_list(){
    if(last_insert)
        return 1;
    else{
        printf("\nEMPTY LIST.\nInsert at least one element for this option.\n\n");
        return 0;
    }
}

int main(){
    system("cls");
    int op, num;
    do{
        op=menu();
        switch (op){
        case 1: // STACK
            printf("\nEnter a number to be inserted at the beginning of the list: ");
            scanf("%d", &num);
            push(num);
            break;

        case 2: // UNSTACK
            pop();
            break;

        case 3: // PRINTS THE LIST
            show();
            break;

        case 0: // EXIT THE SYSTEM
            printf("\n+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
            printf("|         EXITING THE SYSTEM          |\n");
            printf("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\n");
            sleep(2);
            break;

        default:
            printf("\n+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
            printf("|           INVALID OPTION            |\n");
            printf("|   ENTER AN OPTION BETWEEN 0 AND 3   |\n");
            printf("+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n\n");
            break;
        }
    }while (op);
}