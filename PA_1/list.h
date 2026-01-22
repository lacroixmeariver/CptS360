#ifndef LIST_HEADER
#define LIST_HEADER
#define MAX_SIZE 100

/* Data structure definition */
typedef struct
{
    int data[MAX_SIZE];
    int size;
} IntList;

/* Function prototypes */
void initList(IntList* list);
int getValidInteger();
int insertEnd(IntList* list, int value);
int insertAt(IntList* list, int index, int value);
int removeAt(IntList* list, int index);
int search(const IntList* list, int value);
void printList(const IntList* list);
void printMenu(void);

#endif