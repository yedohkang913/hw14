#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>

#define KEY 123455

int main(int argc, char* argv[]) {
	/*int i = 0;
	while(argv[i]){
		printf("argv[%d]: %s\n", i, argv[i]);
		i++;	
	}*/
	char * arg0;
	char * arg1;
	
	if(argv[1]){
		arg0 = argv[1];
	}
	else{
		printf("Please input a command!\n");
		exit(0);
	}
	if(argv[2]){
		arg1 = argv[2];
	}
	
	if (strcmp(arg0, "-c") == 0) {
		if(!argv[2]){
			printf("-c requires a second command (integer)!\n");
			exit(0);
		}
		
		int ds = semget(KEY, 1, IPC_CREAT | IPC_EXCL);
		if (ds != -1) {
			printf("semaphore created: %d\n", ds);
			printf("value set: 0\n");
			semctl(ds, 0, SETVAL, arg1);
		}
		else {
			printf("semaphore already exists\n");
		}
	}
	
	
}