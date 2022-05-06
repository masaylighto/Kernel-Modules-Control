#include <stdio.h>
#include <stdlib.h> 
#include <sys/syscall.h>
#include <unistd.h>
#include <fcntl.h>
#include<stdbool.h>
#ifndef H_HelperMethod
#define H_HelperMethod
/*
this function make use of syscall to remove Kernel module
*/
bool UnloadModule(const char * ModuleName);
/*
this function make sure you are a superuser or end the application
*/
void ExitIfNotRoot();

#endif