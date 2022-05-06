#include "../Headers/MainWindow.h"

void LoadMainWindow(GtkBuilder * Builder)
{
    LoadGladeFile(Builder,"Ui/MainWindow.glade" )    ;// load the xml file we want into the Builder
    GtkCssProvider* Css= LoadCssFile("Ui/Css/MainWindow.css");  //Load the Css File
    ApplyCss(Css);//apply the Css File
    GtkWidget * Window  = GetWidget(Builder,"TopWindow");//get The window the declared inside of the glade file  
    MapWidgetsToSignals(Builder); //get all the widgets from GtkBuilder and map them to their signal 
    gtk_widget_show_all (Window);//Show The window

}
/*
some widget are gonna be used from different method so here we gonna get them out the GtkBuilder and set them to their Global Variable
*/
void SetWidgetToGlobal(GtkBuilder * Builder){

}
/*
get all the widgets from GtkBuilder and map them to their signal 
*/
void MapWidgetsToSignals(GtkBuilder * Builder)
{
    //Get the button that is responsible for loading new module to the Kernel
    GtkWidget * AddBtn=GetWidget(Builder,"AddBtn");
    //Link The button into the method that load the new module to the Kernel
    g_signal_connect(AddBtn,"clicked",G_CALLBACK(AddBtnClicked),NULL);
}
/*
The Add btn Signal 
this method will be fired when the add btn Get Clicked
*/
void AddBtnClicked(GtkWidget *widget,gpointer data)
{
    g_print("Button Clicked\n");
}