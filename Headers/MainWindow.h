#include <gtk/gtk.h>
#include"GtkMethod.h"
#include"HelperFunction.h"
#include <errno.h>
#ifndef H_MainWindow
#define H_MainWindow

/*
this method load the first Ui file which reperesent the main window
*/
void LoadMainWindow(GtkBuilder * Builder);
/*
get all the widgets from GtkBuilder and map them to their signal 
*/
void GetAndDisplayKernelModule();
/*
add new row that repersent the module to the grid
*/
void InsertKernelModule(const char * ModuleName);
/*
this method used to apply module name to the Row
*/
void ConnectUnloadSignal(GtkGrid* Box,const char * Name,int Position);
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
/*
this method will Create A Widget That Reperesent THe Kernal Module
*/
GtkGrid* CreateKernelModuleRow();
/*
this method used to apply module name to the Row
*/
void SetModuleName(GtkGrid* Box , const char * Name);
/*
The Unload btn Signal 
this method will be fired when the Unload btn Get Clicked
*/
void Unload(GtkWidget *widget,gpointer data);
/*
get the value that repersent the parameter that will be passed to the  module from the ui
*/
const gchar* GetParametersEntryText();
#endif