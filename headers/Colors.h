#pragma once 
#include "GameConfig.h"

class Colors{
    public:
    float red, green, blue,alpha;
    Colors(float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f) : red(r), green(g), blue(b), alpha(a){};
    void apply() const;
};

enum class ThemeType{
    Classic,
    Modern
};


class Theme{
    public:
    Colors field;
    Colors net;
    Colors paddle;
    Colors ball;
    Colors button;
    Colors text;
    Colors digit;
    ThemeType type;
    Theme(Colors field = {}, Colors net = {}, Colors paddle = {}, Colors ball={}, Colors text={}, Colors digit={},Colors Button={}, ThemeType type = ThemeType::Classic);
    bool isClassic() const;
    bool isModern() const;
};

namespace ThemeManager{
    void setTheme(const Theme& theme);
    const Theme& getTheme();
}

extern Theme ClassicTheme;
extern Theme ModernTheme;
