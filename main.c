#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>

int child() {
  printf("Child process %d started\n", getpid());
  int hold = rand() % 4 + 2;
  sleep(hold);
  printf("Child process %d finished\n", getpid());
  return hold;
}

int main() {
  printf("Beginning forking process\n");

  srand( time(NULL) );
  int one, two;

  one = fork();
  if (one == -1) printf("Child process error\n");

  if (one) {
    two = fork();
    if (two == -1) printf("Child process error\n");
  }

  if (one && two) {
    int status;
    printf("Child process %d slept for %d seconds and is now finished\n", wait(&status), WEXITSTATUS(status));
    printf("Parent process finished\n");
    return 0;
  }
  else if (!one) return child();
  else return child();
  return 0;
}
