#include "events.h"


void button_lighting(Component* button, const Component* buttons)
{
        static Component* prev = NULL; 
        Vector2 cur = GetMousePosition();
        if (prev == NULL)
        {
                if (CheckCollisionPointRec(cur, button->body))
                {
                        button->color = LIGHTGRAY;
                        prev = button;

                        return;
                }

                return;
        }

        //IF ON SAME BUTTON
        if (CheckCollisionPointRec(cur, prev->body))
        {
                return;
        }
        //IF CURSOR ON A BUTTON
        if (CheckCollisionPointRec(cur, button->body) && prev != NULL)
        {
                button->color = LIGHTGRAY; 
                prev->color = BUTTON_COLOR;
                prev = button;
        }

        for (int i = 0; i < NUMBER_OF_BUTTONS; i++)
        {
                if (CheckCollisionPointRec(cur, buttons[i].body))
                {
                        return;
                }
        }

        prev->color = BUTTON_COLOR;
        prev = NULL;
}

void event_listener(Component* buttons)
{
        for (int i = 0; i < NUMBER_OF_BUTTONS; i++)
        {
                button_lighting(&buttons[i], buttons);
        }
}
