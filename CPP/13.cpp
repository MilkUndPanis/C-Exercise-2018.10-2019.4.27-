#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
//1
int main(void)
{
	int i;
	char filename[40];
	char ch;
	unsigned long int count = 0;
	FILE* fp;
	printf("Enter a file name,press Ctrl+Z to end up:");
	for (i = 0; i < 40; i++)
	{
		while ((filename[i] = getchar()) == EOF)
			goto flag;
	}
flag:filename[i] = '\0';
	printf("This is the file name:");
	puts(filename);
	if ((fp = fopen(filename, "r+")) == NULL)
	{
		printf("Can't open file %s", filename);
		fprintf(stderr, "Error opening file\n");
		exit(EXIT_FAILURE);
	}
	else while ((ch = getchar()) != '\n')
		putc(ch, fp);
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file\n");
	return 0;
}
//2
int main(int argc, char* argv[])
{
	FILE* in, * out;
	char ch;
	if (argc < 2)
	{
		printf("Usage %s character filename.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((in = fopen(argv[1], "r+")) == NULL)
	{
		fprintf(stderr, "Cannot open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((out = fopen(argv[1], "a+")) == NULL)
	{
		fprintf(stderr, "Cannot open file %s", argv[2]);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(in)) != EOF)
	{
		putc(ch, out);
	}
	if (fclose(in) != 0)
	{
		fprintf(stderr, "Cannot close file %s", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (fclose(out) != 0)
	{
		fprintf(stderr, "Cannot close file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	return 0;
}
//3
int main(void)
{
	char ch;
	char filename[40];
	FILE* fp;
	int i;
	printf("Please enter a filename,press Ctrl+Z to quit:");
	for (i = 0; i < 40; i++)
	{
		while ((filename[i] = getchar()) == EOF)
			goto flag;
	}
flag:filename[i] = '\0';
	if ((fp = fopen(filename, "w+")) == NULL)
	{
		fprintf(stderr, "Cannot open file %s", filename);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		toupper(ch);
		putc(ch, fp);
	}
	if (fclose(fp) != 0)
	{
		fprintf(stderr, "Cannot close file %s", filename);
		exit(EXIT_FAILURE);
	}
	return 0;
}
//4
int main(int argc, char* argv[])
{
	FILE* fp;
	int i;
	char ch;
	for (i = 1; i < argc; i++)
	{
		if ((fp = fopen(argv[i], "r")) == NULL)
		{
			fprintf(stderr, "Cannot open file %s", argv[i]);
			exit(EXIT_FAILURE);
		}
		while ((ch = getc(fp)) != EOF)
			putc(ch, stdout);
		if (fclose(fp) != 0)
		{
			fprintf(stderr, "Cannot close file %s", argv[i]);
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}
//5
#define BUFSIZE 4096
#define SLEN 81
void append(FILE * source, FILE * dest);
int main(int argc, char* argv[])
{
	FILE* fap, * fsr;
	int ch;
	printf("Use %s to get source,and destination file is %s.", argv[1], argv[2]);
	if ((fap = fopen(argv[1], "a+")) == NULL)
	{
		fprintf(stderr, "Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (strcmp(argv[1], argv[2]) == 0)
	{
		fprintf(stderr, "Can't append file to itself\n");
		exit(EXIT_FAILURE);
	}
	if ((fsr = fopen(argv[2], "a+")) == NULL)
	{
		fprintf(stderr, "Can't open file %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	if ((setvbuf(fap, NULL, _IOFBF, BUFSIZE)) != 0)
	{
		fprintf(stderr, "Can't create a new buffer\n");
		exit(EXIT_FAILURE);
	}
	if ((setvbuf(fsr, NULL, _IOFBF, BUFSIZE)) != 0)
	{
		fprintf(stderr, "Can't create a new buffer\n");
		exit(EXIT_FAILURE);
	}
	append(fsr, fap);
	if (ferror(fsr) != 0)
		fprintf(stderr, "Error in reading file %s", argv[2]);
	if (ferror(fap) != 0)
		fprintf(stderr, "Error in reading file %s", argv[1]);
	if (fclose(fsr) != 0)
	{
		fprintf(stderr, "Cannot close source file.\n");
		exit(EXIT_FAILURE);
	}
	printf("File appended successfully.\n");
	rewind(fap);
	printf("%s contents:\n", argv[1]);
	while ((ch = getc(fap)) != EOF)
		putchar(ch);
	puts("Done displaying.\n");
	if (fclose(fap) != 0)
	{
		fprintf(stderr, "Cannot close source file.\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}
void append(FILE* source, FILE* dest)
{
	size_t bytes;
	static char temp[BUFSIZE];
	while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
}
//6
#define LEN 40
int main(void)
{
	FILE* in, * out;
	int ch;
	int i;
	char src[LEN];
	char des[LEN];
	int count = 0;
	printf("Enter a source file name,press Ctrl+Z to end up:");
	for (i = 0; i < LEN; i++)
	{
		while ((src[i] = getchar()) == EOF)
			goto flag1;
	}
flag1:src[i] = '\0';
	printf("This is the file name:");
	puts(src);
	printf("Enter a destination file name,press Ctrl+Z to end up:");
	for (i = 0; i < LEN; i++)
	{
		while ((des[i] = getchar()) == EOF)
			goto flag2;
	}
flag2:des[i] = '\0';
	printf("This is the file name:");
	puts(des);
	if ((in = fopen(src, "r+")) == NULL)
	{
		fprintf(stderr, "Can't open file %s", src);
		exit(EXIT_FAILURE);
	}
	if ((out = fopen(des, "w")) == NULL)
	{
		fprintf(stderr, "Can't open file %s", des);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out);
	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Cannot close file.\n");
	return 0;
}
//7
#define LEN 40
int main(void)
{
	FILE* in, * out;
	int ch;
	int i;
	char one[LEN];
	char two[LEN];
	int count = 0;
	int lines_1 = 0, lines_2 = 0;
	int morel = 0, lessl = 0;
	bool where = 0;
	printf("Enter a source file name,press Ctrl+Z to end up:");
	for (i = 0; i < LEN; i++)
	{
		while ((one[i] = getchar()) == EOF)
			goto flag1;
	}
flag1:one[i] = '\0';
	printf("This is the file name:");
	puts(one);
	printf("Enter a destination file name,press Ctrl+Z to end up:");
	for (i = 0; i < LEN; i++)
	{
		while ((two[i] = getchar()) == EOF)
			goto flag2;
	}
flag2:two[i] = '\0';
	printf("This is the file name:");
	puts(two);
	if ((in = fopen(one, "r+")) == NULL)
	{
		fprintf(stderr, "Can't open file %s", one);
		exit(EXIT_FAILURE);
	}
	if ((out = fopen(two, "w")) == NULL)
	{
		fprintf(stderr, "Can't open file %s", two);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(in)) != EOF)
	{
		if (ch == '\n')
			lines_1++;
	}
	while ((ch = getc(out)) != EOF)
	{
		if (ch == '\n')
			lines_2++;
	}
	printf("The file %s has %d lines.", one, lines_1);
	printf("The file %s has %d lines.", two, lines_2);
	morel = fmax((double)lines_1, (double)lines_2);
	lessl = fmin((double)lines_1, (double)lines_2);
	if (morel = lines_1)
		where = 1;
	else where = 0;
	for (i = 1; i <= lessl; i++)
	{
		printf("file 1 line %d", i);
		while ((ch = getc(in)) != '\n')
			putc(ch, stdout);
		putchar('\n');
		printf("file 2 line %d", i);
		while ((ch = getc(out)) != '\n')
			putc(ch, stdout);
		putchar('\n');
	}
	for (i = lessl + 1; i <= morel; i++)
	{
		if (where)
		{
			printf("file 1 line %d", i);
			while ((ch = getc(in)) != '\n')
				putc(ch, stdout);
			putchar('\n');
		}
		else
		{
			printf("file 2 line %d", i);
			while ((ch = getc(out)) != '\n')
				putc(ch, stdout);
			putchar('\n');
		}
	}
	printf("Printed successfully.\n");
	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Cannot close file.\n");
	return 0;
}
//8
int main(int argc, char* argv[])
{
	FILE* fp;
	char ch;
	int cha;
	int i;
	int charcount;
	ch = argv[1][0];
	if (argc == 1)
	{
		fp = stdin;
		charcount = 0;
		while ((cha = getc(fp)) != EOF)
		{
			if (cha == ch)
				charcount++;
		}
		printf("The input stream has %d %cs.\n", charcount, ch);
	}
	else
		for (i = 1; i < argc; i++)
		{
			if ((fp = fopen(argv[i], "r")) == NULL)
			{
				fprintf(stderr, "Cannot open file %s.\n", argv[i]);
				continue;
			}
			printf("File %d,file name:%s.", i, argv[i]);
			charcount = 0;
			while ((cha = getc(fp)) != EOF)
			{
				if (cha == ch)
					charcount++;
			}
			printf("This file has %d %cs.\n", charcount, ch);
			if (fclose(fp) != 0)
				fprintf(stderr, "Cannot close file %d %s.\n", i, argv[i]);
		}
	printf("Done successfully.\n");
	return 0;
}
//9
#define MAX 41
int number = 0;/*没有任何办法*/
int main(void)
{
	FILE* fp;
	char words[MAX];
	int ch;
	if ((fp = fopen("wordy", "a+")) == NULL)
	{
		fprintf(stderr, "Cannot open file .\n");
		exit(EXIT_FAILURE);
	}
	puts("Enter words to add to the file;press the #");
	puts("key at the beginning of aline to terminate.");
	while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
	{
		number++;
		fprintf(fp, "%d:%s\n", number, words);
	}
	puts("File contents:");
	rewind(fp);
	while ((ch = getc(fp)) != EOF)
		putc(ch, stdout);
	puts("Done!");
	if (fclose(fp) != 0)
		fprintf(stderr, "Cannot close file\n");
	return 0;
}
//10
int main(void)
{
	FILE* fp;
	int i;
	char filename[40];
	unsigned int location;
	int ch;
	printf("Enter a file name,press Ctrl+Z to end up:");
	for (i = 0; i < 40; i++)
	{
		while ((filename[i] = getchar()) == EOF)
			goto flag;
	}
flag:filename[i] = '\0';
	printf("This is the file name:");
	puts(filename);
	if ((fp = fopen(filename, "r+")) == NULL)
	{
		printf("Can't open file %s", filename);
		fprintf(stderr, "Error opening file\n");
		exit(EXIT_FAILURE);
	}
	printf("Enter a location:");
	while ((scanf("%d", &location)) == 1)
	{
		fseek(fp, location, SEEK_SET);
		while ((ch = getc(fp)) != '\n')
		{
			putc(ch, stdout);
		}
		printf("DONE.Next location:");
	}
	if (fclose(fp) == NULL)
	{
		fprintf(stderr, "Error closing file\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}
//11
int main(int argc, char* argv[])
{
	char contents[256];
	FILE* fp;
	if (argc != 3)
	{
		printf("Usage:%s<string><file_name>\n", argv[0]);
	}
	if ((fp = fopen(argv[2], "r")) == NULL)
		fprintf(stderr, "Can't open the file %s.\n", argv[2]);
	while ((fgets(contents, 256, fp)) != NULL)
	{
		if (strstr(contents, argv[1]) != NULL)
			fputs(contents, stdout);
	}
	return 0;
}
//12
/*如果输入得当的话，这个程序应该没问题*/
char change(char ptr);
int main(void)
{
	char photo[20][31];
	char photol[20][31];
	int i, j;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 30; j++)
		{
			scanf("%c", &photo[i][j]);
		}
		photo[i][30] = '\0';
	}
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 30; j++)
		{
			photol[i][j] = change(photo[i][j]);
		}
	}
	for (i = 0; i < 20; i++)
	{
		puts(photol[i]);
	}
	return 0;
}
char change(char ptr)
{
	char word;
	if (ptr == 0)
		word = ' ';
	else if (ptr == '1')
		word = '.';
	else if (ptr == '2')
		word = '\'';
	else if (ptr == '3')
		word = ':';
	else if (ptr == '4')
		word = '~';
	else if (ptr == '5')
		word = '*';
	else if (ptr == '6')
		word = '=';
	else if (ptr == '7')
		word = '\\';
	else if (ptr == '8')
		word = '%';
	else if (ptr == '9')
		word = '#';
	return word;
}
//13.14.心态已爆炸，略
