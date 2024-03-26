#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	const int headerLen = 9;

	unsigned char *data;
	FILE *fileR = fopen(argv[1], "rb");

	if (fileR == NULL)
	{
		printf("Cannot open file \033[31m%s\033[0m\n", argv[1]);
		return 1;
	}
	fseek(fileR, 0, SEEK_END);
	unsigned long length = ftell(fileR);
	fseek(fileR, 0, SEEK_SET);
	data = (char *)malloc(length*sizeof(data)+1);
	int fileReturn = fread(data, 1, length, fileR);
	if (length < headerLen){
		printf("Too small file");
		return 1;
	}
	// IIF = Ileska Image Format
	if (data[0] != 'I' && data[1] != 'I' && data[2] != 'F' ){
		printf("Format not regocnize");
		return 1;
	}

	int width = data[3] * 256 * 256 + data[4] * 256 + data[5];
	int height = data[6] * 256 * 256 + data[7] * 256 + data[8];
	// printf("width'%d'\n",width);
	// printf("height'%d'\n",height);
	if (width * height != length - headerLen){
		printf("Wrong amount of pixels. Pixels found %ld", length - headerLen);
		return 1;
	}
	for (long long int curH = 0; curH < height;curH++) {
		for (long long int curW = 0; curW < width;curW++) {
			printf("\033[48;2;%d;%d;%dm  ", data[headerLen + curH * width + curW],
					data[headerLen + curH * width + curW], data[headerLen + curH * width + curW]);
		}
		printf("\033[0m\n");
	}
	free(data);
	fclose(fileR);
}
