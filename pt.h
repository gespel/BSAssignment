#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
	int PID;
	int PPID;
	struct Process *prev;
	struct Process *next;
}Process;

Process *getLast(Process *root);
Process *createProcess(int pid);
void printProcess(Process *proc);
int append(Process *root, Process *new);
