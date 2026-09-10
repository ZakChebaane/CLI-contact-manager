#include "contact_manager.h"
#include "string.h"
#include <ctype.h>
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
}
int selectOption(void) {
  while (1) {
    int userInput;
    printf("----------------------------------\n");
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
void listContacts(Contact *contacts, int *countIndex, int *heapSize) {
  if (*countIndex == 0) {
    printf("[INFO] Contact list is empty.\n");
  } else {
    printf("==================================================================="
           "=============\n");
    printf("ID    NAME                 PHONE                 EMAIL\n");
    printf("==================================================================="
           "=============\n");
    for (int i = 0; i < *countIndex; i++) {
      printf("%d     %s                   %s           %s\n", contacts[i].id,
             contacts[i].name, contacts[i].phoneNumber, contacts[i].email);
    }
    printf("==================================================================="
           "=============\n");
    printf("Total: %d contacts (Heap capacity: %d)\n", *countIndex, *heapSize);
  }
}
void addContact(Contact **contacts, int *countIndex, int *heapSize) {
  if (*countIndex == *heapSize) {
    printf("[DEBUG] Capacity full (%d/%d). Doubling heap buffer via realloc() "
           "-> new capacity: %d.\n",
           *countIndex, *heapSize, (*heapSize) *= 2);

    *contacts = realloc(*contacts, (*heapSize) * sizeof(Contact));
    if (contacts == NULL) {
      printf("Memory Reallocation Failed\n");
      return;
    }
  }

  (*contacts)[*countIndex].id = *countIndex + 1;
  printf("Enter Name: ");
  fgets((*contacts)[*countIndex].name, sizeof((*contacts)[*countIndex].name),
        stdin);
  (*contacts)[*countIndex].name[strcspn((*contacts)[*countIndex].name, "\n")] =
      '\0';
  printf("Enter Email: ");
  fgets((*contacts)[*countIndex].email, sizeof((*contacts)[*countIndex].email),
        stdin);
  (*contacts)[*countIndex]
      .email[strcspn((*contacts)[*countIndex].email, "\n")] = '\0';
  printf("Enter Phone Number: ");
  fgets((*contacts)[*countIndex].phoneNumber,
        sizeof((*contacts)[*countIndex].phoneNumber), stdin);
  (*contacts)[*countIndex]
      .phoneNumber[strcspn((*contacts)[*countIndex].phoneNumber, "\n")] = '\0';

  printf("[SUCCESS] Added '%s'. (Count: %d/%d)\n",
         (*contacts)[*countIndex].name, *countIndex + 1, *heapSize);
  *countIndex += 1;
}
void searchContact(Contact *contacts, int *countIndex) {
  char nameStr[15];
  printf("Enter search query: ");
  fgets(nameStr, sizeof(nameStr), stdin);
  nameStr[strcspn(nameStr, "\n")] = '\0';
  // convert str to lowercase
  for (size_t i = 0; i < strlen(nameStr); i++) {
    nameStr[i] = tolower(nameStr[i]);
  }
  printf("---------------------------------------------------------------------"
         "-----------\n");
  int found = 0;
  // Search for str
  for (int i = 0; i < *countIndex; i++) {
    char contactsName[sizeof(contacts[i].name)];
    strncpy(contactsName, contacts[i].name, sizeof(contactsName));
    for (size_t i = 0; i < strlen(contactsName); i++) {
      contactsName[i] = tolower(contactsName[i]);
    }

    if (strstr(contactsName, nameStr) != NULL) {
      found += 1;
      printf("* ID %d: %s | %s | %s\n", contacts[i].id, contacts[i].name,
             contacts[i].phoneNumber, contacts[i].email);
    }
  }
  printf("Found %d match:\n", found);
  printf("---------------------------------------------------------------------"
         "-----------\n");
}
void deleteContact(Contact **contacts, int *countIndex, int *heapSize) {
  int selectedID = 0;
  int maxIndex = (*countIndex) - 1;
  printf("Enter ID of contact to remove: ");
  scanf("%d", &selectedID);
  // flush stdin so next time it is used there isnt a random \n in there
  while (getchar() != '\n')
    ;
  for (int i = 0; i < *countIndex; i++) {
    if ((*contacts)[i].id == selectedID) {
      if ((*contacts)[i].id != *countIndex) {
        // Contact is the not the end one
        // copy values from the last contact to the contact we want to delete
        strncpy((*contacts)[i].name, (*contacts)[maxIndex].name,
                sizeof((*contacts)[maxIndex].name));
        strncpy((*contacts)[i].email, (*contacts)[maxIndex].email,
                sizeof((*contacts)[maxIndex].email));
        strncpy((*contacts)[i].phoneNumber, (*contacts)[maxIndex].phoneNumber,
                sizeof((*contacts)[maxIndex].phoneNumber));
      }
      // remove end contact
      *countIndex -= 1;
      // reallocate memory if needed
      if ((*heapSize) / 2 == *countIndex) {
        *heapSize /= 2;
        *contacts = realloc(*contacts, (*heapSize) * sizeof(Contact));
        if (*contacts == NULL) {
          printf("Memory Reallocation Failed\n");
          return;
        } else {
          printf("[DEBUG] Deallocating memory, New heap size -> %d, (Size: %d/%d)\n", *heapSize, *countIndex, *heapSize);
        }
      }
      return;
    }
  }
  printf("[ERROR] (ID: %d) does not exist\n", selectedID);
}
