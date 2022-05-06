#include "../Headers/HelperFunction.h"
char * CreateCommand(char * Permission,char *filePath)
{
    char *command;
    asprintf(&command,"chmod %s %s",Permission,filePath);
    system(command);
    return command;
}