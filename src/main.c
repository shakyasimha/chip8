#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

// Screen dimension constraints
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480   ;

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
        } else {
            // Get window surface 
            screenSurface = SDL_GetWindowSurface( window );

            // Fill the surface white 
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF) );

            // Update the surface
            SDL_UpdateWindowSurface( window );

            // Hack to get the window to stay up 
            SDL_Event e; bool quit = false; while( quit == false ) { while( SDL_PollEvent( &e )) { if ( e.type == SDL_QUIT) quit = true; }}
        }
    }

    // Destroy window 
    SDL_DestroyWindow( window );

    // Quit SDL subsystems
    SDL_Quit();

    return 0;
}
