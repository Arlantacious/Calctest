#include <stdint.h>
#include <raylib.h>
#include "../backend/utils.h"


#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 600

#define NUMBER_OF_BUTTONS 20

#define BUTTON_WIDTH 100
#define BUTTON_HEIGHT 100
#define BUTTON_COLOR DARKGRAY
#define BUTTON_BORDER_COLOR BLACK
#define BUTTON_FONT_SIZE 50
#define BUTTON_TEXT_COLOR WHITE

#define TEXT_FIELD_WIDTH 400
#define TEXT_FIELD_HEIGHT 100
#define TEXT_FIELD_COLOR GRAY
#define TEXT_FIELD_BORDER_COLOR BLACK
#define TEXT_FIELD_FONT_SIZE 50
#define TEXT_FIELD_TEXT_COLOR WHITE

typedef struct
{
        Rectangle body;
        char* content;
        Vector2 pos;
} Object;


Object create_button(char content[], size_t x, size_t y)
{
        Object button;
        Rectangle body = { x, y, BUTTON_WIDTH, BUTTON_HEIGHT };
        
        button.body = body;
        button.content = content;
        button.pos.x = x;
        button.pos.y = y;

        return button;
}

void draw_buttons(Object button[])
{       
        for (size_t i = 0; i < NUMBER_OF_BUTTONS; i++)
        {
                DrawRectangleRec(button[i].body, BUTTON_COLOR);
                DrawRectangleLinesEx(button[i].body, 3, BUTTON_BORDER_COLOR);

                size_t text_width = MeasureText(button[i].content, BUTTON_FONT_SIZE);
                size_t text_x = button[i].pos.x + (size_t)((BUTTON_WIDTH - text_width) / 2);
                size_t text_y = button[i].pos.y + (size_t)((BUTTON_HEIGHT - BUTTON_FONT_SIZE) / 2);
               
                DrawText(button[i].content,
                         text_x,
                         text_y,
                         BUTTON_FONT_SIZE,
                         BUTTON_TEXT_COLOR
                         );
        }
}

Object create_text_field(char content[], int x, int y)
{
        Object text_field;
        Rectangle body = { x, y, TEXT_FIELD_WIDTH, TEXT_FIELD_HEIGHT };
        
        text_field.body = body;
        text_field.content = content;
        text_field.pos.x = x;
        text_field.pos.y = y;

        return text_field;
}

void draw_text_field(Object text_field)
{       
        DrawRectangleRec(text_field.body, TEXT_FIELD_COLOR);
        DrawRectangleLinesEx(text_field.body, 3, TEXT_FIELD_BORDER_COLOR);

        size_t text_width = MeasureText(text_field.content, TEXT_FIELD_FONT_SIZE);
        size_t text_x = text_field.pos.x + (size_t)((TEXT_FIELD_WIDTH - text_width) / 2);
        size_t text_y = text_field.pos.y + (size_t)((TEXT_FIELD_HEIGHT - TEXT_FIELD_FONT_SIZE) / 2);

        DrawText(text_field.content,
                 text_x,
                 text_y,
                 TEXT_FIELD_FONT_SIZE,
                 TEXT_FIELD_TEXT_COLOR
                 );
}

void gui(void)
{ 
        InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Calculator");
        SetTargetFPS(60);

        Object button_zero = create_button("0", 100, 500);
        Object button_one = create_button("1", 0, 200);
        Object button_two = create_button("2", 100, 200);
        Object button_three = create_button("3", 200, 200);
        Object button_four = create_button("4", 0, 300);
        Object button_five = create_button("5", 100, 300);
        Object button_six = create_button("6", 200, 300);
        Object button_seven = create_button("7", 0, 400);
        Object button_eight = create_button("8", 100, 400);
        Object button_nine = create_button("9", 200, 400);
        Object button_add = create_button("+", 300, 400);
        Object button_subtract = create_button("-", 300, 300);
        Object button_multiply = create_button("*", 300, 200);
        Object button_divide = create_button("/", 300, 100);
        Object button_modulus = create_button("%", 200, 100);
        Object button_exponent = create_button("^", 100, 100);
        Object button_minus = create_button("-", 0, 100);
        Object button_period = create_button(".", 200, 500);
        Object button_equals = create_button("=", 300, 500);
        Object button_clear = create_button("C", 0, 500);
        
        Object text_field = create_text_field("", 0, 0);

        Object buttons[] = { button_zero, button_one, button_two, button_three, button_four, button_five, button_six,
                             button_seven, button_eight, button_nine, button_add, button_subtract, button_multiply,
                             button_divide, button_modulus, button_exponent, button_minus, button_period,
                             button_equals, button_clear
                           };

        while (!WindowShouldClose())
        {
                BeginDrawing();
                ClearBackground(LIGHTGRAY);
                
                draw_buttons(buttons);
                draw_text_field(text_field);

                EndDrawing();
        }

        CloseWindow();
}
