#include "../Headers/HelperFunction.h"
 
bool UnloadModule(const char * ModuleName){

    //remove module by syscall if the operation succeed the function return zero so we compare it to zero  
    return syscall(SYS_delete_module,ModuleName,(O_NONBLOCK | O_TRUNC))==0;
}
bool loadModule(const char * ModuleName,unsigned long Len, const char *Paramters){

    //add module by syscall if the operation succeed the function return zero so we compare it to zero  
    return syscall(SYS_init_module,ModuleName,Len,Paramters)==0;
}
void ExitIfNotRoot()
{
    uid_t  uid = getuid(); 
     if (uid<0) {
        printf("Sorry This Application need to be run in SuperUser mode \n");
        system("exit");
    }
}
/*
git file size
*/
long GetFileSize(const char* FilePath){
//variable to store File Attributes
struct stat FileAttributes;
//get file Attributes
stat(FilePath, &FileAttributes);
//return File Size
return FileAttributes.st_size;
}