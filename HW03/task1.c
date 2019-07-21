#include <stdio.h>
#include <string.h>

void outputT1(int i) { printf("%d ", i); }

int main (int argc, char* argv[])
{
    // var
    char text[256];
    int count = 0;
    //use input argument and combine it to string
    strcpy(text, argv[1]);
    for (int i = 2; i <argc; i=i+1)
	{
        strcat(text, argv[i]);
    }
    //counting Stringlength
    while (text[count] != '\0')
	{
  		count++;
    }
    
 	outputT1 (count);
  	return 0;
}


