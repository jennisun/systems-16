#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>

int main() {
  printf("About to begin forking process\n");

  srand( time(NULL) );
  int one = fork();
  printf("Child PID: %d\n", getpid());
  int two = fork();
  printf("Child PID: %d\n", getpid());

  if (one == -1 || two == -1) printf("Child process error\n");
  if (one && two) {
    int status;
    int hold = rand() % 4 + 2;
    sleep(hold);
    printf("Child process %d slept for %d and is now finished\n", wait(&status), WEXITSTATUS(status));
    return 0;
  }

  if (one || two) {
    int hold = rand() % 4 + 2;
    sleep(hold);
    printf("Child process %d finished\n", getpid());
    return hold;
  }


}
