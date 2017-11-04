#include<stdlib.h>
#include "menu.h"

int Quit(int argc, char *argv[])
{
    /*  add XXX clean ops */
    exit(0);
}

int main(int argc, char *argv[])
{
    MenuConfig("version","XXX V1.0(Menu program v1.0 inside)",NULL);
    MenuConfig("quit","Quit from XXX",Quit);

    ExecuteMenu();
}
