#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
//1
int main(void)
{
	int ch;
	int word = 0;
	while ((ch = getchar()) != EOF)/*在下一行最开始按下Ctrl+Z，表示输入结束。*/
	{
		word++;
	}
	printf("The number of word before the end of input is %d", word);
	return 0;
}
//2
int main(void)
{
	int ch;
	int words = 0;
	while ((ch = getchar()) != EOF)/*在下一行最开始按下Ctrl+Z，表示输入结束。*/
	{
		words++;
		printf("%d ", ch);
		if (ch == '\n')
			printf("\\n\n ", ch);
		else if (ch == '\t')
			printf("\\t\n ", ch);
		else if (ch >= 1 && ch <= 26)
			printf("Ctrl%c\n ", ch + 64);
		else printf("%c ", ch, ch);
		if (words % 10 == 0)
			printf("\n");
	}
	return 0;
}
//3
int main(void)
{
	int ch;
	int lower_letter = 0, upper_letter = 0;
	while ((ch = getchar()) != EOF)
	{
		if (islower(ch))
			lower_letter++;
		else if (isupper(ch))
			upper_letter++;
		else continue;
	}
	printf("There is %d lower letters and %d upper letters.", lower_letter, upper_letter);
	return 0;
}
//4
int main(void)
{
	int ch;
	int words = 0, letter = 0;
	float aver_letter_number;
	bool inword = false;
	while ((ch = getchar()) != EOF)/*在下一行最开始按下Ctrl+Z，表示输入结束。*/
	{
		if (ispunct(ch)) /*ctype.h中的ispunct()函数规定，若参数为标点符号则返回一真值*/
			continue;
		else if (isspace(ch) && inword)
			inword = false;
		else if (!isspace(ch) && !inword)
		{
			words++;
			letter++;
			inword = true;
		}
		else letter++;
	}
	aver_letter_number = (float)letter / (float)words;
	printf("The number of average letter per word is %.2f.", aver_letter_number);
	return 0;
}
//5
int main(void)
{
	char ch = 0;
	int upper = 100;
	int lower = 0;
	int guess = 50;

	printf("Pick an interger between 1 and 100.\nNow I will guess the number before you tell me about it.\n"
		"I guess the number is 50.Is it right(Y\\N)?\nTell me:");
	scanf("%c", &ch);
	while (ch != 'Y')
	{
		while (getchar() != '\n')
			continue;
		printf("Ok,the number you chosen is bigger or smaller than I guess?(B/S)");
		scanf("%c", &ch);
		if (ch == 'B')
		{
			lower = guess;
			guess = (lower + upper) / 2;/*若这次计算机猜的数过小，则下一个试猜值是以上一次猜的数为下限（调整下限），调整过的上限为新上限的平均数*/
		}
		else
		{
			upper = guess;
			guess = (lower + upper) / 2;/*若这次计算机猜的数过大，则下一个试猜值是以上一次猜的数为上限（调整上限），调整过的下限为新下限的平均数*/
		}
		printf("I guess the number is %d,Is it right(Y\\N)?", guess);
		while (getchar() != '\n')
			continue;
		scanf("%c", &ch);
	}
	printf("I can do it.");
	return 0;
}
//6
char get_first(void);
int main(void)
{
	int ch;
	ch = get_first();
	printf("The first  non-blank character is:%c", ch);
	return 0;
}
char get_first(void)
{
	int ch, ch_return;
	bool ahead = false;
	while (ch = getchar())
	{
		if (!isblank(ch) && !ahead)
		{
			ch_return = ch;
			ahead = true;
		}
		else if (ch == '\n')
			break;
	}
	return ch_return;
}
//7
#define BASIC1 8.75
#define BASIC2 9.33
#define BASIC3 10.00
#define BASIC4 11.20
#define OVERWORK 40
#define OVER_SY 15.00
#define RATE_BL300 0.15
#define RATE_BT300_450 0.20
#define RATE_UD450 0.25
void menu(int index, int space);
int main(void)
{
	float BASIC, TOTAL, TAX, REST;
	int index = 0, space = 0, WORK;
	char index1;
	int salary[4] = { BASIC1,BASIC2,BASIC3,BASIC4 };
	menu(index, space);
	while (scanf("%c", &index1) == 1)
	{
		switch (index1)
		{
		case'a':BASIC = BASIC1; break;
		case'b':BASIC = BASIC2; break;
		case'c':BASIC = BASIC3; break;
		case'd':BASIC = BASIC4; break;
		default:break;
		}
		if (index1 >= 'd' || index1 < 'a')
			break;
		printf("Please input your working hours;press q to quit.Time:");
		while (scanf("%d", &WORK) == 1)
		{
			if (WORK <= OVERWORK)
				TOTAL = BASIC * WORK;
			else
				TOTAL = BASIC * OVERWORK + OVER_SY * (WORK - OVERWORK);
			if (TOTAL <= 300)
				TAX = TOTAL * RATE_BL300;
			else if (TOTAL > 300 && TOTAL <= 450)
				TAX = 300 * RATE_BL300 + (TOTAL - 300) * RATE_BT300_450;
			else
				TAX = 300 * RATE_BL300 + 150 * RATE_BT300_450 + RATE_UD450 * (TOTAL - 450);
			REST = TOTAL - TAX;
			printf("total salary:%.2f,tax:%.2f,rest:%.2f\n", TOTAL, TAX, REST);
			printf("Input your working hours again.Press q to quit.Time:");
		}
		printf("You have quit.Please try to select again.\n");
		menu(index, space);
		while (getchar() != '\n')
			continue;
	}
	printf("Done.");
	return 0;
}
void menu(int index, int space)
{
	int salary[4] = { BASIC1,BASIC2,BASIC3,BASIC4 };
	for (index = 0; index <= 64; index++)
		printf("*");
	printf("\n");
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	for (index = 1; index <= 4; index++)
	{
		printf("%c)  $%d/hr", 96 + index, salary[index - 1]);
		if (index == 1)
		{
			for (space = 0; space <= 30; space++)
				printf(" ");
		}
		else if (index == 3)
		{
			for (space = 0; space <= 29; space++)
				printf(" ");
		}
		index++;
		printf("%c)  $%d/hr\n", 96 + index, salary[index - 1]);
	}
	printf("q)  quit\n");
	for (index = 0; index <= 64; index++)
		printf("*");
	printf("\n");
}
//8
void menu(void);
float select_number(void);
float select_number_in_dividing(void);
int main(void)
{
	char select;
	float num_previous, num_behind;
	menu();
	while (scanf("%c", &select) == 1)
	{
		if (select != 'a' && select != 's' && select != 'm' && select != 'd' && select != 'q')
			printf("It is valid.Enter an available operation:");
		else
		{
			switch (select)
			{
			case'a': {
				printf("Enter the first number:");
				num_previous = select_number();
				printf("Enter the second number:");
				num_behind = select_number();
				printf("%.2f+%.2f=%.2f\n", num_previous, num_behind, num_previous + num_behind);
			} break;
			case's': {printf("Enter the first number:");
				num_previous = select_number();
				printf("Enter the second number:");
				num_behind = select_number();
				printf("%.2f-%.2f=%.2f\n", num_previous, num_behind, num_previous - num_behind);
			}break;
			case'm': {printf("Enter the first number:");
				num_previous = select_number();
				printf("Enter the second number:");
				num_behind = select_number();
				printf("%.2f*%.2f=%.2f\n", num_previous, num_behind, num_previous * num_behind); }break;
			case'd': {printf("Enter the first number:");
				num_previous = select_number();
				printf("Enter the second number:");
				num_behind = select_number_in_dividing();
				printf("%.2f/%.2f=%.2f\n", num_previous, num_behind, num_previous / num_behind); }; break;
			case'q':printf("Bye.\n"); break;
			}
			if (select == 'q')
				break;
			menu();
		}
		while (getchar() != '\n')
			continue;
	}
	return 0;
}
void menu(void)
{
	printf("Enter the operator of your choice:\n");
	printf("a.add              s.subtract\n"
		"m.nultiply         d.divide\n"
		"q.quit\n");
}
float select_number(void)
{
	float num;
	while (scanf("%f", &num) != 1)
	{
		char ch = 0;
		while ((ch = getchar()) != '\n')
			putchar(ch);
		printf(" is not a number.\nPlease enter a number,such as 2.5,-1.78E8,or 3:", num);
	}
	return num;
}
float select_number_in_dividing(void)
{
	float num;
	int status;
	status = scanf("%f", &num);
	while (status != 1)
	{
		char ch = 0;
		while ((ch = getchar()) != '\n')
			putchar(ch);
		printf(" is not a number.\nPlease enter a number,such as 2.5,-1.78E8,or 3:", num);
		scanf("%f", &num);
	}
	while (status == 1 && num == 0)
	{
		printf("Enter a number other than 0:");
		scanf("%f", &num);
	}
	return num;
}
