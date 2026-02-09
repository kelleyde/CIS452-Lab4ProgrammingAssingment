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
int keepRunning = 1;

int main() {
    signal (SIGINT, sigHandler);

    while(keepRunning){
    	pthread_t thread1;
	    char* arg1 = malloc(300);	
    	
        if (scanf("%s", arg1) != 1){
            free(arg1);
            break;
        }

        int threadStatus = pthread_create(&thread1, NULL, findFile, (void*)arg1);
        if (threadStatus != 0) {
            fprintf(stderr, "Error creating thread\n");
            free(arg1);
            break;
        }

        fileRequests++;
        pthread_detach(thread1);
    }

    printf("The total number of file requests is %d\n", fileRequests);

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
    free(filename);

    return NULL;
}

void sigHandler (int sigNum)
{
    if(sigNum == SIGINT){
        printf ("Exit Gracefully\n");
        keepRunning = 0;
        printf("The total number of file requests is %d\n", fileRequests);
        exit(0);
    }
}
