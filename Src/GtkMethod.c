#include "../Headers/GtkMethod.h"
/*
this method load Css File From Path
*/

GtkCssProvider* LoadCssFile(const char *Path)
{
    
    GtkCssProvider* CssProvider =gtk_css_provider_new();//GtkCssProvider Parse Css Into Style For Widgets
    GFile *CssFile=g_file_new_for_path(Path); //GFile  reperesent file that can be used with gtk method
    GError *Err=0;//will hold the errors if there any
    gtk_css_provider_load_from_file(CssProvider,CssFile,&Err); // Load Css file into The GtkCssProvider
    // if there is an error print it  also you see we return the css provider in both case 
    // cause styling is not necessary for the application to work
    if (Err!=NULL) 
    {
        printf("Failed To Load Css File \n%s\n",Err->message);
    }
    return CssProvider;        
}
/*
Get Widget From Builder Object
*/
GtkWidget* GetWidget (GtkBuilder *Builder,const gchar* WidgetName){
    //we get the widget object as object from builder then cast it to GtkWidget using the GTK_WIDGET() Directive and return it to the user
    return GTK_WIDGET(gtk_builder_get_object (Builder,WidgetName));
}
/*

this method apply Css To Screen
*/
void ApplyCss (GtkCssProvider* Css){
    //when we want to apply css to gtk Window We need to apply it directly to the GdkScreen 
    //which represent the Screen that hold the different windows of the application
    //and to get it we need first to get GdkDisplay which reperesent the X Display which will hold the deferent Screen
    GdkDisplay* Display = gdk_display_get_default ();
    GdkScreen* Screen = gdk_display_get_default_screen (Display);  
    //we apply the css to the screen
    gtk_style_context_add_provider_for_screen(Screen,GTK_STYLE_PROVIDER(Css),GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

}
/*

Load Glade File Into Builder if it failed it will close the application
in this application we only have one window so if it wont load then there is no need for the application to run
*/
void LoadGladeFile (GtkBuilder * Builder,const char* Path){
    //read the glade file into the builder and if its failed exist the application
  if(!gtk_builder_add_from_file (Builder,Path , NULL))
     {
         printf("\n failed To load Glade File \n");
         exit(-1);
     }   
}
