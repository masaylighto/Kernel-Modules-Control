#include <gtk/gtk.h>
#include "../Headers/GtkMethod.h"
#include "../Headers/HelperFunction.h"
char * filePath;

int main ( int argc, char **argv) 
{   
    filePath=argv[1];

     gtk_init (&argc , &argv);  

     GtkBuilder * builder = gtk_builder_new();  //GtkBuilder  reads XML descriptions of a user interface and instantiates the described objects. 
     LoadGladeFile(builder,"Ui/MainWindow.glade" )    ;// load the xml file we want into the Builder
     GtkCssProvider* Css= LoadCssFile("Ui/Css/MainWindow.css");  //Load the Css File
     ApplyCss(Css);//apply the Css File
    
     GtkWidget * window  = GetWidget(builder,"TopWindow");//get The window the declared inside of the glade file    
     gtk_widget_show_all (window);//Show The window
     gtk_main (); // gtk_main run infinit loop so the application will keep on working (there is a lot of thing that happen inside this infinit loop you can read its code if you want)
     return 0;
 }
 