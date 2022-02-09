/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleteLinkedDeque.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:49:01 by sujilee           #+#    #+#             */
/*   Updated: 2022/02/09 15:37:14 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkeddeque.h"

void			deleteLinkedDeque(LinkedDeque** pDeque)
{
	DequeNode	*curr;	
	DequeNode	*temp;
	
	
	if (!pDeque || !(*pDeque))
		return ;
	curr = (*pDeque)->pFrontNode;
	while (curr)
	{
		temp = curr;
		//temp�� curr�� �ּҰ� �����ϱ� ������ free(temp)�� �����ϸ�
		//curr�� ���� ����ִ� �ּ� ���� free
		curr = curr->pRLink;
		free(temp);
		temp = NULL;
	}
	free(*pDeque);
	*pDeque = NULL;
}