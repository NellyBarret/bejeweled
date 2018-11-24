CC                  = g++
CFLAGS              = -std=c++11 -W -Wall 
OBJ_DIR				= obj
SRC_DIR             = src
BIN_DIR             = bin
DOC_DIR				= doc

OBJ_FILES = $(OBJ_DIR)/Grid.o $(OBJ_DIR)/Game.o $(OBJ_DIR)/GameWindow.o $(OBJ_DIR)/Image.o $(OBJ_DIR)/Jewel.o

EXEC_NAME_MAIN = main 
OBJ_FILES_MAIN = $(OBJ_DIR)/main.o $(OBJ_FILES)

OS = $(shell uname)

ifeq ($(OS),Darwin)
	INCLUDE_DIR_SDL = `sdl2-config --cflags`
	LIBS_SDL = `sdl2-config --libs` -lSDL2_image -lSDL2_ttf
endif

ifeq ($(OS),Linux)
	INCLUDE_DIR_SDL = -I/usr/include/SDL2
	LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image
endif

ifeq ($(OS),Windows_NT)
	INCLUDE_DIR_SDL = 	-Iextern/SDL2_mingw/SDL2-2.0.3/include \
						-Iextern/SDL2_mingw/SDL2_ttf-2.0.12/i686-w64-mingw32/include/SDL2 \
						-Iextern/SDL2_mingw/SDL2_image-2.0.0/i686-w64-mingw32/include/SDL2
	LIBS_SDL = 	-Lextern \
				-Lextern/SDL2_mingw/SDL2-2.0.3/i686-w64-mingw32/lib \
				-Lextern/SDL2_mingw/SDL2_ttf-2.0.12/i686-w64-mingw32/lib \
				-Lextern/SDL2_mingw/SDL2_image-2.0.0/i686-w64-mingw32/lib \
				-lmingw32 -lSDL2main -lSDL2.dll -lSDL2_ttf.dll -lSDL2_image.dll
endif

all: $(BIN_DIR)/$(EXEC_NAME_MAIN)

$(BIN_DIR)/$(EXEC_NAME_MAIN): $(OBJ_FILES_MAIN)
	$(CC) -o $(BIN_DIR)/$(EXEC_NAME_MAIN) $(OBJ_FILES_MAIN) $(LIBS_SDL)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE_DIR_SDL) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/$(EXEC_NAME_MAIN)
