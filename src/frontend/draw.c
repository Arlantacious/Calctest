#include "draw.h"
#include <raylib.h>
#include "utils.h"


void draw_buttons(const Component buttons[])
{       
        for (int i = 0; i < NUMBER_OF_BUTTONS; i++)
        {
                DrawRectangleRec(buttons[i].body, buttons[i].color);
                DrawRectangleLinesEx(buttons[i].body, 3, BUTTON_BORDER_COLOR);

                const int width = MeasureText(buttons[i].content, BUTTON_FONT_SIZE);
                const int x = buttons[i].pos.x + (int)((BUTTON_WIDTH - width) / 2);
                const int y = buttons[i].pos.y + (int)((BUTTON_HEIGHT - BUTTON_FONT_SIZE) / 2);
               
                DrawText(buttons[i].content, x, y, BUTTON_FONT_SIZE,BUTTON_TEXT_COLOR);
        }
}

void draw_display(const Component* display)
{       
        DrawRectangleRec(display->body, display->color);
        DrawRectangleLinesEx(display->body, 3, DISPLAY_BORDER_COLOR);

        const int width = MeasureText(display->content, DISPLAY_FONT_SIZE);
        const int x = display->pos.x + (int)((DISPLAY_WIDTH - width) / 2);
        const int y = display->pos.y + (int)((DISPLAY_HEIGHT - DISPLAY_FONT_SIZE) / 2);

        DrawText(display->content, x, y, DISPLAY_FONT_SIZE, DISPLAY_TEXT_COLOR);
}
