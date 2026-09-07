#include "contact_manager.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printDetails(void) {
  printf("==================================\n");
  printf("       CONTACT MANAGER CLI        \n");
  printf("==================================\n");
  printf("1. List All Contacts\n");
  printf("2. Add New Contact\n");
  printf("3. Search by Name\n");
  printf("4. Delete Contact\n");
  printf("5. Exit & Save\n");
  printf("----------------------------------\n");
}
int selectOption(void) {
  while (1) {
    int userInput;
    printf("Select an option (1-5): ");
    int result = scanf("%d", &userInput);
    if (result > 0) {
      if (userInput > 0 && userInput < 6) {
        // added here because scanf leaves as extra \n in stdin, so i need to 
        //          remove it or my next fgets function wont work as expected
        while (getchar() != '\n')
          ;
        return userInput;
      } else {
        printf("[ERROR] Only enter a number between 1 and 5\n");
      }
    } else if (result == 0) {
      printf("[ERROR] Only enter a number between 1 and 5\n");
      while (getchar() != '\n')
        ;
      userInput = 0;
    } else if (result < 0) {
      printf("Major error with scanf.");
    }
  }
}
void listContacts(Contact *contacts) {}
void addContact(Contact *contacts, int *countIndex, int *heapSize) {
  printf("Enter Name: ");
  fgets(contacts[*countIndex].name, sizeof(contacts[*countIndex].name), stdin);
  contacts[*countIndex].name[strcspn(contacts[*countIndex].name, "\n")] = '\0';
  printf("name -> %s\n", contacts[*countIndex].name);
}
