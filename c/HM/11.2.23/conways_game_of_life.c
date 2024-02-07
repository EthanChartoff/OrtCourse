#include <stdio.h>
#include <SDL2/SDL.h>  

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define CELL_SIZE 10
#define GRID_WIDTH (WINDOW_WIDTH / CELL_SIZE)
#define GRID_HEIGHT (WINDOW_HEIGHT / CELL_SIZE)


/// @brief initialize window 
int init_window(SDL_Window **window) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    *window = SDL_CreateWindow(
        "Conway's Game of Life", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        WINDOW_WIDTH, 
        WINDOW_HEIGHT, 
        SDL_WINDOW_SHOWN
    );

    if (*window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    return 0;
}

/// @brief init renderer
/// @param renderer 
/// @param window 
/// @return 
int init_renderer(SDL_Renderer **renderer, SDL_Window *window) {
    *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    return 0;
}

/// @brief initialize grid
/// @note maybe add initial states, like a glider.
void init_grid(int ***grid) {
    int i;

    *grid = malloc(GRID_WIDTH * sizeof(int *));
    for(i = 0; i < GRID_WIDTH; ++i)
        (*grid)[i] = calloc(GRID_HEIGHT, sizeof(int));

    (*grid)[2][1] = 1;
    (*grid)[3][2] = 1;
    (*grid)[1][3] = 1;
    (*grid)[2][3] = 1;
    (*grid)[3][3] = 1;
}

/// @brief count the neighbours of a cell in a position on the grid
/// @param x 
/// @param y 
/// @return 
int count_neighbours(int x, int y, int **grid) {
    int count = 0;
    int x_neighbour, y_neighbour;
    int dx, dy;

    for(dx = -1; dx <= 1; ++dx) {
        for(dy = -1; dy <= 1; ++dy) {
            if(dx == 0 && dy == 0)
                continue;

            x_neighbour = x + dx;
            y_neighbour = y + dy;

            if (x_neighbour >= 0 && x_neighbour < GRID_WIDTH && y_neighbour >= 0 && y_neighbour < GRID_HEIGHT)
                count += grid[x_neighbour][y_neighbour];
        }
    }

    return count;
}

/// @brief update the game grid according to the rules of the game of life.
/// @param grid 
/// @param next 
void update_grid(int **grid) {
    int **next;
    int x, y;
    int neighbours;

    next = malloc(sizeof(int *) * GRID_WIDTH);
    for(x = 0; x < GRID_WIDTH; ++x) {
        next[x] = malloc(sizeof(int) * GRID_HEIGHT);
    }
    
    for(x = 0; x < GRID_WIDTH; ++x) {
        for(y = 0; y < GRID_HEIGHT; ++y) {
            neighbours = count_neighbours(x, y, grid);

            if(neighbours < 2 || neighbours > 3) {
                next[x][y] = 0;
            } else if(neighbours == 3) {
                next[x][y] = 1;
            } else {
                next[x][y] = grid[x][y];
            }
        }
    }

    for(x = 0; x < GRID_WIDTH; ++x) {
        for(y = 0; y < GRID_HEIGHT; ++y) {
            grid[x][y] = next[x][y];
        }
    }

    for(x = 0; x < GRID_WIDTH; ++x) {
        free(next[x]);
    }
    free(next);
}

/// @brief render grid to window
void render(SDL_Renderer *renderer, int **grid) {
    int x, y;
    SDL_Rect cell;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    cell.w = CELL_SIZE;
    cell.h = CELL_SIZE;
    
    for(x = 0; x < GRID_WIDTH; ++x) {
        for(y = 0; y < GRID_HEIGHT; ++y) {
            if(grid[x][y] == 1) {
                cell.x = x * CELL_SIZE;
                cell.y = y * CELL_SIZE;

                SDL_RenderFillRect(renderer, &cell);
            }
        }
    }

    SDL_RenderPresent(renderer);
}



int main(void) {
    int **grid; // the current grid with the current population

    SDL_Window *window;
    SDL_Renderer *renderer;

    if(init_window(&window) || init_renderer(&renderer, window)) return 1;
    
    init_grid(&grid);
    render(renderer, grid);

    SDL_Event event;
    int quit = 0;

    while(!quit) {
        while (SDL_PollEvent(&event) != 0) {
            if(event.type == SDL_QUIT) {
                quit = 1;
            }
        }
        update_grid(grid);
        render(renderer, grid);

        SDL_Delay(1000);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}