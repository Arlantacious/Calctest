#include <string.h>
#include "events.h"


void button_click(Component* display, const Component* buttons, const Vector2 cursor)
{
        if (CheckCollisionPointRec(cursor, buttons[BUTTON_ZERO].body) && IsKeyPressed(KEY_SPACE))
        {
                strcat(display->content, "0");
        }
}

void button_lighting(Component* button, const Component* buttons, const Vector2 cursor)
{
        static Component* prev = NULL; 
     
        if (prev == NULL)
        {
                if (CheckCollisionPointRec(cursor, button->body))
                {
                        button->color = LIGHTGRAY;
                        prev = button;

                        return;
                }

                return;
        }

        if (CheckCollisionPointRec(cursor, prev->body))
        {
                return;
        }

        if (CheckCollisionPointRec(cursor, button->body) && prev != NULL)
        {
                button->color = LIGHTGRAY; 
                prev->color = BUTTON_COLOR;
                prev = button;
        }

        for (int i = 0; i < NUMBER_OF_BUTTONS; i++)
        {
                if (CheckCollisionPointRec(cursor, buttons[i].body))
                {
                        return;
                }
        }

        prev->color = BUTTON_COLOR;
        prev = NULL;
}

void event_listener(Component* buttons, Component* display)
{
        for (int i = 0; i < NUMBER_OF_BUTTONS; i++)
        {
                Vector2 cursor = GetMousePosition();
                button_click(display, buttons, cursor);
                button_lighting(&buttons[i], buttons, cursor);
        }
}
