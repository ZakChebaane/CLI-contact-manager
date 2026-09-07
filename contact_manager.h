#ifndef CONTACT_MANAGER
#define CONTACT_MANAGER

typedef struct {
  char name[15];
  char phoneNumber[10];
  char email[15];
} Contact;

void printDetails(void);
int selectOption(void);
void listContacts(Contact *contacts);
void addContact(Contact *contacts, int *countIndex, int *heapSize);

#endif
