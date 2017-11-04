/****************************************************************/
/* Copyright  (C)  SSE_USTC,  2017-2018                         */
/*                                                              */
/*  FILE NAME              :   menu.h                           */
/*  PRINCIPAL AUTHOR       :   shawn520                         */
/*  SUBSYSTEN NAME         :   menu                             */
/*  MODULE NAME            :   menu                             */
/*  LANGUAGE               :   C                                */ 
/*  TARGET ENVIRONMENT     :   ANY                              */
/*  DATE OF FIRST RELEASE  :   2017/11/3                        */
/****************************************************************/

/* 
 * Revision log:
 * Created by shawn520,2017/11/3
 * Verified callback and head/next for search by shawn520,2017/11/3
 */

/* add cmd to menu */
int MenuConfig(char * cmd, char * desc, void (*handler)(int argc, char *argv[]));

/* Menu Engine Execute */
int ExecuteMenu();
