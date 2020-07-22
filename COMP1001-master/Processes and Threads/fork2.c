


#include <stdlib.h>	/* needed to define exit() */
#include <unistd.h>	/* needed for fork() and getpid() */
#include <stdio.h>	/* needed for printf() */

int
main(int argc, char **argv) {
	int pid;	/* process ID */
 	int a=1, b=0;


	pid = fork();

	a++;
	printf("\nJust after fork a=%d - b=%d\n",a,b);

	switch (pid) {
	case 0:		/* a fork returns 0 to the child */
		printf("I am the child process: pid=%d\n", getpid());
		a++; b--;
		printf("\nIn child process a=%d\n",a);
		break;


	case -1:	/* something went wrong */
		perror("fork");
		exit(1);

	default:	/* a fork returns a pid to the parent */
		printf("I am the parent process: pid=%d, child pid=%d\n", getpid(), pid);
		a++; b++;
		printf("\nIn parent process a=%d\n",a);
		break;
	}

	printf("\nJust before end a=%d - b=%d\n",a,b);

	exit(0);
}


