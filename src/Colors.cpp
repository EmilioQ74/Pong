#include "Colors.h"

void Colors::apply() const
{
    glColor4f(red, green, blue, alpha);
}

Theme::Theme(Colors field, Colors net, Colors paddle, Colors ball, Colors text,Colors digit,Colors Button, ThemeType type) : 
field(field), net(net), paddle(paddle), ball(ball), text(text),digit(digit), button(Button), type(type)
{

}

Theme ClassicTheme(
    Colors(.0f, .0f, .0f, .0f),     // field
    Colors(1.0f, 1.0f, 1.0f, 1.0f), // net
    Colors(1.0f, 1.0f, 1.0f, 1.0f), // paddle
    Colors(1.0f, 1.0f, 1.0f, 1.0f), // ball
    Colors(.0f, .0f, .0f, 1.0f),    // text
    Colors(1.0f, 1.0f, 1.0f, 1.0f), // digit
    Colors(.5f, .5f, .5f, .5f),     // button
    ThemeType::Classic              //this theme is a classic theme type
);

Theme ModernTheme(
    Colors(0.275, 0.627, 0.494, .0f),     // field
    Colors(1.0f, 0.9216f, 0.5961f, 1.0f), // net
    Colors(0.827, 0.29, 0.29,1),    // paddle
    Colors(.18f,.95f, .71f, 1.0f),  // ball
    Colors(.0f, .0f, .0f, 1.0f),    // text
    Colors(0.67, 0.67, 1, 1.0f), // digit
    Colors(.5f, .5f, .5f, .5f),     // button
    ThemeType::Modern               //this theme is a modern theme type
);



bool Theme::isClassic() const
{
    return type == ThemeType::Classic;
}

bool Theme::isModern() const
{
    return type == ThemeType::Modern;
}


namespace ThemeManager{
    static Theme currentTheme = ClassicTheme;

    void setTheme(const Theme& theme)
    {
        currentTheme = theme;
    }

    const Theme& getTheme()
    {
        return currentTheme;
    }
}