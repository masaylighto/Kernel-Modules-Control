#include "../Headers/MainWindow.h"


/*
Repersent the box in the ui that will hold the Modules 
*/
GtkGrid * ModulesContainer;

void LoadMainWindow(GtkBuilder * Builder)
{
    LoadGladeFile(Builder,"Ui/MainWindow.glade" )    ;// load the xml file we want into the Builder
    GtkCssProvider* Css= LoadCssFile("Ui/Css/MainWindow.css");  //Load the Css File
    ApplyCss(Css);//apply the Css File
    GtkWidget * Window  = GetWidget(Builder,"TopWindow");//get The window the declared inside of the glade file  
    MapWidgetsToSignals(Builder); //get all the widgets from GtkBuilder and map them to their signal 
    SetWidgetToGlobal(Builder);
    gtk_widget_show_all (Window);//Show The window
    GetAndDisplayKernelModule();
}
/*
read the module from the system and display it to the ui
*/
void GetAndDisplayKernelModule(){
    //open the file that hold the list of modules
    FILE* modulesfile =fopen("/proc/modules","r");
    //variable that will hold the current line
    char * line ;
    //text length
    size_t len = 0;
    //get Line and loop
    while ( getline(&line, &len, modulesfile) != -1) {
        //strtok to remove every thing after space then insert it to view through InsertKernelModule
        InsertKernelModule(strtok(line," "));
    }
    
    //close file object
    fclose(modulesfile);
    //free the line
    free (line);
}
/*
some widget are gonna be used from different method so here we gonna get them out the GtkBuilder and set them to their Global Variable
*/
void SetWidgetToGlobal(GtkBuilder * Builder){
   ModulesContainer  =GTK_GRID( gtk_builder_get_object (Builder,"ModulesContainer") );
}
//this variable will be used to track the next grid place we gonna insert our row into it in InsertKernelModule
int NextGridRow=0;
void InsertKernelModule(const char * ModuleName){

    //Create A Row
    GtkGrid *Row = CreateKernelModuleRow();
    //Set Module Info into it
    SetModuleName(Row,ModuleName);
    //add Row into Grid
    gtk_grid_attach(ModulesContainer,Row,0,NextGridRow++,1,1);
    
}
/*
this method used to apply module name to the Row
*/
void SetModuleName(GtkGrid* Box ,const char * Name){
    //get the label from the grid
  GtkLabel *Label=    gtk_grid_get_child_at(Box,0,0);  
  //set the label name
  gtk_label_set_label(Label,Name);
}
/*
this method will Create A Widget That Reperesent THe Kernal Module
*/
GtkGrid* CreateKernelModuleRow(){
    //Create  GtkBuilder to Parse The Glade File That Hold The Widget
    GtkBuilder * Tempbuilder = gtk_builder_new();
    //Load The Widget into The GtkBuilder
    LoadGladeFile(Tempbuilder,"Ui/ModulesRow.glade");  
    //we get the widget object as object from builder then cast it to GTKBOX using the GTK_BOX() Directive and return it to the user
    return GTK_GRID(gtk_builder_get_object (Tempbuilder,"Row"));
   
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