#include "pt.h"

int main() {
	Process *root = createProcess(1);
	Process *emacs = createProcess(2);
	Process *vim = createProcess(3);
	Process *nano = createProcess(4);
	
	append(root, nano);
	append(root, emacs);
	append(root, vim);
	
	printProcess(root);
	printProcess(root->next);
	printProcess(root->next->next);
	printProcess(getLast(root));

	return 0;
}
