#include "../Headers/HelperFunction.h"

      #include <errno.h>

bool UnloadModule(const char * FilePath){

    //remove module by syscall if the operation succeed the function return zero so we compare it to zero  
    return syscall(SYS_delete_module,FilePath,(O_NONBLOCK | O_TRUNC))==0;
}

static void *grab_file(const char *filename, unsigned long *size)
{
	unsigned int max = 16384;
	int ret, fd, err_save;
	void *buffer;

	if (strcmp(filename, "-") == 0)
		fd = dup(STDIN_FILENO);
	else
		fd = open(filename, O_RDONLY, 0);

	if (fd < 0)
		return NULL;

	buffer = malloc(max);
	if (!buffer)
		goto out_error;

	*size = 0;
	while ((ret = read(fd, buffer + *size, max - *size)) > 0) {
		*size += ret;
		if (*size == max) {
			void *p;

			p = realloc(buffer, max *= 2);
			if (!p)
				goto out_error;
			buffer = p;
		}
	}
	if (ret < 0)
		goto out_error;

	close(fd);
	return buffer;

out_error:
	err_save = errno;
	free(buffer);
	close(fd);
	errno = err_save;
	return NULL;
}
//Read File Binary
 void * ReadFileBytes(const char * FilePath,long FileSize)
 {
	int FileDiscriptor = open(FilePath, O_RDONLY, 0);
    void * FileBytes = malloc(FileSize);
    read(FileDiscriptor,FileBytes,FileSize);
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