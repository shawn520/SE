#ifndef __LINK_TABLE_H__
#define __LINK_TABLE_H__

#include<pthread.h>

#define SUCCESS 0
#define FAILURE (-1)

//LinkTable Node Type

typedef struct LinkTableNode
{
    struct LinkTableNode *pNext;
}tLinkTableNode;

//LinkTable Type
typedef struct LinkTable
{
    tLinkTableNode *pHead;
    tLinkTableNode *pTail;
    int SumOfNode;
    pthread_mutex_t mutex;
}tLinkTable;

//Create a LinkTable
tLinkTable *CreateLinkTable();

//Delete LinkTable
int DeleteLinkTable(tLinkTable *pLinkTable);

//Add CMD
int AddLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode);

//Delete CMD
int DelLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode);

//Get LinkTableHead
tLinkTableNode *GetLinkTableHead(tLinkTable *pLinkTable);

//Get nextLinkTableNode
tLinkTableNode *GetNextLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode);

#endif
