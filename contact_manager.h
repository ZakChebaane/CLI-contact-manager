#ifndef CONTACT_MANAGER
#define CONTACT_MANAGER

typedef struct {
  char name[15];
  char phoneNumber[15];
  char email[30];
} Contact;

void printDetails(void);
int selectOption(void);
void listContacts(Contact *contacts, int *countIndex);
void addContact(Contact **contacts, int *countIndex, int *heapSize);

#endif
