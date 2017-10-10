B3_LINKLIST_H

/*data struct and its operation*/
typedef struct
{
	    char* cmd;
		    char* desc;
			    int (*handler)();
				    struct DataNode *next;
}
/*find a cmd in the linklist and return the DataNode pointer */
tDataNode* FindCmd(tDataNode *head,char *cmd);

/*show all cmd in linklist */
int ShowAllCmd(tDataNode *head);
