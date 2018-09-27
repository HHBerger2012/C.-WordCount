#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int totalLines = 0;
int totalWords = 0;
int totalChars = 0;

void counter(char *fName)
{
	FILE *file;
	int numOfLines = 0;
	int numOfWords = 0;
	int numOfChars = 0;
	char currentChar;
	char lastChar = '\0';

	file = fopen(fName, "r");
	
	if(file) {
		while((currentChar = fgetc(file)) != EOF)
		{
			if(isspace(currentChar)) {
				if (currentChar == '\n')
					numOfLines++;
			}
			else {
				if (lastChar == '\0' || isspace(lastChar))
					numOfWords++;
			}	

			numOfChars++;
			lastChar = currentChar;
		}
	}
	else {
		printf("Count not open the specified file..");
	}

	totalLines += numOfLines;
	totalWords += numOfWords;
	totalChars += numOfChars;

	printf("%s: \n", fName);
	printf("Lines: %d \n", numOfLines);
	printf("Words: %d \n", numOfWords);
	printf("Chars: %d \n", numOfChars);

	fclose(file);
}

int main(int argc, char *argv[])
{
	int i;
	for(i = 1; i < argc; ++i) {
		counter(argv[i]);
	}
	
	printf("Total Lines: %d \n", totalLines);
	printf("Total Words: %d \n", totalWords);
	printf("Total Chars: %d \n", totalChars);

	return(0);
}
