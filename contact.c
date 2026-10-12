#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook) //function to list all contacts
{
    // Sort contacts based on the chosen criteria
    //Sorting the contacts
    for(int i=0;i<addressBook->contactCount-1;i++)
    {
        for(int j=i+1;j<addressBook->contactCount;j++)
        {
            if(strcmp(addressBook->contacts[i].name,addressBook->contacts[j].name)>0)// checking whether the string is greater
            {
                Contact temp=addressBook->contacts[i];
                addressBook->contacts[i]=addressBook->contacts[j];
                addressBook->contacts[j]=temp;
            }
        }
    }
    printf("----------------------------------------------\n");
    for(int i=0;i<addressBook->contactCount;i++)  // Loop to print all contacts
    {
        printf("%s\t",addressBook->contacts[i].name);
        printf("%s\t",addressBook->contacts[i].phone);
        printf("%s\n",addressBook->contacts[i].email);
    }
    printf("----------------------------------------------");
    
}

void initialize(AddressBook *addressBook) {
    //populateAddressBook(addressBook);
    addressBook->contactCount=0;
    loadContactsFromFile(addressBook);  // loading contacts from contact.txt to addressBook
  }

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook);  // Saving contacts to file contact.txt

}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    int number=0;
    printf("Enter name :");
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);

    printf("Enter phone no :");
    //logic for validation of phone number 
    while(1)             
    {
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].phone);
    number=strlen(addressBook->contacts[addressBook->contactCount].phone);
    if(number==10)   // checking if 10 numbers are present
    break;
    else
    printf("Please enter valid Phone number :"); // if 10 numbers are not present ,asking the user to enter it again
    }

    printf("Enter mail id :");
    // logic for validation of email
    while(1)
    {
    int flag=0;
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);
    int len=strlen(addressBook->contacts[addressBook->contactCount].email);
    for(int i=0;i<len;i++)
    {
        //checking if @ symbol is present in the enetered email
        if(addressBook->contacts[addressBook->contactCount].email[i]=='@')
        {
        flag=1;
        break;
        }
    }
    if(flag==1)
    break;
    else
    printf("Please enter a valid email :");
    }
    addressBook->contactCount++;  //increasing the value of contactCount
    
}

void searchContact(AddressBook *addressBook)  //function to search contact
{
    int choice;
    char str[50];
    /* Define the logic for search */
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Enter the choice : ");
    scanf(" %d",&choice);
    int flag=0;
    switch(choice)
    {
        case 1:
        //searching by name
        printf("Enter the name : ");
        scanf(" %s",str);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(str,addressBook->contacts[i].name)==0)
            {
                //if match is found , we print the contact details
                flag=1;
                printf("%s\t",addressBook->contacts[i].name);
                printf("%s\t",addressBook->contacts[i].phone);
                printf("%s\t",addressBook->contacts[i].email);
                break;
            }
        }
        if(flag!=1)
        printf("Contact not found\n");
        break;

        case 2:
        //searching by Phone number
        printf("Enter the phone no. : ");
        scanf(" %s",str);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(str,addressBook->contacts[i].phone)==0)
            {
                //if match is found , we print the contact details
                flag=1;
                printf("%s\t",addressBook->contacts[i].name);
                printf("%s\t",addressBook->contacts[i].phone);
                printf("%s\t",addressBook->contacts[i].email);
                break;
            }
        }
        if(flag!=1)
        printf("Contact not found\n");
        break;

        case 3:
        //searching by email
        printf("Enter the email : ");
        scanf(" %s",str);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(str,addressBook->contacts[i].email)==0)
            {
                //if match is found , we print the contact details
                flag=1;
                printf("%s\t",addressBook->contacts[i].name);
                printf("%s\t",addressBook->contacts[i].phone);
                printf("%s\t",addressBook->contacts[i].email);
                break;
            }
        }
        if(flag==0)
        printf("Contact not found\n");
        break;
        default:
        printf("Invalid choice\n");
    }
}

void editContact(AddressBook *addressBook) //function to edit contact
{
	/* Define the logic for Editcontact */
    int choice,pos;
    char str[50];
    /* Define the logic for search */
    //first asking user to search for the contact thst needs to be editted
    printf("Enter the choice to search for the contact to edit\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Enter the choice : ");
    scanf("%d",&choice);
    int flag=0;
    switch(choice)
    {
        case 1:
        //searching conatct by name
        printf("Enter the name : ");
        scanf(" %s",str);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(str,addressBook->contacts[i].name)==0)
            {
                //if match is found , we print the contact details
                flag=1;
                printf("%s\t",addressBook->contacts[i].name);
                printf("%s\t",addressBook->contacts[i].phone);
                printf("%s\t\n",addressBook->contacts[i].email);

                //Asking user to select which option to edit
                printf("1. Name\n");
                printf("2. Phone\n");
                printf("3. Email\n");
                printf("Enter choice to edit :");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                    // logic for editing name
                    printf("Enter the new name :");
                    scanf(" %[^\n]",str);
                    strcpy(addressBook->contacts[i].name,str);
                    printf("%s\t",addressBook->contacts[i].name);
                    printf("%s\t",addressBook->contacts[i].phone);
                    printf("%s\t\n",addressBook->contacts[i].email);
                    break;

                    case 2:
                    //logic for editing number
                    printf("Enter the new phone number :");
                    //when entering new number we check for validation
                    while(1)
                    {
                    scanf(" %[^\n]",str);
                    int len=strlen(str);
                    if(len==10)
                    {
                    //if valid we change the name
                    strcpy(addressBook->contacts[i].phone,str);
                    break;
                    }
                    else
                    {
                    printf("Please Enter a valid phone number :");
                    }
                    }
                    printf("%s\t",addressBook->contacts[i].name);
                    printf("%s\t",addressBook->contacts[i].phone);
                    printf("%s\t\n",addressBook->contacts[i].email);
                    break;

                    case 3:
                    //logic  to change email
                    printf("Enter the new email :");
                    int flag;
                    //when enetering new email, we check for validation
                    while(1)
                    {
                    flag=0;
                    scanf(" %[^\n]",str);
                    int len=strlen(str);
                    for(int i=0;i<len;i++)
                    {
                        if(str[i]=='@')
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag==1)
                    {
                    strcpy(addressBook->contacts[i].email,str);
                    break;
                    }
                    else
                    {
                        printf("Please enter a valid email :");
                    }
                    }
                    printf("%s\t",addressBook->contacts[i].name);
                    printf("%s\t",addressBook->contacts[i].phone);
                    printf("%s\t\n",addressBook->contacts[i].email);
                    break;
                    default:
                    printf("Invalid choice\n");
                    break;
                }
                break;
            }
        }
        if(flag!=1)
        printf("Contact not found\n");
        break;

        case 2:
        //we search by phone number
        printf("Enter the phone no. : ");
        scanf(" %s",str);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(str,addressBook->contacts[i].phone)==0)
            {
                flag=1;
                printf("%s\t",addressBook->contacts[i].name);
                printf("%s\t",addressBook->contacts[i].phone);
                printf("%s\t\n",addressBook->contacts[i].email);

                //after printing contact we ask user to enter the choice to edit
                printf("1. Name\n");
                printf("2. Phone\n");
                printf("3. Email\n");
                printf("Enter choice to edit :");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                    //logic for editing new name
                    printf("Enter the new name :");
                    scanf(" %[^\n]",str);
                    strcpy(addressBook->contacts[i].name,str);
                    printf("%s\t",addressBook->contacts[i].name);
                    printf("%s\t",addressBook->contacts[i].phone);
                    printf("%s\t\n",addressBook->contacts[i].email);
                    break;

                    case 2:
                    //logic for editting new number
                    printf("Enter the new phone number :");
                    //validation
                    while(1)
                    {
                    scanf(" %[^\n]",str);
                    int len=strlen(str);
                    if(len==10)
                    {
                    strcpy(addressBook->contacts[i].phone,str);
                    break;
                    }
                    else
                    {
                    printf("Please Enter a valid phone number :");
                    }
                    }
                    printf("%s\t",addressBook->contacts[i].name);
                    printf("%s\t",addressBook->contacts[i].phone);
                    printf("%s\t\n",addressBook->contacts[i].email);
                    break;

                    case 3:
                    //logic for editing email
                    printf("Enter the new email :");
                    int flag;
                    //validation
                    while(1)
                    {
                    flag=0;
                    scanf(" %[^\n]",str);
                    int len=strlen(str);
                    for(int i=0;i<len;i++)
                    {
                        if(str[i]=='@')
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag==1)
                    {
                    strcpy(addressBook->contacts[i].email,str);
                    break;
                    }
                    else
                    {
                        printf("Please enter a valid email :");
                    }
                    }
                    printf("%s\t",addressBook->contacts[i].name);
                    printf("%s\t",addressBook->contacts[i].phone);
                    printf("%s\t\n",addressBook->contacts[i].email);
                    break;
                    default:
                    printf("Invalid choice\n");
                    break;
                }
                break;
            }
        }
        if(flag!=1)
        printf("Contact not found\n");
        break;

        case 3:
        //searching by email
        printf("Enter the email : ");
        scanf(" %s",str);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(str,addressBook->contacts[i].email)==0)
            {
                flag=1;
                printf("%s\t",addressBook->contacts[i].name);
                printf("%s\t",addressBook->contacts[i].phone);
                printf("%s\t\n",addressBook->contacts[i].email);

                printf("1. Name\n");
                printf("2. Phone\n");
                printf("3. Email\n");
                printf("Enter choice to edit :");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                    //logic for editing email
                    printf("Enter the new name :");
                    scanf(" %[^\n]",str);
                    strcpy(addressBook->contacts[i].name,str);
                    printf("%s\t",addressBook->contacts[i].name);
                    printf("%s\t",addressBook->contacts[i].phone);
                    printf("%s\t\n",addressBook->contacts[i].email);
                    break;

                    case 2:
                    //logic for editing phone number
                    printf("Enter the new phone number :");
                    //validation
                    while(1)
                    {
                    scanf(" %[^\n]",str);
                    int len=strlen(str);
                    if(len==10)
                    {
                    strcpy(addressBook->contacts[i].phone,str);
                    break;
                    }
                    else
                    {
                    printf("Please Enter a valid phone number :");
                    }
                    }
                    printf("%s\t",addressBook->contacts[i].name);
                    printf("%s\t",addressBook->contacts[i].phone);
                    printf("%s\t\n",addressBook->contacts[i].email);
                    break;

                    case 3:
                    //logic for editing email
                    printf("Enter the new email :");
                    int flag;
                    //validation
                    while(1)
                    {
                    flag=0;
                    scanf(" %[^\n]",str);
                    int len=strlen(str);
                    for(int i=0;i<len;i++)
                    {
                        if(str[i]=='@')
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag==1)
                    {
                    strcpy(addressBook->contacts[i].email,str);
                    break;
                    }
                    else
                    {
                        printf("Please enter a valid email :");
                    }
                    }
                    printf("%s\t",addressBook->contacts[i].name);
                    printf("%s\t",addressBook->contacts[i].phone);
                    printf("%s\t\n",addressBook->contacts[i].email);
                    break;
                    default:
                    printf("Invalid choice\n");
                    break;
                }
                break;
            }
        }
        if(flag==0)
        printf("Contact not found\n");
        break;
        default:
        printf("Invalid choice\n");
    }
}

void deleteContact(AddressBook *addressBook)  // function to edit  contact
{
	/* Define the logic for deletecontact */
    int choice;
    char str[50];
    /* Define the logic for search */
    printf("Search for the contact to be deleted :\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Enter the choice : ");
    scanf(" %d",&choice);
    int flag=0;
    switch(choice)
    {
        case 1:
        //searching by name
        printf("Enter the name : ");
        scanf(" %s",str);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(str,addressBook->contacts[i].name)==0)
            {
                flag=1;
                printf("%s\t",addressBook->contacts[i].name);
                printf("%s\t",addressBook->contacts[i].phone);
                printf("%s\t",addressBook->contacts[i].email);
                //if match is presnt we delete that contact by replacing that conatct by the next contact
                for(int j=i;j<addressBook->contactCount;j++)
                {
                    //shifting each contact to left
                    addressBook->contacts[j]=addressBook->contacts[j+1];
                }
                printf("\nContact deleted successfully\n");
                addressBook->contactCount--;
                break;
            }
        }
        if(flag!=1)
        printf("Contact not found\n");
        break;

        case 2:
        //searching by phone number
        printf("Enter the phone no. : ");
        scanf(" %s",str);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(str,addressBook->contacts[i].phone)==0)
            {
                flag=1;
                printf("%s\t",addressBook->contacts[i].name);
                printf("%s\t",addressBook->contacts[i].phone);
                printf("%s\t",addressBook->contacts[i].email);
                for(int j=i;j<addressBook->contactCount;j++)
                {
                    //shifting eavh contact to left
                    addressBook->contacts[j]=addressBook->contacts[j+1];
                }
                printf("\nContact deleted successfully\n");
                addressBook->contactCount--;
                break;
            }
        }
        if(flag!=1)
        printf("Contact not found\n");
        break;

        case 3:
        //searching by email
        printf("Enter the email : ");
        scanf(" %s",str);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(str,addressBook->contacts[i].email)==0)
            {
                flag=1;
                printf("%s\t",addressBook->contacts[i].name);
                printf("%s\t",addressBook->contacts[i].phone);
                printf("%s\t",addressBook->contacts[i].email);
                for(int j=i;j<addressBook->contactCount;j++)
                {
                    //shifting each contact to left
                    addressBook->contacts[j]=addressBook->contacts[j+1];
                }
                printf("\nContact deleted successfully\n");
                addressBook->contactCount--;
                break;
            }
        }
        if(flag==0)
        printf("Contact not found\n");
        break;
        default:
        printf("Invalid choice\n");
    }
   
}
