#include <stdio.h>
#include "contact.h"

int main() {
    int choice;
    AddressBook A1;
    initialize(&A1);
    do
    {
    printf("\nAddressbook Menu:\n");
    printf("1.Create contact\n");
    printf("2.Search contact\n");
    printf("3.Edit contact\n");
    printf("4.Delete contact\n");
    printf("5.List all contact\n");
    printf("6.Save contact\n");
    printf("7.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Selected Create contact\n");
        createContact(&A1);
        break;
        case 2:
        printf("Selected Search contact\n");
        searchContact(&A1);
        break;
        case 3:
        printf("Selected Edit contact\n");
        editContact(&A1);
        break;
        case 4:
        printf("Selected Delete contact\n");
        deleteContact(&A1);
        break;
        case 5:
        printf("Selected List all contact\n");
        listContacts(&A1);
        break;
        case 6:
        printf("Selected Save contact\n");
        saveContactsToFile(&A1);
        break;
        case 7:
        printf("Exit application\n");
        break;
        default:
        printf("Invalid choice\n");
    }
    }while(choice!=7);
    return 0;
}
