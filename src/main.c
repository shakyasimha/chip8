#include <stdio.h>
#include <stdbool.h>

#include "SDL.h"
#include "chip8.h"

// SDL Container Object
typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
} sdl_t;

// Emulator configuration
typedef struct {
    uint32_t window_width;  // SDL Window Width
    uint32_t window_height; // SDL Window Height
    uint32_t fg_color;      // Foreground colour RGBA8888
    uint32_t bg_color;      // Background colour RGBA8888
    uint32_t scale_factor;  // Scaling factor 
} config_t;

// enum for emulator state
typedef enum {
    QUIT, 
    RUNNING,
    PAUSED,
} emulator_state_t

// CHIP8 machine state
typedef struct {
    emulator_state_t state;
} chip8_t;

// Initializing SDL
bool init_sdl(sdl_t* sdl, const config_t config) {
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0) {
        SDL_Log("Failed to initialize SDL subsystem! %s\n", SDL_GetError());
        return false; 
    }

    sdl->window = SDL_CreateWindow("CHIP8 Emulator", SDL_WINDOWPOS_CENTERED, 
                                SDL_WINDOWPOS_CENTERED, 
                                config.window_width * config.scale_factor, config.window_height * config.scale_factor, 
                                0);

    if(!sdl->window) {
        SDL_Log("Failed to create SDL window! %s\n", SDL_GetError());
        return false;
    }

    sdl->renderer = SDL_CreateRenderer(sdl->window, -1, SDL_RENDERER_ACCELERATED);
    if(!sdl->renderer) {
        SDL_Log("Failed to render SDL subsystem. %s\n", SDL_GetError());
        return false;
    }

    return true; // Success
}

// Initializing CHIP8 configuration
void init_chip8(const chip8_t *chip8) {

}

// Setup initial emulator configuration from passed down arguments
bool set_config_from_args(config_t *config, int argc, const char **argv) {
    // Set defaults 
    *config = (config_t){
        .window_width = 64,
        .window_height = 32,
        .fg_color = 0x000000FF,   // WHITE
        .bg_color = 0xFFFFFFFF,   // YELLOW
        .scale_factor = 20,       // Default resolution will be 1280x640;
    };

    // Override defualts passed in the arguments
    for(int i = 1; i < argc; i++){
        (void)argv[i];  // prevent compiler error form unused argc/arg
        //...
    }
}

// Clear screen / SDL window to background colour
void clear_screen(const sdl_t sdl, const config_t config) {
    const uint8_t r = (config.bg_color >> 24) & 0xFF;
    const uint8_t g = (config.bg_color >> 16) & 0xFF;
    const uint8_t b = (config.bg_color >> 8) & 0xFF;
    const uint8_t a = (config.bg_color >> 0) & 0xFF;

    SDL_SetRenderDrawColor(sdl.renderer, r, g, b, a);
    SDL_RenderClear(sdl.renderer);
}

// Updating screen
void update_screen(const sdl_t sdl, const config_t config) {
    SDL_RenderPresent(sdl.renderer);
}

// For handling input
void handle_input(chip8_t *chip8) {
    SDL_Event event; 
    
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                // Exit window; End program
                chip8->state = QUIT;    // Will exit main emulator loop
                return;

            case SDL_KEYDOWN:

            case SDL_KEYUP:
                break;

        }
    }
}

// Final cleanup
void final_cleanup(const sdl_t sdl) {
    if(sdl.renderer) SDL_DestroyRenderer(sdl.renderer);
    if(sdl.window) SDL_DestroyWindow(sdl.window);
    SDL_Quit(); // Shuts down the SDL subsystem
}

int main(int argc, char **argv) {
    (void)argc; 
    (void)argv;
    
    // Initialize SDL values
    sdl_t sdl = {0};
    config_t config = {0};

    // Initialize sdl config options
    if (!set_config_from_args(&config, argc, argv)) exit(EXIT_FAILURE);

    // Initialize CHIP8 state
    chip8_t chip8 = {0};
    if(!init_chip8(&chip8)) exit(EXIT_FAILURE);

    // Finally initialize sdl
    if(!init_sdl(&sdl, config)) exit(EXIT_FAILURE);
    
    // Initial screen clear
    clear_screen(sdl, config);

    // Main emulator loop
    while(chip8.state != QUIT) {
        // Handle user input
        handle_input(&chip8);

        // Get_Time();
        // Emulate CHIP8 instructions here 
        // Get_Time();

        // 60 Hz / fps (16.67ms)
        // SDL_Delay(16 - time_elapsed);
        SDL_Delay(16);

        // Update window with changes
        update_screen(sdl, config);
    }

    // Final cleanup
    final_cleanup(sdl);

    exit(EXIT_SUCCESS);
}
