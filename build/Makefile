CC=gcc
CC_CROSS=x86_64-w64-mingw32-gcc
LIBS=`pkg-config --cflags --libs sdl2`
CFLAGS=-Wall -pedantic -Wshadow -Werror
CFLAGS_CROSS=-mwindows
DEPENDENCIES=../src/main.c ../src/func.c ../src/vars.c

demo: ${DEPENDENCIES}
	${CC} ${CFLAGS} ${DEPENDENCIES} -o $@ ${LIBS}

cross: ${DEPENDENCIES}
	${CC_CROSS} ${CFLAGS} ${CFLAGS_CROSS} ${DEPENDENCIES} -o windows/demo_win32 ${LIBS}

release: ${DEPENDENCIES}
	${CC} ${CFLAGS} -O4 ${DEPENDENCIES} -o demo ${LIBS} && ${CC_CROSS} ${CFLAGS} ${CFLAGS_CROSS} -O4 ${DEPENDENCIES} -o windows/demo_win32 ${LIBS}

run: 
	make && ./demo

