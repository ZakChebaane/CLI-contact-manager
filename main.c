#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact_manager.h"

int main(void) {
  // Check for previous data print [info]
  // print [DEBUG] heap size (should start with 2 slots, then when capacity is reached it will double)
  // Print start screen
  // If sequence for options 1 - 5 : take user input

  // create Array of contacts with maloc()
  Contact *contacts = malloc(sizeof(Contact));

  if (contacts == NULL) {
    printf("Memory Allocation Failed.\n");
    return 1;
  }

  printDetails();

  strcpy(contacts[0].name, "Zak");

  free(contacts);
  contacts = NULL;
  return 0;
}
