#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){
    printf("%d about to create 2 child processes.\n", getpid());
    pid_t p1, p2;
    p1 = fork();
    if(p1<0){
        perror("fork fail");
        exit(1);
    }
    else if (p1==0){
        int random_number = open("/dev/random/", O_RDONLY);
        if (random_number == -1){
            printf("errno %d\n",errno);
            printf("%s\n",strerror(errno));
            exit(1);
        }
        unsigned char one_byte;
        read(random_number, &one_byte, 1);
        close(random_number);

        int random_seconds = (one_byte%5) + 1;
        printf("%d %d sec\n", getpid(), random_seconds);
        sleep(random_seconds);
        printf("%d finished after %d seconds\n", getpid(), random_seconds);
        exit(random_seconds);
    }
    p2 = fork();
    

        

    }

}