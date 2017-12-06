#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>

int main(int argc, char* argv[]) {
	
	int num = 0;
	int ds = 0;
	
	int KEY = 12345;

	if (argv[1] == NULL) {
		printf("Please enter in an argument.");
		exit(1);
	}
	
	if (strcmp(argv[1], "-c") == 0) {
		ds = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0600);
		num = atoi(argv[2]);
		if(!argv[2]){
			printf("-c requires a second command (integer)!\n");
			exit(0);
		}
		if (ds == -1) {
			printf("semaphore already exists\n");
			exit(1);
		}
		else {
			printf("semaphore created: %d\n", ds);
			printf("value set: %d\n", semctl(ds, 0, GETVAL));
			semctl(ds, 0, SETVAL, num);
		}
	}
	
	if (strcmp(argv[1], "-v") == 0) {
		ds = semget(KEY, 1, 0600);
		printf("semaphore value: %d\n", semctl(ds, 0, GETVAL));
	}
	
	if (strcmp(argv[1], "-r") == 0) {
		ds = semget(KEY, 1, 0600);
		printf("semaphore removed: %d\n", semctl(ds, 0, IPC_RMID));
	}
	
	return 0;
	
}