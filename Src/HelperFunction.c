#include "../Headers/HelperFunction.h"

      #include <errno.h>

bool UnloadModule(const char * FilePath){

    //remove module by syscall if the operation succeed the function return zero so we compare it to zero  
    return syscall(SYS_delete_module,FilePath,(O_NONBLOCK | O_TRUNC))==0;
}

//Read File Binary
 void * ReadFileBytes(const char * FilePath,long FileSize)
 {
	int FileDiscriptor = open(FilePath, O_RDONLY, 0);
    void * FileBytes = malloc(FileSize);
    read(FileDiscriptor,FileBytes,FileSize);
	close(FileDiscriptor);
    return FileBytes;
 }
 bool LoadModule(const char * ModulePath,unsigned long ModuleFileSize, const char *Paramters){
    
    void* ModuleFileBytes= ReadFileBytes(ModulePath,ModuleFileSize);
    //add module by syscall if the operation succeed the function return zero so we compare it to zero  
    bool Result= syscall(SYS_init_module,ModuleFileBytes,ModuleFileSize,Paramters)==0;
    free(ModuleFileBytes);

    return Result;
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