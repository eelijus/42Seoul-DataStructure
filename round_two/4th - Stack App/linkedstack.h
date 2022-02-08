#ifndef _LINKED_STACK_
#define _LINKED_STACK_

#include "mapdef.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


// typedef struct MapPositionType
// {
// 	int x;				// ���� ��ġ x��ǥ.
// 	int y;				// ���� ��ġ y��ǥ.
// 	int direction;		// ���� ��ġ�� �̵� ����
// } MapPosition;

typedef struct StackNodeType
{
	MapPosition data;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;	// ���� ������ ����
	int max_width;
	int max_height;
	int (*maze)[WIDTH];

	StackNode* pTopElement;		// Top ����� ������
} LinkedStack;

LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, StackNode element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);
void displayLinkedStack(LinkedStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define EXIT		2
#define TRUE		1
#define FALSE		0

#endif