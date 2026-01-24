# CptS 360 - PA1
## How to Compile and Run
- Compile program: `gcc -Wall -Wextra -std=c99 main.c list.c -o PA1`
- Run program: `./PA1`

#### Compiling and running test cases written (if desired)
- `gcc -Wall -Wextra -std=c99 testList.c list.c -o list_tests
  ./list_tests`

## Assumptions Made
- User understands 0-based list indexing/first element of the list starts at 0
- Insertion range for insertAt() goes from 0 - list size at time of insertion except for inserting first element.
- Inserting a value at index equal to list size appends value to end of list.
- Only integer values are intended as inputs (incorrect values entered will re-prompt user until valid entry)

## Example Input and Output
Some operations performed taken from console output:
```
Menu:
1. Insert at end
2. Insert at index
3. Remove at index
4. Search
5. Print list
0. Exit
Enter choice: 1
Enter value to insert at end: 1001
1001 successfully added to end of list.

Menu:
1. Insert at end
2. Insert at index
3. Remove at index
4. Search
5. Print list
0. Exit
Enter choice: 5
Item #1: 1001 

Menu:
1. Insert at end
2. Insert at index
3. Remove at index
4. Search
5. Print list
0. Exit
Enter choice: 2
Enter index: 0
Enter value: 693
693 successfully added to index: 0.

Menu:
1. Insert at end
2. Insert at index
3. Remove at index
4. Search
5. Print list
0. Exit
Enter choice: 5
Item #1: 693 
Item #2: 1001 

Menu:
1. Insert at end
2. Insert at index
3. Remove at index
4. Search
5. Print list
0. Exit
Enter choice: 2
Enter index: 2
Enter value: 222
222 successfully added to index: 2.

Menu:
1. Insert at end
2. Insert at index
3. Remove at index
4. Search
5. Print list
0. Exit
Enter choice: 5
Item #1: 693 
Item #2: 1001 
Item #3: 222 

Menu:
1. Insert at end
2. Insert at index
3. Remove at index
4. Search
5. Print list
0. Exit
Enter choice: 3
Enter index to remove: 1
Value at index: 1 successfully removed.

Menu:
1. Insert at end
2. Insert at index
3. Remove at index
4. Search
5. Print list
0. Exit
Enter choice: 4
Enter value to search: 3
Value not found.

Menu:
1. Insert at end
2. Insert at index
3. Remove at index
4. Search
5. Print list
0. Exit
Enter choice: 4
Enter value to search: 693
Value found at index 0.

Menu:
1. Insert at end
2. Insert at index
3. Remove at index
4. Search
5. Print list
0. Exit
Enter choice: 0
Exiting program.

```