#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int child(){
  FILE * rand = fopen("/dev/random", "r");
  unsigned int randBytes;
  if(rand){
    fread(&randBytes, sizeof(int),1,rand);
    fclose(rand);

    randBytes %= 5;
    randBytes++;
  }
  else{
    perror(strerror(errno));
  }
  printf("%d sleeping for %d\n", getpid(), randBytes);

  sleep(randBytes);
  printf("%d finished after %d sec\n", getpid(), randBytes);
  exit(randBytes);
}

int main(){
    printf("%d now spawning 2 child processes\n", getpid());
    int kidid;
    if(kidid=fork()){ //parent
      if(kidid<0){
        perror(strerror(errno));
      }
      if(kidid = fork()){
        if(kidid<0){
          perror(strerror(errno));
        }
      }
      else{
        child();
      }

      int status;
      kidid = wait(&status);
      printf("Main Process %d is done. Child %d slept for %d sec\n",
        getpid(),kidid, WEXITSTATUS(status));
      //end parent
    }


    else {
      child();
    }

}
