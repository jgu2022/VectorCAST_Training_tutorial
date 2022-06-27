set path=%VECTORCAST_DIR%\mingw\bin;%PATH%

g++ -c real_fun.cpp
ar rcs libreal_fun.a real_fun.o


