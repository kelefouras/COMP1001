 
/*
The fork system call allows us to clone a process. When fork() is called, the operating system creates a new clone process, i.e., a process creates a copy of itself. As soon as the fork call returns, both the parent and child are now running at the same point in the program. The only difference is that the child gets a different return value from fork. The parent gets the procsss ID of the child that was just created. The child gets a return of 0. If fork returns -1 then the operating system was unable to create the process. 

It is important to note that nothing is shared after the fork. Even though the child is running the same code and has the same files open, it maintains its own copy of all memory. If a child changes a memory location, the parent won't see the change (and vice versa). 

Task1. This is a small program that clones itself. The parent prints a message stating its process ID and the child's process ID. It gets its process ID via the getpid system call and it gets its child's process ID from the return of fork. The child prints its process ID. The parent and child then each exit. Note that exit takes a parameter. This becomes the exit code of the program. The convention for Unix systems is to exit with a code of zero on success and a non-zero on failure. This helps in scripting programs. 
*/



#include <stdlib.h>	/* needed to define exit() */
#include <unistd.h>	/* needed for fork() and getpid() */
#include <stdio.h>	/* needed for printf() */

int
main(int argc, char **argv) {
	int pid;	/* process ID */

	pid = fork();

	printf("\nHellow there\n");

	if (pid==0) { /* a fork returns 0 to the child */
		printf("I am the child process: pid=%d\n", getpid());
		}

	else if (pid==-1){	/* something went wrong */
		perror("fork");
		exit(1);}

	else{	/* a fork returns a pid to the parent */
		printf("I am the parent process: pid=%d, child pid=%d\n", getpid(), pid);
		}
	exit(0);
}


