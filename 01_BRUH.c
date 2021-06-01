#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int value;
	struct node *next;
} node;

typedef struct list
{
	struct node *head;
} list;
void init(list *l)
{
	l->head = NULL;
}
void clean(list *l)
{
	if (l->head != NULL)
	{
		node *star = NULL;
		while (l->head->next)
		{
			star = l->head;
			l->head = l->head->next;
			free(star);
		}
		free(l->head);
		star = NULL;
		l->head = NULL;
	}
	else
		printf("Ошибка");
}
bool is_empty(list *l)
{
	if (l->head)
		return true;
	else
		return false;
}
node *find(list *l, int value)
{
	node *star = l->head;
	while ((star != NULL) && (star->value != value))
		star = star->next;
	if (star == NULL)
	{
		printf("0 ");
		return NULL;
	}
	else
	{
		printf("1 ");
		star = NULL;
	}
}
int push_back(list *l, int value)
{
	if (l->head != NULL)
	{
		node *star = l->head;
		while (star->next != NULL)
			star = star->next;
		star->next = malloc(sizeof(node));
		star->next->value = value;
		star->next->next = NULL;
		star = NULL;
		return 0;
	}
	else
	{
		node *star = malloc(sizeof(node));
		star->value = value;
		star->next = l->head;
		l->head = star;
		star = NULL;
		return 0;
	}
}
int push_front(list *l, int value)
{
	node *star = malloc(sizeof(node));
	star->value = value;
	star->next = l->head;
	l->head = star;
	star = NULL;
	return 0;
}
int insert_after(node *n, int value)
{
	if (n!=NULL)
	{
	node *star = malloc(sizeof(node));
	star->value = value;
	star->next = n->next;
	n->next = star;
	star = NULL;
	return 0;
	}
	else
	{
		printf("Ошибка");
		return 2;
	}
}
node *list_index(list *l, int v)
{
	node *star = l->head;
	int index = 0;
	while (index != v - 1 && star != NULL)
	{
		star = star->next;
		++index;
	}
	return star;
}
int remove_node(list *l, int value)
{
	if (l->head == NULL)
		return 1;
	else
	{
		node *star = l->head;
		node *temp = NULL;
		while (star != NULL)
		{
			if (star->value == value)
			{
				if (temp == NULL)
				{
					l->head = star->next;
					free(star);
					star = NULL;
					return 0;
				}
				temp->next = star->next;
				free(star);
				star = NULL;
				return 0;
			}
			temp = star;
			star = star->next;
		}
		return 1;
	}
}
void print(list *l)
{
	node *star = l->head;
	while (star != NULL)
	{
		printf("%d ", star->value);
		star = star->next;
	}
}

int main()
{
	int n;
	(void)scanf("%d", &n);
	list l;
	init(&l);
	int a;
	for (int i = 1; i <= n; ++i)
	{
		(void)scanf("%d", &a);
		push_back(&l, a);
	}
	print(&l);
	printf("\n");
	for (int k = 1; k <= 3; ++k)
	{
		(void)scanf("%d", &a);
		find(&l, a);
	}
	printf("\n");
	int m;
	(void)scanf("%d", &m);
	push_back(&l, m);
	print(&l);
	printf("\n");
	int c;
	(void)scanf("%d", &c);
	push_front(&l, c);
	print(&l);
	printf("\n");
	int j, x;
	(void)scanf("%d", &j);
	(void)scanf("%d", &x);
	node *usel = list_index(&l, j);
	insert_after(usel, x);
	print(&l);
	printf("\n");
	int z;
	(void)scanf("%d", &z);
	remove_node(&l, z);
	print(&l);
	printf("\n");
	clean(&l);
	bool b = is_empty(&l);
	return 0;
}