#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Process {
	int PID;
	int PPID;
	struct Process *prev;
	struct Process *next;
}Process;

Process *getLast(Process *root);
Process *createProcess(int pid);
void printProcess(Process *proc);
void printAll(Process *root);
int append(Process *root, Process *new);
int delete(Process *root, int dPID);
