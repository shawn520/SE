#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"

#define SUCCESS 0
#define FAILURE (-1)

tLinkTable *CreateLinkTable()
{
    tLinkTable *pLinkTable = (tLinkTable *)malloc(sizeof(tLinkTable));
    if (pLinkTable == NULL)
    {
        printf("malloc error!\n");
        return NULL;
    }
    pLinkTable->pHead = NULL;
    pLinkTable->pTail = NULL;
    pLinkTable->SumOfNode = 0;
    pthread_mutex_init(&(pLinkTable->mutex), NULL);
    return pLinkTable;
}

int DeleteLinkTable(tLinkTable *pLinkTable)
{
    if (pLinkTable == NULL)
    {
        return SUCCESS;
    }
    while (pLinkTable->pHead != NULL)
    {
        tLinkTableNode *pNode = pLinkTable->pHead;
        pLinkTable->pHead = pNode->pNext;
        free(pNode);
    }
    free(pLinkTable);
    return SUCCESS;
}

int AddLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode)
{
    if (pLinkTable == NULL || pNode == NULL)
    {
        printf("AddLinkTableNode error!\n");
        return FAILURE;
    }
    pNode->pNext = NULL;
    if (pLinkTable->pHead == NULL)
    {
        pLinkTable->pHead = pNode;
        pLinkTable->pTail = pNode;
        pLinkTable->SumOfNode += 1;
    }
    else
    {
        pLinkTable->pTail->pNext = pNode;
        pLinkTable->pTail = pNode;
        pLinkTable->SumOfNode += 1;
    }
    return SUCCESS;
}

int DelLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode)
{
    if (pLinkTable == NULL || pNode == NULL)
    {
        printf("DelLinkTableNode error!\n");
        return FAILURE;
    }
    tLinkTableNode *pFront = pLinkTable->pHead;
    if (pFront == NULL)
    {
        printf("pLinkTable is NULL!\n");
        return FAILURE;
    }
    else if (pFront == pNode)
    {
        pLinkTable->pHead = pFront->pNext;
        free(pFront);
        return SUCCESS;
    }
    tLinkTableNode *pBack = pFront;
    pFront = pFront->pNext;
    while (pFront != NULL)
    {
        if (pFront == pNode)
        {
            pBack->pNext = pFront->pNext;
            free(pFront);
            return SUCCESS;
        }
        pFront = pFront->pNext;
        pBack = pBack->pNext;
    }
    printf("not find error!\n");
    return FAILURE;
}

tLinkTableNode *GetLinkTableHead(tLinkTable *pLinkTable)
{
    if (pLinkTable == NULL)
    {
        return NULL;
    }
    return pLinkTable->pHead;
}

tLinkTableNode *GetNextLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode)
{
    if (pLinkTable == NULL || pNode == NULL)
    {
        return NULL;
    }
    tLinkTableNode *p = pLinkTable->pHead;
    if (p == NULL)
    {
        return NULL;
    }
    while (p != NULL)
    {
        if (p == pNode)
        {
            return p->pNext;
        }
        p = p->pNext;
    }
    return NULL;
}
