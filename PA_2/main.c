#include "cacheSim.h"

int main(int argc, char* argv[])
{
    // argc = argument count, argv = argument vector containing actual args
    if (argc != 4)
    {
        printf("Usage: %s <cache_size> <block_size> <input_file>\n", argv[0]);
        return 1;
    }
    int cache_size = atoi(argv[1]); // in bytes
    int block_size = atoi(argv[2]); // in bytes

    char* filename = argv[3];
    Cache* cache = create_cache(cache_size, block_size);
    if (cache == NULL)
    {
        printf("Error creating cache\n");
        return 1;
    }
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening input file\n");
        free_cache(cache);
        return 1;
    }
    unsigned int address;
    int accesses = 0;
    int hits = 0;
    int misses = 0;
    /* Read memory addresses from file */
    while (fscanf(fp, "%i", &address) == 1)
    {
        accesses++;
        if (access_cache(cache, address))
        {
            hits++;
        }
        else
        {
            misses++;
        }
    }
    fclose(fp);
    print_stats(accesses, hits, misses);
    free_cache(cache);
    return 0;
}


