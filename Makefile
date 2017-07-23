#OBJS: files to compile in the project
OBJS = *.cpp

#CC: which compiler we are using
CC = g++

#COMPILER_FLAGS
COMPILER_FLAGS = -w -g -o

#LINKER_FLAGS
LINKER_FLAGS = -lSDL2 -lSDL2_image

#OBJ_NAME = 01_hello_SDL
OBJ_NAME = main.x

all: $(OBJS) 
	$(CC) $(OBJS) $(COMPILER_FLAGS)  $(OBJ_NAME) $(LINKER_FLAGS)

clean: 
	rm $(OBJ_NAME)

run: $(OBJ_NAME)
	stdbuf -i0 -e0 -o0 ./$(OBJ_NAME)
