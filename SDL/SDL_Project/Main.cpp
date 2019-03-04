#include "../SDL/include/SDL.h"
#pragma comment( lib, "../SDL/libx86/SDL2.lib" )
#pragma comment( lib, "../SDL/libx86/SDL2main.lib" )

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Event event;

	bool loop = true;

	SDL_Window *win = SDL_CreateWindow("RedSquare",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		900,
		720,
		SDL_WINDOW_RESIZABLE);

	SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, 0);

	SDL_Rect redrect = {50, 300, 100, 100};
	SDL_Rect greenrect = { redrect.w/2, redrect.h/2, 50, 20 };

	while (loop)
	{
		// input
		// logic
		if (SDL_PollEvent(&event) != 0)
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) 
				{
                case SDLK_UP:
					if (redrect.y > 0)
					{
						redrect.y -= 10;
					}
                    break;
                case SDLK_DOWN:
                    if (redrect.y < 720 - redrect.h) 
					{
						redrect.y += 10;
                    }
                    break;
                case SDLK_RIGHT:
                    if (redrect.x < (720 - redrect.w)) 
					{
						redrect.x += 10;
                    }
                    break;
                case SDLK_LEFT:
                    if (redrect.x > 0) 
					{
						redrect.x -= 10;
                    }
                    break;
				case SDLK_SPACE:
					while (greenrect.x < (720 - greenrect.w))
					{
						greenrect.x += 15;
					}
					break;
                case SDLK_ESCAPE:
                    loop = false;
                    break;
                }
			}
		}
		//print
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderFillRect(renderer, &greenrect);

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &redrect);
		SDL_RenderPresent(renderer);
	}

	SDL_Quit();
	return 0;
}