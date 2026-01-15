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
    return list->size;
}

/// Inserts a value at a specific index
/// @param list Represents the list being modified.
/// @param index Represents the index position a value is being assigned to.
/// @param value Represents the value being assigned into a specific index.
/// @return Integer value representing the number of elements in the list.
int insertAt(IntList* list, int index, int value)
{
    if (list->size >= MAX_SIZE || index > list->size || index < 0)
    {
        return -1;
    }

    // assuming user knows indexing is 0 based
    int tempCurrent = list->data[index];
    list->data[index] = value;

    for (int i = index + 1; i < list->size; i++)
    {
        int tempNext = list->data[i];
        list->data[i] = tempCurrent;
        tempCurrent = tempNext;
    }
    list->data[list->size] = tempCurrent;

    list->size++;
    return list->size;
}

/// Removes the element at a specific index.
/// @param list Represents the list being modified.
/// @param index Represents the index with value being removed.
/// @return Integer value representing the number of elements in the list.
int removeAt(IntList* list, int index)
{
    if (index >= list->size || index < 0)
    {
        return -1;
    }

    for (int i = index; i < list->size - 1; i++)
    {
        int tempNext = list->data[i + 1];
        list->data[i] = tempNext;
    }

    list->size--;
    return list->size;

}

/// Searches for a value and returns its index or -1
/// @param list Represents the list being searched.
/// @param value Represents the target value.
/// @return Integer value representing the index containing target value.
int search(const IntList* list, int value)
{
    for (int i = 0; i < list->size; i++)
    {
        if (list->data[i] == value)
        {
            return i;
        }
    }

    return -1;
}

/// Prints all the elements in the list.
/// @param list Represents the list a user wishes to print.
/// @remark Recognizes empty lists based on size.
void printList(const IntList* list)
{
    if (list->size <= 0)
    {
        printf("List is empty, nothing to display.");
        return;
    }

    for (int i = 0; i < list->size; i++)
    {
        printf("Item #%d: %d \n", i+1, list->data[i]);
    }
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
