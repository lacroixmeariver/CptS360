#include "list.h"
#include <assert.h>
#include <stdio.h>

/// Tests initialization of an empty list.
/// @remark Verifies size is set to 0.
void test_empty_list()
{
    // initializing list
    IntList testList;
    initList(&testList);

    // assert statement(s)
    assert(testList.size == 0);
}

/// Tests inserting/appending a single value into an empty list.
/// @remark Verifies size increments and value is stored at index 0.
void test_insert_end_empty()
{
    IntList testList;
    initList(&testList);

    // operation(s) performed
    insertEnd(&testList, 5);

    // assert statement(s)
    assert(testList.size == 1);
    assert(testList.data[0] == 5);
}

/// Tests inserting multiple values at the end of the list.
/// @remark Verifies size increments correctly and values are in order.
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

/// Tests inserting values until list reaches maximum capacity.
/// @remark Verifies insertion fails when list is full.
void test_insert_end_max()
{
    IntList testList;
    initList(&testList);

    for (int i = 0; i < MAX_SIZE; i++)
    {
        insertEnd(&testList, i);
    }

    assert(testList.data[99] == 99); // verifying that up until this point the list is full
    assert(testList.size == MAX_SIZE);

    // adding another element to overload the list
    assert(insertEnd(&testList, 100) == -1); // should result in -1
    assert(testList.size == MAX_SIZE);
}

/// Tests inserting at index 0 in an empty list.
/// @remark Verifies insertion works correctly at start of empty list.
void test_insert_at_empty()
{
    IntList testList;
    initList(&testList);

    insertAt(&testList, 0, 5);

    assert(testList.size == 1);
    assert(testList.data[0] == 5);
}

/// Tests inserting at a specific index with list element shifting.
/// @remark Verifies elements shift right and new value is placed correctly.
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

/// Tests inserting at index equal to current size.
/// @remark Verifies insertion at end of list using insertAt.
void test_insert_at_size_index()
{
    IntList testList;
    initList(&testList);

    insertEnd(&testList, 9); // size at this point is 1
    insertAt(&testList, 1, 11);

    assert(testList.size == 2);
    assert(testList.data[1] == 11);
}

/// Tests inserting at a negative index.
/// @remark Verifies function rejects invalid negative index.
void test_insert_at_negative_index()
{
    IntList testList;
    initList(&testList);

    assert(testList.size == 0);
    assert(insertAt(&testList, -5, 11) == -1);
}

/// Tests inserting at an index beyond current size.
/// @remark Verifies function rejects index larger than current list size.
void test_insert_at_large_index()
{
    IntList testList;
    initList(&testList);

    assert(testList.size == 0);
    assert(insertAt(&testList, 10, 11) == -1);
}

/// Tests inserting when list is at maximum capacity.
/// @remark Verifies function rejects insertion when full.
void test_insert_at_max()
{
    IntList testList;
    initList(&testList);

    for (int i = 0; i < MAX_SIZE; i++)
    {
        insertEnd(&testList, i);
    }

    assert(testList.size == 100);
    assert(insertAt(&testList, 99, 5) == -1); // inserting at max index
}

/// Tests removing from an empty list.
/// @remark Verifies function rejects removal from empty list.
void test_remove_at_empty()
{
    IntList testList;
    initList(&testList);

    assert(testList.size == 0);
    assert(removeAt(&testList, 0) == -1);
}

/// Tests removing the only element in a list.
/// @remark Verifies list becomes empty after removal.
void test_remove_at_single_element()
{
    IntList testList;
    initList(&testList);

    insertEnd(&testList, 10); // inserting element
    removeAt(&testList, 0); // removing single element

    assert(testList.size == 0);
}

/// Tests removing the first element with left shift.
/// @remark Verifies remaining elements shift left correctly.
void test_remove_at_first_index()
{
    IntList testList;
    initList(&testList);

    // list state after inserts: [5|10|15]
    insertEnd(&testList, 5);
    insertEnd(&testList, 10);
    insertEnd(&testList, 15);
    removeAt(&testList, 0); // should leave list at: [10|15]

    assert(testList.size == 2);
    assert(testList.data[0] == 10);
}

/// Tests removing the last element in the list.
/// @remark Verifies last element removal without shifting.
void test_remove_at_last_index()
{
    IntList testList;
    initList(&testList);

    // list state after inserts: [5|10|15]
    insertEnd(&testList, 5);
    insertEnd(&testList, 10);
    insertEnd(&testList, 15);
    removeAt(&testList, 2); // should leave list at: [5|10]

    assert(testList.size == 2);
    assert(testList.data[0] == 5);
    assert(testList.data[1] == 10);
}

/// Tests removing at a negative index.
/// @remark Verifies function rejects invalid negative index.
void test_remove_at_invalid_index()
{
    IntList testList;
    initList(&testList);

    assert(testList.size == 0);
    assert(removeAt(&testList, -10) == -1);
}

/// Tests removing at an index beyond current size.
/// @remark Verifies function rejects out-of-bounds index.
void test_remove_at_large_index()
{
    IntList testList;
    initList(&testList);

    assert(testList.size == 0);
    assert(removeAt(&testList, 105) == -1);
}

/// Tests searching in an empty list.
/// @remark Verifies searching an empty list returns -1.
void test_search_empty()
{
    IntList testList;
    initList(&testList);

    assert(testList.size == 0);
    assert(search(&testList, 10) == -1);
}

/// Tests searching for value at first index.
/// @remark Verifies search correctly identifies element at index 0.
void test_search_first_index()
{
    IntList testList;
    initList(&testList);

    // list state after inserts: [5|10|15]
    insertEnd(&testList, 5);
    insertEnd(&testList, 10);
    insertEnd(&testList, 15);

    assert(search(&testList, 5) == 0); // returns index of value present
}

/// Tests searching for value in middle of list.
/// @remark Verifies search correctly identifies element at middle index.
void test_search_middle_index()
{
    IntList testList;
    initList(&testList);

    // list state after inserts: [5|10|15]
    insertEnd(&testList, 5);
    insertEnd(&testList, 10);
    insertEnd(&testList, 15);

    assert(search(&testList, 10) == 1);
}

/// Tests searching for value at last index.
/// @remark Verifies search correctly identifies element at end.
void test_search_last_index()
{
    IntList testList;
    initList(&testList);

    // list state after inserts: [5|10|15]
    insertEnd(&testList, 5);
    insertEnd(&testList, 10);
    insertEnd(&testList, 15);

    assert(search(&testList, 15) == 2);
}

/// Tests searching for value not in list.
/// @remark Verifies search returns -1 when value is not found.
void test_search_invalid_target()
{
    IntList testList;
    initList(&testList);

    // list state after inserts: [5|10|15]
    insertEnd(&testList, 5);
    insertEnd(&testList, 10);
    insertEnd(&testList, 15);

    assert(search(&testList, 300) == -1); // should return -1
}

/// Tests searching when multiple instances of target exist.
/// @remark Verifies search returns first occurrence of value.
void test_search_multiple_target_instances()
{
    IntList testList;
    initList(&testList);

    // list state after inserts: [5|10|10]
    insertEnd(&testList, 5);
    insertEnd(&testList, 10);
    insertEnd(&testList, 10);

    assert(search(&testList, 10) == 1); // first instance in list at index 1
}

/// Tests mixed insert and remove operations.
/// @remark Verifies list behaves as expected following alternating operations.
void test_insert_remove_insert()
{
    IntList testList;
    initList(&testList);

    insertEnd(&testList, 2);
    insertEnd(&testList, 10);
    removeAt(&testList, 0); // state of list after removal: [2|10] --> [10]

    // inserting value at the same index removed
    insertAt(&testList, 0, 3);

    assert(testList.data[0] == 3);
    assert(testList.size == 2);
}

/// Tests filling list to capacity then removing all elements.
/// @remark Verifies list can be emptied and reused after filling.
void test_insert_max_values_and_remove()
{
    IntList testList;
    initList(&testList);

    for (int i = 0; i < MAX_SIZE; i++)
    {
        insertEnd(&testList, i);
    }

    // list current at max, now removing elements at all indices
    for (int j = 0; j < MAX_SIZE; j++)
    {
        removeAt(&testList, testList.size - 1); // removing from end of the list
    }

    assert(testList.size == 0);
}

/// Tests alternating insertAt and insertEnd operations.
/// @remark Verifies mixed insertion methods maintain correct element order.
void test_mixed_insert_methods()
{
    IntList testList;
    initList(&testList);

    // insertions using insertAt and insertEnd
    insertEnd(&testList, 10);
    insertEnd(&testList, 900);
    insertAt(&testList, 2, 99); // list at this point: [10|900|99]
    insertEnd(&testList, 55);
    insertEnd(&testList, 123);
    insertAt(&testList, 3, 334); // list at this point: [10|900|99|334|55|123]
    insertEnd(&testList, 11);

    // verifying all indices in list
    assert(testList.size == 7);
    assert(testList.data[0] == 10);
    assert(testList.data[1] == 900);
    assert(testList.data[2] == 99);
    assert(testList.data[3] == 334);
    assert(testList.data[4] == 55);
    assert(testList.data[5] == 123);
    assert(testList.data[6] == 11);
}

/// Main entry point for running test functions.
/// @return 0 if all tests pass.
/// @remark Uses assert statements to verify correctness.
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
    test_insert_at_max();

    // removeAt tests
    test_remove_at_empty();
    test_remove_at_single_element();
    test_remove_at_first_index();
    test_remove_at_invalid_index();
    test_remove_at_large_index();

    // search tests
    test_search_empty();
    test_search_first_index();
    test_search_middle_index();
    test_search_last_index();
    test_search_invalid_target();
    test_search_multiple_target_instances();

    // integration testing
    test_insert_remove_insert();
    test_insert_max_values_and_remove();
    test_mixed_insert_methods();

    printf("All tests executed!");
}