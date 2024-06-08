#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    char num_phone[30];
    char email[30];
} contact;

contact *contacts = NULL;
int size = 0;
int number_of_contact = 0;

//--------------------------------------------------------------------------------------------------------------------------------
void add() {
    size++;
    contacts = realloc(contacts, size * sizeof(contact)); // 1

    if (contacts == NULL) {
        printf("allocation error!!!!!\n"); // 2
        exit(1);
    }
    printf("Pls enter your name : ");
    scanf("%s", contacts[number_of_contact].name); // 3

    printf("Pls enter your number : ");
    scanf("%s", contacts[number_of_contact].num_phone); // 4

    printf("Pls enter your email : ");
    scanf("%s", contacts[number_of_contact].email); // 5
    printf("-----------------------------------------------------------------------------------------------\n");


    number_of_contact++;
}

//---------------------------------------------------------------------------------------------------------------------------------
void display() {
    for (int i = 0; i < number_of_contact; i++) {
        printf("contact %d :\n name : %s , number : %s , email : %s\n", i+1, contacts[i].name, contacts[i].num_phone, contacts[i].email);
    }
}
//---------------------------------------------------------------------------------------------------------------------------------
void search() {
    char n[100];
    printf("Pick a number please : ");
    scanf("%s", n); // 1

    for (int i = 0; i < number_of_contact; i++) {
        if (strcmp(contacts[i].num_phone, n) == 0) { // 2
            printf("OK! %s , %s , %s\n", contacts[i].name, contacts[i].num_phone, contacts[i].email);
            return;
        }
    }

    printf("Sorry, this contact doesn't exist!! :'( \n");
}

//----------------------------------------------------------------------------------------------------------------------------------
int main() {
    int choice;

    printf("-------------------Welcome to the contact generator pls choose your option------------------- : \n ");

    do {
        printf("1-Add\n 2-Display\n 3-Search \n 4-Quit\n");
        scanf("%d", &choice);
        printf("-----------------------------------------------------------------------------------------------\n");

        switch (choice) {
            case 1: add(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: break;
            default: printf("INVALID!!!!\n");
        }
    } while (choice != 4);

    free(contacts);
    return 0;
}
