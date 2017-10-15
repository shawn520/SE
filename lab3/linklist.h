                                                                            
/**************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2017-2018                          */
/*                                                                        */
/*  FILE NAME                   :   menu.c                                */
/*  PRINCIPAL AUTHOR            :   ShawnLiu                              */
/*  SUBSYSTEM NAME				:   menu                                  */
/*  MODULE NAME                 :   menu                                  */
/*  LANGUAGE					:   C                                     */
/*  TARGET ENVIRONMENT          :   ANY                                   */
/*  DATE OF FIRST RELEASE       :   2017/10/07                            */
/*  DESCRIPTION                 :   This is a menu program                */
/**************************************************************************/
   
/*
 * Revision log:
 *
 * Created by ShawnLiu, 2017/10/07
 *
 */

/* data struct and its operations */
typedef struct DataNode
{
	char*	cmd;
	char*	desc;
	int		(*handler)();
	struct	DataNode *next;
}tDataNode;

/* find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(tDataNode * head, char * cmd);

/* show all cmd in listlist*/
int ShowAllCmd(tDataNode * head);

int Help();
int Quit();
int Add();
int Sub();
int Mul();
int Div();

