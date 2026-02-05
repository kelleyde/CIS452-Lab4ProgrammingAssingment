// File creation
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* findFile (void* arg);

int main() {
    pthread_t thread1;
    char arg1[300];
    scanf("%s", arg1);
    thread1 = pthread_create (&thread1, NULL, findFile, (void*)arg1);
}