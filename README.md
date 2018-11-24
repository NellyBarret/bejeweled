# BEJEWELED (2017)

## USER MANUAL

### COMPILATION

Compilation on Linux:
1. decompress the archive
2. in command line, access to the folder's root "p1507550-bejeweled"
3. choose the version you want: text version (folder Text), graphic version (folder SDL) or music version (folder SDL_music)
4. in command line, access the folder with "cd Text" or "cd SDL" or "cd SDL_music"
4. in command line, generate the executable with "make"
5. in command line, access to the executable's folder with "cd bin"
6. in command line, execute the executable with "./main"

NB: If you choose music version, you must install SDL mixer with the command line "sudo apt-get install libsdl2-mixer-dev" and if packages don't work, you can download them on https://www.libsdl.org/projects/SDL_mixer/ (choose SDL2_mixer-2.0.1.tar.gz)

### RULES

When the game is open, choose your game mode:
- classic: a game without time. The goal is to make 100 points.
- action: a game with time. The goal is to have as many points as it's possible before the timer is over.

If you choose action, you should choose the timer: 30 seconds (0:30 minute), 60 seconds (1:00 minute), 90 seconds (1:30 minutes) or 120 seconds (2:00 minutes).

How it works
- The goal? Make alignments of at least 3 jewels (which have the same color). 
- How? Swap two close jewels and make an horizontal or vertical alignment. 

### FUNCTIONALITIES

- text version and graphic version with SDL2
- 2 types of game: classic and action
- swap 2 close jewels. If they are too far away, they will be not swap
- graphic interface
- timer (for action game)
- rules are in the ? (at the top left)
- playing a new game even if the first isn't finished.


## ARCHIVE'S ORGANISATION

In the root, you have:
- Text for the text version of our Bejweled
- SDL for the graphic version
- SDL_music for the graphic audio version
- readme: this document
- the PowerPoint presentation
- the module diagram and the Gantt diagram

In Text folder, you have:
- bin: the executable file
- data: nothing
- doc: the Doxygen documentation
- obj: binary files
- src: the source code files writed in modular programming
- makefile: the file for compilation

In SDL folder, you have:
- bin: the executable file
- data: the images (like jewels and background) and some usefull data like fonts
- doc: the Doxygen documentation
- obj: binary files
- src: the source code files writed in modular programming
- makefile: the file for compilation

In SDL_music folder, you have:
- bin: the executable file
- data: the images (like jewels and background) and some usefull data like fonts and sounds
- doc: the Doxygen documentation
- obj: binary files
- src: the source code files writed in modular programming
- makefile: the file for compilation