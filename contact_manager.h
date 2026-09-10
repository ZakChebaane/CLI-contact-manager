#ifndef CONTACT_MANAGER
#define CONTACT_MANAGER

typedef struct {
  char name[15];
  char phoneNumber[15];
  char email[30];
  int id;
} Contact;

void printDetails(void);
int selectOption(void);
void listContacts(Contact *contacts, int *countIndex, int *heapSize);
void addContact(Contact **contacts, int *countIndex, int *heapSize);
void searchContact(Contact *contacts, int *countIndex);
void deleteContact(Contact **contacts, int *countIndex, int *heapSize);

#endif
