#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH ((long long)5)
#define HEIGHT ((long long)5)

int strLen(char*word){
	int ii = 0;
	while (word[ii] != '\0'){
		ii++;
	}
	return ii;
}

int main(int argc, char **argv)
{
	char image[HEIGHT * WIDTH] = {
		255, 255, 255, 255, 255,
		255,   0, 255,   0, 255,
		255, 255, 255, 255, 255,
		255,   0,   0,   0, 255,
		255, 255, 255, 255, 255
	};

	char identifier[] = {'I','I','F'};
	char width[3] = {(char)(WIDTH / (256*256)),(char)(WIDTH/256),(char)WIDTH};
	char height[3] = {(char)(HEIGHT / (256*256)),(char)(HEIGHT/256),(char)HEIGHT};

	unsigned char *data;
	char* fileName;
	
	if (argv[1] == NULL){
		fileName = (char*)malloc(strLen("testi")*sizeof(char));
		fileName = "testi";
	}else{
		fileName = (char*)malloc(strLen(argv[1])*sizeof(char));
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
	char moi[] = "01234567890123456789";

	printf("1 %ld\n", sizeof("Moi"));
	printf("2 %ld\n", sizeof(char*));
	printf("3 %ld\n", sizeof("Moi"));
	printf("4 %ld\n", sizeof(moi));
	printf("5 %ld\n", sizeof(image));

	fclose(fileW);
}
