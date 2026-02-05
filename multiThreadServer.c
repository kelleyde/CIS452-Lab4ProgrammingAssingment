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
int fileRequests = 0;

int main() {
    while(1){
    	pthread_t thread1;
	    char* arg1 = malloc(300);	
    	scanf("%s", arg1);
        pthread_create(&thread1, NULL, findFile, (void*)arg1);
        fileRequests++;
        pthread_detach(thread1);
        //free(arg1);
    }

    signal (SIGINT, sigHandler);
    return 0;
}

void* findFile (void* arg) {
    // pthread_detach(pthread_self());
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
