# gcc/dll/win64

SHELL = cmd.exe

CC := gcc
LD := gcc

CPPDEF := -DWIN32 -D_CONSOLE -D_MBCS -DNDEBUG
CFLAGS := -c -ansi -std=c99 -m64
LDFLAGS := -mwindows -mwin32 -shared -static-libgcc
LDLIBS := -lm

CCINC := -I
CCOUT := -o
LDDEF :=
LDLIB := -l
LDOUT := -o

# user: USER_CFLAGS, USER_LDFLAGS, USER_LDLIBS, USER_CPPDEF

USER_CPPDEF = -DBUILD_DLL
USER_CFLAGS = -pedantic
