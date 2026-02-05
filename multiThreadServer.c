// File creation
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>

void* findFile (void* arg);
void sigHandler (int sigNum);

int main() {
    while (1) {
	void *result;
    	pthread_t thread1;
	
	char arg1[300];	
    //	char* arg1 = malloc[300];
    	scanf("%s", arg1);
    	thread1 = pthread_create (&thread1, NULL, findFile, (void*)arg1);
	
	// pthread_join(thread1, &result);
	
	signal (SIGINT, sigHandler);
    }
    
    // free char* arg1;
    return 0;
}

void* findFile (void* arg) {
    char* filename = (char*)arg;

    if (rand() % 100 < 80) {
        sleep(1);
    } else {
        sleep(7 + rand() % 4);
    }
    printf("File %s accessed\n", filename);
    return NULL;
}

void sigHandler (int sigNum)
{
 if(sigNum == SIGINT){
 printf ("Exit Gracefully\n");
 exit(0);
 }
}
