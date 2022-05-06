#include<gtk/gtk.h>
#include"GtkMethod.h"
#ifndef H_MainWindow
#define H_MainWindow

GtkWidget * ModulesContainer;

/*
this method load the first Ui file which reperesent the main window
*/
void LoadMainWindow(GtkBuilder * Builder);
/*
get all the widgets from GtkBuilder and map them to their signal 
*/
void MapWidgetsToSignals(GtkBuilder * Builder);
/*
The Add btn Signal 
this method will be fired when the add btn Get Clicked
*/
void AddBtnClicked(GtkWidget *widget,gpointer data);
/*
some widget are gonna be used from different method so here we gonna get them out the GtkBuilder and set them to their Global Variable
*/
void SetWidgetToGlobal(GtkBuilder * Builder);
#endif