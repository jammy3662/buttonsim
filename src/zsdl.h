#include <SDL.h>

class sdlwindow {
public:
    char* title;
    SDL_Window *window;
    SDL_Renderer *renderer;
    void make(char* t, int x, int y, int w, int h, uint32_t shown) {
    	title = t;
    	window = SDL_CreateWindow(title, x, y, w, h, shown);
    }
    void render(SDL_Renderer *r) {
    	SDL_Init(SDL_INIT_EVERYTHING);
    	renderer = r;
    	SDL_RenderClear(renderer);
    	SDL_RenderPresent(renderer);
    }
};