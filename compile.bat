@echo off

echo who uses bat? wtf....

:: header files, and a general functions one, that I am adding random stuff to, that I think is useful
SET INCLUDES=-I"./include" 

:: c files, and that general one
SET SOURCES=./*.c	

:: the executable made
SET OUTPUT=-o Maze_Runner								

:: -Wall enables compiler warnings and -g puts stuff into the executable to make it debuggable
SET FLAGS=-Wall -g									

echo Compiling...

gcc %FLAGS% %INCLUDES% %SOURCES% %OUTPUT% 