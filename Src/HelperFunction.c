#include "../Headers/HelperFunction.h"
char * CreateCommand(char * Permission,char *FilePath)
{
    char *command;
    asprintf(&command,"chmod %s %s",Permission,FilePath);
    system(command);
    return command;
}