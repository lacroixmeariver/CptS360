# CptS_360

## About
Repository for work done in CptS 360 at Washington State University in the Spring of 2026.

All project files in their completed and submitted state can be found on the main branch, while each individual 
assignment has its own working branch. 

### Assignment Descriptions
- [PA 1](https://github.com/lacroixmeariver/CptS360/tree/hw/PA1) - Refresher on C data structures
  - Requirements were to implement and manipulate basic data structures in C
  - Required operations and function declarations:
    - `initList` - `void initList(IntList *list);`
    - `insertEnd` - `int insertEnd(IntList *list, int value);`
    - `insertAt` - `int insertAt(IntList *list, int index, int value);`
    - `removeAt` - `int removeAt(IntList *list, int index);`
    - `search` - `int search(const IntList *list, int value);`
    - `printList` - `void printList(const IntList *list);`
- [PA 2](https://github.com/lacroixmeariver/CptS360/tree/hw/PA2) - Direct-mapped Cache Simulator
  - Instructions were to implement a cache simulator that processes a sequence of memory accesses 
  and reports cache statistics.
  - Functional Requirements:
    - Correctly divide memory addresses into tag, index, and offset values
    - Determine whether each access results in a cache hit or miss
    - Update cache state appropriately after each access
    - Maintain accurate statistics throughout execution