#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
//1
typedef int Item;
#define MAXSTACK 10
typedef struct stack {
	Item item[MAXSTACK];
	int top;
}Stack;
typedef Stack* poo;
void Initializestack(poo);
bool Fullstack(const poo);
bool Emptystack(const poo);
bool Push(Item item, poo);
bool Pop(Item item, poo);
//2
#define TSIZE 45
struct film {
	char title[TSIZE];
	int rating;
	struct film* next;
	struct film* pre;/*设置正反指针*/
};
char* s_gets(char* st, int n);
int main(void)
{
	struct film* head = NULL;
	struct film* prev, * current, * next;
	char input[TSIZE];
	/*收集并存储信息*/
	puts("Enter first movie title:");
	while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
	{
		current = (struct film*)malloc(sizeof(struct film));
		if (head == NULL)
		{
			head = current;
			head->pre = NULL;
		}
		else
		{
			prev->next = current;
			current->pre = prev;
		} current->next = NULL;
		strcpy(current->title, input);
		puts("Enter your rating <0-10>:");
		scanf("%d", &current->rating);
		while (getchar() != '\n');
		puts("Enter next movie title (empty line to stop):");
		prev = current;
	}
	/*正序显示电影列表*/
	if (head == NULL)
		printf("No data entered.");
	else
		printf("Here is the movie list(by sequence):\n");
	current = head;
	while (current != NULL)
	{
		printf("Movie:%s Rating:%d\n", current->title, current->rating);
		current = current->next;
	}
	/*反序显示电影列表*/
	puts("Here is the movie list(by inverted sequence):");
	current = prev;
	while (current != NULL)
	{
		printf("Movie:%s Rating:%d\n", current->title, current->rating);
		current = current->pre;
	}
	/*删除所有项*/
	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	printf("Bye!\n");
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
			* find = '\0';
		else while (getchar() != '\n')
			continue;
	}
	return ret_val;
}
//3
//list2.h
#ifndef LIST_H_    
#define LIST_H_   
#include <stdbool.h>
#define TSIZE 45
struct film {
	char title[TSIZE];
	int rating;
};
typedef struct film Item;
typedef struct node {
	Item item;
	struct node* next;
} Node;
typedef struct list {
	Node* head;
	Node* end;
} List;
void InitializeList(List* plist);
bool ListIsEmpty(const List* plist);
bool ListIsFull(const List* plist);
unsigned int ListItemCount(const List* plist);
bool AddItem(Item item, List* plist);
void Traverse(const List* plist, void(*pfun)(Item item));
void EmptyTheList(List* plist);
void ShowEnd(List* plist);
#endif
#pragma once
//list2.c
//include "list2.h"
static void CopyToNode(Item item, Node* pnode);
void InitializeList(List* plist)
{
	(*plist).head = NULL;
	(*plist).end = NULL;
}
bool ListIsEmpty(const List* plist)
{
	if ((*plist).head == NULL)
		return true;
	else
		return false;
}
bool ListIsFull(const List* plist)
{
	Node* pt;
	bool full;
	pt = (Node*)malloc(sizeof(Node));
	if (pt == NULL)
		full = true;
	else
		full = false;
	return full;
}
unsigned int ListItemCount(const List* plist)
{
	unsigned int count = 0;
	Node* pnode = (*plist).head;
	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;
	}
	return count;
}
bool AddItem(Item item, List* plist)
{
	Node* pnew;
	Node* scan = (*plist).head;
	pnew = (Node*)malloc(sizeof(Node));
	if (pnew == NULL)
		return false;
	CopyToNode(item, pnew);
	pnew->next = NULL;
	if (scan == NULL)
		(*plist).head = pnew;
	else
	{
		while (scan->next != NULL)
			scan = scan->next;
		scan->next = pnew;
	}
	(*plist).end = pnew;
	return true;
}
void Traverse(const List* plist, void(*pfun)(Item item))
{
	Node* pnode = (*plist).head;
	while (pnode != NULL)
	{
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}
void EmptyTheList(List* plist)
{
	Node* psave;
	while ((*plist).head != NULL)
	{
		psave = (*plist).head->next;
		free((*plist).head);
		(*plist).head = psave;
	}
}
void ShowEnd(List* plist)    //新增函数
{
	printf("Movies:%s Rating:%d\n", (*plist).end->item.title, (*plist).end->item.rating);
}
static void CopyToNode(Item item, Node* pnode)
{
	pnode->item = item;
}
//film3_2.c
//include "list2.h"
void showmovies(Item item);
char* s_gets(char* st, int n);
int main(void)
{
	List movies;
	Item temp;
	InitializeList(&movies);
	if (ListIsFull(&movies))
	{
		fprintf(stderr, "No memeory available!Bye!\n");
		exit(1);
	}
	puts("Enter first movie title:");
	while (s_gets(temp.title) != NULL && temp.title[0] != '\0')
	{
		puts("Enter your rating <0-10>:");
		scanf("%d", &temp.rating);
		while (getchar() != '\n');
		if (AddItem(temp, &movies) == false)
		{
			fprintf(stderr, "Problem allocating memory\n");
			break;
		}
		if (ListIsFull(&movies))
		{
			puts("The list is now full.");
			break;
		}
		puts("Enter next movie title(empty line to stop):");
	}
	if (ListIsEmpty(&movies))
		printf("No data entered.");
	else
	{
		printf("Here is the movie list :\n");
		Traverse(&movies, showmovies);
	}
	printf("Last movie is\n");
	ShowEnd(&movies);
	printf("You entered %d movies.\n", ListItemCount(&movies));
	EmptyTheList(&movies);
	printf("Bye!\n");
	return 0;
}
void showmovies(Item item)
{
	printf("Movies:%s Rating:%d\n", item.title, item.rating);
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
			* find = '\0';
		else while (getchar() != '\n')
			continue;
	}
	return ret_val;
}
//4
//list3.h
#ifndef LIST_H_    
#define LIST_H_   
#define TSIZE 45
#define MAXSIZE 100
struct film {
	char title[TSIZE];
	int rating;
};
typedef struct film Item;
//typedef struct node {
//    Item item;
//    struct node * next;
//} Node;
typedef struct list {
	Item enteries[MAXSIZE];
	int items;
} List;
void InitializeList(List* plist);
bool ListIsEmpty(const List* plist);
bool ListIsFull(const List* plist);
unsigned int ListItemCount(const List* plist);
bool AddItem(Item item, List* plist);
void Traverse(const List* plist, void(*pfun)(Item item));
void EmptyTheList(List* plist);
#endif
//list3.c
//#include "list3.h"
static void CopyToNode(Item item, Item* pnode);
void InitializeList(List* plist)
{
	(*plist).items = 0;
}
bool ListIsEmpty(const List* plist)
{
	if ((*plist).items == 0)
		return true;
	else
		return false;
}
bool ListIsFull(const List* plist)
{
	bool full;
	if ((*plist).items == MAXSIZE - 1)
		full = true;
	else
		full = false;
	return full;
}
unsigned int ListItemCount(const List* plist)
{
	return (unsigned int)(*plist).items;
}
bool AddItem(Item item, List* plist)
{
	if ((*plist).items == MAXSIZE - 1)
		return false;
	(*plist).enteries[(*plist).items++] = item;
	return true;
}
void Traverse(const List* plist, void(*pfun)(Item item))
{
	int i = 0;
	while (i < (*plist).items)
		(*pfun)((*plist).enteries[i++]);
}
void EmptyTheList(List* plist)
{
	while (*plist != NULL)
	{
		psave = (*plist).head->next;
		free((*plist).head);
		(*plist).head = psave;
	}
}
static void CopyToNode(Item item, Item* pnode)
{
	pnode = &item;
}
//film3_2.c
//#include "list3.h"
void showmovies(Item item);
char* s_gets(char* st, int n);
int main(void)
{
	List movies;
	Item temp;
	InitializeList(&movies);
	if (ListIsFull(&movies))
	{
		fprintf(stderr, "No memeory available!Bye!\n");
		exit(1);
	}
	puts("Enter first movie title:");
	while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
	{
		puts("Enter your rating <0-10>:");
		scanf("%d", &temp.rating);
		while (getchar() != '\n');
		if (AddItem(temp, &movies) == false)
		{
			fprintf(stderr, "Problem allocating memory\n");
			break;
		}
		if (ListIsFull(&movies))
		{
			puts("The list is now full.");
			break;
		}
		puts("Enter next movie title(empty line to stop):");
	}
	if (ListIsEmpty(&movies))
		printf("No data entered.");
	else
	{
		printf("Here is the movie list :\n");
		Traverse(&movies, showmovies);
	}
	printf("You entered %d movies.\n", ListItemCount(&movies));
	EmptyTheList(&movies);
	printf("Bye!\n");
	return 0;
}
void showmovies(Item item)
{
	printf("Movies:%s Rating:%d\n", item.title, item.rating);
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
			* find = '\0';
		else while (getchar() != '\n')
			continue;
	}
	return ret_val;
}
//5
/*其他两份文件不改变*/
//#include "queue.h"
#define MIN_PER_HR 60.0

bool newcustomer(double x);
Item customertime(long when);

int main(void)
{
	Queue line1, line2;
	Item temp1, temp2;
	int hours1, hours2;
	int perhour1, perhour2;
	long cycle1, cyclelimit1, cycle2, cyclelimit2;
	long turnaways1 = 0;
	long turnaways2 = 0;
	long customers1 = 0;
	long customers2 = 0;
	long served1 = 0;
	long served2 = 0;
	long sum_line1 = 0;
	long sum_line2 = 0;
	int wait_time1 = 0;
	int wait_time2 = 0;
	double min_per_cust1, min_per_cust2;
	long line_wait1 = 0;
	long line_wait2 = 0;

	InitializeQueue(&line1);
	InitializeQueue(&line2);
	srand(time(0));
	puts("Case Study:Sigmund Lander's Advice Booth");
	puts("Enter the number of simulation hours for queue1:");
	scanf("%d", &hours1);
	cyclelimit1 = MIN_PER_HR * hours1;
	puts("Enter the number of simulation hours for queue2:");
	scanf("%d", &hours2);
	cyclelimit2 = MIN_PER_HR * hours2;
	puts("Enter the average number of customers per hour for queue1:");
	scanf("%d", &perhour1);
	min_per_cust1 = MIN_PER_HR / perhour1;
	puts("Enter the average number of customers per hour for queue2:");
	scanf("%d", &perhour2);
	min_per_cust2 = MIN_PER_HR / perhour2;


	for (cycle1 = 0; cycle1 < cyclelimit1; cycle1++)
	{
		if (newcustomer(min_per_cust1))
		{
			if (QueueIsFull(&line1))
				turnaways1++;
			else
			{
				customers1++;
				temp1 = customertime(cycle1);
				EnQueue(temp1, &line1);
			}
		}
		if (wait_time1 <= 0 && !QueueIsEmpty(&line1))
		{
			DeQueue(&temp1, &line1);
			wait_time1 = temp1.processtime;
			line_wait1 += cycle1 - temp1.arrive;
			served1++;
		}
		if (wait_time1 > 0)
			wait_time1--;
		sum_line1 += QueueItemCount(&line1);
	}
	for (cycle2 = 0; cycle2 < cyclelimit2; cycle2++)
	{
		if (newcustomer(min_per_cust2))
		{
			if (QueueIsFull(&line2))
				turnaways2++;
			else
			{
				customers2++;
				temp2 = customertime(cycle2);
				EnQueue(temp2, &line2);
			}
		}
		if (wait_time2 <= 0 && !QueueIsEmpty(&line2))
		{
			DeQueue(&temp2, &line2);
			wait_time2 = temp2.processtime;
			line_wait2 += cycle2 - temp2.arrive;
			served2++;
		}
		if (wait_time2 > 0)
			wait_time2--;
		sum_line2 += QueueItemCount(&line2);
	}


	if (customers1 > 0)
	{
		printf("customers accepted for queue1:%ld\n", customers1);
		printf(" customers served for queue1:%ld\n", served1);
		printf("    turnaways for queue1:%ld\n", turnaways1);
		printf("average wait time for queue1:%.2f minutes\n", (double)line_wait1 / served1);
	}
	else
		puts("No cunstomers for queue1!");
	EmptyTheQueue(&line1);
	if (customers2 > 0)
	{
		printf("customers accepted for queue2:%ld\n", customers2);
		printf(" customers served for queue2:%ld\n", served2);
		printf("    turnaways for queue2:%ld\n", turnaways2);
		printf("average wait time for queue2:%.2f minutes\n", (double)line_wait2 / served2);
	}
	else
		puts("No cunstomers for queue2!");
	EmptyTheQueue(&line2);
	puts("Bye!");

	return 0;
}

bool newcustomer(double x)
{
	if (rand() * x / RAND_MAX < 1)
		return true;
	else
		return false;
}

Item customertime(long when)
{
	Item cust;

	cust.processtime = rand() % 3 + 1;
	cust.arrive = when;

	return cust;
}
//6
//list5.h
#pragma once
#ifndef LIST_H_  
#define LIST_H_   
#define TSIZE 45
struct film {
	char title[TSIZE];
	int rating;
};
typedef struct film Item;
typedef struct node {
	Item item;
	struct node* next;
} Node;
typedef Node* List;
void InitializeList(List* plist);
bool ListIsEmpty(const List* plist);
bool ListIsFull(const List* plist);
unsigned int ListItemCount(const List* plist);
bool AddItem(Item item, List* plist);
bool PopItem(Item* item, List* plist);
void Traverse(const List* plist, void(*pfun)(Item item));
void EmptyTheList(List* plist);
#endif
//list5.c
//#include "list5.h"
static void CopyToNode(Item item, Node* pnode);
void InitializeList(List* plist)
{
	*plist = NULL;
}
bool ListIsEmpty(const List* plist)
{
	if (*plist == NULL)
		return true;
	else
		return false;
}
bool ListIsFull(const List* plist)
{
	Node* pt;
	bool full;
	pt = (Node*)malloc(sizeof(Node));
	if (pt == NULL)
		full = true;
	else
		full = false;
	return full;
}
unsigned int ListItemCount(const List* plist)
{
	unsigned int count = 0;
	Node* pnode = *plist;
	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;
	}
	return count;
}
bool AddItem(Item item, List* plist)
{
	Node* pnew;
	Node* scan = *plist;
	pnew = (Node*)malloc(sizeof(Node));
	if (pnew == NULL)
		return false;
	CopyToNode(item, pnew);
	pnew->next = NULL;
	if (scan == NULL)
		* plist = pnew;
	else
	{
		while (scan->next != NULL)
			scan = scan->next;
		scan->next = pnew;
	}
	return true;
}
bool PopItem(Item* item, List* plist)
{
	Node* prev;
	Node* current = *plist;
	if (current == NULL)
		return false;
	if (current->next == NULL)
	{
		*item = current->item;
		*plist = NULL;
	}
	else
	{
		while (current->next != NULL)
		{
			prev = current;
			current = current->next;
		}
		prev->next = NULL;
		*item = current->item;
	}
	free(current);
	return true;
}
void Traverse(const List* plist, void(*pfun)(Item item))
{
	Node* pnode = *plist;
	while (pnode != NULL)
	{
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}
void EmptyTheList(List* plist)
{
	Node* psave;
	while (*plist != NULL)
	{
		psave = (*plist)->next;
		free(*plist);
		*plist = psave;
	}
}
static void CopyToNode(Item item, Node* pnode)
{
	pnode->item = item;
}
//operating.c
//#include "list5.h"
void showchar(Item item);
int main(void)
{
	List line;
	Item temp;
	char ch;


	InitializeList(&line);
	puts("Enter your line:");
	while ((ch = getchar()) != '\n')
	{
		temp.title[0] = ch;
		temp.title[1] = '\0';
		AddItem(temp, &line);
	}
	puts("Show line:");
	Traverse(&line, showchar);
	printf("\n");
	puts("Show line by inverted sequence:");
	while (line != NULL)
	{
		PopItem(&temp, &line);
		printf("%s", temp.title);
	}
	printf("\n");
	puts("Bye!");
	return 0;
}
void showchar(const Item item)
{
	printf("%s", item.title);
}
//7
#define SIZE 20
int com(const void*, const void*);
int find(const int*, size_t, int);
int main(void)
{
	int n, i, input, numbers[SIZE];
	int result;
	srand(time(0));
	for (i = 0; i < SIZE; i++)
		numbers[i] = rand() % 1000;
	qsort(numbers, SIZE, sizeof(int), com);
	puts("There are numbers:");
	for (i = 0; i < SIZE; i++)
		printf(" %d", numbers[i]);
	putchar('\n');
	puts("Input which number you want to find:");
	scanf("%d", &input);
	result = find(numbers, SIZE, input);
	if (result)
		printf("find it!\n");
	else
		printf("Do not find it!\n");
	return 0;
}
int com(const void* p1, const void* p2)
{
	const int* ps1 = (const int*)p1;
	const int* ps2 = (const int*)p2;
	if (*ps1 > * ps2)
		return 1;
	else if (*ps1 == *ps2)
		return 0;
	else
		return -1;
}
int find(const int* arr, size_t len, int in)
{
	size_t index = len / 2;
	size_t low = 0;
	size_t high = len;
	int result;
	if (arr[index] == in)
		return 1;
	while (arr[index] != in)
	{
		if (in > arr[index])
			low = index;
		else
			high = index;
		if (index == (low + high) / 2)
			break;
		else
			index = (low + high) / 2;
	}
	if (arr[index] == in)
		result = 1;
	else
		result = 0;
	return result;
}
//8
//tree.h
#ifndef _TREE_H_
#define _TREE_H_
typedef struct item {
	char word[40];
	int times;
} Item;
#define MAXITEMS 1000
typedef struct node {
	Item item;
	struct node* left;
	struct node* right;
} Node;
typedef struct tree {
	Node* root;
	int size;
} Tree;
void InitializeTree(Tree* ptree);
bool TreeIsEmpty(const Tree* ptree);
bool TreeIsFull(const Tree* ptree);
int TreeItemCount(const Tree* ptree);
bool AddItem(const Item* pi, Tree* ptree);
bool InTree(const Item* pi, const Tree* ptree);
void Report(const Tree* pt);
bool DeleteItem(const Item* pi, Tree* ptree);
void Traverse(const Tree* ptree, void(*pfun)(Item item));
void DeleteAll(Tree* ptree);
#endif
//tree7.c
//#include "tree.h"
typedef struct pair {
	Node* parent;
	Node* child;
} Pair;
static Node* MakeNode(const Item* pi);
static bool ToLeft(const Item* i1, const Item* i2);
static bool ToRight(const Item* i1, const Item* i2);
static void AddNode(Node* new_node, Node* root);
static void InOrder(const Node* root, void(*pfun)(Item item));
static Pair SeekItem(const Item* pi, const Tree* ptree);
static void DeleteNode(Node** ptr);
static void DeleteAllNodes(Node* ptr);
void InitializeTree(Tree* ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}
bool TreeIsEmpty(const Tree* ptree)
{
	if (ptree->root == NULL)
		return true;
	else
		return false;
}
bool TreeIsFull(const Tree* ptree)
{
	if (ptree->size == MAXITEMS)
		return true;
	else
		return false;
}
int TreeItemCount(const Tree* ptree)
{
	return ptree->size;
}
bool AddItem(const Item* pi, Tree* ptree)
{
	Node* new_node;
	if (TreeIsFull(ptree))
	{
		fprintf(stderr, "Tree is full\n");
		return false;
	}
	new_node = MakeNode(pi);
	if (new_node == NULL)
	{
		fprintf(stderr, "Couldn't create node\n");
		return false;
	}
	ptree->size++;
	if (ptree->root == NULL)
		ptree->root = new_node;
	else
		AddNode(new_node, ptree->root);
	return true;
}
bool InTree(const Item* pi, const Tree* ptree)
{
	return (SeekItem(pi, ptree).child == NULL) ? false : true;
}
void Report(const Tree* pt)
{
	Item temp;
	Pair pair;
	int t;
	puts("which word you want to count");
	scanf("%s", temp.word);
	while (getchar() != '\n');
	pair = SeekItem(&temp, pt);
	if (pair.child == NULL)
		printf("No entries!\n");
	else
	{
		t = pair.child->item.times;
		printf("%s appears %d times\n", temp.word, t);
	}
}
bool DeleteItem(const Item* pi, Tree* ptree)
{
	Pair look;
	look = SeekItem(pi, ptree);
	if (look.child == NULL)
		return false;
	if (look.parent == NULL)
		DeleteNode(&ptree->root);
	else if (look.parent->left == look.child)
		DeleteNode(&look.parent->left);
	else
		DeleteNode(&look.parent->right);
	ptree->size--;
	return true;
}
void Traverse(const Tree* ptree, void(*pfun)(Item item))
{
	if (ptree != NULL)
		InOrder(ptree->root, pfun);
}
void DeleteAll(Tree* ptree)
{
	if (ptree != NULL)
		DeleteAllNodes(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}
static void InOrder(const Node* root, void(*pfun)(Item item))
{
	if (root != NULL)
	{
		InOrder(root->left, pfun);
		(*pfun)(root->item);
		InOrder(root->right, pfun);
	}
}
static void DeleteAllNodes(Node* root)
{
	Node* pright;
	if (root != NULL)
	{
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}
}
static void AddNode(Node* new_node, Node* root)
{
	if (ToLeft(&new_node->item, &root->item))
	{
		if (root->left == NULL)
			root->left = new_node;
		else
			AddNode(new_node, root->left);
	}
	else if (ToRight(&new_node->item, &root->item))
	{
		if (root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node, root->right);
	}
	else
	{
		(root->item.times)++;
		free(new_node);
	}
}
static bool ToLeft(const Item* i1, const Item* i2)
{
	int comp1;
	if ((comp1 = strcmp(i1->word, i2->word)) < 0)
		return true;
	else
		return false;
}
static bool ToRight(const Item* i1, const Item* i2)
{
	int comp1;
	if ((comp1 = strcmp(i1->word, i2->word)) > 0)
		return true;
	else
		return false;
}
static Node* MakeNode(const Item* pi)
{
	Node* new_node;
	new_node = (Node*)malloc(sizeof(Node));
	if (new_node != NULL)
	{
		new_node->item = *pi;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return new_node;
}
static Pair SeekItem(const Item* pi, const Tree* ptree)
{
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;
	if (look.child == NULL)
		return look;
	while (look.child != NULL)
	{
		if (ToLeft(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (ToRight(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else
			break;
	}
	return look;
}
static void DeleteNode(Node** ptr)
{
	Node* temp;
	puts((*ptr)->item.word);
	if ((*ptr)->left == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	}
	else if ((*ptr)->right == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
	else
	{
		for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
			continue;
		temp->right = (*ptr)->right;
		temp = (*ptr);
		(*ptr) = (*ptr)->left;
		free(temp);
	}
}
//op.c
//#include "tree.h"
char menu(void);
void show(Item item);
int main(int argc, char* argv[])
{
	char ch;
	Tree file;
	FILE* fp;
	Item* temp;
	if (argc != 2)
	{
		fprintf(stderr, "Usage:commond filename\n");
		exit(1);
	}
	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(2);
	}
	while (fscanf(fp, "%s", (*temp).word) == 1)
	{
		(*temp).times = 1;
		AddItem(temp, &file);
	}
	fclose(fp);
	while ((ch = menu()) != 'q')
	{
		switch (ch)
		{
		case 's':Traverse(&file, show);
			break;
		case 'r':Report(&file);
		}
	}
	puts("Bye!");
	DeleteAll(&file);
	return 0;
}
char menu(void)
{
	char ch;
	do
	{
		puts("file is opened,what do you want to do:");
		puts("s)show all words and its times");
		puts("r)find a word and report its times");
		puts("q)quit");
		ch = getchar();
		while (getchar() != '\n');
	} while (ch != 's' && ch != 'r' && ch != 'q' && puts("wrong input,try again"));
	return ch;
}
void show(Item item)
{
	printf("%s appear %d times\n", item.word, item.times);
}

