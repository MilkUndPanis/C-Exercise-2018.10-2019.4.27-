#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
//1
struct month {
	const char FUNAME[15];
	const char MONAME[4];
	int days;
	int num;
};
#define size 12
struct month months[size] = { {"January","Jan",31,1},
{"February","Feb",28,2},{"March","Mar",31,3} ,{"April","Apr",30,4},{"May","May",31,5},{"June","Jun",30,6},
{"July","Jul",31,7} ,{"August","Aug",31,8},{"September","Sep",30,9},{"October","Oct",31,10},
{"November","Nov",30,11},{"December","Dec",31,12} };
int totaldays(char* str);
int main(void)
{
	char op[15];
	printf("Enter the name of a month:");
	fgets(op, 15, stdin);
	printf("The total days from Jan 1 to the last day of %s is:", op);
	printf("%d days.", totaldays(op));
	return 0;
}
int totaldays(char* str)
{
	int index, total = 0;
	bool ismonth = 0;
	int monthowari;
	for (index = 0; index < size; index++)
	{
		if (strncmp(str, months[index].FUNAME, strlen(months[index].FUNAME)) != 0)
			ismonth = 0;
		if (strncmp(str, months[index].FUNAME, strlen(months[index].FUNAME)) == 0)
		{
			ismonth = 1;
			monthowari = index;
			break;
		}
	}
	if (ismonth == 0)
		return -1;
	if (ismonth == 1)
	{
		for (int i = 0; i <= monthowari; i++)
			total += months[i].days;
		return total;
	}
}
//2
struct month {
	const char FUNAME[15];
	const char MONAME[4];
	int days;
	int num;
};
#define size 12
struct month nonleapmonths[size] = { {"January","Jan",31,1},
{"February","Feb",28,2},{"March","Mar",31,3} ,{"April","Apr",30,4},{"May","May",31,5},{"June","Jun",30,6},
{"July","Jul",31,7} ,{"August","Aug",31,8},{"September","Sep",30,9},{"October","Oct",31,10},
{"November","Nov",30,11},{"December","Dec",31,12} };
struct month leapmonths[size] = { {"January","Jan",31,1},
{"February","Feb",29,2},{"March","Mar",31,3} ,{"April","Apr",30,4},{"May","May",31,5},{"June","Jun",30,6},
{"July","Jul",31,7} ,{"August","Aug",31,8},{"September","Sep",30,9},{"October","Oct",31,10},
{"November","Nov",30,11},{"December","Dec",31,12} };
int totaldays(int year, char* str, int day);
int main(void)
{
	char op[15];
	int year;
	int day;
	printf("Enter a year:");
	scanf("%d", &year);
	while (getchar() != '\n')
		continue;
	printf("Enter the name of a month:");
	fgets(op, 15, stdin);
	printf("Enter the day:");
	scanf("%d", &day);
	while (getchar() != '\n')
		continue;
	printf("The total days from %d Jan 1 to the %d %s %d is:", year, year, op, day);
	printf("%d days.", totaldays(year, op, day));
	return 0;
}
int totaldays(int year, char* str, int day)
{
	int index, total = 0;
	bool ismonth = 0;
	int monthowari;
	for (index = 0; index < size; index++)
	{
		if (strncmp(str, leapmonths[index].FUNAME, strlen(leapmonths[index].FUNAME)) != 0)
			ismonth = 0;
		if (strncmp(str, leapmonths[index].FUNAME, strlen(leapmonths[index].FUNAME)) == 0)
		{
			ismonth = 1;
			monthowari = index;
			break;
		}
	}
	if (ismonth == 0)
		return -1;
	if (ismonth == 1)
	{
		if ((year % 100 != 0 && year % 4 == 0) || (year % 100 == 0 && year % 400 == 0))
		{
			if (monthowari == 0)
				return day;
			else
			{
				for (int i = 0; i < monthowari; i++)
					total += leapmonths[i].days;
				total += day;
			}
		}
		else {
			if (monthowari == 0)
				return day;
			else
			{
				for (int i = 0; i < monthowari; i++)
					total += nonleapmonths[i].days;
				total += day;
			}
		}
		return total;
	}
}
//3
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  100
struct book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
char* s_gets(char* st, int n);
int p14_3(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index;

	printf("Please enter the book title.\n");
	printf("Please [enter] at the start of a line to stop.\n");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
		&& library[count].title[0] != '\0')
	{
		printf("Now enter the author.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("Now enter the value.\n");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
		{
			continue;
		}
		if (count < MAXBKS)
		{
			printf("Enter the next title.\n");
		}
	}

	if (count > 0)
	{
		printf("Here is the list of your books:\n");
		printf("Array by original:\n");
		for (index = 0; index < count; index++)
		{
			printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
		}/*常规输出*/
		printf("\n");

		printf("Array by title:\n");
		for (int i = 0; i < count; i++)
		{
			for (int j = i; j < count; j++)
			{
				if (strcmp(library[i].title, library[j].title) > 0)
				{
					struct book tmp = library[i];
					library[i] = library[j];
					library[j] = tmp;
				}
			}/*冒泡法对标题成员所在的结构数组排序*/
		}

		for (index = 0; index < count; index++)
		{
			printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
		}/*输出按照标题*/
		printf("\n");

		printf("Array by value:\n");
		for (int i = 0; i < count; i++)
		{
			for (int j = i; j < count; j++)
			{
				if (library[i].value > library[j].value)
				{
					struct book tmp = library[i];
					library[i] = library[j];
					library[j] = tmp;
				}/*冒泡法对价格成员所在的结构数组排序*/
			}
		}

		for (index = 0; index < count; index++)
		{
			printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
		}
		printf("\n");/*输出按照价钱*/
	}
	else
		printf("No books? Too bad.\n");

	return 0;
}
char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
		{
			*find = '\0';
		}
		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}
	return ret_val;
}
//4
struct fulname {
	char namae[20];
	char nakanona[20];
	char sei[20];
};
struct infor {
	int soinnum[9];
	struct fulname name;
};
char* s_gets(char* st, int n);
int main(void)
{
	int i;
	struct infor informa;
	for (i = 0; i < 9; i++)
		scanf("%d", &informa.soinnum[i]);
	s_gets(informa.name.namae, 20);
	s_gets(informa.name.nakanona, 20);
	s_gets(informa.name.sei, 20);
	if (informa.name.nakanona[0] == '\0')
	{
		printf("%s,%s ----", informa.name.sei, informa.name.namae);
		for (i = 0; i < 9; i++)
			printf("%d", informa.soinnum[i]);
	}
	else
	{
		printf("%s,%s %c. ----", informa.name.sei, informa.name.namae, informa.name.nakanona[0]);
		for (i = 0; i < 9; i++)
			printf("%d", informa.soinnum[i]);
	}
	return 0;
}
char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
		{
			*find = '\0';
		}
		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}
	return ret_val;
}
//5
struct name {
	char namae[20];
	char sei[20];
};
struct student {
	struct name name;
	float grade[3];
	float av;
};
#define CSIZE 4
char* s_gets(char* st, int n);
int main(void)
{
	int i;
	float aves[3];
	float totalav;
	struct student star[CSIZE];
	for (i = 0; i < CSIZE; i++)
	{
		printf("Enter the first name of student %d:", i + 1);
		s_gets(star[i].name.namae, 20);
		printf("Enter the first name of student %d:", i + 1);
		s_gets(star[i].name.sei, 20);
		printf("Enter three scores of student %d:\n", i + 1);
		for (int j = 0; j < 3; j++)
		{
			printf("%d:", j + 1);
			scanf("%f", &star[i].grade[j]);
			while (getchar() != '\n')
				continue;
		}
	}
	printf("Average score of every student:\n\n");
	for (i = 0; i < CSIZE; i++)
		star[i].av = (1.0 / 3.0) * (star[i].grade[0] + star[i].grade[1] + star[i].grade[2]);
	for (i = 0; i < 3; i++)
		aves[i] = (1.0 / (float)CSIZE) * (star[0].grade[i] + star[1].grade[i] + star[2].grade[i] + star[3].grade[i]);
	float total = 0;
	for (i = 0; i < CSIZE; i++)
		for (int j = 0; j < 3; j++)
		{
			total += star[i].grade[j];
		}
	totalav = total / (3 * CSIZE);
	for (i = 0; i < CSIZE; i++)
	{
		printf("Student %d %s %s:", i + 1, star[i].name.namae, star[i].name.sei);
		for (int j = 0; j < 3; j++)
			printf("Score %d:%.0f ", j + 1, star[i].grade[j]);
		putchar('\n');
		printf("Average of his three scores:%.0f\n\n", star[i].av);
	}
	printf("Every subject's average score is: %.0f %.0f %.0f\n", aves[0], aves[1], aves[2]);
	printf("Total's average score: %.0f\n", totalav);
	return 0;
}
char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
		{
			*find = '\0';
		}
		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}
	return ret_val;
}
//6
struct softball_player {
	char first_name[128];
	char last_name[128];
	int play_times;
	int hit_times;
	int run_bar_times;
	int rbi;
	double hit_rate;
};
int main(void)
{
	struct softball_player players[19] = { {'\0', '\0', 0, 0, 0, 0, 0.0} };
	FILE* fp;
	char file_name[128];
	struct softball_player player;
	int player_number;

	printf("Enter the file name: ");
	s_gets(file_name, 128);

	if ((fp = fopen(file_name, "r")) == NULL)
	{
		printf("Can't open the %s.\n", file_name);
	}

	while (feof(fp) == 0)
	{
		fscanf(fp, "%d", &player_number);
		fscanf(fp, "%s", &player.first_name);
		fscanf(fp, "%s", &player.last_name);
		fscanf(fp, "%d", &player.play_times);
		fscanf(fp, "%d", &player.hit_times);
		fscanf(fp, "%d", &player.run_bar_times);
		fscanf(fp, "%d", &player.rbi);
		if (players[player_number].first_name[0] == '\0')
		{
			players[player_number] = player;
		}
		else
		{
			players[player_number].play_times += player.play_times;
			players[player_number].hit_times += player.hit_times;
			players[player_number].run_bar_times += player.run_bar_times;
			players[player_number].rbi += player.rbi;
		}
	}

	for (int i = 0; i < 19; i++)
	{
		if (players[i].first_name[0] != '\0')
		{
			players[i].hit_rate = (double)players[i].hit_times / players[i].play_times;
		}
	}

	for (int i = 0; i < 19; i++)
	{
		if (players[i].first_name[0] != '\0')
		{
			printf("Player:%s %s, play times: %d, hit times: %d, run barrier times: %d, rbi: %d, hit_rate: %.2lf\n",
				players[i].first_name, players[i].last_name, players[i].play_times, players[i].hit_times, players[i].run_bar_times, players[i].rbi,
				players[i].hit_rate);
		}
	}
	return 0;
}
//7
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  100
struct book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	int thedelete;
};
char* s_gets(char* st, int n);
int main(void)
{
	struct book library[MAXBKS] = { {'\0', '\0', 0.0, 0} };
	int count = 0;
	int index, filecount;
	FILE* pbooks;
	int s_size = sizeof(struct book);

	if ((pbooks = fopen("book.dat", "r+b")) == NULL)
	{
		fputs("Can't open book.dat file\n", stderr);
	}

	rewind(pbooks);
	while (count < MAXBKS && fread(&library[count], s_size, 1, pbooks) == 1)
	{
		if (count == 0)
		{
			puts("Current contents of boot.dat:");
		}
		printf("%s by %s: $%.2f\n", library[count].title,
			library[count].author, library[count].value);
		count++;
	}
	filecount = count;
	if (count == MAXBKS)
	{
		fputs("The book.dat file is null.", stderr);
	}

	printf("Please enter the book.dat title.\n");
	printf("Please [enter] at the start of a line to stop.\n");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
		&& library[count].title[0] != '\0')
	{
		printf("Now enter the author.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("Now enter the value.\n");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
		{
			continue;
		}
		if (count < MAXBKS)
		{
			printf("Enter the next title.\n");
		}
	}

	if (count > 0)
	{
		printf("Here is the list of your books:\n");
		for (index = 0; index < count; index++)
		{
			printf("%d: %s by %s: $%.2f\n", index + 1, library[index].title, library[index].author, library[index].value);
		}
	}
	else
		puts("No books? Too bad.\n");

	while (1)
	{
		int item;
		char ch;
		printf("Which book do you want to delete or modify(-1 to exit)?");
		scanf("%d", &item);
		while (getchar() != '\n')
		{
			continue;
		}
		if (item == -1)
		{
			break;
		}
		printf("[D]elete or [M]dify?");
		scanf("%c", &ch);
		while (getchar() != '\n')
		{
			continue;
		}
		if (ch == 'D')
		{
			library[item - 1].thedelete = 1;
		}
		else
		{
			printf("Please enter the book title.\n");
			s_gets(library[item - 1].title, MAXTITL);
			printf("Now enter the author.\n");
			s_gets(library[item - 1].author, MAXAUTL);
			printf("Now enter the value.\n");
			scanf("%f", &library[item - 1].value);
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}
	/*关闭再以只读打开文件后可以完全清空文件*/
	fclose(pbooks);
	if ((pbooks = fopen("book.dat", "w")) == NULL)
	{
		printf("Can't open boot.dat file\n");
	}
	for (int i = 0; i < count; i++)
	{
		if (library[i].thedelete != 1)
		{
			fwrite(&library[i], size, 1, pbooks);
		}
	}
	puts("Done.\n");
	fclose(pbooks);
	return 0;
}
char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
		{
			*find = '\0';
		}
		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}
	return ret_val;
}
//8

struct situ_persit {
	int index;
	bool booked;
	char surname[50];
	char name[50];
};
#define SIT 12
char* s_gets(char* st, int n);
void menu(void);
void showempty(struct situ_persit sit[]);
void shownumempty(struct situ_persit sit[]);
void showbooks(struct situ_persit sit[]);
void booking(struct situ_persit sit[]);
void unbooking(struct situ_persit sit[]);
int main(void)
{
	int i = 0;
	char op;
	struct situ_persit sit[SIT];
	for (i = 0; i < SIT; i++)
	{
		sit[i].booked = 0;
		sit[i].index = i + 1;
		for (int j = 0; j < 50; j++)
		{
			sit[i].surname[j] = '\0';
			sit[i].name[j] = '\0';
		}
	}
	printf("********************************************\n");
	printf("WELCOME TO GIANT AIRCRAFT COP SERVICE SYSTEM!\n");
	while (1)
	{
		menu();
		scanf("%c", &op);
		while (getchar() != '\n')
			continue;
		if (op == 'f')
		{
			printf("Exiting______------\n");
			break;
		}
		switch (op)
		{
		case 'a':shownumempty(sit); break;
		case 'b':showempty(sit); break;
		case 'c':showbooks(sit); break;
		case 'd':booking(sit); break;
		case 'e':unbooking(sit); break;
		default:break;
		}
		getchar();
	}
	return 0;
}
void menu(void)
{
	printf("To choose a function,enter its letter label:\n");
	printf("a) Show number of empty seats\n");
	printf("b) Show list of empty seats\n");
	printf("c) Show alphabetical list of seats\n");
	printf("d) Assign a customer to a seat assignment\n");
	printf("e) Delete a seat assignment\n");
	printf("f) Quit\n");
}
void showempty(struct situ_persit sit[])
{
	int i;
	for (i = 0; i < SIT; i++)
	{
		if (!sit[i].booked)
			printf("sit No.%d is unbooked.It is empty.\n", i + 1);
		else continue;
	}
}
void shownumempty(struct situ_persit sit[])
{
	int i;
	int num = 0;
	for (i = 0; i < SIT; i++)
	{
		if (!sit[i].booked)
			num++;
	}
	printf("%d of the %d sits are empty.\n", num, SIT);
}
void showbooks(struct situ_persit sit[])
{
	int i;
	int num = 0;
	char* temp;
	for (i = 0; i < SIT; i++)
	{
		if (sit[i].booked)
			num++;
	}
	if (num == 0)
	{
		printf("No sits are booked.\n");
		return;
	}
	else
	{
		printf("Show alphabetical:\n");
		for (int i = 0; i < SIT; i++)
		{
			if (sit[i].booked)
			{
				printf("%d booked by %s %s.\n", sit[i].index, sit[i].name, sit[i].surname);
			}
		}
		return;
	}
}
void booking(struct situ_persit sit[])
{
	int sitn;
	printf("********************************************\n");
	printf("WELCOME TO THE ASSIGNING SERVISE SYSTEM\n");
	printf("Entering the seat you want to book:");
	scanf("%d", &sitn);
	while (getchar() != '\n')
		continue;
	if (sit[sitn - 1].booked != 0)
	{
		printf("The seat is already booked.Try again.");
		return;
	}
	printf("Your name?");
	s_gets(sit[sitn - 1].name, 50);
	printf("Your surname?");
	s_gets(sit[sitn - 1].surname, 50);
	sit[sitn - 1].booked = 1;
	printf("Booking successfully.\n");
}
void unbooking(struct situ_persit sit[])
{
	int unsign;
	printf("********************************************\n");
	printf("WELCOME TO THE ASSIGNING SERVISE SYSTEM\n");
	printf("Entering the seat you want to unbook:");
	scanf("%d", &unsign);
	while (getchar() != '\n')
		continue;
	if (sit[unsign - 1].booked != 0)
	{
		printf("The seat is unbooked.Try again.");
		return;
	}
	else
	{
		sit[unsign - 1].booked = 0;
		for (int i = 0; i < 50; i++)
		{
			sit[unsign - 1].surname[i] = '\0';
			sit[unsign - 1].name[i] = '\0';
		}
		printf("Unbooked successfully.\n");
		return;
	}
}
char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
		{
			*find = '\0';
		}
		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}
	return ret_val;
}
//9
#define SIT 12
#define TOTAL 4
struct situ_persit {
	int index;
	bool booked;
	char surname[50];
	char name[50];
};
struct flightdealing {
	struct situ_persit sit[SIT];
	char flightnumber[4];
	bool dealing;
};
char flights[4][4] = { "102","311","444","519" };
char* s_gets(char* st, int n);
void menu(void);
void showempty(struct situ_persit sit[]);
void shownumempty(struct situ_persit sit[]);
void showbooks(struct situ_persit sit[]);
void booking(struct situ_persit sit[]);
void unbooking(struct situ_persit sit[]);
int main(void)
{
	int i = 0;
	char op;
	struct flightdealing deal[TOTAL];
	char flight[4];
	int status;
	for (int k = 0; k < TOTAL; k++)
	{
		for (i = 0; i < SIT; i++)
		{
			deal[k].sit[i].booked = 0;
			deal[k].sit[i].index = i + 1;
			for (int j = 0; j < 50; j++)
			{
				deal[k].sit[i].surname[j] = '\0';
				deal[k].sit[i].name[j] = '\0';
			}
		}
		for (i = 0; i < 4; i++)
			deal[k].flightnumber[i] = flights[k][i];
	}
	printf("********************************************\n");
	printf("WELCOME TO GIANT AIRCRAFT COP SERVICE SYSTEM!\n");
	while (1)
	{
		printf("Enter the flight you want to deal with----102,311,444,519:");
		scanf("%s", flight);
		while (getchar() != '\n')
			continue;
		for (i = 0; i < TOTAL; i++)
		{
			if (strcmp(flight, flights[i]) == 0)
			{
				status = i + 1;
				deal[i].dealing = 1;
				break;
			}
		}
		printf("The flight %s are dealing.\n", deal[status - 1].flightnumber);
		menu();
		scanf("%c", &op);
		while (getchar() != '\n')
			continue;
		if (op == 'f')
		{
			printf("Exiting______------\n");
			break;
		}
		switch (op)
		{
		case 'a':shownumempty(deal[status - 1].sit); break;
		case 'b':showempty(deal[status - 1].sit); break;
		case 'c':showbooks(deal[status - 1].sit); break;
		case 'd':booking(deal[status - 1].sit); break;
		case 'e':unbooking(deal[status - 1].sit); break;
		default:break;
		}
		getchar();
		deal[status - 1].dealing = 0;
	}
	return 0;
}
void menu(void)
{
	printf("To choose a function,enter its letter label:\n");
	printf("a) Show number of empty seats\n");
	printf("b) Show list of empty seats\n");
	printf("c) Show alphabetical list of seats\n");
	printf("d) Assign a customer to a seat assignment\n");
	printf("e) Delete a seat assignment\n");
	printf("f) Quit\n");
}
void showempty(struct situ_persit sit[])
{
	int i;
	for (i = 0; i < SIT; i++)
	{
		if (!sit[i].booked)
			printf("sit No.%d is unbooked.It is empty.\n", i + 1);
		else continue;
	}
}
void shownumempty(struct situ_persit sit[])
{
	int i;
	int num = 0;
	for (i = 0; i < SIT; i++)
	{
		if (!sit[i].booked)
			num++;
	}
	printf("%d of the %d sits are empty.\n", num, SIT);
}
void showbooks(struct situ_persit sit[])
{
	int i;
	int num = 0;
	char* temp;
	for (i = 0; i < SIT; i++)
	{
		if (sit[i].booked)
			num++;
	}
	if (num == 0)
	{
		printf("No sits are booked.\n");
		return;
	}
	else
	{
		printf("Show alphabetical:\n");
		for (int i = 0; i < SIT; i++)
		{
			if (sit[i].booked)
			{
				printf("%d booked by %s %s.\n", sit[i].index, sit[i].name, sit[i].surname);
			}
		}
		return;
	}
}
void booking(struct situ_persit sit[])
{
	int sitn;
	printf("********************************************\n");
	printf("WELCOME TO THE ASSIGNING SERVISE SYSTEM\n");
	printf("Entering the seat you want to book:");
	scanf("%d", &sitn);
	while (getchar() != '\n')
		continue;
	if (sit[sitn - 1].booked != 0)
	{
		printf("The seat is already booked.Try again.");
		return;
	}
	printf("Your name?");
	s_gets(sit[sitn - 1].name, 50);
	printf("Your surname?");
	s_gets(sit[sitn - 1].surname, 50);
	sit[sitn - 1].booked = 1;
	printf("Booking successfully.\n");
}
void unbooking(struct situ_persit sit[])
{
	int unsign;
	printf("********************************************\n");
	printf("WELCOME TO THE ASSIGNING SERVISE SYSTEM\n");
	printf("Entering the seat you want to unbook:");
	scanf("%d", &unsign);
	while (getchar() != '\n')
		continue;
	if (sit[unsign - 1].booked != 0)
	{
		printf("The seat is unbooked.Try again.");
		return;
	}
	else
	{
		sit[unsign - 1].booked = 0;
		for (int i = 0; i < 50; i++)
		{
			sit[unsign - 1].surname[i] = '\0';
			sit[unsign - 1].name[i] = '\0';
		}
		printf("Unbooked successfully.\n");
		return;
	}
}
char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
		{
			*find = '\0';
		}
		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}
	return ret_val;
}

