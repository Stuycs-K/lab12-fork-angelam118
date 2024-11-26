#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){
    printf("%d about to create 2 child processes.\n", getpid());
    pid_t p;
    p = fork();
    if(p<0){
        perror("fork fail");
        exit(1);
    }
    else if (p==0){
        int random_number = open("/dev/random/", O_RDONLY);
        if (random_number == -1){
            printf("errno %d\n",errno);
            printf("%s\n",strerror(errno));
            exit(1);
        }
        

    }

}