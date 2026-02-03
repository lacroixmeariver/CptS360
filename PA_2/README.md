# CptS 360 - PA2

## Cache Specifications
- **Cache Type:** Direct-mapped cache 
- **Cache Size:** Tested with 64 bytes as default value, but configurable via command line
- **Block Size:** Tested with 16 bytes as default value, but configurable via command line
- **Memory address size:** 4 bytes (32-bits)
- **Replacement policy:** Direct-mapped

## How to Compile and Run
- Compile program: `gcc -Wall -o PA2 main.c cacheSim.c`
- Run program: `./PA2 64 16 input_sequential.txt` \
Note: Cache size and block size can be changed, replace existing values with desired sizes. 
## Assumptions Made
- Input files contain addresses in either hexadecimal or decimal values
- Each address corresponds to a single line in the input file
- Given addresses are non-negative and fit within range defined by 32-bit unsigned integers
- Cache size is evenly divisible by block size
## Example Input and Output
Some operations performed taken from console output:

```
-- Expected input with legal values --

./PA2 64 16 input_sequential.txt  
Total memory accesses: 10
Cache hits: 7
Cache misses: 3
Cache hit rate: 70.00%

./PA2 64 16 input_repeated.txt    
Total memory accesses: 10
Cache hits: 8
Cache misses: 2
Cache hit rate: 80.00%

./PA2 64 16 input_conflicts.txt
Total memory accesses: 8
Cache hits: 0
Cache misses: 8
Cache hit rate: 0.00%

./PA2 64 16 input_mixed.txt    
Total memory accesses: 14
Cache hits: 5
Cache misses: 9
Cache hit rate: 35.71%

./PA2 64 16 input_hex.txt  
Total memory accesses: 8
Cache hits: 6
Cache misses: 2
Cache hit rate: 75.00%

-- Expected input with illegal values -- 

./PA2 512 0 input_hex.txt        
Invalid input, cache or block size cannot be less than or equal to 0.
Error creating cache                                                                                                                                                      

./PA2 64 128 input_sequential.txt 
Invalid input, block size cannot be greater than cache size.
Error creating cache                                                                                                                                          

./PA2 512 -128 input_sequential.txt
Invalid input, cache or block size cannot be less than or equal to 0.
Error creating cache

-- Corrupted/invalid input -- 

./PA2 64 input_sequential.txt 
Usage: ./PA2 <cache_size> <block_size> <input_file>

./PA2 64 16 input_nonexistentFile.txt
Error opening input file

```