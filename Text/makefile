CC 					= g++
CFLAGS 				= -std=c++11 -W -Wall
OBJ_DIR 			= obj
SRC_DIR 			= src
BIN_DIR 			= bin
DOC_DIR 			= doc

OBJ_FILES = $(OBJ_DIR)/Grid.o $(OBJ_DIR)/Timer.o $(OBJ_DIR)/Game.o 

EXEC_NAME_MAIN = main 
OBJ_FILES_MAIN = $(OBJ_DIR)/main.o $(OBJ_FILES)

all: $(BIN_DIR)/$(EXEC_NAME_MAIN)

$(BIN_DIR)/$(EXEC_NAME_MAIN): $(OBJ_FILES_MAIN)
	$(CC) -o $(BIN_DIR)/$(EXEC_NAME_MAIN) $(OBJ_FILES_MAIN) -lpthread

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/$(EXEC_NAME_MAIN)
