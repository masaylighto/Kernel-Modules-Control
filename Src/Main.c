#include <gtk/gtk.h>
#include "../Headers/GtkMethod.h"
#include "../Headers/HelperFunction.h"
#include "../Headers/MainWindow.h"
char * filePath;

int main ( int argc, char **argv) 
{   
    
    ExitIfNotRoot();
 
    filePath=argv[1];

    gtk_init (&argc , &argv);  

    GtkBuilder * builder = gtk_builder_new();  //GtkBuilder  reads XML descriptions of a user interface and instantiates the described objects. 
    LoadMainWindow(builder);
    gtk_main (); // gtk_main run infinit loop so the application will keep on working (there is a lot of thing that happen inside this infinit loop you can read its code if you want)
    return 0;
 }
 