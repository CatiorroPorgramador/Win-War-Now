@echo off

g++ -Iinclude/ -Llibs/ -o bin/Game src/Main.cpp -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system
