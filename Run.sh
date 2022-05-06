
 gcc `pkg-config gtk+-3.0 --cflags` Src/Main.c Src/GtkMethod.c Src/HelperFunction.c -o App `pkg-config gtk+-3.0 --libs`  