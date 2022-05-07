#include <stdio.h>
#include <stdlib.h> 
#include <sys/syscall.h>
#include <unistd.h>
#include <fcntl.h>
#include<stdbool.h>

#include <sys/stat.h>
#ifndef H_HelperMethod
#define H_HelperMethod
/*
this function make use of syscall to remove Kernel module
*/
bool UnloadModule(const char * ModuleName);
/*
this function make use of syscall to add Kernel module
*/
bool loadModule(const char * ModuleName,unsigned long Len, const char *Paramters);
/*
this function make sure you are a superuser or end the application
*/
void ExitIfNotRoot();
/*
get file size
*/
long GetFileSize(const char* FilePath);

#endif