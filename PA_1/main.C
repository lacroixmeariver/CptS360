#include <stdio.h>
#include "list.h"

int main(void)
{
    IntList list;
    int choice = -1;
    int value;
    int index;
    int result;
    initList(&list);
    do
    {
        printMenu();
        printf("Enter choice: ");
        choice = getValidInteger(); // prevents anything other than an integer from being used

        switch (choice)
        {
        case 1:
            printf("Enter value to insert at end: ");
            value = getValidInteger();
            result = insertEnd(&list, value);
            if (result == -1)
            {
                printf("List is full.\n");
            }
            else
            {
                printf("%d successfully added to end of list.\n", value);
            }

            break;
        case 2:
            printf("Enter index: ");
            index = getValidInteger();
            printf("Enter value: ");
            value = getValidInteger();
            result = insertAt(&list, index, value);
            if (result == -1)
            {
                printf("Invalid index or list is full.\n");
            }
            else
            {
                printf("%d successfully added to index: %d.\n", value, index);
            }
            break;
        case 3:
            printf("Enter index to remove: ");
            index = getValidInteger();
            result = removeAt(&list, index);
            if (result == -1)
            {
                printf("Invalid index.\n");
            }
            else
            {
                printf("Value at index: %d successfully removed.\n", index);
            }
            break;
        case 4:
            printf("Enter value to search: ");
            value = getValidInteger();

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
            printf("Please select a valid menu option.\n");
        }
    }
    while (choice != 0);
    return 0;
}

/// Prints the menu options to the screen.
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

/// Validates user input by verifying stdin integer assignment using scanf().
/// @return Integer value representing user choice or input.
int getValidInteger(void)
{
    int numEntered;

    while (scanf("%d", &numEntered) != 1)
    {
        while (getchar() != '\n')
        {
            continue;
        }
        printf("Invalid input, try again: ");
    }
    return numEntered;
}
