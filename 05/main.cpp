//
//  main.cpp
//  SDL_Lab1
//
//  Created by CGIS on 16/02/16.
//  Copyright � 2016 CGIS. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "transform.h"

using namespace egc;

SDL_Renderer *windowRenderer;
// define rectangle vertices

vec3 P1(100, 100, 1), P2(400, 100, 1);
vec3 P3(400, 200, 1), P4(100, 200, 1);

mat3 rotation_mat = mat3();
mat3 translate_from_origin = egc::translate(250, 150);
mat3 translate_to_origin = egc::translate(-250, -150);
mat3 scale_mat = mat3();


//define window dimensions
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

SDL_Window *window = NULL;
SDL_Event currentEvent;

SDL_Rect rectangleCoordinates = {100, 100, 200, 200};

bool quit = false;

int mouseX, mouseY;

bool initWindow()
{
    bool success = true;

    //Try to initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL initialization failed" << std::endl;
        success = false;
    }
    else {
        //Try to create the window
        window = SDL_CreateWindow("SDL Hello World Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);

        if (window == NULL)
        {
            std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
            success = false;
        }
        else
        {
            // Create a renderer for the current window
            windowRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

            if (windowRenderer == NULL)
            {
                std::cout << "Failed to create the renderer: " << SDL_GetError() << std::endl;
                success = false;
            }
            else
            {
                //Set background color
                SDL_SetRenderDrawColor(windowRenderer, 255, 255, 255, 255);

                //Apply background color
                SDL_RenderClear(windowRenderer);
            }

        }
    }

    return success;
}

void destroyWindow()
{
    //Destroy window
    SDL_DestroyWindow(window);
    window = NULL;

    //Quit SDL
    SDL_Quit();
}

int main(int argc, char * argv[]) {
    if (!initWindow())
    {
        std::cout << "Failed to initialize" << std::endl;
        return -1;
    }


    while (!quit) {
        //Handle events on queue
        if (SDL_WaitEvent(&currentEvent) != 0)
        {
            //User requests quit
            if (currentEvent.type == SDL_QUIT)
            {
                quit = true;
            }

            //Mouse event -> pressed button
            if (currentEvent.type == SDL_MOUSEBUTTONDOWN)
            {
                if (currentEvent.button.button == SDL_BUTTON_LEFT)
                {
                    SDL_GetMouseState(&mouseX, &mouseY);
                    std::cout << "Mouse click => " << "x: " << mouseX << ", y: " << mouseY << std::endl;
                }
            }

            //Mouse event -> mouse movement
            if (currentEvent.type == SDL_MOUSEMOTION)
            {
                if (currentEvent.button.button == SDL_BUTTON_LEFT)
                {
                    SDL_GetMouseState(&mouseX, &mouseY);
                    std::cout << "Mouse move => " << "x: " << mouseX << ", y: " << mouseY << std::endl;
                }
            }

            //Keyboard event
            if (currentEvent.type == SDL_KEYDOWN)
            {
                switch (currentEvent.key.keysym.sym)
                {
                case SDLK_UP:
                    scale_mat = egc::scale(2.0f, 2.0f);
                    P1 = translate_from_origin * scale_mat * translate_to_origin * P1;
                    P2 = translate_from_origin * scale_mat * translate_to_origin * P2;
                    P3 = translate_from_origin * scale_mat * translate_to_origin * P3;
                    P4 = translate_from_origin * scale_mat * translate_to_origin * P4;
                    break;
                case SDLK_r:
                    
                    break;
                case SDLK_DOWN:
                    scale_mat = egc::scale(0.5f, 0.5f);
                    P1 = translate_from_origin * scale_mat * translate_to_origin * P1;
                    P2 = translate_from_origin * scale_mat * translate_to_origin * P2;
                    P3 = translate_from_origin * scale_mat * translate_to_origin * P3;
                    P4 = translate_from_origin * scale_mat * translate_to_origin * P4;
                    break;
                default:
                    break;
                }
            }


            SDL_SetRenderDrawColor(windowRenderer, 255, 255, 255, 255);
            SDL_RenderClear(windowRenderer);

            SDL_SetRenderDrawColor(windowRenderer, 0, 0, 255, 255);
            SDL_RenderDrawLine(windowRenderer, P1.x, P1.y, P2.x, P2.y);
            SDL_RenderDrawLine(windowRenderer, P2.x, P2.y, P3.x, P3.y);
            SDL_RenderDrawLine(windowRenderer, P3.x, P3.y, P4.x, P4.y);
            SDL_RenderDrawLine(windowRenderer, P1.x, P1.y, P4.x, P4.y);

            SDL_RenderPresent(windowRenderer);
        }
    }

    destroyWindow();
    return 0;
}
