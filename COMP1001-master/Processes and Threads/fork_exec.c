


#include <stdlib.h>	/* needed to define exit() */
#include <unistd.h>	/* needed for fork() and getpid() */
#include <stdio.h>	/* needed for printf() */

void funct1(void);

int main() {

	
	int pid;	/* process ID */

	switch (pid = fork()) {
	case 0:		/* a fork returns 0 to the child */
		funct1();
		break;


	case -1:	/* something went wrong */
		perror("fork");
		exit(1);

	default:	/* a fork returns a pid to the parent */
		sleep(5);	/* sleep for 5 seconds */
		printf("Parent is still here!\n");
		break;

	}
	exit(0);
}

void funct1(void) {
	
	execlp("echo", "echo", "Cheers", "from child !", (char*)0);
	perror("execlp");	/* if we get here, execlp failed */
	exit(1);
}



