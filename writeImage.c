#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "image.h"


int strLen(char*word){
	int ii = 0;
	while (word[ii] != '\0'){
		ii++;
	}
	return ii;
}

int main(int argc, char **argv)
{
	char identifier[] = {'I','I','F'};
	char width[3] = {(char)(WIDTH / (256*256)),(char)(WIDTH/256),(char)WIDTH};
	char height[3] = {(char)(HEIGHT / (256*256)),(char)(HEIGHT/256),(char)HEIGHT};

	unsigned char *data;
	char* fileName;
	
	if (argv[1] == NULL){
		fileName = "testi";
	}else{
		fileName = argv[1];
	}

	FILE *fileW = fopen(fileName, "wb");

	if (fileW == NULL)
	{
		printf("Cannot open file \033[31m%s\033[0m\n", argv[1]);
		return 1;
	}

	fwrite(identifier, 1, sizeof(identifier), fileW);
	fwrite(width, 1, sizeof(width), fileW);
	fwrite(height, 1, sizeof(height), fileW);
	fwrite(image, 1, sizeof(image), fileW);

	fclose(fileW);
}
