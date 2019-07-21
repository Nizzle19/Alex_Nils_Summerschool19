#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void outputT1(int i);

int main(int argc, char* argv[]) {
	// var
	//char text[];
	int count = 0;

	if (argc != 2) {
		printf("Need one argument to play.\n");
		exit(1);
	}

	printf("Argument is %s\n", argv[1]);

	char *t = argv[1];
	

	while (*t!='\0') { 
	t++; 
	if (*t != '\x20') count++;
	}


 	outputT1 (count);
  	return 0;
}


