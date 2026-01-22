#include "list.h"
#include <assert.h>
#include <stdio.h>

void test_empty_list()
{
    IntList testList;
    initList(&testList);
    assert(testList.size == 0);
}

void test_insert_end_empty()
{
    IntList testList;
    initList(&testList);

    insertEnd(&testList, 5);

    assert(testList.size == 1);
    assert(testList.data[0] == 5);
}


void test_insert_end()
{
    IntList testList;
    initList(&testList);

    insertEnd(&testList, 5);
    insertEnd(&testList, 10);
    insertEnd(&testList, 15);

    assert(testList.size == 3);
    assert(testList.data[0] == 5);
    assert(testList.data[1] == 10);
    assert(testList.data[2] == 15);
}

void test_insert_end_max()
{
    IntList testList;
    initList(&testList);

    for (int i = 0; i < MAX_SIZE; i++)
    {
        insertEnd(&testList, i);
    }

    // verifying that up until this point the list is full
    assert(testList.data[99] == 99);
    assert(testList.size == MAX_SIZE);

    // adding another element to overload the list
    // should result in -1
    assert(insertEnd(&testList, 100) == -1);
}


int main(void)
{
    test_empty_list();
    test_insert_end_empty();
    test_insert_end();
    test_insert_end_max();

    printf("All tests executed...");
}

// TODO: Test initList - verify size is 0

// TODO: Test insertEnd - empty list
// TODO: Test insertEnd - multiple values
// TODO: Test insertEnd - fill to MAX_SIZE
// TODO: Test insertEnd - when list is full (should fail)

// TODO: Test insertAt - index 0 in empty list
// TODO: Test insertAt - index 0 in non-empty list (shift right)
// TODO: Test insertAt - middle of list (verify shifting)
// TODO: Test insertAt - at index == size (append)
// TODO: Test insertAt - negative index (should fail)
// TODO: Test insertAt - index > size (should fail)
// TODO: Test insertAt - when list is full (should fail)

// TODO: Test removeAt - from empty list (should fail)
// TODO: Test removeAt - only element in list
// TODO: Test removeAt - first element (index 0)
// TODO: Test removeAt - last element
// TODO: Test removeAt - middle element (verify shifting)
// TODO: Test removeAt - negative index (should fail)
// TODO: Test removeAt - index >= size (should fail)

// TODO: Test search - in empty list (should return -1)
// TODO: Test search - value at index 0
// TODO: Test search - value in middle
// TODO: Test search - value at last index
// TODO: Test search - value not in list (should return -1)
// TODO: Test search - multiple copies exist (returns first)

// TODO: Test printList - empty list
// TODO: Test printList - single element
// TODO: Test printList - multiple elements

// TODO: Integration test - insert, remove, insert again
// TODO: Integration test - fill list, empty list, reuse
// TODO: Integration test - mixed insertAt and insertEnd operations