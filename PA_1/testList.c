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

void test_insert_at_empty()
{
    IntList testList;
    initList(&testList);

    insertAt(&testList, 0, 5);

    assert(testList.size == 1);
    assert(testList.data[0] == 5);
}

void test_insert_at_multiple_values()
{
    IntList testList;
    initList(&testList);

    insertEnd(&testList, 5);
    insertEnd(&testList, 10);
    insertEnd(&testList, 15);

    // list at this point: [5|10|15]
    assert(testList.size == 3);
    assert(testList.data[0] == 5);
    assert(testList.data[1] == 10);
    assert(testList.data[2] == 15);

    // inserting at index 1 should result in: [5|33|10|15]
    insertAt(&testList, 1, 3);
    assert(testList.size == 4);
    assert(testList.data[0] == 5);
    assert(testList.data[1] == 3);
    assert(testList.data[2] == 10);
    assert(testList.data[3] == 15);

}

void test_insert_at_size_index()
{
    IntList testList;
    initList(&testList);

    insertEnd(&testList, 9);
    // size at this point is 1
    insertAt(&testList, 1, 11);

    assert(testList.size == 2);
    assert(testList.data[1] == 11);
}

void test_insert_at_negative_index()
{
    IntList testList;
    initList(&testList);

    assert(testList.size == 0);
    assert(insertAt(&testList, -5, 11) == -1);
}

void test_insert_at_large_index()
{
    IntList testList;
    initList(&testList);

    assert(testList.size == 0);
    assert(insertAt(&testList, 10, 11) == -1);
}

void test_insert_at_max()
{
    // in progress...
}

int main(void)
{
    // insertEnd tests
    test_empty_list();
    test_insert_end_empty();
    test_insert_end();
    test_insert_end_max();

    // insertAt tests
    test_insert_at_empty();
    test_insert_at_multiple_values();
    test_insert_at_size_index();
    test_insert_at_negative_index();
    test_insert_at_large_index();

    printf("All tests executed...");
}


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