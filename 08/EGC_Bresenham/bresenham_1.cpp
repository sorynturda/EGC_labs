#include "bresenham.h"
#include "math.h"
//#include <SDL2/SDL.h>

#include <iostream>
//Detects in which octant a line is situated
/*int getOctant(BresenhamLine line) {

	int deltaY = (line.endY - line.startY);
	int deltaX = (line.endX - line.startX);

	//Slope		
	float m = abs(deltaY) / (float)abs(deltaX);

	if ((m < 1) && (deltaX > 0) && (deltaY < 0)) //first octant
		return 1;
	if ((m > 1) && (deltaX > 0) && (deltaY < 0))  //second octant
		return 2;
	if ((m > 1) && (deltaX < 0) && (deltaY < 0))  //third octant
		return 3;
	if ((m < 1) && (deltaX < 0) && (deltaY < 0)) //forth octant 
		return 4;
	if ((m < 1) && (deltaX < 0) && (deltaY > 0)) //fifth octant
		return 5;
	if ((m > 1) && (deltaX < 0) && (deltaY > 0)) // sixth octant
		return 6;
	if ((m > 1) && (deltaX > 0) && (deltaY > 0)) // seventh octant
		return 7;
	if ((m < 1) && (deltaX > 0) && (deltaY > 0)) // eight octant
		return 8;

	return 0;
}*/

int getOctant(BresenhamLine line) {

	int deltaY = (line.endY - line.startY);
	int deltaX = (line.endX - line.startX);

	//Slope		
	float m = abs(deltaY) / (float)abs(deltaX);

	if ((m < 1) && (deltaX > 0) && (deltaY < 0)) //first octant
		return 1;
	if ((m > 1) && (deltaX > 0) && (deltaY < 0)) {
		return 2;
	}
	if (m > 1 && deltaX < 0 && deltaY < 0) {
		return 3;
	}
	if (m < 1 && deltaX < 0 && deltaY < 0) {
		return 4;
	}
	if (m < 1 && deltaX < 0 && deltaY > 0) {
		return 5;
	}
	if (m > 1 && deltaX < 0 && deltaY > 0) {
		return 6;
	}
	if (m > 1 && deltaY > 0 && deltaX > 0) {
		return 7;
	}
	if (m < 1 && deltaY >0 && deltaX > 0) {
		return 8;
	}
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
	std::cout << octant << std::endl;
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
			SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0x00);
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
		break;
	case 2:
		
		tmpStartX = tmpCurrentX = line.startX;
		tmpEndX = line.endX;
		tmpStartY = tmpCurrentY = line.startY;
		tmpEndY = line.endY;

		d = 2 * dx - dy;
		inc1 = 2 * dx;
		inc2 = 2 * (dx - dy);

		while (tmpCurrentY > tmpEndY) {
			SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255);
			SDL_RenderDrawPoint(renderer, tmpCurrentX, tmpCurrentY);
			--tmpCurrentY;

			if (d < 0)
				d += inc1;
			else {
				d += inc2;
				++tmpCurrentX;
			}
		}
		break;
	case 3:
		
		tmpStartX = tmpCurrentX = line.startX;
		tmpEndX = line.endX;
		tmpStartY = tmpCurrentY = line.startY;
		tmpEndY = line.endY;

		d = 2 * dx - dy;
		inc1 = 2 * dx;
		inc2 = 2 * (dx - dy);

		while (tmpCurrentY > tmpEndY) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
			SDL_RenderDrawPoint(renderer, tmpCurrentX, tmpCurrentY);
			--tmpCurrentY;

			if (d < 0)
				d += inc1;
			else {
				d += inc2;
				--tmpCurrentX;
			}
		}
		break;
	case 4:
		tmpStartX = tmpCurrentX = line.startX;
		tmpEndX = line.endX;
		tmpStartY = tmpCurrentY = line.startY;
		tmpEndY = line.endY;

		d = 2 * dy - dx;
		inc1 = 2 * dy;
		inc2 = 2 * (dy - dx);

		while (tmpCurrentX > tmpEndX)
		{
			//Draw current point
			SDL_SetRenderDrawColor(renderer, 0, 128, 0, 255);
			SDL_RenderDrawPoint(renderer, tmpCurrentX, tmpCurrentY);
			--tmpCurrentX;

			if (d < 0)
				d += inc1;
			else
			{
				d += inc2;
				--tmpCurrentY;
			}
		}
		break;
	case 5:
		tmpStartX = tmpCurrentX = line.startX;
		tmpEndX = line.endX;
		tmpStartY = tmpCurrentY = line.startY;
		tmpEndY = line.endY;

		d = 2 * dy - dx;
		inc1 = 2 * dy;
		inc2 = 2 * (dy - dx);

		while (tmpCurrentX > tmpEndX)
		{
			//Draw current point
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
			SDL_RenderDrawPoint(renderer, tmpCurrentX, tmpCurrentY);
			--tmpCurrentX;

			if (d < 0)
				d += inc1;
			else
			{
				d += inc2;
				++tmpCurrentY;
			}
		}
		break;
	case 6:
		tmpStartX = tmpCurrentX = line.startX;
		tmpEndX = line.endX;
		tmpStartY = tmpCurrentY = line.startY;
		tmpEndY = line.endY;

		d = 2 * dx - dy;
		inc1 = 2 * dx;
		inc2 = 2 * (dx - dy);

		while (tmpCurrentY < tmpEndY) {
			SDL_SetRenderDrawColor(renderer, 75, 0, 130, 255);
			SDL_RenderDrawPoint(renderer, tmpCurrentX, tmpCurrentY);
			++tmpCurrentY;

			if (d < 0)
				d += inc1;
			else {
				d += inc2;
				--tmpCurrentX;
			}
		}
		break;
	case 7:
		tmpStartX = tmpCurrentX = line.startX;
		tmpEndX = line.endX;
		tmpStartY = tmpCurrentY = line.startY;
		tmpEndY = line.endY;

		d = 2 * dx - dy;
		inc1 = 2 * dx;
		inc2 = 2 * (dx - dy);

		while (tmpCurrentY < tmpEndY) {
			SDL_SetRenderDrawColor(renderer, 148, 0, 211, 255);
			SDL_RenderDrawPoint(renderer, tmpCurrentX, tmpCurrentY);
			++tmpCurrentY;

			if (d < 0)
				d += inc1;
			else {
				d += inc2;
				++tmpCurrentX;
			}
		}
		break;
	case 8:
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
			SDL_SetRenderDrawColor(renderer, 255, 105, 180, 255);
			SDL_RenderDrawPoint(renderer, tmpCurrentX, tmpCurrentY);
			++tmpCurrentX;

			if (d < 0)
				d += inc1;
			else
			{
				d += inc2;
				++tmpCurrentY;
			}
		}
		break;

	default:
		break;
	}
}

/*void BresenhamDraw(BresenhamLine line, SDL_Renderer* renderer) {
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
	std::cout << octant << std::endl;
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
			SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0x00);
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
		break;
	case 2:
		//SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255);

		tmpStartX = tmpCurrentX = line.startX;
		tmpEndX = line.endX;
		tmpStartY = tmpCurrentY = line.startY;
		tmpEndY = line.endY;

		d = 2 * dy - dx;
		inc1 = 2 * dy;
		inc2 = 2 * (dy - dx);

		while (tmpCurrentY > tmpEndY)
		{
			//Draw current point
			SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255);
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

		break;
	case 3:
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
*/
void BresenhamDraw(BresenhamCircle circle, SDL_Renderer* renderer) {
	int x = 0;
	int y = circle.radius;
	int d = 1/4 - circle.radius;

	while (x < (circle.radius / std::sqrt(2))) {
		plot_points(renderer, x , y, circle.centerX, circle.centerY );
		x++;
		d = d + 2 * x + 1;
		if (d > 0) {
			--y;
			d = d + 2 - 2 * y;
		}
	}
}

void plot_points(SDL_Renderer* renderer, int x, int y, int x0, int y0) {
	SDL_RenderDrawPoint(renderer, x0+x, y0+y);
	SDL_RenderDrawPoint(renderer, x0-x, y0+y);
	SDL_RenderDrawPoint(renderer, x0+x, y0-y);
	SDL_RenderDrawPoint(renderer, x0-x,y0-y);
	SDL_RenderDrawPoint(renderer, x0+y, y0+x);
	SDL_RenderDrawPoint(renderer, x0-y, y0+x);
	SDL_RenderDrawPoint(renderer, x0+y, y0-x);
	SDL_RenderDrawPoint(renderer, x0-y, y0-x);
}

