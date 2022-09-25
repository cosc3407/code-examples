#include <stdio.h>
#include <unistd.h>
int main() {
   int x = fork(); //create child process
   if (x > 0) //if x is non zero, then it is parent process
      printf("Inside Parent---- PID is : %d\n", getpid());
   else if (x == 0) { //for chile process x will be 0
      sleep(5); //wait for some times
      x = fork();
      if (x > 0) {
         printf("Inside Child---- PID :%d and PID of parent : %d\n", getpid(), getppid());
         while(1)
            sleep(1);
         printf("Inside Child---- PID of parent : %d\n", getppid());
      }else if (x == 0)
      printf("Inside grandchild process---- PID of parent : %d\n", getppid());
   }
   return 0;
}
