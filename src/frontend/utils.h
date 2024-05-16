#ifndef UTILS_H
#define UTILS_H


#include <raylib.h>
#include <stdlib.h>
#include <assert.h>


#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 600

#define WINDOW_COLOR LIGHTGRAY

#define NUMBER_OF_BUTTONS 20

#define BUTTON_WIDTH 100
#define BUTTON_HEIGHT 100
#define BUTTON_COLOR DARKGRAY
#define BUTTON_BORDER_COLOR BLACK
#define BUTTON_FONT_SIZE 50
#define BUTTON_TEXT_COLOR WHITE

#define DISPLAY_POSITION (Vector2) { 0, 0 }
#define DISPLAY_WIDTH 400
#define DISPLAY_HEIGHT 100
#define DISPLAY_COLOR DARKGRAY
#define DISPLAY_BORDER_COLOR BLACK
#define DISPLAY_FONT_SIZE 50
#define DISPLAY_TEXT_COLOR WHITE
#define DISPLAY_BUFFER_SIZE 10

#define BUTTON_ZERO 0
#define BUTTON_ONE 1
#define BUTTON_TWO 2
#define BUTTON_THREE 3
#define BUTTON_FOUR 4
#define BUTTON_FIVE 5
#define BUTTON_SIX 6
#define BUTTON_SEVEN 7
#define BUTTON_EIGHT 8
#define BUTTON_NINE 9
#define BUTTON_ADD 10
#define BUTTON_SUBTRACT 11
#define BUTTON_MULTIPLY 12
#define BUTTON_DIVIDE 13
#define BUTTON_MODULUS 14
#define BUTTON_EXPONENT 15
#define BUTTON_MINUS 16
#define BUTTON_PERIOD 17
#define BUTTON_EQUALS 18
#define BUTTON_CLEAR 19


typedef struct
{
        Rectangle body;
        char* content;
        Color color;
} Component;


Component* create_buttons(void);

Component create_display(void);


#endif
