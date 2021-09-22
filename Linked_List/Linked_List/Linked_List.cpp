// Linked_List.cpp : This file contains the 'main' function. Program execution begins and ends there.

//Create a linked list with following functionalities 

#include <iostream>
#include<stdio.h>
#include<malloc.h>

struct node
{
	int no;
	struct node* next;
};
typedef struct node node;
node* start = NULL;

void AddAtEnd(int item)
{
	node *p, *loc;
	p = (node*)malloc(sizeof(node));
	p->no = item;
	p->next = NULL;
	if (start == NULL)
	{
		start = p;
	}
	else
	{
		loc = start;
		while (loc->next != NULL)
		{
			
			loc = loc->next;
		}
		printf("%d-AddAtEnd\n", p->no);
		loc->next = p;
	}
}

void AddAtBegin(int item)
{
	node* p;
	p = (node*)malloc(sizeof(node));
	p->no = item;
	if (start == NULL)
		p->next = NULL;
	else
		p->next = start;
	start = p;
	printf("%d-AddAtBegin\n", p->no);
}


void InsertatGivenPosition(int item, int pos)
{
	node* p,* temp;
	int ctr = 1;
	temp = start;
	while (ctr < pos - 1)
	{
		temp = temp->next;
		ctr++;
	}
	p = (node*)malloc(sizeof(node));
	p->no = item;
	printf("%d-InsertatGivenPosition\n", p->no);
	p->next = temp->next;
	temp->next = p;
}

void GetFromGivenPosition(int pos)
{
	node* temp;
	int ctr = 1;
	temp = start;
	while (ctr <= pos - 1)
	{
		temp = temp->next;
		ctr++;
	}
	printf("%d-GetFromGivenPosition\n", temp->no);
}

void RemoveFromGivenPosition(int pos)
{
	node* p,* temp;
	int ctr = 1;
	temp = start;
	while (ctr < pos - 1)
	{
		temp = temp->next;
		ctr++;
	}
	p = temp->next;
	printf("%d-Remove Number\n", p->no);
	temp->next = p->next;
	free(p);
}


void DisplayAllItems()
{
	node* items;
	if (start == NULL)
	{
		printf("No Items\n");
	}
	items = start;
	printf("Display All Items\n");
	while (items != NULL)
	{
		printf("%d\n", items->no);
		items = items->next;
	}
}

int main()
{
	AddAtEnd(10);
	AddAtBegin(30);
	AddAtEnd(40);
	InsertatGivenPosition(20, 2);
	DisplayAllItems();
	GetFromGivenPosition(4);
	RemoveFromGivenPosition(2);
	DisplayAllItems();
}