#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>
//1
#define SIZE 40
char* getss(char* string, unsigned int n);
int main(void)
{
	char string[SIZE];
	getss(string, SIZE);
	puts(string);
	return 0;
}
char* getss(char* string, unsigned int n)
{
	fgets(string, n + 1, stdin);
	return string;
}
//2
#define SIZE 40
char* getss(char* string, unsigned int n);
int main(void)
{
	char string[SIZE];
	getss(string, SIZE);
	puts(string);
	return 0;
}
char* getss(char* string, unsigned int n)
{
	fgets(string, n + 1, stdin);
	while (*string)/*注意是元素为空字符而不是指针！*/
	{
		if (*string == ' ' || *string == '\n' || *string == '\t' || *string == '\v')
			* string = '\0';
		if (*string == '\0')
			while (getchar() != '\n')
				continue;
		string++;
	}
	return string;
}
//3
#define SIZE 40
void getss(char* string);
int main(void)
{
	int i;
	char string[SIZE];
	getss(string);
	puts(string);
	return 0;
}
void getss(char* string)
{
	char ch = 0;
	int i = 0;
	do
	{
		ch = getchar();
		if (!isblank(ch))
			break;
	} while (1);
	string[i++] = ch;
	do
	{
		ch = getchar();
		if (isblank(ch))
			break;
		string[i++] = ch;
	} while (1);
	string[i] = '\0';
	return;
}
//4
#define SIZE 40
void gets_s(char* string, unsigned int num);
int main(void)
{
	int i;
	char string[SIZE];
	getss(string, SIZE);
	puts(string);
	return 0;
}
void gets_s(char* string, unsigned int num)
{
	char ch = 0;
	int i = 0;
	do
	{
		ch = getchar();
		if (!isblank(ch))
			break;
	} while (1);
	string[i++] = ch;
	do
	{
		ch = getchar();
		if (isblank(ch))
			break;
		string[i++] = ch;
		if (i >= num - 1)
			break;
	} while (1);
	string[i] = '\0';
	return;
}
//5
#define SIZE 4
char* strchr(char* string, char ch, int num);
int main(void)
{
	int i;
	char string[SIZE];
	char* find;
	for (i = 0; i < SIZE - 1; i++)
		scanf("%c", &string[i]);
	find = strchr(string, 'c', i);
	*find = 'C';
	for (i = 0; i < SIZE; i++)
		printf("%c", string[i]);
	return 0;
}
char* strchr(char* string, char ch, int num)
{
	int i = 0;
	while (i < num)
	{
		if (string[i] == ch)
			return string;
		i++;
	}
	return NULL;
}
//6
#define SIZE 40
int is_within(char* string, char ch);
int main(void)
{
	int i;
	char string[SIZE];
	fgets(string, SIZE, stdin);
	i = is_within(string, 'c');
	printf("%d", i);
	return 0;
}
int is_within(char* string, char ch)
{
	while (*string)
	{
		if (*string++ == ch)
			return 1;
	}
	return 0;
}
//7
#define SIZE 10
char* mystrncpy(char* string1, char* string2, unsigned int n);
int main(void)
{
	int index;
	char string1[SIZE];
	char string2[SIZE];
	fgets(string2, SIZE, stdin);
	mystrncpy(string1, string2, SIZE);
	puts(string1);
	return 0;
}
char* mystrncpy(char* string1, char* string2, unsigned int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		string1[i] = string2[i];
		if (!string1[i])
			return string1;
	}
	if (string1[i])
		return string1;
}
//8
#define SIZE 10
char* string_in(char* string1, char* string2);
int main(void)
{
	int index;
	char string1[SIZE];
	char string2[SIZE];
	char* find;
	fgets(string2, SIZE, stdin);
	fgets(string1, SIZE, stdin);
	find = string_in(string1, string2);
	*find = 'O';
	puts(string1);
	return 0;
}
char* string_in(char* string1, char* string2)
{
	int i = 0;
	int j = 0;
	int len1 = strlen(string1);
	int len2 = strlen(string2);
	for (int l = 0; l < len1; l++)
	{
		i = l;
		j = 0;
		while (string1[i] == string2[j])
		{
			i++;
			j++;/*当第一个字符相同时，l在for循环中被储存下来，i，j在内层循环中同时递增*/
			if (j >= len2)
				return &string1[l];
		}
	}
	return NULL;
}
//9
void rev(char* string);
int main(void)
{
	char string[10];
	printf("Enter a string of character,must less than 10 letter:");
	fgets(string, 10, stdin);
	rev(string);
	printf("And here is the reverse:");
	puts(string);
	return 0;
}
void rev(char* string)
{
	int len = strlen(string);
	int size = len - 1;
	char temp;
	for (int i = 0; i < len / 2; i++)
	{
		temp = string[i];
		string[i] = string[size - i];
		string[size - i] = temp;
	}
}
//10
void deleteblank(char* string);
int main(void)
{
	char string[10];
	printf("Enter a string of character,must less than 10 letter:");
	fgets(string, 10, stdin);
	deleteblank(string);
	printf("And here is the blank_deleted string:");
	puts(string);
	return 0;
}
void deleteblank(char* string)
{
	int len = strlen(string);
	int size = len - 1;
	char temp;
	int m = 0;
	for (int i = 0; i < len; i++)
	{
		if (isspace(string[i]))
			continue;/*遇到空格就跳过*/
		string[m++] = string[i];/*其他字符照样保留*/
	}
	string[m] = '\0';/*新字符串最后一个字符设为空字符*/
	return;
}
//11
#define SIZE 10
#define LENTH 81
void menu(void);
void asciiorder(char* string[], int num);/*字符串(相当于指针）数组*/
void heighorder(char* string[], int num);
int firstwordlenfinder(char* string);
void reorder(char* string[], int num);
int main(void)
{
	int index;
	int option;
	char re[SIZE][LENTH];
	char* temp[SIZE];
	printf("Let's begin--Enter %d strings:\n", SIZE);
	for (index = 0; index < SIZE; index++)
		fgets(re[index], LENTH, stdin);
	while (1)
	{
		while (getchar() != '\n')
			continue;
		menu();
		scanf("%d", &option);
		while (getchar() != '\n')
			continue;
		switch (option)
		{
		case 1: {printf("Here is the original strings:\n");
			for (index = 0; index < SIZE; index++)
				fputs(re[index], stdout); }break;
		case 2: {for (index = 0; index < SIZE; index++)
			temp[index] = re[index];
			asciiorder(temp, SIZE);
			printf("Here is the ascii-ordered strings:\n");
			for (index = 0; index < SIZE; index++)
				fputs(temp[index], stdout); }; break;
		case 3: {for (index = 0; index < SIZE; index++)
			temp[index] = re[index];
			heighorder(temp, SIZE);
			printf("Here is the ascii-ordered strings:\n");
			for (index = 0; index < SIZE; index++)
				fputs(temp[index], stdout); }; break;
		case 4:
		{for (index = 0; index < SIZE; index++)
			temp[index] = re[index];
		reorder(temp, SIZE);
		printf("Here is the re-ordered strings:\n");
		for (index = 0; index < SIZE; index++)
			fputs(temp[index], stdout); }; break;
		case 5:break;
		}
		if (option == 5)
			break;
		else
		{
			printf("Let's begin--Enter %d strings:\n", SIZE);
			for (index = 0; index < SIZE; index++)
				fgets(re[index], LENTH, stdin);
		}
	}
	printf("That's all.\n");
	return 0;
}
void menu(void)
{
	printf("HERE IS THE FUNCTION OF THIS PROJECT:\n");
	printf("1.Show the original strings:\n"
		"2.Show the strings in ASCII order:\n"
		"3.Show the strings by incremental heigh:\n"
		"4.Show the strings according to the length of the first word of the string:\n"
		"5.Quit.\n");
	printf("Your options:");
}
void asciiorder(char* string[], int num)
{
	int a, b;
	char* temp;
	for (a = 0; a < num - 1; a++)
		for (b = a + 1; b < num; b++)
		{
			if (strcmp(string[a], string[b]))
			{
				temp = string[a];
				string[a] = string[b];
				string[b] = temp;
			}
		}
}
void heighorder(char* string[], int num)
{
	int a, b;
	char* temp;
	for (a = 0; a < num - 1; a++)
		for (b = a + 1; b < num; b++)
		{
			if (strlen(string[a]) > strlen(string[b]))
			{
				temp = string[a];
				string[a] = string[b];
				string[b] = temp;
			}
		}
}
int firstwordlenfinder(char* string)
{
	int length;
	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] == ' ')
		{
			return i;
			break;
		}
	}
	return strlen(string);
}
void reorder(char* string[], int num)
{
	int a, b;
	char* temp;
	for (a = 0; a < num - 1; a++)
		for (b = a + 1; b < num; b++)
		{
			if (firstwordlenfinder(string[a]) > firstwordlenfinder(string[b]))
			{
				temp = string[a];
				string[a] = string[b];
				string[b] = temp;
			}
		}
}
//12
#define SIZE 81
int words(char* string);
int uppers(char* string);
int lowers(char* string);
int puncts(char* string);
int digits(char* string);
int main(void)
{
	int i = 0;
	char string[SIZE];
	char ch;
	printf("Please Enter a string,press Ctrl+Z to end up:");
	while ((ch = getchar()) != EOF || i == SIZE)
	{
		string[i] = ch;
		i++;
	}
	string[i] = '\0';
	printf("The string you have entered is:\n");
	for (i = 0; i < strlen(string); i++)
		putchar(string[i]);
	printf("\nThe string have %d words.\n", words(string));
	printf("The string have %d uppercase letter.\n", uppers(string));
	printf("The string have %d lowercase letter.\n", lowers(string));
	printf("The string have %d punctuations.\n", puncts(string));
	printf("The string have %d digits.\n", digits(string));
	return 0;
}
int words(char* string)
{
	bool space = true;
	int num;
	int word = 0;
	for (num = 0; num < strlen(string); num++)
	{
		if (space && !(isspace(string[num])) && !(ispunct(string[num])))
		{
			word++;
			space = false;
		}
		if (!space && (isspace(string[num])) || (ispunct(string[num])))
		{
			space = true;
		}
	}
	return word;
}
int uppers(char* string)
{
	int uppers = 0;
	for (int i = 0; i < strlen(string); i++)
	{
		if (isupper(string[i]))
			uppers++;
	}
	return uppers;
}
int lowers(char* string)
{
	int lowers = 0;
	for (int i = 0; i < strlen(string); i++)
	{
		if (islower(string[i]))
			lowers++;
	}
	return lowers;
}
int puncts(char* string)
{
	int puncts = 0;
	for (int i = 0; i < strlen(string); i++)
	{
		if (ispunct(string[i]))
			puncts++;
	}
	return puncts;
}
int digits(char* string)
{
	int digits = 0;
	for (int i = 0; i < strlen(string); i++)
	{
		if (isdigit(string[i]))
			digits++;
	}
	return digits;
}
//13
int main(int argc, char* argv[])
{
	int count;
	for (count = argc - 1; count >= 1; count--)
	{
		printf("%s ", argv[count]);
	}
	return 0;
}
