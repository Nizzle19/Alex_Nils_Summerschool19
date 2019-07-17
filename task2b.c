#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


void outputT2(int i);


int main(int argc, char* argv[]){
    int k;
	int int_val;
	int p;

	if (argc != 2) {
		printf("Need one argument to play.\n");
		exit(1);
	}
	   
	int arg1 = atoi(argv[1]); // argv[0] is the program name
	
	if (arg1 < 0) {
		printf("The argument has to be positiv (including 0).\n");
		exit(1);
	}
		printf("Argument is %d\n", arg1);

for (k = 0; k <= arg1; k++) {
outputT2(k);
}

return 0;
}