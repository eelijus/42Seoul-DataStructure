#ifndef _MAP_DEF_
#define _MAP_DEF_

#define WIDTH 8
#define HEIGHT 8
#define NUM_DIRECTIONS 4

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// offset: x, y
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, -1},		// �������� �̵�.
	{1, 0},			// ���������� �̵�.
	{0, 1},			// �Ʒ������� �̵�.
	{-1, 0}			// �������� �̵�.
};

enum PosStatus { NOT_VISIT = 0, WALL = 1 , VISIT = 2  };

typedef struct MapPositionType
{
	int x;				// ���� ��ġ x��ǥ.
	int y;				// ���� ��ġ y��ǥ.
	int direction;		// ���� ��ġ�� �̵� ����
} MapPosition;

#define NORTH 0 //����
#define EAST 1 //������
#define SOUTH 2 //�Ʒ���
#define WEST 3 //����
#define NODIRECTION 4

#endif