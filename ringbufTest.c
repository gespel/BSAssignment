#include "ringbuf.h"
#include <string.h>

int main(int argc, char* argv[]) {
    ringbuf_t *buffer;
    buffer = createRing(200);
    for(int i = 1; i < argc; i++) {
        char *argu = argv[i];
        int argulen = strlen(argu);
        for(int j = 0; j < argulen; j++) {
            append(argu[j], buffer);
        }
        append(' ', buffer);
    }
    char *aus = malloc(200 * sizeof(char));
    readUntil(aus, buffer, '.');
    printf("%s", aus);
    free(aus);
    return 0;
}
