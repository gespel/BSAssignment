#include "pt.h"

Process *createProcess(int pid) {
	Process *new = malloc(sizeof(Process));
	new->PID = pid;
	if(pid == 1) {
		new->PPID = 0;
	}
	return new;
}
Process *getLast(Process *root) {
	Process *tmp = root;
	while(tmp->next != NULL) {
		tmp = tmp->next;
	}
	return tmp;
}
void printProcess(Process *proc) {
	printf("PID %d\tPPID %d\n", proc->PID, proc->PPID);
}
int append(Process *root, Process *new) {
	Process *tmp = root;
	while(tmp->next != NULL) {
		if(tmp->next->PID > new->PID) {
			break;
		}
		else if(tmp->next->PID == new->PID) {
			printf("FEHLER! Den Prozess mit der PID %d gibt es bereits!\n", new->PID);
			return -1;
		}
		tmp = tmp->next;
	}
	if(tmp->next != NULL) {
		Process *tmp2 = tmp->next;
		tmp->next->prev = new;
		new->next = tmp2;
	}
	tmp->next = new;
	new->PPID = getLast(root)->PID;
	return 0;
}
