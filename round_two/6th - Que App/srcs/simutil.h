#ifndef _SIM_UTIL_
#define _SIM_UTIL_


#include "simlinkedqueue.h"


// �� ���� -> �� ��� -> ���� ��� -> free 
// -> ��ť, ��ȯ���� ���� ť�� ��ť



/**
 * �� ����Ʈ�� ���� ť�� �ִٰ�, �ý���Ÿ�Ӱ� �� �����ð��� ��ġ�ϸ�
 * ��� ť�� �Ѿ. ���� ���࿡ �����ߴٴ� �ǹ�.
 * serviceNode�� �����Ǿ������
 * ���� serviceNode�� ���� �ð��̴�?
 * ������ ���� ����, �ƴϸ� ��� ����
 * serviceNode ����ִ�?
 * �׷� ���� start
 */




// �� ���� ť�� �� �߰�
void insertCustomer(int arrivalTime, int serviceTime, LinkedQueue *pArrivalQueue);

// �� ���� ó��
// currentTime : system�� ���� �ð�
void processArrival(LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue);

// ���� ���� ó��
QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue);


// ���� ���� ó��
QueueNode* processServiceNodeEnd(int currentTime, QueueNode *pServiceNode,
					  int *pServiceUserCount, int *pTotalWaitTime);

// ���� ���¸� ���
void printSimCustomer(int currentTime, SimCustomer customer);

// ��⿭�� ���¸� ���
void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue);

// ���� �ùķ��̼� ���(���ġ) ���
void printReport(LinkedQueue *pWaitQueue, LinkedQueue *pArrivalQueue, 
				int serviceUserCount,
				int totalWaitTime);

#endif