#pragma once
#include "GameConfig.h"
#include "Colors.h"

class Board {

public:
    Board();
    void Draw();
    void DrawDigit(int digit, int x, int y);
};