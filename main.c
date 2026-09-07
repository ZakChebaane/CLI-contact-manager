#include "contact_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  // Check for previous data print [info]
  // print [DEBUG] heap size (should start with 2 slots, then when capacity is
  // reached it will double) Print start screen If sequence for options 1 - 5 :
  // take user input

  int countIndex = 0;
  int heapSize = 2;

  int runLoop = 1;

  // create Array of contacts with maloc()
  Contact *contacts = malloc(heapSize * sizeof(Contact));

  if (contacts == NULL) {
    printf("Memory Allocation Failed.\n");
    return 1;
  }

  printDetails();
  while (runLoop) {
    int selection = selectOption();
    if (selection == 1) {
      listContacts(contacts, &countIndex);
    } else if (selection == 2) {
      addContact(&contacts, &countIndex, &heapSize);
    } else if (selection == 5) {
      runLoop = 0;
    }
  }

  free(contacts);
  contacts = NULL;
  return 0;
}
