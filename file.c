#include <stdio.h>
#include "file.h"
//function to save contacts to file
void saveContactsToFile(AddressBook *addressBook) {
    FILE *fptr;   
    fptr=fopen("contacts.txt","w");
    //check if file is opened or not
    if(fptr==NULL)
    {
        printf("Failed to open file");
        return;
    }
    //printing the total count of contacts in the file
    fprintf(fptr,"%d\n",addressBook->contactCount);
    //printing contacts to the file by using loop
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fprintf(fptr,"%s|%s|%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fptr);
    printf("Contacts saved successfully\n");
    
}

//function to read contacts from file
void loadContactsFromFile(AddressBook *addressBook) {
    FILE *fptr;
    fptr=fopen("contacts.txt","r");
    //checking if file is opened
    if(fptr==NULL)
    {
        addressBook->contactCount=0;
        return;
    }
    fscanf(fptr,"%d\n",&addressBook->contactCount);  //reading contactCount
    //reading each contact from file using loop
    for(int i=0;i<addressBook->contactCount;i++)
    {
        //[^|] means read until '|' 
        fscanf(fptr," %49[^|]|%19[^|]|%49[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        
    }
    fclose(fptr);
}
