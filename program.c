#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int main(){
    printf("%d now spawning 2 child processes\n", getpid());
    int kidid;
    if(kidid=fork()){ //parent
      if(kidid<0){
        perror("%s", strerror(errno));
      }

      if(kidid = fork()){
        if(kidid<0){
          perror("%s", strerror(errno));
        }
      }
      int status;
      wait(&status);
    }

    //child
    FILE * rand = fopen("/dev/random", "r");
    
}
