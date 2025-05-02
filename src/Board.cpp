#include "Board.h"


#define DIGIT_WIDTH 60
#define DIGIT_HEIGHT 80

#define SEGMENT_WIDTH 8
#define SEGMENT_HEIGHT 8

// Digital type of segment basically 
//  ======   segment top 
// |     |   segment topleft and topright
// |     |
// ======      segment middle
// |     |     segment bottomleft and bottomright
// |     |
// ======       segment bottom
//and we draw the segment one by one so we can draw the whole digits
void SegmentTop(int x, int y){glRectd(x,y,x+DIGIT_WIDTH,y+SEGMENT_HEIGHT);}                                               
void SegmentMiddle(int x, int y){glRectd(x,y+DIGIT_HEIGHT/2,x+DIGIT_WIDTH,y+DIGIT_HEIGHT/2+SEGMENT_HEIGHT);}
void SegmentBottom(int x, int y){glRectd(x,y+DIGIT_HEIGHT,x+DIGIT_WIDTH,y+DIGIT_HEIGHT+SEGMENT_HEIGHT);}
void SegmentTopLeft(int x, int y){glRectd(x,y,x+SEGMENT_WIDTH,y+DIGIT_HEIGHT/2);}
void SegmentTopRight(int x, int y){glRectd(x+DIGIT_WIDTH-SEGMENT_WIDTH,y,x+DIGIT_WIDTH,y+DIGIT_HEIGHT/2);}
void SegmentBottomLeft(int x, int y){glRectd(x,y+DIGIT_HEIGHT/2,x+SEGMENT_WIDTH,y+DIGIT_HEIGHT);}
void SegmentBottomRight(int x, int y){glRectd(x+DIGIT_WIDTH-SEGMENT_WIDTH,y+DIGIT_HEIGHT/2,x+DIGIT_WIDTH,y+DIGIT_HEIGHT);}

void DrawAllSegments(int x, int y)
{
    SegmentTop(x,y);
    SegmentMiddle(x,y);
    SegmentBottom(x,y);
    SegmentTopLeft(x,y);
    SegmentTopRight(x,y);
    SegmentBottomLeft(x,y);
    SegmentBottomRight(x,y);
}

void Board::DrawDigit(int digit, int x, int y)
{
    ThemeManager::getTheme().digit.apply();
    switch(digit)
    {
        case 0: SegmentTop(x,y); SegmentTopLeft(x,y);SegmentBottomLeft(x,y);SegmentBottom(x,y);SegmentBottomRight(x,y);SegmentTopRight(x,y); break;
        case 1: SegmentTopRight(x,y); SegmentBottomRight(x,y); break;
        case 2: SegmentTop(x,y); SegmentTopRight(x,y); SegmentMiddle(x,y); SegmentBottomLeft(x,y);SegmentBottom(x,y); break;
        case 3: SegmentTop(x,y); SegmentMiddle(x,y); SegmentTopRight(x,y); SegmentBottomRight(x,y);SegmentBottom(x,y); break;
        case 4: SegmentTopLeft(x,y); SegmentTopRight(x,y); SegmentMiddle(x,y); SegmentBottomRight(x,y); break;
        case 5: SegmentTop(x,y); SegmentTopLeft(x,y); SegmentMiddle(x,y); SegmentBottom(x,y); SegmentBottomRight(x,y); break;
        case 6: SegmentTop(x,y);SegmentTopLeft(x,y); SegmentMiddle(x,y); SegmentBottom(x,y); SegmentBottomRight(x,y); SegmentBottomLeft(x,y); break;
        case 7: SegmentTop(x,y); SegmentTopRight(x,y); SegmentBottomRight(x,y); break; 
        case 8: DrawAllSegments(x,y); break;
        case 9: SegmentTop(x,y); SegmentTopLeft(x,y); SegmentTopRight(x,y); SegmentMiddle(x,y); SegmentBottom(x,y); SegmentBottomRight(x,y); break;
        default: break;
    }
}

Board::Board()
{

}

void Board::Draw()
{
    ThemeManager::getTheme().field.apply();
    glRectf(0,0,GAME_WIDTH,GAME_HEIGHT);
    ThemeManager::getTheme().net.apply();
    for(int i = 0; i < GAME_HEIGHT; i+=20)
        glRectf(GAME_WIDTH/2-3,i,GAME_WIDTH/2+3,i+10);
}
