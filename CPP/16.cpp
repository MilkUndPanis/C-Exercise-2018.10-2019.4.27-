#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdarg.h>
//1
#ifndef DRAFT_ALLDEFINE_H
#define DRAFT_ALLDEFINE_H 
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) > (Y) ? (Y) : (X))
#endif 
//2
#define AV(x,y) (((2)*(x)*(y))/((x)+(y)))
int main(void)
{
	int x = 2;
	int y = 2;
	printf("%d", AV(x, y));
	return 0;
}
//3
#define TRANS (180/(4*atan(1)))
struct polar {
	double length;
	double arg;
};
struct descartes {
	double x;
	double y;
};
struct descartes* tran(struct polar* pr);
struct descartes* tran(struct polar* pr)
{
	struct descartes* prm;
	prm->x = (pr->length) * cos(pr->arg);
	prm->y = (pr->length) * sin(pr->arg);
	return prm;
}
//4
void delay(double a);
int main(void)
{
	double time;
	printf("The frog want to steal your time(unit:second):");
	while (scanf("%lf", &time) == 1)
	{
		while (getchar() != '\n')
			continue;
		delay(time);
		printf("The frog want to steal your time(unit:second):");
	}
	printf("You are too young too simple.");
	return 0;
}
void delay(double a)
{
	double s = (double)clock();
	double f = 0;
	while ((a - f) > 0.00000001)
	{
		f = ((double)clock() - s) / CLOCKS_PER_SEC;
	}
	printf("%.10lf s have passed\n", f);
}
//5
void select(int ar[], int n, int times);
int main(void)
{
	int ar[50], argc, times;
	scanf("%d,%d", &argc, &times);
	for (int i = 0; i < argc; ++i)
		scanf("%d", &ar[i]);
	select(ar, argc, times);
	return 0;
}
void select(int ar[], int n, int times)
{
	srand((unsigned long)time(0));
	int x;
	int* b = (int*)malloc(sizeof(int));
	while (n)
	{
		x = rand();
		if (b[x] == 1)
			continue;
		else printf("[%d]=%d ", x, ar[x]);
		b[x] = 1;
		n--;
	}
	free(b);
}
//6
typedef struct names {
	char first[40];
	char last[40];
}names;
names vals[100];
void fillarray(names ar[], int n);
void showarray(const names ar[], int n);
int mycomp(const void* p1, const void* p2);
int main(void)
{
	fillarray(vals, 100);
	puts("Random list:");
	showarray(vals, 100);
	qsort(vals, 100, sizeof(names), mycomp);
	puts("\nSorted list:");
	showarray(vals, 100);
	return 0;
}
void fillarray(names ar[], int n)
{
	int index;
	int x;
	srand((unsigned long)time(0));
	for (index = 0; index < n; index++)
	{
		x = rand() % 10 + 1;
		for (int i = 0; i < x; ++i)
		{
			ar[index].first[i] = rand() % 26 + 'a';
		}
		x = rand() % 10 + 1;
		for (int i = 0; i < x; ++i)
		{
			ar[index].last[i] = rand() % 26 + 'a';

		}
	}
}
void showarray(const names ar[], int n)
{
	int index;
	for (index = 0; index < n; index++)
	{
		printf("%10s.%-10s ", ar[index].first, ar[index].last);
		if (index % 4 == 3)
			putchar('\n');
	}
	if (index % 4 != 0)
		putchar('\n');
}
int mycomp(const void* p1, const void* p2)/* 要使用指向double的指针来访问这两个值 */
{
	const names* a1 = (const names*)p1;
	const names* a2 = (const names*)p2;
	int x = strcmp(a1->first, a2->first);
	if (x)
		return x;
	else
		return 0;
}
//7
void show_array(const double ar[], int n);
double* new_d_array(int n, ...);
int main(void)
{
	double* p1;
	double* p2;
	p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
	p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
	show_array(p1, 5);
	show_array(p2, 4);
	free(p1);
	free(p2);
	return 0;
}
void show_array(const double ar[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("[%d]=%.3f\n", i, ar[i]);
}
double* new_d_array(int n, ...)/*n is ParmN.*/
{
	int i;
	double* pr = (double*)malloc(sizeof(double) * n);
	va_list ap;
	va_start(ap, n);
	for (i = 0; i < n; i++)
		pr[i] = va_arg(ap, double);
	va_end(ap);
	return pr;
}
