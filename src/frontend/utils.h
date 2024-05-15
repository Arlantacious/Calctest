#ifndef UTILS_H
#define UTILS_H


#include <raylib.h>
#include <stdlib.h>
#include <assert.h>

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 600

#define NUMBER_OF_BUTTONS 20

#define BUTTON_WIDTH 100
#define BUTTON_HEIGHT 100
#define BUTTON_COLOR DARKGRAY
#define BUTTON_BORDER_COLOR BLACK
#define BUTTON_FONT_SIZE 50
#define BUTTON_TEXT_COLOR WHITE

#define DISPLAY_WIDTH 400
#define DISPLAY_HEIGHT 100
#define DISPLAY_COLOR GRAY
#define DISPLAY_BORDER_COLOR BLACK
#define DISPLAY_FONT_SIZE 50
#define DISPLAY_TEXT_COLOR WHITE


typedef struct
{
        Rectangle body;
        char* content;
        Vector2 pos;
        Color color;
} Component;


Component* create_buttons(void);

Component* create_display(char* content, int x, int y);


#endif
