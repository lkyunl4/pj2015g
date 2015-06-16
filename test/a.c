#include <stdio.h>

int main(){
	int x;
	char str[128];

	int buff_size = 1024;
	FILE* fp;
	fp = fopen("tmp", "r");
	printf("file pointer : %x\n", fp);

	fgets(str, 3, fp);
	printf("%s\n", str);
	fclose(fp);
	
	return 0;
}
