#include "pt.h"

int main(int argc, char *argv[]) {
	Process *root = createProcess(1);
	for(int i = 1; i < argc; i++) {
		if(atoi(argv[i]) > 0) {
			Process *new = createProcess(atoi(argv[i]));
			append(root, new);
		}
		else if(atoi(argv[i]) < 0) {
			delete(root, abs(atoi(argv[i])));
		}
		else {
			fprintf(stderr, "%s ist keine Zahl. Ignoriere!\n", argv[i]);
		}
	}
	printAll(root);
	printf("\n");
	deleteAll(root);
	return 0;
}
