#pragma once
#include <unistd.h>
#include <termios.h>
#include <stdio.h>
/**
 * @brief reads the current key being that's pressed
 * @return char value
 */
char getch();