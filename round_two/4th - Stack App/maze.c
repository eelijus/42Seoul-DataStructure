/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maze.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:22:45 by sujilee           #+#    #+#             */
/*   Updated: 2022/02/08 11:28:28 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedstack.h"
#

int		validation_check(LinkedStack *history, MapPosition curr)
{

	int x = curr.x;
	int y = curr.y;
	
	if (x < 0 || x >= history->max_width)
	{
		return FALSE;
	}
	if (y < 0 || y >= history->max_height)
	{
		return FALSE;
	}
	
	if (history->maze[y][x] > 0)
		return FALSE;

	return TRUE;
}


MapPosition move_hyopark(MapPosition currPosition , int direction)
{
	MapPosition retPos;
	retPos.x = currPosition.x + DIRECTION_OFFSETS[direction][0];
	retPos.y = currPosition.y + DIRECTION_OFFSETS[direction][1];
	retPos.direction = NODIRECTION;
	return (retPos);
}

void printMaze(LinkedStack *history)
{
	for (int i = 0 ; i < WIDTH ; i ++)
	{
		for (int j = 0 ; j < HEIGHT ; j++)
		{
			printf("%d ",history->maze[i][j]);
		}
		printf("\n ");
	}
	printf("\n ");
}

int maze(LinkedStack *history, MapPosition prevPos, int direction)
{
	//���� ȿ���� ��ġ -> ȿ���� ���ִ� ��
	StackNode prev;
	//���� ȿ���� ��ġ -> ȿ���� ���� ��
	StackNode curr;

	printMaze(history);

	//prev�� ���� ����
	prev.data = prevPos;
	prev.data.direction = direction;
	//curr�� �̵��� ȿ���� ���� ����
	curr.data = move_hyopark(prevPos ,direction);
	
	//��� ����!!
	//�� ��ġ�� ���� ��ȿ�� �˻� : �� �� ���� ���̸� fail!
	if (!validation_check(history,curr.data))
		return (FALSE);
	//�� ��ġ�� �� ����Ʈ�� Ż��!
	else if (curr.data.x == WIDTH - 1 &&curr.data.y == HEIGHT - 1)
	{
		history->maze[curr.data.y][curr.data.x] = 2;
		pushLS(history, prev);
		pushLS(history,curr);
		//���⼭ TURE�� ��ȯ�Ǹ� ���Ž���� ���� �� �ϳ��� TRUE�� ��ȯ�ϰ� ��� ��Ͱ� ���������� �������� ������.
		return (TRUE);
	}
	//���� �̷��� ���� ���
	else
	{
		//�� ��ġ�� ���ÿ� Ǫ��
		pushLS(history, prev);
		//���ڱ� ���
		history->maze[curr.data.y][curr.data.x] = 2;

		//��, ��, ��, ���� ������ ���� �̷θ� Ž���Ѵ�.
		// || �����ڷ� �����⿡ �տ������� �ϳ��� �����Ѵٸ� TRUE ��ȯ(���������� ��͸� ���� ������Ʈ�� �����ϸ� ���� TRUE ��ȯ)
		if (maze(history,curr.data,EAST) || maze(history, curr.data, SOUTH)||maze(history, curr.data, WEST)||maze(history, curr.data, NORTH))
			return (TRUE);
		//����� �������� ���
		else
		{
			//���� ��
			popLS(history);
			return (FALSE);
		}
	}

}

int main(int ac, char **av)
{
	LinkedStack *history = NULL;

	history = createLinkedStack();
	history->max_height = WIDTH;
	history->max_width = HEIGHT;

	//���� ��ġ ��ǥ
	MapPosition startPosition;
	startPosition.x = 0;
	startPosition.y = 0;
	//ù ���� �� ������ ��𷺼�
	startPosition.direction = NODIRECTION;

	int mazeArr[WIDTH][HEIGHT] = {
		{0, 0, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 0},
	};

	history->maze = mazeArr;

	//maze ȣ��!!
	//ù maze ȣ�� �ÿ��� ���� �� �ߵ��̱⶧���� ��𷺼��� ����
	if (maze(history, startPosition, NODIRECTION))
	{
		printMaze(history);
		printf("GOAL!!!\n");
		displayLinkedStack(history);
	}
	else
	{
		printf("not vailed map!!!\n");
	}
	return 0;

}
