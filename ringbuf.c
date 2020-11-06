#include "ringbuf.h"

ringbuf_t *createRing(int size) {
    ringbuf_t *buffer = (ringbuf_t *)malloc(sizeof(ringbuf_t));

    buffer->readIndex = 0;
    buffer->writeIndex = 0;
    buffer->data = (char *)malloc(sizeof(char) * (size + 1));
    buffer->size = size;

    return buffer;
}
void deleteRing(ringbuf_t *buffer) {
    free(buffer->data);
    free(buffer);
}
void append(char buchstabe, ringbuf_t *buffer) {
    if(buffer) {
        //printf("%d:%c\n", buffer->writeIndex, buchstabe);
    	buffer->data[buffer->writeIndex] = buchstabe;
        buffer->writeIndex += 1;
        buffer->writeIndex %= (buffer->size+1);
        if(buffer->readIndex == buffer->writeIndex) {
            buffer->readIndex += 1;
    	    buffer->readIndex %= (buffer->size+1);
        }
    }
}
void read(char *out, ringbuf_t *buffer, int size) {
    if(buffer) {
        for(int i = 0; i < size; i++) {
            if(buffer->readIndex != buffer->writeIndex) {
                //printf("%d:%c\n", buffer->readIndex, buffer->data[buffer->readIndex]);
                out[i] = buffer->data[buffer->readIndex];
                buffer->readIndex = ++buffer->readIndex % (buffer->size+1);
            }
            else {
                fprintf(stderr, "Buffer ist leer an der Stelle %d!\n", buffer->readIndex);
                return;
            }
        }
    }
    else {
        fprintf(stderr, "Buffer existiert nicht!\n");
    }
}
void readUntil(char *out, ringbuf_t *buffer, char end) {
    if(buffer) {
        int i = 0;
        while(buffer->data[i] != end) {
            if(buffer->readIndex != buffer->writeIndex) {
                //printf("%d:%c\n", buffer->readIndex, buffer->data[buffer->readIndex]);
                out[i] = buffer->data[buffer->readIndex];
                buffer->readIndex = ++buffer->readIndex % (buffer->size+1);
                i++;
            }
            else {
                fprintf(stderr, "Buffer ist leer an der Stelle %d!\n", buffer->readIndex);
                return;
            }
        }
        out[i] = end;
    }
    else {
        fprintf(stderr, "Buffer existiert nicht!\n");
    }
}
