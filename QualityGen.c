#include <stdio.h>
#include <stdlib.h>
/*
	Author: Dan Jirasek
	Program Name: QualityGen.c
	Description: Prompts user for a txt file in the directory, reads character 		by character of file, converts respective character according to position 		in string to upper case, and writes it to a new file. 
	
*/
int main() 
{
	/*
		TODO:
		-Add function for reading in text of existing file, char by char
		-Add function for writing characters to new file
		-Create function for converting character to upper-case w/o toUpper()
		-use function to alter characters before written to buffer for writing
	*/
	char str[50];
	printf("Enter file name: ");
	scanf("%s", str);
	printf("%s\n", str);
	
	
	
	
	
	return 0;
}
