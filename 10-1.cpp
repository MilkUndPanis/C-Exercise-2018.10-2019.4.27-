#include<stdio.h>
//1
#define MONTHS 12
#define YEARS 5
int main(void)
{
	const float rain[YEARS][MONTHS] =
	{ {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
	{8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
	{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
	{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
	{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2} };
	int year, month;
	float subtot, total;
	const float(*ptr)[MONTHS];/*声明行指针*/
	ptr = rain;

	printf("YEAR     RAINFALL(INCHES)\n");
	for (year = 0, total = 0; year < YEARS; year++)
	{
		for (month = 0, subtot = 0; month < MONTHS; month++)
			subtot += *(*(ptr + year) + month);
		printf("%5d %15.1f\n", 2010 + year, subtot);
		total += subtot;
	}
	printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
	printf("MONTHLY AVERAGES:\n\n");
	printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");

	for (month = 0; month < MONTHS; month++)
	{
		for (year = 0, subtot = 0; year < YEARS; year++)
			subtot += *(*(rain + year) + month);
		printf("%4.1f", subtot / YEARS);
	}
	printf("\n");
	return 0;
}
//2
#define L 5
void copy_arr(double tg1[], double sr[], int n);
void copy_ptr(double* tg2, double* sr, int n);
void copy_ptrs(double tg3[], double sr[], double* ptr);
int main(void)
{
	double source[L] = { 1.1,2.2,3.3,4.4,5.5 };
	double target1[L];
	double target2[L];
	double target3[L];
	double* ptr;
	copy_arr(target1, source, L);
	copy_ptr(target2, source, L);
	copy_ptrs(target3, source, source + L);
	for (ptr = source; ptr < source + L; ptr++)
		printf("%.1f ", *ptr);
	putchar('\n');
	for (ptr = target1; ptr < target1 + L; ptr++)
		printf("%.1f ", *ptr);
	putchar('\n');
	for (ptr = target2; ptr < target2 + L; ptr++)
		printf("%.1f ", *ptr);
	putchar('\n');
	for (ptr = target3; ptr < target3 + L; ptr++)
		printf("%.1f ", *ptr);
	putchar('\n');
	return 0;
}
void copy_arr(double tg1[], double sr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		tg1[i] = sr[i];
}
void copy_ptr(double* tg2, double* sr, int n)
{
	int i;
	for (i = 0; i < n; i++)
		* (tg2 + i) = *(sr + i);
}
void copy_ptrs(double tg3[], double sr[], double* ptr)
{
	double* ptr1 = sr;
	while (ptr1 < ptr)
		* (tg3++) = *(ptr1++);
}
//3
#define SIZE 10
int max(int* ar, int n);
int main(void)
{
	int i, max_n;
	int num[SIZE];
	printf("Enter five numbers:");
	scanf("%d,%d,%d,%d,%d", num, num + 1, num + 2, num + 3, num + 4);
	max_n = max(num, SIZE);
	printf("The largest number of the serial numbers is %d", max_n);
	return 0;
}
int max(int* ar, int n)
{
	int i;
	int max_num;
	max_num = *ar;
	for (i = 1; i < n; i++)
	{
		if (*(ar + i) > max_num)
			max_num = *(ar + i);
	}
	return max_num;
}
//4
#define SIZE 10
int max(double* ar, int n);
int main(void)
{
	int i, max_n;
	double num[SIZE];
	printf("Enter five numbers:");
	scanf("%lf,%lf,%lf,%lf,%lf", num, num + 1, num + 2, num + 3, num + 4);
	max_n = max(num, SIZE);
	printf("The serial number of the largest number is num[%d]=%.2f", max_n, *(num + max_n));
	return 0;
}
int max(double* ar, int n)
{
	int index;
	int i;
	int max_num;
	max_num = *ar;
	for (i = 1; i < n; i++)
	{
		if (*(ar + i) > max_num)
		{
			max_num = *(ar + i);
			index = i;
		}
	}
	return index;
}
//5
#define SIZE 5
double dif(double* ar, int n);
int main(void)
{
	double diff;
	double num[SIZE];
	printf("Enter five numbers:");
	scanf("%lf,%lf,%lf,%lf,%lf", num, num + 1, num + 2, num + 3, num + 4);
	diff = dif(num, SIZE);
	printf("The difference between largest number and lowest number is %.2f", diff);
	return 0;
}
double dif(double* ar, int n)
{
	int i;
	int max_num, min_num;
	max_num = *ar;
	for (i = 1; i < n; i++)
	{
		if (*(ar + i) > max_num)
			max_num = *(ar + i);
	}
	min_num = *ar;
	for (i = 1; i < n; i++)
	{
		if (*(ar + i) < min_num)
			min_num = *(ar + i);
	}
	return max_num - min_num;
}
//6
#define SIZE 5
void rev(double* ar, int n);
int main(void)
{
	double diff;
	double num[SIZE];
	printf("Enter five numbers:");
	scanf("%lf,%lf,%lf,%lf,%lf", num, num + 1, num + 2, num + 3, num + 4);
	rev(num, SIZE);
	printf("The reversed array is %.1f,%.1f,%.1f,%.1f,%.1f\n", *num, *(num + 1), *(num + 2), *(num + 3), *(num + 4));
	return 0;
}
void rev(double* ar, int n)
{
	int i;
	double temp;
	for (i = 0; i < n / 2; i++)
	{
		temp = *(ar + i);
		*(ar + i) = *(ar + n - i - 1);
		*(ar + n - i - 1) = temp;
	}
}
//7
#define L 5
void copy_ptr(double(*tg)[L], double(*sr)[L], int n);
int main(void)
{
	int col;
	double source[2][L] = { {1.1,2.2,3.3,4.4,5.5},{6.6,7.7,8.8,9.9,11.0} };
	double target[2][L];
	double(*ptr)[L]; /*行指针*/
	copy_ptr(target, source, 2);
	for (ptr = source; ptr < source + 2; ptr++)
	{
		for (col = 0; col < L; col++)
			printf("%.1f ", *(*ptr + col));
		putchar('\n');
	}
	for (ptr = target; ptr < target + 2; ptr++)
	{
		for (col = 0; col < L; col++)
			printf("%.1f ", *(*ptr + col));
		putchar('\n');
	}
	return 0;
}
void copy_ptr(double(*tg)[L], double(*sr)[L], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < L; j++)
			* (*(tg + i) + j) = *(*(sr + i) + j);
	}
}
//8
#define L1 7
#define L2 3
void copy_ptr(double* tg2, double* sr, int n);
int main(void)
{
	double source[L1] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7 };
	double target2[L2];
	double* ptr;
	copy_ptr(target2, source, L2);
	for (ptr = source; ptr < source + L1; ptr++)
		printf("%.1f ", *ptr);
	putchar('\n');
	for (ptr = target2; ptr < target2 + L2; ptr++)
		printf("%.1f ", *ptr);
	putchar('\n');
	return 0;
}
void copy_ptr(double* tg2, double* sr, int n)
{
	int i;
	for (i = 0; i < n; i++)
		* (tg2 + i) = *(sr + i + 2);
}
//9
#define COL 5
void copy(int m, double ar1[][COL], double ar2[][COL]);
void print(int m, double ar1[][COL], double ar2[][COL]);
int main(void)
{
	double ar1[3][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
	double ar2[3][5];
	copy(3, ar1, ar2);
	print(3, ar1, ar2);
	return 0;
}
void copy(int m, double ar1[][COL], double ar2[][COL])
{
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < COL; j++)
			* (*(ar2 + i) + j) = *(*(ar1 + i) + j);
}
void print(int m, double ar1[][COL], double ar2[][COL])
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("ar1[%d][%d]=%.1f   ", i, j, *(*(ar1 + i) + j));
		}
		putchar('\n');
	}
	putchar('\n');
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("ar2[%d][%d]=%.1f   ", i, j, *(*(ar1 + i) + j));
		}
		putchar('\n');
	}
	putchar('\n');
}
//10
//<1>
void addup(int* ar1, int* ar2, int* ar3, int n);
int main(void)
{
	int i;
	int ar1[4] = { 2,4,5,8 };
	int ar2[4] = { 1,0,4,6 };
	int ar3[4];
	addup(ar1, ar2, ar3, 4);
	for (i = 0; i < 4; i++)
	{
		printf("%d ", *(ar3 + i));
	}
	return 0;
}
void addup(int* ar1, int* ar2, int* ar3, int n)
{
	int i;
	for (i = 0; i < n; i++)
		* (ar3 + i) = *(ar1 + i) + *(ar2 + i);
}
//(原题目)
//<2>
void addup(int* ar1, int* ar2, int* ar3, int n);
int main(void)
{
	int i;
	int ar1[4];
	int ar2[4];
	int ar3[4];
	printf("Enter 4 letter to complete the first array,using comma to seperate:");
	scanf("%d,%d,%d,%d", ar1, ar1 + 1, ar1 + 2, ar1 + 3);
	printf("Enter 4 letter to complete the first array,using comma to seperate:");
	scanf("%d,%d,%d,%d", ar2, ar2 + 1, ar2 + 2, ar2 + 3);
	addup(ar1, ar2, ar3, 4);
	printf("The added-up array is:");
	for (i = 0; i < 4; i++)
	{
		printf("ar3[%d]=%d ", i, *(ar3 + i));
	}
	return 0;
}
void addup(int* ar1, int* ar2, int* ar3, int n)
{
	int i;
	for (i = 0; i < n; i++)
		* (ar3 + i) = *(ar1 + i) + *(ar2 + i);
}
//(数组内容自己输入)
//<3>
#define SIZE 4
void addup_num(double* ar1, double* ar2, double* ar3, int n);
void addup_ch(char* ar1, char* ar2, char* ar3, int n);
int main(void)
{
	char select;
	int i;
	printf("Would you like to explore a add-up between to array of characters or numbers?\n"
		"C.characters                      N.numbers\n");
	printf("Your choice(Press q to quit):");
	while (scanf("%c", &select) == 1)
	{
		while (getchar() != '\n')
			continue;
		if (select == 'N')
		{
			double ar1[SIZE];
			double ar2[SIZE];
			double ar3[SIZE];
			printf("Enter %d number to complete the first array,using comma to seperate:", SIZE);
			scanf("%lf,%lf,%lf,%lf", ar1, ar1 + 1, ar1 + 2, ar1 + 3);
			while (getchar() != '\n')
				continue;
			printf("Enter %d number to complete the first array,using comma to seperate:", SIZE);
			scanf("%lf,%lf,%lf,%lf", ar2, ar2 + 1, ar2 + 2, ar2 + 3);
			while (getchar() != '\n')
				continue;
			addup_num(ar1, ar2, ar3, SIZE);
			printf("The added-up array is:");
			for (i = 0; i < SIZE; i++)
			{
				printf("ar3[%d]=%.1f, ", i, *(ar3 + i));
			}
			putchar('\n');
			printf("Would you like to explore a add-up between to array of characters or numbers?\n"
				"C.characters                      N.numbers\n");
			printf("Your choice(Press q to quit):");
		}
		if (select == 'C')
		{
			char ch1[SIZE];
			char ch2[SIZE];
			char ch3[SIZE];
			printf("Enter %d character to complete the first array,using comma to seperate:", SIZE);
			scanf("%c,%c,%c,%c", ch1, ch1 + 1, ch1 + 2, ch1 + 3);
			while (getchar() != '\n')
				continue;
			printf("Enter %d character to complete the first array,using comma to seperate:", SIZE);
			scanf("%c,%c,%c,%c", ch2, ch2 + 1, ch2 + 2, ch2 + 3);
			while (getchar() != '\n')
				continue;
			addup_ch(ch1, ch2, ch3, SIZE);
			printf("The added-up array is:");
			for (i = 0; i < SIZE; i++)
			{
				printf("ar3[%d]=%c, ", i, *(ch3 + i));
			}
			putchar('\n');
			printf("Would you like to explore a add-up between to array of characters or numbers?\n"
				"C.characters                      N.numbers\n");
			printf("Your choice(Press q to quit):");
		}
		if (select == '\n')
			continue;
		if (select == 'q')
			break;
		else
			printf("ERROR!Please enter one of the two options:");

	}
	printf("Done.");
	return 0;
}
void addup_num(double* ar1, double* ar2, double* ar3, int n)
{
	int i;
	for (i = 0; i < n; i++)
		* (ar3 + i) = *(ar1 + i) + *(ar2 + i);
}
void addup_ch(char* ar1, char* ar2, char* ar3, int n)
{
	int i;
	for (i = 0; i < n; i++)
		* (ar3 + i) = *(ar1 + i) + *(ar2 + i);
}
//(能处理任意大小的字符型和浮点型一维数组)
//11
void twice(int(*ar)[5], int m);
void print(int(*ar)[5], int m);
int main(void)
{
	int ar[3][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
	print(ar, 3);
	putchar('\n');
	twice(ar, 3);
	print(ar, 3);
	return 0;
}
void twice(int(*ar)[5], int m)
{
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < 5; j++)
			ar[i][j] *= 2;
}
void print(int(*ar)[5], int m)
{
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < 5; j++)
			printf("%d ", *(*(ar + i) + j));
}
//12
#define MONTHS 12
#define YEARS 5
float tot1(const float(*ptr)[MONTHS], int n);
void tot2(const float(*ptr)[MONTHS], int n);
int main(void)
{
	const float rain[YEARS][MONTHS] =
	{ {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
	{8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
	{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
	{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
	{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2} };
	int year, month;
	float subtot, total;
	printf("YEAR     RAINFALL(INCHES)\n");

	total = tot1(rain, YEARS);

	printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
	printf("MONTHLY AVERAGES:\n\n");
	printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");

	tot2(rain, YEARS);
	printf("\n");
	return 0;
}
float tot1(const float(*ptr)[MONTHS], int n)
{
	int i, j;
	float subtot, total;
	for (i = 0, total = 0; i < n; i++)
	{
		for (j = 0, subtot = 0; j < MONTHS; j++)
			subtot += *(*(ptr + i) + j);
		printf("%5d %15.1f\n", 2010 + i, subtot);
		total += subtot;
	}
	return total;
}
void tot2(const float(*ptr)[MONTHS], int n)
{
	int i, j;
	float subtot;
	for (i = 0; i < MONTHS; i++)
	{
		for (j = 0, subtot = 0; j < n; j++)
			subtot += *(*(ptr + j) + i);
		printf("%4.1f", subtot / n);
	}
}
//13
//<1>
#define ROW 3
#define COL 5
void storage(int m, double(*ptr)[COL]);
double av_everow(double(*ptr)[COL], int m);
double av_all(double(*ptr)[COL], int m);
double max_all(double(*ptr)[COL], int m);
void print(double n);
int main(void)
{
	int i, j;
	double average, max;
	double num[ROW][COL];
	double avperrow[ROW];
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
	average = av_all(num, ROW);
	max = max_all(num, ROW);
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
	printf("\nAnd the largest number of all %d numbers is:", ROW * COL);
	print(max);
	putchar('\n');
	printf("\nDone.");
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
			scanf("%lf", *(ptr + i) + j);
		}
		printf("num[%d][%d]=", i, COL - 1);
		scanf("%lf", *(ptr + i) + COL - 1);
		while (getchar() != '\n')
			continue;
	}
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
void print(double n)
{
	printf("%.2f", n);
}
//(原题要求)
//<2>
//根据题干，加入输入验证
#define ROW 3
#define COL 5
void storage(int m, double(*ptr)[COL]);
double av_everow(double(*ptr)[COL], int m);
double av_all(double(*ptr)[COL], int m);
double max_all(double(*ptr)[COL], int m);
void print(double n);
int main(void)
{
	int i, j;
	double average, max;
	double num[ROW][COL];
	double avperrow[ROW];
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
	average = av_all(num, ROW);
	max = max_all(num, ROW);
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
	printf("\nAnd the largest number of all %d numbers is:", ROW * COL);
	print(max);
	putchar('\n');
	printf("\nDone.");
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
void print(double n)
{
	printf("%.2f", n);
}
