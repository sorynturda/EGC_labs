#include "bresenham.h"
#include "math.h"

//Detects in which octant a line is situated
int getOctant(BresenhamLine line) {

    int deltaY = (line.endY - line.startY);
    int deltaX = (line.endX - line.startX);

    //Slope
    float m = abs(deltaY) / (float)abs(deltaX);

    if ((m < 1) && (deltaX > 0) && (deltaY <= 0)) //first octant
        return 1;
    if ((m > 1) && (deltaX > 0) && (deltaY <= 0)) //second octant
        return 2;
    if ((m > 1) && (deltaX < 0) && (deltaY <= 0)) //second octant
        return 3;
    if ((m < 1) && (deltaX > 0) && (deltaY <= 0)) //second octant
        return 4;
    if ((m > 1) && (deltaX > 0) && (deltaY <= 0)) //second octant
        return 5;
    if ((m > 1) && (deltaX > 0) && (deltaY <= 0)) //second octant
        return 6;
    if ((m > 1) && (deltaX > 0) && (deltaY <= 0)) //second octant
        return 7;
    if ((m > 1) && (deltaX > 0) && (deltaY <= 0)) //second octant
        return 8;

    return 0;
}

//Draws a new raster line using Bresenham's algorithm
void BresenhamDraw(BresenhamLine line, SDL_Renderer* renderer) {
    int tmpStartX = 0;
    int tmpStartY = 0;
    int tmpEndX = 0;
    int tmpEndY = 0;
    int tmpCurrentX = 0;
    int tmpCurrentY = 0;

    int dy = abs(line.endY - line.startY);
    int dx = abs(line.endX - line.startX);

    int d, inc1, inc2;

    int octant = getOctant(line);

    switch (octant)
    {
    case 1:
        tmpStartX = tmpCurrentX = line.startX;
        tmpEndX = line.endX;
        tmpStartY = tmpCurrentY = line.startY;
        tmpEndY = line.endY;

        d = 2 * dy - dx;
        inc1 = 2 * dy;
        inc2 = 2 * (dy - dx);

        while (tmpCurrentX < tmpEndX)
        {
            //Draw current point
            SDL_RenderDrawPoint(renderer, tmpCurrentX, tmpCurrentY);
            ++tmpCurrentX;

            if (d < 0)
                d += inc1;
            else
            {
                d += inc2;
                --tmpCurrentY;
            }
        }
        printf("1\n");
        break;
    case 2:
        tmpStartX = tmpCurrentX = line.startX;
        tmpEndX = line.endX;
        tmpStartY = tmpCurrentY = line.startY;
        tmpEndY = line.endY;

        d = 2 * dx - dy;
        inc1 = 2 * dx;
        inc2 = 2 * (dx - dy);

        while (tmpCurrentY > tmpEndY)
        {
            //Draw current point
            SDL_RenderDrawPoint(renderer, tmpCurrentX, tmpCurrentY);
            --tmpCurrentY;

            if (d < 0)
                d += inc1;
            else
            {
                d += inc2;
                ++tmpCurrentX;
            }
        }
        printf("2\n");
        break;
    case 3:
        tmpStartX = tmpCurrentX = line.startX;
        tmpEndX = line.endX;
        tmpStartY = tmpCurrentY = line.startY;
        tmpEndY = line.endY;

        d = 2 * dx - dy;
        inc1 = 2 * dx;
        inc2 = 2 * (dx - dy);

        while (tmpCurrentY > tmpEndY)
        {
            //Draw current point
            SDL_RenderDrawPoint(renderer, tmpCurrentX, tmpCurrentY);
            --tmpCurrentY;

            if (d < 0)
                d += inc1;
            else
            {
                d += inc2;
                --tmpCurrentX;
            }
        }
        printf("3\n");
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;

    default:
        break;
    }
}

//Draws a new raster circle using Bresenham's algorithm
void BresenhamDraw(BresenhamCircle circle, SDL_Renderer* renderer) {

}