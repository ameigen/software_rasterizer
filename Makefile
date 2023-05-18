#OBJS specifies which files to compile as part of the project
OBJS = src/*.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -g 

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -static-libstdc++ -lSDL2main -lSDL2 -lmingw32 -lSDL2_image -lSDL2_ttf

#INCLUDE_DIR specifies the relative path to this projects defined headers
INCLUDE_DIR = -I./include/

#OBJ_NAME specifies our output file
OBJ_NAME = build/"Software Rasterizer"

#OBJ_TYPE specifies our output file type
OBJ_TYPE = ".exe"

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(INCLUDE_DIR) $(LIB_DIR) $(LINKER_FLAGS) -o $(OBJ_NAME)$(OBJ_TYPE)
run : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(INCLUDE_DIR) $(LIB_DIR) $(LINKER_FLAGS) -o $(OBJ_NAME)
	./$(OBJ_NAME)$(OBJ_TYPE)
run-v : $(OBJS) 
	$(CC) $(OBJS) --verbose $(COMPILER_FLAGS) $(INCLUDE_DIR) $(LIB_DIR) $(LINKER_FLAGS) -o $(OBJ_NAME)
	./$(OBJ_NAME)$(OBJ_TYPE)