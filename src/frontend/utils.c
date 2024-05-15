#include "utils.h"


Component create_button(char* content, int x, int y)
{
        return (Component) { (Rectangle) { x, y, BUTTON_WIDTH, BUTTON_HEIGHT }, content, (Vector2) { x, y }, BUTTON_COLOR };
}


Component* create_buttons(void)
{
        Component* buttons = malloc(NUMBER_OF_BUTTONS * sizeof(Component));
        
        assert(buttons != NULL);

        buttons[0] = create_button("0", 100, 500),
        buttons[1] = create_button("1", 0, 200),
        buttons[2] = create_button("2", 100, 200),
        buttons[3] = create_button("3", 200, 200),
        buttons[4] = create_button("4", 0, 300),
        buttons[5] = create_button("5", 100, 300),
        buttons[6] = create_button("6", 200, 300),
        buttons[7] = create_button("7", 0, 400),
        buttons[8] = create_button("8", 100, 400),
        buttons[9] = create_button("9", 200, 400),
        buttons[10] = create_button("+", 300, 400),
        buttons[11] = create_button("-", 300, 300),
        buttons[12] = create_button("*", 300, 200),
        buttons[13] = create_button("/", 300, 100),
        buttons[14] = create_button("%", 200, 100),
        buttons[15] = create_button("^", 100, 100),
        buttons[16] = create_button("-", 0, 100),
        buttons[17] = create_button(".", 200, 500),
        buttons[18] = create_button("=", 300, 500),
        buttons[19] = create_button("C", 0, 500);
    
        return buttons;
}

Component* create_display(char* content, int x, int y)
{
        return &(Component) { (Rectangle) { x, y, DISPLAY_WIDTH, DISPLAY_HEIGHT }, content, (Vector2) { x, y }, DISPLAY_COLOR };
}
