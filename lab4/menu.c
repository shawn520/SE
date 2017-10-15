#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linktable.h"

#define     FILEPATH_MAX          80
#define     CMD_MAX_LENGTH         128

void help();        
void quit();

typedef struct DataNode
{
    tLinkTableNode *pNext;
    char *cmd;
    char *desc;
    void (*handler)();
}tDataNode;

char cwdbuff[64] = {0};
char cwdbuffsub[64] = {0};
//declare a tLinkTable


tLinkTable *head = NULL;
//find the command
tDataNode *FindCmd(tLinkTable *head, char *cmd)
{
    tDataNode *pNode = (tDataNode *)GetLinkTableHead(head);
    while (pNode != NULL)
    {
        if (strcmp(pNode->cmd, cmd) == 0)
        {
            return pNode;
        }
        pNode = (tDataNode *)GetNextLinkTableNode(head, (tLinkTableNode *)pNode);
    }
    return NULL;
}
//show the desc
int ShowAllCmd(tLinkTable *head)
{
    tDataNode *pNode = (tDataNode *)GetLinkTableHead(head);
    while (pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode *)GetNextLinkTableNode(head, (tLinkTableNode *)pNode);
    }
    return 0;
}
//init
int InitMenuData(tLinkTable **ppLinktable)
{
    *ppLinktable = CreateLinkTable();

    tDataNode *pNode = (tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd = "help";
    pNode->desc = "This is help command.";
    pNode->handler = help;
    AddLinkTableNode(*ppLinktable, (tLinkTableNode *)pNode);

    pNode = (tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd = "quit";
    pNode->desc = "quit the command line.";
    pNode->handler = quit;
    AddLinkTableNode(*ppLinktable, (tLinkTableNode *)pNode);
    return 0;
}

int main ()
{
    char getCommand[CMD_MAX_LENGTH];
    InitMenuData(&head);
    while(1)
    {
        printf("Please Input Command: ");
        scanf("%s",getCommand);
        tDataNode *p = FindCmd(head,getCommand);
        if(p == NULL)
        {
            printf("error: Wrong Command!!\n");        
        }
        else
        {
            p -> handler();
        }
    }
    return 0;
}

//show commmand imformation
void help()
{
    ShowAllCmd(head);
}

//exit
void quit()
{
    exit(0);
}
