#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define IGNORE_VOWEL 1
/*
 * Author: Dan Jirasek
 * Program Name: QualityGen.c
 * Description: Prompts user for a txt file in the directory, 
 * reads character by character of file, and writes it to a new altered
 * version of the file. 	
*/
 int chLower(int * chr);
 void toCaps(int * c);
 void toMock(int * ch, unsigned long p);
 void rmvowel(int * ch, unsigned short * vval);
 
int main() 
{
	//create buffers to use for reading and writing
	FILE * rbuffer, * wbuffer;
	//strings for existing and new file names, respectively.
	char ifile[50], ofile[100] = "Quality",
	 wfilename[100] = "ofiles/", rfilename[100] = "ifiles/";
	//flag for remove vowel format. Used to ignore a vowel character.
	unsigned short vwlVal = 0;
	//prompt user for existing file name
	printf("Enter file name: ");
	scanf("%s", ifile);
	strcat(rfilename, ifile);
	//if file name could not be found, show error then end the program
	if((rbuffer = fopen(rfilename, "r")) == NULL)
	{
		perror("Error: File not found");
		return -1;
	}
	//could open file for reading, so proceed as normal
	else
	{
		//pos: Tracks the position of the current read in char from file
		//ch: integer value of character read in from rbuffer
		unsigned long pos = 0;
		int ch;
		char fmt[15];
		
		
		//prompt for the type of format for the new file
		printf("Enter quality format: \n\t1 for Mock\n\t2 for CAPS\n");
		printf("\t3 for no vowel format\n");
		scanf("%s", fmt);
		
		//create quality version filename that will be added to ofiles
		strcat(ofile, ifile);
		strcat(wfilename, ofile);
		
		//create quality version of file to write to
		wbuffer = fopen(wfilename, "w");
		
		// while the end of the original file has not been reached,
		// read in chars from file and write chars to new file
		while(feof(rbuffer) == 0)
		{
			ch = getc(rbuffer);
			switch(fmt[0]){
					case '1':
						toMock(&ch, pos);
						break;
					case '2':
						toCaps(&ch);
						break;
					case '3':
						rmvowel(&ch, &vwlVal);
						break;
					//create mock format if someone entered an invalid 
					//but still a single character
					default:
						toMock(&ch, pos);
			}
			pos++;
			if(vwlVal != 1)
				putc(ch, wbuffer);
			//reset vwlVal to not ignore char by default.
			vwlVal = 0;
		}
		//close buffers
		fclose(rbuffer);
		fclose(wbuffer);
		
		printf("The file %s has been created in ofiles\n", ofile);
	}

	return 0;
}


/*
 * Function: chLower()
 * parameters: int * chr: decimal value of character
 * return: 0 if upper case, 1 if lower case
 */
 int chLower(int * chr){
	 return ((*chr >= 'a')&&(*chr <= 'z'))? 1 : 0;
 } 
 
/*
 *  Function: toMock
 *  c: value of character as an integer.
 * 	Used for ALL CAPS format
 * 	function for converting character to upper case based on its decimal
 *  value.
 */
 void toCaps(int * c)
 {
	if((chLower(c)))
		*c = *c - 32;
 }

/*
 *  Function: toMock
 *  ch: value of character as an integer.
 * 	p: Position of char in file. Used for mock format
 * 	function for converting character to upper case based on position
 * 	in string.
 */
 void toMock(int * ch, unsigned long p)
 {
	if((chLower(ch))&&((p % 2) == 0))
		*ch = *ch - 32;
 }
 
 /*
 *  Function: rmvowel
 *  ch: pointer to a character read in from rbuffer.
 * 	vval: flag marked as 1 whenever the value of ch
 * 	Marks flag vval as 1 if the value pointed at by ch is a vowel.
 */
void rmvowel(int * ch, unsigned short * vval)
{
		switch(*ch)
		{
			case 'A':
				*vval = 1;
				break;
			case 'E':
				*vval = 1;
				break;
			case 'I':
				*vval = 1;
				break;
			case 'O':
				*vval = 1;
				break;
			case 'U':
				*vval = 1;
				break;
			case 'a':
				*vval = 1;
				break;
			case 'e':
				*vval = 1;
				break;
			case 'i':
				*vval = 1;
				break;
			case 'o':
				*vval = 1;
				break;
			case 'u':
				*vval = 1;
				break;
		}
		
}
