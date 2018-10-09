#include <stdio.h>
#include <stdlib.h>

void ler_arquivo(){
	FILE *fileptr;
	char *buffer;
	long filelen;

	fileptr = fopen("sample.wav", "rb");  // Open the file in binary mode
	fseek(fileptr, 0, SEEK_END);          // Jump to the end of the file
	filelen = ftell(fileptr);             // Get the current byte offset in the file
	rewind(fileptr);                      // Jump back to the beginning of the file

	buffer = (char *)malloc((filelen+1)*sizeof(char)); // Enough memory for file + \0
	fread(buffer, filelen, 1, fileptr); // Read in the entire file
	fclose(fileptr); // Close the file
	printf("%s\n", buffer);
	return;
}

int main()
{
	ler_arquivo();
	return 0;
}