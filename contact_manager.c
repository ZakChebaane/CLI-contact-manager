#include "contact_manager.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

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
        return userInput;
      } else {
        printf("[ERROR] Only enter a number between 1 and 5\n");
      }
    } else if (result == 0) {
      printf("[ERROR] Only enter a number between 1 and 5\n");
      while (getchar() != '\n');
      userInput = 0;
    } else if (result < 0) {
      printf("Major error with scanf.");
    }
  }
}
void listContacts(Contact *contacts) {}
void addContact(Contact *contacts) {}
