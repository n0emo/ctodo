#ifndef SV_H
#define SV_H

#include <assert.h>
#include <stdlib.h>

#define array_len(arr) (sizeof(arr) / sizeof(arr[0]))

#define da_append(da, item)                                                                                            \
    do                                                                                                                 \
    {                                                                                                                  \
        if (da.count == da.capacity)                                                                                   \
        {                                                                                                              \
            if (da.items == NULL)                                                                                      \
            {                                                                                                          \
                da.capacity = INITIAL_CAP;                                                                             \
                da.items = malloc(sizeof(da.items[0]) * INITIAL_CAP);                                                  \
                da.count = 0;                                                                                          \
            }                                                                                                          \
            da.items = realloc(da.items, sizeof(da.items[0]) * da.capacity * 2);                                       \
            assert(da.items != NULL && "Buy more RAM lol");                                                            \
            da.capacity *= 2;                                                                                          \
        }                                                                                                              \
        da.items[da.count] = item;                                                                                     \
        da.count++;                                                                                                    \
    } while (0)

#endif // SV_H
