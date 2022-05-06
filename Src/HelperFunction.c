#include "../Headers/HelperFunction.h"
 
char * UnloadModule(char * ModuleName){

    syscall(SYS_delete_module,);
}