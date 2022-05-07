#include<gtk/gtk.h>

#ifndef H_GtkMethod
#define H_GtkMethod
/*
this method load Css File From Path
*/
GtkCssProvider* LoadCssFile(const char *Path); 
/*
Get Widget From Builder Object
*/
GtkWidget* GetWidget (GtkBuilder *builder,const gchar * WidgetName);
/*
this method apply Css To Screen
*/
void ApplyCss (GtkCssProvider* Css);
/*

Load Glade File Into Builder if it failed it will close the application
in this application we only have one window so if it wont load then there is no need for the application to run
*/
void LoadGladeFile (GtkBuilder * builder,const char* Path);
void ErrorMessageDialog(GtkWindow * Window ,const char * Text);
GtkFileChooser* CreateFileDialog(GtkWindow * Window,const char * FilterPattern,const char* FilterName);

#endif