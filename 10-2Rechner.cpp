#include<stdio.h>
#define ROW 3
#define COL 5
void menu(void);
float select_number(void);
float select_number_in_dividing(void);
void to_base_n(int dex, int cons);
unsigned long long int rfact(int n);
double power(double base, double index);
void storage(int m, double(*ptr)[COL]);
double sum_everow(double(*ptr)[COL], int m);
double av_everow(double(*ptr)[COL], int m);
double av_all(double(*ptr)[COL], int m);
double max_all(double(*ptr)[COL], int m);
double max_singlerow(double(*ptr)[COL], int m);
double min_all(double(*ptr)[COL], int m);
double min_singlerow(double(*ptr)[COL], int m);
double vari(double(*ptr)[COL], int m, int av);
double variperrow(double(*ptr)[COL], int m, int av);
void print(double n);
int sta(void);
int cal(void);
int main(void)
{
	char op;
	printf("Welcome to super calculator!What do you want to do?\n");
	printf("C.Calculating                    S.Statistics\n");
	printf("Your option(Press Ctrl+Z to quit):");
	while (scanf("%c", &op) == 1 && op != EOF)
	{
		while (getchar() != '\n')
			continue;
		if (op == 'C' || op == 'c')
			cal();
		else if (op == 'S' || op == 's')
			sta();
		else
		{
			printf("That's wrong.Please choose again:");
			continue;
		}
		printf("Now let's choose again.What do you want to do?\n");
		printf("C.Calculating                    S.Statistics\n");
		printf("Your option(Press Ctrl+Z to quit):");
		while (getchar() != '\n')
			continue;
	}
	printf("\nThat's all.");
	return 0;
}
int sta(void)
{
	int i, j;
	char cho;
	double average, max, min;
	double variance;
	double num[ROW][COL];
	double avperrow[ROW];
	double sumperrow[ROW];
	double maxperrow[ROW];
	double minperrow[ROW];
	double rangeperrow[ROW];
	double vari_row[ROW];
	double sum_all;
	printf("Welcome to statistics calculator.Press q to quit,Press any key to continue:");
	while (scanf("%c", &cho) == 1 && cho != 'q')
	{
		printf("Enter %d rows of numbers.Every row contains %d numbers:\n", ROW, COL);
		storage(ROW, num);
		printf("The %d * %d array you have storaged is:\n", ROW, COL);
		for (i = 0; i < ROW; i++)
		{
			for (j = 0; j < COL; j++)
			{
				printf("num[%d][%d]=%.2f", i, j, *(*(num + i) + j));
				putchar(' ');
			}
			putchar('\n');
		}
		for (i = 0; i < ROW; i++)
			* (avperrow + i) = av_everow(num, i);
		for (i = 0; i < ROW; i++)
			* (sumperrow + i) = sum_everow(num, i);
		for (sum_all = 0, i = 0; i < ROW; i++)
			sum_all += *(sumperrow + i);
		average = av_all(num, ROW);
		max = max_all(num, ROW);
		min = min_all(num, ROW);
		for (i = 0; i < ROW; i++)
			* (maxperrow + i) = max_singlerow(num, i);
		for (i = 0; i < ROW; i++)
			* (minperrow + i) = min_singlerow(num, i);
		for (i = 0; i < ROW; i++)
			* (rangeperrow + i) = (*(maxperrow + i)) - (*(minperrow + i));
		variance = vari(num, ROW, average);
		for (i = 0; i < ROW; i++)
			* (vari_row + i) = variperrow(num, i, avperrow[i]);
		printf("The average number of every row is:\n");
		for (i = 0; i < ROW; i++)
		{
			printf("The %dth row :", i + 1);
			print(*(avperrow + i));
			putchar('\n');
		}
		printf("\nAnd the average of all %d numbers is :", ROW * COL);
		print(average);
		putchar('\n');
		printf("The sum of every row is:\n");
		for (i = 0; i < ROW; i++)
		{
			printf("The %dth row :", i + 1);
			print(*(sumperrow + i));
			putchar('\n');
		}
		printf("\nAnd the sum of all %d numbers is :", ROW * COL);
		print(sum_all);
		putchar('\n');
		printf("\nAnd the largest number of all %d numbers is:", ROW * COL);
		print(max);
		printf("\nAnd the smallest number of all %d numbers is:", ROW * COL);
		print(min);
		printf("\nAnd the range of all %d numbers is:", ROW * COL);
		print(max - min);
		putchar('\n');
		for (i = 0; i < ROW; i++)
		{
			printf("\nThe largest number of %dth row is:", i + 1);
			print(*(maxperrow + i));
		}
		for (i = 0; i < ROW; i++)
		{
			printf("\nThe lowest number of %dth row is:", i + 1);
			print(*(minperrow + i));
		}
		for (i = 0; i < ROW; i++)
		{
			printf("\nThe range of %dth row is:", i + 1);
			print(*(rangeperrow + i));
		}
		putchar('\n');
		printf("\nAnd the variance of all numbers is:", ROW * COL);
		print(variance);
		for (i = 0; i < ROW; i++)
		{
			printf("\nThe variance of %dth row is:", i + 1);
			print(*(vari_row + i));
		}
		printf("\nPress q to quit,Press any key to continue another calculation:\n");
		while (getchar() != '\n')
			continue;
	}
	printf("\nDone.");
	return 0;
}
int cal(void)
{
	int base_int;
	char select;
	float num_previous, num_behind;
	double base, pow;
	double index;
	menu();
	while (scanf("%c", &select) == 1)
	{
		if (select != 'a' && select != 's' && select != 'm' && select != 'd' && select != 'q' && select != 'f' && select != 'b' && select != 'p')
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
			case'b': {int dec, cons;
				printf("Enter the decimal number and the number of base according the order,press q to quit:");
				while (scanf("%d,%d", &dec, &cons) == 2)
				{
					if (cons > 10 || cons < 1)
					{
						printf("The base number should be a interger and between 2 and 10.Please retry.");
						continue;
					}
					else
						to_base_n(dec, cons);
					printf(" is %d in %d decimal.\n", dec, cons);
					printf("Enter the decimal number and the number of base according the order,press q to quit:");
				}
				printf("Return to main menu.");
			}; break;
			case'f': { printf("Enter the base number:");
				base_int = (int)select_number();
				printf("%d!=%llu\n", base_int, rfact(base_int)); }; break;
			case 'p': {printf("Enter the base number:");
				base = select_number();
				printf("Enter the index number:");
				index = select_number();
				printf("%.2f^%.2f=%.2f\n", base, index, power(base, index)); }; break;
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
void storage(int m, double(*ptr)[COL])
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		printf("Please Enter the %dth rows of numbers,using comma to seperate:\n", i + 1);
		for (j = 0; j < COL - 1; j++)
		{
			printf("num[%d][%d]=", i, j);
			while (scanf("%lf", *(ptr + i) + j) != 1)
			{
				printf("It is not a number.Please try again:");
				printf("num[%d][%d]=", i, j);
				while (getchar() != '\n')
					continue;
			}
		}
		printf("num[%d][%d]=", i, COL - 1);
		while (scanf("%lf", *(ptr + i) + COL - 1) != 1)
		{
			printf("It is not a number.Please try again:");
			printf("num[%d][%d]=", i, COL - 1);
			while (getchar() != '\n')
				continue;
		}
	}
}
double sum_everow(double(*ptr)[COL], int m)
{
	int i;
	double subtot = 0;
	for (i = 0; i < COL; i++)
		subtot += *(*(ptr + m) + i);
	return subtot;
}
double av_everow(double(*ptr)[COL], int m)
{
	int i;
	double subtot = 0;
	for (i = 0; i < COL; i++)
		subtot += *(*(ptr + m) + i);
	return subtot / COL;
}
double av_all(double(*ptr)[COL], int m)
{
	int i, j;
	double total = 0;
	for (i = 0; i < m; i++)
		for (j = 0; j < COL; j++)
			total += *(*(ptr + i) + j);
	return total / (m * COL);
}
double max_all(double(*ptr)[COL], int m)
{
	int i, j;
	double max;
	max = **ptr;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < COL; j++)
			if (*(*(ptr + i) + j) > max)
				max = *(*(ptr + i) + j);
	}
	return max;
}
double max_singlerow(double(*ptr)[COL], int m)
{
	int j;
	double max;
	max = **ptr;
	for (j = 0; j < COL; j++)
	{
		if (*(*(ptr + m) + j) > max)
			max = *(*(ptr + m) + j);
	}
	return max;
}
double min_all(double(*ptr)[COL], int m)
{
	int i, j;
	double min;
	min = **ptr;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < COL; j++)
			if (*(*(ptr + i) + j) < min)
				min = *(*(ptr + i) + j);
	}
	return min;
}
double min_singlerow(double(*ptr)[COL], int m)
{
	int j;
	double min;
	min = **ptr;
	for (j = 0; j < COL; j++)
	{
		if (*(*(ptr + m) + j) < min)
			min = *(*(ptr + m) + j);
	}
	return min;
}
double vari(double(*ptr)[COL], int m, int av)
{
	int i, j;
	double range;
	double vr = 0;
	double range_av[ROW][COL];
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < COL; j++)
		{
			range = ptr[i][j] - av;
			range_av[i][j] = power(range, 2);
		}
	}
	for (i = 0; i < m; i++)
		for (j = 0; j < COL; j++)
			vr += range_av[i][j];
	vr = vr / (m * COL);
	return vr;
}
double variperrow(double(*ptr)[COL], int m, int av)
{
	int j;
	double range;
	double vr = 0;
	double range_av[ROW][COL];
	for (j = 0; j < COL; j++)
	{
		range = ptr[m][j] - av;
		range_av[m][j] = power(range, 2);
	}
	for (j = 0; j < COL; j++)
		vr += range_av[m][j];
	vr = vr / COL;
	return vr;
}
void print(double n)
{
	printf("%.2f", n);
}
void menu(void)
{
	printf("Enter the operator of your choice:\n");
	printf("a.add              s.subtract\n"
		"m.nultiply         d.divide\n"
		"b.binary conservation\n"
		"f.factorial operation\n"
		"p.power            q.quit\n");
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
double power(double base, double index)
{
	double pow;
	int i;
	if (index > 0)
	{
		for (i = 1, pow = 1; i <= index; i++)
			pow *= base;
	}
	else if (index < 0)
	{
		for (i = 1, pow = 1; i <= -index; i++)
			pow *= base;
		pow = 1 / pow;
	}
	else {
		pow = 1;
		if (base == 0)
			printf("The 0 power of 0 is unidentified.\n");
	}
	return pow;
}
void to_base_n(int dex, int cons)
{
	int r;
	r = dex % cons;
	if (dex >= cons)
		to_base_n(dex / cons, cons);
	printf("%d", r);
}
unsigned long long int rfact(int n)
{
	unsigned long long ans;
	for (ans = 1; n > 1; n--)
		ans *= n;
	return ans;
}

