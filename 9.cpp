#include<stdio.h>
#include<ctype.h>
//1
double min(double x, double y);
int main(void)
{
	double num1, num2, minn1, minn2;
	printf("Enter two numbers:");
	scanf("%lf,%lf", &num1, &num2);
	minn1 = min(num1, num2);
	printf("The smallest number in two numbers is:%.2f\n", minn1);
	return 0;
}
double min(double x, double y)
{
	double c;
	if (x > y)
		c = y;
	else c = x;
	return c;
}
//2、3..
void chline(char ch, int i, int j);
int main(void)
{
	char ch; int rows, lines;
	printf("Enter the character and the lines and rows:\n"
		"character:");
	scanf("%c", &ch);
	printf("lines:");
	scanf("%d", &lines);
	printf("rows:");
	scanf("%d", &rows);
	chline(ch, lines, rows);
	return 0;
}
void chline(char ch, int i, int j)
{
	int index, par;
	for (index = 1; index <= j; index++)
	{
		for (par = 1; par <= i; par++)
			printf("%c", ch);
		printf("\n");
	}
}
//4
double harmonic_avg(double i, double j);
int main(void)
{
	double num1, num2, harmon;
	printf("Enter two numbers:");
	scanf("%lf,%lf", &num1, &num2);
	harmon = harmonic_avg(num1, num2);
	printf("The harmonic average number of the two numbers is %f", harmon);
	return 0;
}
double harmonic_avg(double i, double j)
{
	double status1, status2, status3;
	status1 = (1 / i) + (1 / j);
	status2 = status1 / 2;
	status3 = 1 / status2;
	return status3;
}
//5
void become_larger(double* i, double* j);
int main(void)
{
	double num1, num2;
	printf("Enter two numbers:");
	scanf("%lf,%lf", &num1, &num2);
	become_larger(&num1, &num2);
	printf("Now the two numbers become %.2f and %.2f", num1, num2);
	return 0;
}
void become_larger(double* i, double* j)
{
	double temp;
	if (*i > * j)
		temp = *i;
	else temp = *j;
	*i = temp;
	*j = temp;
}
//6
void smlst_to_lrgst(double* i, double* j, double* k);
int main(void)
{
	double num1, num2, num3;
	printf("Enter three different numbers with comma between numbers,press q to quit:");
	while (scanf("%lf,%lf,%lf", &num1, &num2, &num3) == 3)
	{
		if (num1 == num3 || num1 == num2 || num2 == num3)
		{
			printf("You should input three different numbers:");
			fflush(stdin);/*直接刷新缓冲区以排除换行符*/
			continue;
		}
		else smlst_to_lrgst(&num1, &num2, &num3);
		printf("Now the three numbers become %.2f,%.2f,%.2f\n", num1, num2, num3);
		printf("Enter three different numbers with comma between numbers,press q to quit:");
		fflush(stdin);
	}
	printf("Bye.\n");
	return 0;
}
void smlst_to_lrgst(double* i, double* j, double* k)
{
	double max, min, mid;
	max = *i;
	if (*j > max)
		max = *j;
	if (*k > max)
		max = *k;
	min = *i;
	if (*j < min)
		min = *j;
	if (*k < min)
		min = *k;
	if (*i != min && *i != max)
		mid = *i;
	if (*j != min && *j != max)
		mid = *j;
	if (*k != min && *k != max)
		mid = *k;
	*i = min;
	*j = mid;
	*k = max;
}
//7
void report(char ch);
int main(void)
{
	char ch;
	while ((ch = getchar()) != EOF)
	{
		report(ch);
	}
	printf("Bye.\n");
	return 0;
}
void report(char ch)
{
	int sernum;
	if (isalpha(ch))
	{
		printf("%c is a letter.", ch);
		if (islower(ch))
			sernum = ch - 96;
		else
			sernum = ch - 64;
		printf("It's serial number in alphabet is %d\n", sernum);
	}
	else {
		sernum = -1;
		putchar(ch);
		printf(" is not a letter.It's serial number in alphabet is %d\n", sernum);
	}
	fflush(stdin);
}
//8
double power(double base, double index);
int main(void)
{
	double base, pow;
	double index;
	printf("Enter two numbers to determine the base number and index;press q to quit:");
	while (scanf("%lf,%lf", &base, &index) == 2)
	{
		pow = power(base, index);
		printf("%.2f power of %.2f is %.2f.\n", base, index, pow);
		printf("Enter two numbers to determine the base number and index;press q to quit:");
		fflush(stdin);
	}
	printf("Bye.\n");
	return 0;
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
//9
double power(double base, double index);
int main(void)
{
	double base, pow;
	double index;
	printf("Enter two numbers to determine the base number and index;press q to quit:");
	while (scanf("%lf,%lf", &base, &index) == 2)
	{
		pow = power(base, index);
		printf("%.2f power of %.2f is %.2f.\n", base, index, pow);
		printf("Enter two numbers to determine the base number and index;press q to quit:");
		fflush(stdin);
	}
	printf("Bye.\n");
	return 0;
}
double power(double base, double index)
{
	double pow, temp;
	int i;
	if (index > 0)
	{
		index--;
		return(base * power(base, index));
	}
	else if (index < 0)
	{
		index++;
		temp = 1 / base;
		return(temp * power(base, index));
	}
	else if (index == 0)
	{
		if (base == 0)
			printf("The 0 power of 0 is unidentified.\n");
		return 1;
	}
}
//10
void to_base_n(int dex, int cons);
int main(void)
{
	int dec, cons;
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
	printf("Bye.\n");
	return 0;
}
void to_base_n(int dex, int cons)
{
	int r;
	r = dex % cons;
	if (dex >= cons)
		to_base_n(dex / cons, cons);
	printf("%d", r);
}
//11
/*该程序容易造成系统崩溃*/
unsigned long long Fibonacci(int n);
unsigned long long FIB(int n);
int main(void)
{
	int num;
	unsigned long long fib, Fib;
	printf("Enter the serial number of the Fibonacci number you want to get,press q to quit:");
	while (scanf("%d", &num) == 1)
	{
		if (num <= 0)
		{
			printf("Please enter an positive Interger.Try again:");
			fflush(stdin);
			continue;
		}
		else fib = Fibonacci(num);
		Fib = FIB(num);
		printf("%dth number of the Fibonacci sequence is %llu and %llu\n", num, fib, FIB);
		printf("Enter the serial number of the Fibonacci number you want to get,press q to quit:");
	}
	printf("Done.\n");
	return 0;
}
unsigned long long Fibonacci(int n)
{
	unsigned long long rtn;
	unsigned long long rtn1, rtn2;
	unsigned long long i;
	if (n == 1 || n == 2)
		rtn = 1;
	else
	{
		for (rtn1 = 1, rtn2 = 1, i = 2; i < n; i++)
		{
			rtn = rtn1 + rtn2;
			rtn1 = rtn2;
			rtn2 = rtn;
		}
	}
	return rtn;
}
unsigned long long FIB(int n)
{
	if (n > 2)
		return FIB(n - 1) + FIB(n - 2);
	else return 1;
}
