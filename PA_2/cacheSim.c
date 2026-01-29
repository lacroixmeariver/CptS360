#include "cacheSim.h"

/// Creates and initializes a new cache.
/// @param cache_size Represents the total cache size in bytes.
/// @param block_size Represents the total size of stored block.
/// @return Pointer to newly initialized cache.
Cache* create_cache(int cache_size, int block_size)
{
    Cache* cache = (Cache*)malloc(sizeof(Cache));
    if (cache == NULL)
    {
        return NULL;
    }
    cache->block_size = block_size;
    cache->num_lines = cache_size / block_size;
    cache->lines = (CacheLine*)malloc(sizeof(CacheLine) * cache->num_lines);
    if (cache->lines == NULL)
    {
        free(cache);
        return NULL;
    }

    for (int i = 0; i < cache->num_lines; i++)
    {
        cache->lines[i].tag = 0; // set to 0, new cache will be cold/empty
    }

    return cache;
}


/// Simulates the accessing of a cache using a memory address.
/// @param cache Represents the cache being accessed.
/// @param address Represents the address being evaluated.
/// @return Integer value representing a cache hit (1) or miss (0).
int access_cache(Cache* cache, unsigned int address)
{
    int block_address = address / cache->block_size;
    int index = block_address % cache->num_lines;
    int tag = block_address / cache->num_lines;

    // yes there's data in here and the tag matches target tag
    if (cache->lines[index].valid == 1 && cache->lines[index].tag == tag)
    {
        return 1; // hit
    }

    // otherwise it's a miss
    cache->lines[index].valid = 1; // making sure it flips to indicate valid data being stored
    cache->lines[index].tag = tag; // kicking out the value that was here last
    return 0; // cache miss
}


/// Frees allocated memory for the cache.
/// @param cache Represents the cache in which memory is being deallocated.
void free_cache(Cache* cache)
{
    if (cache != NULL)
    {
        free(cache->lines);
        free(cache);
    }
}


/// Prints cache statistics.
/// @param accesses Total number of queries made to the cache.
/// @param hits Total number of successful queries.
/// @param misses Total number of unsuccessful queries.
void print_stats(int accesses, int hits, int misses)
{
    double hit_rate = 0.0;
    if (accesses > 0)
    {
        hit_rate = (double)hits / accesses * 100.0;
    }
    printf("Total memory accesses: %d\n", accesses);
    printf("Cache hits: %d\n", hits);
    printf("Cache misses: %d\n", misses);
    printf("Cache hit rate: %.2f%%\n", hit_rate);
}