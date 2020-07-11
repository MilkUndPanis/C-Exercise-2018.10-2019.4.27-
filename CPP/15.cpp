#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
//1
int trans(char* pbin);
int main(void)
{
	char pbin[] = "01001001";
	int dec;
	dec = trans(pbin);
	printf("%d", dec);
	return 0;
}
int trans(char* pbin)
{
	int length;
	int number;
	length = strlen(pbin);
	int dec = 0;
	int j;
	for (int i = length - 1, j = 0; i >= 0, j < length; i--, j++)
	{
		if (pbin[j] == '0')
			number = 0;
		else number = 1;
		dec += pow(2, i) * number;
	}
	return dec;
}
//2
int main(int argc, char* argv[])
{
	int length1, length2;
	length1 = strlen(argv[1]);
	length2 = strlen(argv[2]);/*The argv[0] string is the name of this file;*/
	int* result[5];
	int* number1 = (int*)malloc(length1 * sizeof(int));
	int* number2 = (int*)malloc(length2 * sizeof(int));
	for (int i = 0; i < length1; i++)
	{
		if (argv[1][i] == '0')
			number1[i] = 0;
		if (argv[1][i] == '1')
			number1[i] = 1;
	}
	for (int i = 0; i < length2; i++)
	{
		if (argv[2][i] == '0')
			number2[i] = 0;
		if (argv[2][i] == '1')
			number2[i] = 1;
	}
	for (int i = 0; i < length1; i++)
		result[0][i] = ~number1[i];
	for (int i = 0; i < length2; i++)
		result[1][i] = ~number2[i];
	for (int i = 0; i < (int)fmin(length1, length2); i++)
	{
		result[2][i] = number1[i] & number2[i];
		result[3][i] = number1[i] | number2[i];
		result[4][i] = number1[i] ^ number2[i];
	}
	char* results[5];
	for (int i = 0; i < length1; i++)
	{
		if (result[0][i] == '1')
			results[0][i] = 1;
		if (!result[0][i] == '0')
			results[0][i] = 0;
	}
	results[0][length1] = '\0';
	for (int i = 0; i < length2; i++)
	{
		if (result[1][i] == '1')
			results[1][i] = 1;
		if (!result[1][i] == '0')
			results[1][i] = 0;
	}
	results[1][length1] = '\0';
	for (int i = 2; i < 5; i++)
	{
		for (int j = 0; j < (int)fmin(length1, length2); j++)
		{
			if (result[i][j])
				results[i][j] = 1;
			if (!result[i][j])
				results[i][j] = 0;
		}
		results[i][(int)fmin(length1, length2)] = '\0';
	}
	printf("This is the result of four bit_operating:");
	printf("~:%s,%s", results[0], result[1]);
	printf("&:%s", result[2]);
	printf("|:%s", result[3]);
	printf("^:%s", result[4]);
	return 0;
}
//3
void showopen(int n);
int main(void)
{
	showopen(25);
	return 0;
}
void showopen(int n)
{
	int i;
	int openbit = 0;
	const static int size = CHAR_BIT * sizeof(int);
	char* ps = (char*)malloc((size + 1) * sizeof(char));
	for (i = size - 1; i >= 0; i--, n >>= 1)
		ps[i] = (01 & n) + '0';
	ps[size] = '\0';
	fputs(ps, stdout);
	for (i = 0; i < size; i++)
	{
		if (ps[i] == '1')
			openbit++;
		else continue;
	}
	printf("The number of open bits is %d.\n", openbit);
}
//4
int check_bit(int number, int bit);
int main(void)
{
	int num = check_bit(0x55, 1);
	int num2 = check_bit(0x55, 2);
	printf("0x55 bit 1 is %d, bit 2 is %d.\n", num, num2);
}
int check_bit(int number, int bit)
{
	return (number & (0x01 << (bit - 1)));
}
//5
unsigned int rotate(unsigned int x, int bitnum);
int main(void)
{
	unsigned int number = rotate(0x80000001, 1);
	printf("Number:%d", (unsigned int)number);

	return 0;
}
unsigned int rotate(unsigned int x, int bitnum)
{
	unsigned int int_bit = sizeof(unsigned int) * 8;
	for (size_t i = 0; i < bitnum; i++)
	{
		if (((x >> (int_bit - 1)) & 0x01) == 1)/*现将x先右移长度-1位，使得最高阶位移动到最低阶位，将移动后的值与0x01进行按位与，
											   如果按位与的结果是1，也就是目前最低阶位是1，也就是原来最高阶位是1，则左移一位后，
											   最高阶的1丢失，低阶位用0填充，为了满足题目要求，*/
		{
			x = (x << 1) + 0x01;/*在左移一位以后，必须在低阶位追加一位1，使得丢失的高阶1补充到低阶位*/
		}
		else
		{
			x = x << 1;/*如果不是的话，说明原来最高阶位不是1而是0，在左移一位时末尾用0补充，满足旋转的要求，这样无需在末尾追加。*/
		}
	}
	return x;
}
//6
struct character {
	unsigned int ID : 8;
	unsigned int size : 7;
	unsigned int align : 2;
	unsigned int bold : 1;
	unsigned int italic : 1;
	unsigned int underline : 1;
};
#define LEFT_ALIGN 1
#define MID_ALIGN 2
#define RIGHT_ALIGN (LEFT_ALIGN|MID_ALIGN)
#define BOLD 1
#define UNBOLD 0
#define ITALIC 1
#define NON_ITALIC 0
#define UNDERLINE 1
#define NO_UNDERLINE 0
void showinfo(struct character*);
void menu(void);
int main(void)
{
	unsigned int size_s;
	unsigned int font_s;
	char alignment_s;
	char choice;
	struct character chr = { 1,12,LEFT_ALIGN,UNBOLD,NON_ITALIC,NO_UNDERLINE };
	while (1)
	{
		showinfo(&chr);
		menu();
		scanf("%c", &choice);
		while (getchar() != '\n')
			continue;
		switch (choice)
		{

		case's':
		{
			printf("Enter font size(0-127):");
			scanf("%d", &size_s);
			while (getchar() != '\n')
				continue;
			if (size_s >= 0 && size_s <= 127)
				chr.size = size_s;
			else printf("The number is beyond the spectrum.Try again.\n");
		}; break;

		case 'f':
		{
			printf("Please enter a font ID(between 0 and 255):");
			scanf("%d", &font_s);
			while (getchar() != '\n')
				continue;
			if (font_s >= 0 && font_s <= 255)
				chr.ID = font_s;
			else printf("The number is beyond the spectrum.Try again.\n");
		}; break;

		case'a':
		{
			printf("Select alignment:\n");
			printf("l)left   c)center   r)right\n");
			scanf("%c", &alignment_s);
			while (getchar() != '\n')
				continue;
			switch (alignment_s)
			{
			case 'l':chr.align = LEFT_ALIGN; break;
			case 'c':chr.align = MID_ALIGN; break;
			case 'r':chr.align = RIGHT_ALIGN; break;
			default:printf("Try again."); break;
			}
			printf("%d\n", chr.align);
		}; break;

		case 'b':
		{
			if (chr.bold == BOLD)
			{
				chr.bold = UNBOLD;
			}
			else if (chr.bold == UNBOLD)
			{
				chr.bold = BOLD;
			}
		}; break;

		case 'i':
		{
			if (chr.italic == ITALIC)
				chr.italic = NON_ITALIC;
			else chr.italic = ITALIC;
		}; break;

		case 'u':
		{
			if (chr.underline == UNDERLINE)
				chr.underline = NO_UNDERLINE;
			else chr.underline = UNDERLINE;
		}; break;
		case 'q':goto flag; break;
		}
	}
flag:printf("Bye!\n");
	return 0;
}
void showinfo(struct character* ps)
{
	printf("  ID  SIZE  ALIGNMENT  B    I    U\n");
	printf("  %d    %d     ", ps->ID, ps->size);
	if (ps->align == LEFT_ALIGN)
		fputs("left    ", stdout);
	else if (ps->align == MID_ALIGN)
		fputs("center    ", stdout);
	else if (ps->align == RIGHT_ALIGN)
		fputs("right    ", stdout);
	if (ps->bold == BOLD)
		fputs("on    ", stdout);
	else if (ps->bold == UNBOLD)
		fputs("off  ", stdout);
	if (ps->italic == ITALIC)
		fputs("on  ", stdout);
	else if (ps->italic == NON_ITALIC)
		fputs("off  ", stdout);
	if (ps->underline == UNDERLINE)
		fputs("on", stdout);
	else if (ps->underline == NO_UNDERLINE)
		fputs("off", stdout);
	puts("\n");
}
void menu(void)
{
	printf("f)change front    s)change size    a)change alignment\n"
		"b)toggie bold     i)toggie italic  u)toggie underline\n"
		"q)quit\n");
}
//7
void menu(void);
void showinfo(char*, unsigned long);
int main(void)
{
	/*bit:0 表示下划线开关位 bit:1 表示斜体开关位  bit:2 表示加粗开关位
	  bit:3-4  表示对齐 bit:8-15 表示字体大小 bit:16-23 表示字体ID*/
	unsigned long ch = 0;
	char align[10] = "left";
	char choice = 0;
	while (1)
	{
		if ((ch >> 3 & 0x3) == 0)
			strcpy(align, "left");
		else if (((ch >> 3) & 0x3) == 1)
			strcpy(align, "center");
		else if (((ch >> 3) & 0x3) == 2)
			strcpy(align, "right");
		showinfo(align, ch);
		menu();
		scanf("%c", &choice);
		while (getchar() != '\n')
			continue;
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'f':
		{
			printf("Enter font id(0-255): ");
			unsigned char font_id = 0;
			scanf("%d", &font_id);
			ch &= ~(0xff << 16);
			ch |= (font_id << 16);
			while (getchar() != '\n')
				continue;
		}break;

		case 's':
		{
			printf("Enter font size(0-127): ");
			unsigned char font_size = 0;
			scanf("%d", &font_size);
			while (getchar() != '\n')
				continue;
			ch &= ~(0xff << 8);
			ch |= (font_size << 8);
		}break;

		case 'a':
		{
			printf("Select alignment:");
			printf("%-10s%-10s%-10s\n", "l)left", "c)center", "r)right");
			char choice = 0;
			scanf("%c", &choice);
			while (getchar() != '\n')
				continue;
			ch &= ~(0x03 << 3);
			switch (choice)
			{
			case 'l':ch |= (0x00 << 3); break;
			case 'c':ch |= (0x01 << 3); break;
			case 'r':ch |= (0x02 << 3); break;
			default:printf("Input error! Nothing have been changed!\n"); break;
			}
		}break;

		case 'b':
		{	if (ch & (0x01 << 2))
			ch &= ~(0x01 << 2);
		else
			ch |= (0x01 << 2);
		}break;

		case 'i':
		{	if (ch & (0x01 << 1))
			ch &= ~(0x01 << 1);
		else
			ch |= (0x01 << 1);
		}break;

		case 'u':
		{	if (ch & 0x01)
			ch &= ~(0x01);
		else
			ch |= 0x01;
		}	break;
		default:printf("Error choice. Nothing have been changed!\n"); break;
		}
	}
	printf("Bye!\n");
	return 0;
}
void menu(void)
{
	printf("%-20s%-20s%-20s\n", "f)change font", "s)change size", "a)change alignment");
	printf("%-20s%-20s%-20s\n", "b)toggle bold", "i)toggle italic", "u)toggle underline");
	printf("%-20s\n", "q)quit");
}
void showinfo(char* align, unsigned long ch)
{
	printf("ID SIZE ALIGNMENT%4s%4s%4s\n", "B", "I", "U");
	printf("%2d%5d%8s%7s%4s%4s\n", ((ch >> 16) & 0xff), ((ch >> 8) & 0xff), align, (((ch >> 2) & 0x01) ? "on" : "off"),
		(((ch >> 1) & 0x01) ? "on" : "off"), ((ch & 0x01) ? "on" : "off"));
}

