#include "Application.h"

Application::Application() : window(nullptr), renderer(nullptr), isRunning(false) {}

bool Application::init() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_APPLICATION, 
            "Couldn't initialize SDL: %s", 
            SDL_GetError()
        );
        return false;
    }

    if (!SDL_CreateWindowAndRenderer(
        "Chess", 
        WINDOW_SIZE, 
        WINDOW_SIZE, 
        SDL_WINDOW_RESIZABLE, 
        &window, 
        &renderer
    )) {
        SDL_LogError(
            SDL_LOG_CATEGORY_APPLICATION, 
            "Couldn't create window and renderer: %s", 
            SDL_GetError()
        );

        return false;
    }

    isRunning = true;
    return true;
}

void Application::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_EVENT_QUIT) {
        isRunning = false;
    }
}

void Application::render() {
    SDL_SetRenderDrawColor(renderer, 35, 40, 50, 255);
    SDL_RenderClear(renderer);

    // Draw the chess board
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            SDL_FRect tile = {
                static_cast<float>(BORDER_SIZE + col * SQUARE_SIZE),
                static_cast<float>(BORDER_SIZE + row * SQUARE_SIZE),
                static_cast<float>(SQUARE_SIZE),
                static_cast<float>(SQUARE_SIZE)
            };

            // Alternate between light and dark squares
            if ((row + col) % 2 == 0) {
                SDL_SetRenderDrawColor(renderer, 125, 155, 220, 255);
            } else {
                SDL_SetRenderDrawColor(renderer, 35, 40, 50, 255);
            }

            SDL_RenderFillRect(renderer, &tile);
        }
    }

    // Draw the border
    SDL_SetRenderDrawColor(renderer, 125, 155, 220, 255);
    SDL_FRect boardOutline = {
        static_cast<float>(BORDER_SIZE),
        static_cast<float>(BORDER_SIZE),
        static_cast<float>(BOARD_SIZE),
        static_cast<float>(BOARD_SIZE)
    };
    SDL_RenderRect(renderer, &boardOutline);

    SDL_RenderPresent(renderer);
}

void Application::run() {
    while (isRunning) {
        handleEvents();
        render();
    }
}

void Application::cleanup() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    SDL_Quit();
} 

Application::~Application() {
    cleanup();
}