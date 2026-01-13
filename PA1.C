#include <stdio.h>
#define MAX_SIZE 100

/* Data structure definition */
typedef struct
{
    int data[MAX_SIZE];
    int size;
} IntList;

/* Function prototypes */
void initList(IntList* list);
int insertEnd(IntList* list, int value);
int insertAt(IntList* list, int index, int value);
int removeAt(IntList* list, int index);
int search(const IntList* list, int value);
void printList(const IntList* list);
void printMenu(void);

int main(void)
{
    IntList list;
    int choice;
    int value;
    int index;
    int result;
    initList(&list);
    do
    {
        printMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert at end: ");
            scanf("%d", &value);
            result = insertEnd(&list, value);
            if (result == -1)
            {
                printf("List is full.\n");
            }
            break;
        case 2:
            printf("Enter index: ");
            scanf("%d", &index);
            printf("Enter value: ");
            scanf("%d", &value);
            result = insertAt(&list, index, value);
            if (result == -1)
            {
                printf("Invalid index or list is full.\n");
            }
            break;
        case 3:
            printf("Enter index to remove: ");
            scanf("%d", &index);
            result = removeAt(&list, index);
            if (result == -1)
            {
                printf("Invalid index.\n");
            }
            break;
        case 4:
            printf("Enter value to search: ");
            scanf("%d", &value);
            result = search(&list, value);
            if (result == -1)
            {
                printf("Value not found.\n");
            }
            else
            {
                printf("Value found at index %d.\n", result);
            }
            break;
        case 5:
            printList(&list);
            break;
        case 0:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    }
    while (choice != 0);
    return 0;
}

/// Initializes a given list.
/// @param list Represents the list user wishes to initialize.
///
void initList(IntList* list)
{
    list->size = 0;
}

/// Inserts a value at the end of the list
/// @param list Represents pointer to the start of the list being modified.
/// @param value Represents the value user wishes to append to the end of the list.
/// @return Integer value representing the number of elements in the list.
///
int insertEnd(IntList* list, int value)
{
    // checks if the list is full
    if (list->size >= MAX_SIZE)
    {
        return -1;
    }

    list->data[list->size] = value; // adding the value to the end of the list
    list->size++; // increasing list size
    printf("List size: %d", list->size); // print to make sure it's working
    return list->size;
}

/* Inserts a value at a specific index */
int insertAt(IntList* list, int index, int value)
{
    /* TODO:
    * 1. Validate index
    * 2. Shift elements to the right
    * 3. Insert value
    * 4. Update size
    */
    return -1; /* placeholder */
}

/* Removes the element at a specific index */
int removeAt(IntList* list, int index)
{
    /* TODO:
    * 1. Validate index
    * 2. Shift elements to the left
    * 3. Update size
    */
    return -1; /* placeholder */
}

/* Searches for a value and returns its index or -1 */
int search(const IntList* list, int value)
{
    /* TODO:
    * Perform a linear search
    */
    return -1; /* placeholder */
}

/* Prints all elements in the list */
void printList(const IntList* list)
{
    /* TODO:
    * Print elements in order
    * Handle empty list
    */
}

/* Prints the menu options */
void printMenu(void)
{
    printf("\nMenu:\n");
    printf("1. Insert at end\n");
    printf("2. Insert at index\n");
    printf("3. Remove at index\n");
    printf("4. Search\n");
    printf("5. Print list\n");
    printf("0. Exit\n");
}
