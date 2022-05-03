@SET PATH=C:/Program Files/ANSYS Inc/v221/SCADE/contrib/Msys64/mingw64/bin;C:/Program Files/ANSYS Inc/v221/SCADE/contrib/Msys64/usr/bin;C:/Program Files/ANSYS Inc/v221/SCADE/contrib/Msys64/bin;
@gcc -print-search-dirs
@mingw32-make.exe -j4 %*
