#include <raylib.h>
#include "utils.h"
#include "gui.h"
#include "draw.h"
#include "events.h"


void gui(void)
{ 
        InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Calculator");
        SetTargetFPS(60);

        Component* buttons = create_buttons();
        Component display = create_display();
        
        while (!WindowShouldClose())
        {
                event_listener(buttons, &display);
                BeginDrawing();
                ClearBackground(WINDOW_COLOR);
                
                draw_buttons(buttons);
                draw_display(&display);

                EndDrawing();
        }

        CloseWindow();
}
