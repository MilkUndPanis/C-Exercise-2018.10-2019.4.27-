#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>/*为5/6中time函数提供原型，time函数返回时间，它可以作为种子，传递给srand函数*/
//1
void critic(int* units);
int main(void)
{
	int units = 0;
	printf("How many pounds to a firkin of butter?\n");
	scanf("%d", &units);
	while (units != 56)
		critic(&units);
	printf("You must have looked it up!\n");
	return 0;
}
void critic(int* units)
{
	printf("No luck,my friend.Try again.\n");
	scanf("%d", units);
}
//2.一起编译：
//pe12 - 2a.cpp
//#include"pel2-2a.h"
static int mode;
static int distance;
static int confuel;
void set_mode(int set)
{
	if (set == 0 || set == 1)
		mode = set;
	else
		printf("Invalid mode specified.Mode %s used.", (mode ? "1(US)" : "0(metric)"));
}
void get_info(void)
{
	if (mode == 0)
	{
		printf("Enter distance traveled in kilometres:");
		scanf("%d", &distance);
		printf("Enter fuel consumed in liters:");
		scanf("%d", &confuel);
	}
	if (mode == 1)
	{
		printf("Enter distance traveled in miles:");
		scanf("%d", &distance);
		printf("Enter fuel consumed in gallons:");
		scanf("%d", &confuel);
	}
}
void show_info(void)
{
	if (mode == 0)
		printf("Fuel comsuption is %d liters per 100km.", (confuel * 100 / distance));
	if (mode == 1)
		printf("Fuel comsuption is %d miles per gallon.", (distance / confuel));
}
//pe12 - 2b.cpp
//#include"pel2-2a.h"
int main(void)
{
	int setmode;
	printf("Enter 0 for metric mode,1 for US mode:");
	scanf("%d", &setmode);
	while (setmode >= 0)
	{
		set_mode(setmode);
		get_info();
		show_info();
		printf("Enter 0 for metric mode,1 for US code");
		printf("(-1 to quit):");
		scanf("%d", setmode);
	}
	printf("Done.\n");
	return 0;
}
//pel2 - 2a.h
void set_mode(int set);
void get_info(void);
void show_info(void);
//3.（自动变量）
void get_info(int mode);
void show_info(int mode, int distance, int confuel);
int main(void)
{
	int mode;
	int setmode;
	int premode = 0;
	printf("Enter 0 for metric mode,1 for US mode:");
	scanf("%d", &setmode);
	while (setmode >= 0)
	{
		if (setmode == 1 || setmode == 0)
			mode = setmode;
		else
		{
			printf("Invalid mode specified.Mode %s used.\n", (premode ? "1(US)" : "0（metric)"));
			mode = premode;
		}
		get_info(mode);
		premode = mode;
		printf("Enter 0 for metric mode,1 for US code");
		printf("(-1 to quit):");
		scanf("%d", &setmode);
	}
	printf("Done.\n");
	return 0;
}
void get_info(int mode)
{
	int distance;
	int confuel;
	if (mode == 0)
	{
		printf("Enter distance traveled in kilometres:");
		scanf("%d", &distance);
		printf("Enter fuel consumed in liters:");
		scanf("%d", &confuel);
		show_info(mode, distance, confuel);
	}
	if (mode == 1)
	{
		printf("Enter distance traveled in miles:");
		scanf("%d", &distance);
		printf("Enter fuel consumed in gallons:");
		scanf("%d", &confuel);
		show_info(mode, distance, confuel);
	}
}
void show_info(int mode, int distance, int confuel)
{
	if (mode == 0)
		printf("Fuel comsuption is %d liters per 100km.", (confuel * 100 / distance));
	if (mode == 1)
		printf("Fuel comsuption is %d miles per gallon.", (distance / confuel));
}
//4
int time = 0;
int times(void);
int main(void)
{
	int functtimes = 0;
	while (functtimes < 15)
	{
		functtimes = times();
		printf("This function had been called by %d times.\n", functtimes);
	}
	return 0;
}
int times(void)
{
	time++;
	return time;
}
//5
/*要生成随机数在1-10之间，只需要用10求余原来的随机数就可以了。*/
#define SIZE 10
int main(void)
{
	int random[SIZE];
	int temp;
	printf("Next,we create ten random numbers between 1-10.");
	srand((unsigned int)time(0));/*给rand函数提供种子的函数*/
	for (int i = 0; i < SIZE; i++)
		random[i] = rand() % 10 + 1;
	printf("This is ten random numbers:\n");
	for (int i = 0; i < SIZE; i++)
		printf("%d ", random[i]);
	putchar('\n');
	for (int i = 0; i < SIZE - 1; i++)
		for (int j = i + 1; j < SIZE; j++)
			if (random[j] < random[i])
			{
				temp = random[j];
				random[j] = random[i];
				random[i] = temp;
			}
	printf("This is ten descending sorted random numbers:\n");
	for (int i = 0; i < SIZE; i++)
		printf("%d ", random[i]);
	return 0;
}
//6.
/*要生成随机数在1-10之间，只需要用10求余原来的随机数就可以了。*/
#define SIZE 1000
int main(void)
{
	int random[SIZE];
	int temp;
	int times[10];
	for (int i = 0; i < 10; i++)
		times[i] = 0;
	printf("Next,we create 1000 random numbers between 1-10.");
	srand((unsigned int)time(0));/*给rand函数提供种子的函数*/
	for (int i = 0; i < SIZE; i++)
		random[i] = rand() % 10 + 1;
	printf("This is 1000 random numbers:\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", random[i]);
		if (i % 20 == 0 && i != 0)
			putchar('\n');
	}
	putchar('\n');
	for (int i = 0; i < SIZE - 1; i++)
		for (int j = i + 1; j < SIZE; j++)
			if (random[j] < random[i])
			{
				temp = random[j];
				random[j] = random[i];
				random[i] = temp;
			}
	printf("This is 1000 descending sorted random numbers:\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", random[i]);
		if (i % 20 == 0 && i != 0)
			putchar('\n');
	}
	putchar('\n');
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			if (random[i] == j)
				times[j - 1] += 1;
		}
	}
	for (int i = 0; i < 10; i++)
		printf("The number %d had appeared %d times.\n", i + 1, times[i]);
	return 0;
}
//7
int roll_count = 0;
int roll_n_dice(int dice, int sides);
int main(void)
{
	int sets;
	int dice, roll;
	int sides;
	int status;
	int* ptr;
	srand((unsigned int)time(0));
	printf("Enter the number of sets,0 to stop.\n");
	while (scanf("%d", &sets) == 1 && sets > 0)
	{
		printf("How many sides and how many dice?\n");
		if ((status = scanf("%d %d", &sides, &dice)) != 2)
		{
			if (status == EOF)
				break;
			else
			{
				printf("You should have entered two intergers.");
				printf(" Let's begin again.");
				while (getchar() != '\n')
					continue;
				printf("How many sides?Enter 0 to stop.\n");
				continue;
			}
		}
		if (sides < 2 || dice < 1)
		{
			if (sides < 2)
			{
				printf("Need at least two sides.\n");
				roll = -2;
			}
			if (dice < 1)
			{
				printf("Need at least one dice\n");
				roll = -1;
			}
			printf("You have rolled a %d using %d %d-sided dice.\n", roll, dice, sides);
			printf("How many sides?Enter 0 to stop.\n");
			continue;
		}
		ptr = (int*)malloc(sides * dice * sizeof(int));
		for (int i = 0; i < sides * dice; i++)
		{
			ptr[i] = roll_n_dice(dice, sides);
		}
		printf("Here are %d sets of %d %d-sided throws\n", dice * sides, dice, sides);
		for (int i = 0; i < sides * dice; i++)
		{
			printf("%d ", ptr[i]);
		}
		free(ptr);
		printf("\nEnter the number of sets,0 to stop.\n");
	}
	printf("The roll_n_dice() function was called %d times.\n", roll_count);
	printf("GOOD FORTUNE TO YOU!");
	return 0;
}
int roll_n_dice(int dice, int sides)
{
	int d;
	int roll;
	int total = 0;
	for (d = 0; d < dice; d++)
	{
		roll = rand() % sides + 1;
		++roll_count;
		total += roll;
	}
	return total;
}
//8
int* make_array(int elem, int val);
void show_array(const int ar[], int n);
int main(void)
{
	int* pa;
	int size;
	int value;
	printf("Enter the number of elements:");
	while (scanf("%d", &size) == 1 && size > 0)
	{
		printf("Enter the initialization value:");
		scanf("%d", &value);
		pa = make_array(size, value);
		if (pa)
		{
			show_array(pa, size);
			free(pa);
		}
		printf("Enter the number of element(<1 to quit)");
	}
	printf("Done.\n");
	return 0;
}
int* make_array(int elem, int val)
{
	int* ptr;
	ptr = (int*)malloc(elem * sizeof(int));
	ptr[0] = val;
	for (int i = 1; i < elem; i++)
	{
		srand(val);
		ptr[i] = rand();
	}
	return ptr;
}
void show_array(const int ar[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", ar[i]);
	putchar('\n');
}
//9
int main(void)
{
	int wordnum;
	char** ptr;
	char temp[80];
	printf("How many words do you wish to enter?");
	while (scanf("%d", &wordnum) == 1)
	{
		while (getchar() != '\n')
			continue;
		ptr = (char**)malloc(wordnum * sizeof(char*));/*储存的是单词也就是指针，所以它本身是指针的指针*/
		printf("Enter %d words now:\n", wordnum);
		for (int i = 0; i < wordnum; i++)
		{
			for (int j = 0; j < 80; j++)
			{
				temp[j] = getchar();
				if (isspace(temp[j]))
				{
					temp[j] = '\0';
					break;
				}
			}
			ptr[i] = temp;
			puts(ptr[i]);
		}
		printf("Here are your words:\n");
		for (int i = 0; i < wordnum; i++)
		{
			puts(ptr[i]);
		}
		printf("How many words do you wish to enter?");
	}
	return 0;
}
