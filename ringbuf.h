#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int readIndex;
    int writeIndex;
    char *data;
    int size;
} ringbuf_t;

ringbuf_t *createRing(int size);
void deleteRing(ringbuf_t *buffer);
void append(char buchstabe, ringbuf_t *buffer);
void read(char *out, ringbuf_t *buffer, int size);
void readUntil(char *out, ringbuf_t *buffer, char end);
