#ifndef WORDHUNT_H
#define WORDHUNT_H

#define BOARD_HEIGHT 4
#define BOARD_WIDTH 4

bool exist(char[BOARD_HEIGHT][BOARD_WIDTH], std::string);
bool searchw(char[BOARD_HEIGHT][BOARD_WIDTH], std::string, int, int, int);
#endif