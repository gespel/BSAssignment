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
void printAll(Process *root) {
	Process *tmp = root;
	printProcess(tmp);
	while(tmp->next != NULL) {
		tmp = tmp->next;
		printProcess(tmp);
	}
}
int delete(Process *root, int dPID) {
	if(dPID == 1) {
		fprintf(stderr, "Root Prozess kann nicht entfernt werden!\n");
		return -1;
	}
	Process *tmp = root;
	while(tmp->next != NULL) {
		if(tmp->PID == dPID) {
			break;
		}
		tmp = tmp->next;
	}
	if(tmp->next == NULL && tmp->PID != dPID) {
		fprintf(stderr, "PID ist nicht in der Liste!\n");
	}
	else if(tmp->next == NULL) {
		tmp->prev->next = NULL;
		free(tmp);
	}
	else {
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		free(tmp);
	}
	return 0;
}
int append(Process *root, Process *new) {
	if(new->PID == 1) {
		fprintf(stderr, "Den Masterprozess gibt es immer!\n");
	}
	Process *tmp = root;
	while(tmp->next != NULL) {
		if(tmp->next->PID > new->PID) {
			break;
		}
		else if(tmp->next->PID == new->PID) {
			fprintf(stderr, "Den Prozess mit der PID %d gibt es bereits!\n", new->PID);
			return -1;
		}
		tmp = tmp->next;
	}
	new->PPID = getLast(root)->PID;
	if(tmp->next != NULL) {
		Process *tmp2 = tmp->next;
		tmp2->prev = new;
		new->next = tmp2;
		new->prev = tmp;
		tmp->next = new;
	}
	else {
		tmp->next = new;
		new->prev = tmp;
	}
	return 0;
}
