#include <stdio.h>
#include <SDL.h>

// Screen dimension constraints
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char **argv) {
    // Window that we'll be rendering to 
    SDL_Window* window = NULL; 

    // Surface contained by the window 
    SDL_Surface* screenSurface = NULL;

    // Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf("SLD could not initialize! SDL_ERROR: %s\n", SDL_GetError() );
    } else {
        // Create window 
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if(window == NULL) {
            printf("Window could not be created! SDL_ERROR: %s\n", SDL_GetError() ); 
        }
    }
}
