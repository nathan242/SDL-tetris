#include "graphics.h"
#include <SDL2/SDL.h>
#include <time.h>
#include <cstdint>

#define RES_X 800
#define RES_Y 800
#define BPP 32

#define GRID_SIZE_X 10
#define GRID_SIZE_Y 20
#define NEXT_GRID_SIZE_X 4
#define NEXT_GRID_SIZE_Y 4
#define BLOCK_SIZE 40

#define NEXT_OFFSET_X 500
#define NEXT_OFFSET_Y 200

#define PIECE_LINE 0
#define PIECE_L 1
#define PIECE_REVERSE_L 2
#define PIECE_SQUARE 3
#define PIECE_5 4
#define PIECE_S 5
#define PIECE_T 6

#define MOVE_DOWN 0
#define MOVE_LEFT 1
#define MOVE_RIGHT 2

void create_tetrominoe(int tetrominoe[4][2], graphics_obj *grid[GRID_SIZE_X][GRID_SIZE_Y], int piece)
{
    switch (piece) {
        case PIECE_LINE:
            tetrominoe[0][0] = 4;
            tetrominoe[0][1] = 1;
            tetrominoe[1][0] = 5;
            tetrominoe[1][1] = 1;
            tetrominoe[2][0] = 6;
            tetrominoe[2][1] = 1;
            tetrominoe[3][0] = 7;
            tetrominoe[3][1] = 1;
            break;

        case PIECE_L:
            tetrominoe[0][0] = 4;
            tetrominoe[0][1] = 0;
            tetrominoe[1][0] = 6;
            tetrominoe[1][1] = 1;
            tetrominoe[2][0] = 5;
            tetrominoe[2][1] = 0;
            tetrominoe[3][0] = 6;
            tetrominoe[3][1] = 0;
            break;

        case PIECE_REVERSE_L:
            tetrominoe[0][0] = 4;
            tetrominoe[0][1] = 0;
            tetrominoe[1][0] = 4;
            tetrominoe[1][1] = 1;
            tetrominoe[2][0] = 5;
            tetrominoe[2][1] = 0;
            tetrominoe[3][0] = 6;
            tetrominoe[3][1] = 0;
            break;

        case PIECE_SQUARE:
            tetrominoe[0][0] = 5;
            tetrominoe[0][1] = 0;
            tetrominoe[1][0] = 6;
            tetrominoe[1][1] = 0;
            tetrominoe[2][0] = 5;
            tetrominoe[2][1] = 1;
            tetrominoe[3][0] = 6;
            tetrominoe[3][1] = 1;
            break;

        case PIECE_5:
            tetrominoe[0][0] = 5;
            tetrominoe[0][1] = 0;
            tetrominoe[1][0] = 6;
            tetrominoe[1][1] = 0;
            tetrominoe[2][0] = 4;
            tetrominoe[2][1] = 1;
            tetrominoe[3][0] = 5;
            tetrominoe[3][1] = 1;
            break;

        case PIECE_S:
            tetrominoe[0][0] = 4;
            tetrominoe[0][1] = 0;
            tetrominoe[1][0] = 5;
            tetrominoe[1][1] = 0;
            tetrominoe[2][0] = 5;
            tetrominoe[2][1] = 1;
            tetrominoe[3][0] = 6;
            tetrominoe[3][1] = 1;
            break;

        case PIECE_T:
            tetrominoe[0][0] = 4;
            tetrominoe[0][1] = 0;
            tetrominoe[1][0] = 5;
            tetrominoe[1][1] = 0;
            tetrominoe[2][0] = 6;
            tetrominoe[2][1] = 0;
            tetrominoe[3][0] = 5;
            tetrominoe[3][1] = 1;
            break;
    }

    *grid[tetrominoe[0][0]][tetrominoe[0][1]]->active = true;
    *grid[tetrominoe[1][0]][tetrominoe[1][1]]->active = true;
    *grid[tetrominoe[2][0]][tetrominoe[2][1]]->active = true;
    *grid[tetrominoe[3][0]][tetrominoe[3][1]]->active = true;
}

void create_next_tetrominoe(int tetrominoe[4][2], graphics_obj *grid[NEXT_GRID_SIZE_X][NEXT_GRID_SIZE_Y], int piece)
{
    switch (piece) {
        case PIECE_LINE:
            tetrominoe[0][0] = 0;
            tetrominoe[0][1] = 1;
            tetrominoe[1][0] = 1;
            tetrominoe[1][1] = 1;
            tetrominoe[2][0] = 2;
            tetrominoe[2][1] = 1;
            tetrominoe[3][0] = 3;
            tetrominoe[3][1] = 1;
            break;

        case PIECE_L:
            tetrominoe[0][0] = 0;
            tetrominoe[0][1] = 0;
            tetrominoe[1][0] = 2;
            tetrominoe[1][1] = 1;
            tetrominoe[2][0] = 1;
            tetrominoe[2][1] = 0;
            tetrominoe[3][0] = 2;
            tetrominoe[3][1] = 0;
            break;

        case PIECE_REVERSE_L:
            tetrominoe[0][0] = 0;
            tetrominoe[0][1] = 0;
            tetrominoe[1][0] = 0;
            tetrominoe[1][1] = 1;
            tetrominoe[2][0] = 1;
            tetrominoe[2][1] = 0;
            tetrominoe[3][0] = 2;
            tetrominoe[3][1] = 0;
            break;

        case PIECE_SQUARE:
            tetrominoe[0][0] = 1;
            tetrominoe[0][1] = 0;
            tetrominoe[1][0] = 2;
            tetrominoe[1][1] = 0;
            tetrominoe[2][0] = 1;
            tetrominoe[2][1] = 1;
            tetrominoe[3][0] = 2;
            tetrominoe[3][1] = 1;
            break;

        case PIECE_5:
            tetrominoe[0][0] = 1;
            tetrominoe[0][1] = 0;
            tetrominoe[1][0] = 2;
            tetrominoe[1][1] = 0;
            tetrominoe[2][0] = 0;
            tetrominoe[2][1] = 1;
            tetrominoe[3][0] = 1;
            tetrominoe[3][1] = 1;
            break;

        case PIECE_S:
            tetrominoe[0][0] = 0;
            tetrominoe[0][1] = 0;
            tetrominoe[1][0] = 1;
            tetrominoe[1][1] = 0;
            tetrominoe[2][0] = 1;
            tetrominoe[2][1] = 1;
            tetrominoe[3][0] = 2;
            tetrominoe[3][1] = 1;
            break;

        case PIECE_T:
            tetrominoe[0][0] = 0;
            tetrominoe[0][1] = 0;
            tetrominoe[1][0] = 1;
            tetrominoe[1][1] = 0;
            tetrominoe[2][0] = 2;
            tetrominoe[2][1] = 0;
            tetrominoe[3][0] = 1;
            tetrominoe[3][1] = 1;
            break;
    }

    for (int x = 0; x < NEXT_GRID_SIZE_X; x++) {
        for (int y = 0; y < NEXT_GRID_SIZE_Y; y++) {
            *grid[x][y]->active = false;
        }
    }

    *grid[tetrominoe[0][0]][tetrominoe[0][1]]->active = true;
    *grid[tetrominoe[1][0]][tetrominoe[1][1]]->active = true;
    *grid[tetrominoe[2][0]][tetrominoe[2][1]]->active = true;
    *grid[tetrominoe[3][0]][tetrominoe[3][1]]->active = true;
}

void copy_tetrominoe(int src_tetrominoe[4][2], int dst_tetrominoe[4][2])
{
    dst_tetrominoe[0][0] = src_tetrominoe[0][0];
    dst_tetrominoe[0][1] = src_tetrominoe[0][1];
    dst_tetrominoe[1][0] = src_tetrominoe[1][0];
    dst_tetrominoe[1][1] = src_tetrominoe[1][1];
    dst_tetrominoe[2][0] = src_tetrominoe[2][0];
    dst_tetrominoe[2][1] = src_tetrominoe[2][1];
    dst_tetrominoe[3][0] = src_tetrominoe[3][0];
    dst_tetrominoe[3][1] = src_tetrominoe[3][1];
}

bool check_tetrominoe_collision(int tetrominoe[4][2], graphics_obj *grid[GRID_SIZE_X][GRID_SIZE_Y])
{
    return tetrominoe[0][0] >= 0 && tetrominoe[0][0] < GRID_SIZE_X
        && tetrominoe[0][1] >= 0 && tetrominoe[0][1] < GRID_SIZE_Y
        && tetrominoe[1][0] >= 0 && tetrominoe[1][0] < GRID_SIZE_X
        && tetrominoe[1][1] >= 0 && tetrominoe[1][1] < GRID_SIZE_Y
        && tetrominoe[2][0] >= 0 && tetrominoe[2][0] < GRID_SIZE_X
        && tetrominoe[2][1] >= 0 && tetrominoe[2][1] < GRID_SIZE_Y
        && tetrominoe[3][0] >= 0 && tetrominoe[3][0] < GRID_SIZE_X
        && tetrominoe[3][1] >= 0 && tetrominoe[3][1] < GRID_SIZE_Y
        && !*grid[tetrominoe[0][0]][tetrominoe[0][1]]->active
        && !*grid[tetrominoe[1][0]][tetrominoe[1][1]]->active
        && !*grid[tetrominoe[2][0]][tetrominoe[2][1]]->active
        && !*grid[tetrominoe[3][0]][tetrominoe[3][1]]->active;
}

bool move_tetrominoe(int tetrominoe[4][2], graphics_obj *grid[GRID_SIZE_X][GRID_SIZE_Y], int direction)
{
    bool moved = false;
    int new_tetrominoe[4][2];

    copy_tetrominoe(tetrominoe, new_tetrominoe);

    switch (direction) {
        case MOVE_DOWN:
            new_tetrominoe[0][1]++;
            new_tetrominoe[1][1]++;
            new_tetrominoe[2][1]++;
            new_tetrominoe[3][1]++;
            break;
        case MOVE_LEFT:
            new_tetrominoe[0][0]--;
            new_tetrominoe[1][0]--;
            new_tetrominoe[2][0]--;
            new_tetrominoe[3][0]--;
            break;
        case MOVE_RIGHT:
            new_tetrominoe[0][0]++;
            new_tetrominoe[1][0]++;
            new_tetrominoe[2][0]++;
            new_tetrominoe[3][0]++;
            break;
    }

    *grid[tetrominoe[0][0]][tetrominoe[0][1]]->active = false;
    *grid[tetrominoe[1][0]][tetrominoe[1][1]]->active = false;
    *grid[tetrominoe[2][0]][tetrominoe[2][1]]->active = false;
    *grid[tetrominoe[3][0]][tetrominoe[3][1]]->active = false;

    if (check_tetrominoe_collision(new_tetrominoe, grid)) {
        copy_tetrominoe(new_tetrominoe, tetrominoe);
        moved = true;
    }

    *grid[tetrominoe[0][0]][tetrominoe[0][1]]->active = true;
    *grid[tetrominoe[1][0]][tetrominoe[1][1]]->active = true;
    *grid[tetrominoe[2][0]][tetrominoe[2][1]]->active = true;
    *grid[tetrominoe[3][0]][tetrominoe[3][1]]->active = true;

    return moved;
}

// TODO
void rotate_tetrominoe(int tetrominoe[4][2], graphics_obj *grid[GRID_SIZE_X][GRID_SIZE_Y], int type)
{
    int temp_tetrominoe[4][2];
    int new_tetrominoe[4][2];
    int lowest_x;
    int lowest_y;

    lowest_x = tetrominoe[0][0];
    if (lowest_x > tetrominoe[1][0]) lowest_x = tetrominoe[1][0];
    if (lowest_x > tetrominoe[2][0]) lowest_x = tetrominoe[2][0];
    if (lowest_x > tetrominoe[3][0]) lowest_x = tetrominoe[3][0];

    lowest_y = tetrominoe[0][1];
    if (lowest_y > tetrominoe[1][1]) lowest_y = tetrominoe[1][1];
    if (lowest_y > tetrominoe[2][1]) lowest_y = tetrominoe[2][1];
    if (lowest_y > tetrominoe[3][1]) lowest_y = tetrominoe[3][1];

    temp_tetrominoe[0][0] = tetrominoe[0][0] - lowest_x;
    temp_tetrominoe[1][0] = tetrominoe[1][0] - lowest_x;
    temp_tetrominoe[2][0] = tetrominoe[2][0] - lowest_x;
    temp_tetrominoe[3][0] = tetrominoe[3][0] - lowest_x;
    temp_tetrominoe[0][1] = tetrominoe[0][1] - lowest_y;
    temp_tetrominoe[1][1] = tetrominoe[1][1] - lowest_y;
    temp_tetrominoe[2][1] = tetrominoe[2][1] - lowest_y;
    temp_tetrominoe[3][1] = tetrominoe[3][1] - lowest_y;

    switch (type) {
        case 0:
        default:
            new_tetrominoe[0][0] = temp_tetrominoe[0][1];
            new_tetrominoe[0][1] = 1-(temp_tetrominoe[0][0]-(4-2));
            new_tetrominoe[1][0] = temp_tetrominoe[1][1];
            new_tetrominoe[1][1] = 1-(temp_tetrominoe[1][0]-(4-2));
            new_tetrominoe[2][0] = temp_tetrominoe[2][1];
            new_tetrominoe[2][1] = 1-(temp_tetrominoe[2][0]-(4-2));
            new_tetrominoe[3][0] = temp_tetrominoe[3][1];
            new_tetrominoe[3][1] = 1-(temp_tetrominoe[3][0]-(4-2));
    }

    new_tetrominoe[0][0] = new_tetrominoe[0][0] + lowest_x;
    new_tetrominoe[1][0] = new_tetrominoe[1][0] + lowest_x;
    new_tetrominoe[2][0] = new_tetrominoe[2][0] + lowest_x;
    new_tetrominoe[3][0] = new_tetrominoe[3][0] + lowest_x;
    new_tetrominoe[0][1] = new_tetrominoe[0][1] + lowest_y;
    new_tetrominoe[1][1] = new_tetrominoe[1][1] + lowest_y;
    new_tetrominoe[2][1] = new_tetrominoe[2][1] + lowest_y;
    new_tetrominoe[3][1] = new_tetrominoe[3][1] + lowest_y;

    *grid[tetrominoe[0][0]][tetrominoe[0][1]]->active = false;
    *grid[tetrominoe[1][0]][tetrominoe[1][1]]->active = false;
    *grid[tetrominoe[2][0]][tetrominoe[2][1]]->active = false;
    *grid[tetrominoe[3][0]][tetrominoe[3][1]]->active = false;

    if (check_tetrominoe_collision(new_tetrominoe, grid)) {
        copy_tetrominoe(new_tetrominoe, tetrominoe);
    }

    *grid[tetrominoe[0][0]][tetrominoe[0][1]]->active = true;
    *grid[tetrominoe[1][0]][tetrominoe[1][1]]->active = true;
    *grid[tetrominoe[2][0]][tetrominoe[2][1]]->active = true;
    *grid[tetrominoe[3][0]][tetrominoe[3][1]]->active = true;
}

void get_remove_lines(graphics_obj *grid[GRID_SIZE_X][GRID_SIZE_Y], int remove_lines[4])
{
    int remove_count = 0;

    for (int y = 0; y < GRID_SIZE_Y; y++) {
        for (int x = 0; x < GRID_SIZE_X; x++) {
            if (!*grid[x][y]->active) {
                goto next_line;
            }
        }

        remove_lines[remove_count++] = y;

        next_line:
        continue;
    }
}

void do_remove_lines(graphics_obj *grid[GRID_SIZE_X][GRID_SIZE_Y], int remove_lines[4])
{
    for (int i = 0; i < 4; i++) {
        if (remove_lines[i] == -1) { continue; }

        // Remove the line
        for (int x = 0; x < GRID_SIZE_X; x++) {
            *grid[x][remove_lines[i]]->active = false;
        }

        // Move above lines down
        for (int y = remove_lines[i]; y != 0; y--) {
            for (int x = 0; x < GRID_SIZE_X; x++) {
                *grid[x][y]->active = *grid[x][y-1]->active;
            }
        }

        remove_lines[i] = -1;
    }
}

void tetris()
{
    // bool vars for control directions and quit event
    bool quit = false;
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
    bool key_pressed = false;

    SDL_Event input;

    graphics_obj *grid[GRID_SIZE_X][GRID_SIZE_Y];
    graphics_obj *next_grid[NEXT_GRID_SIZE_X][NEXT_GRID_SIZE_Y];
    int tetrominoe[4][2];
    int next_tetrominoe[4][2];
    int current;
    int next = -1;
    int remove_lines[4] = {-1, -1, -1, -1};

    timespec last_move {0, 0};
    timespec now;
    uint64_t timediff;

    srand(time(NULL));

    graphics *window = new graphics("SDL TETRIS", RES_X, RES_Y, BPP);

    for (int x = 0; x < GRID_SIZE_X; x++) {
        for (int y = 0; y < GRID_SIZE_Y; y++) {
            grid[x][y] = new graphics_obj;
            grid[x][y]->sprite = SDL_CreateRGBSurface(0, BLOCK_SIZE, BLOCK_SIZE, 32, 0, 0, 0, 0);
            grid[x][y]->draw_pos_x = x*BLOCK_SIZE;
            grid[x][y]->draw_pos_y = y*BLOCK_SIZE;
            grid[x][y]->draw_active = false;
            grid[x][y]->pos_x = &grid[x][y]->draw_pos_x;
            grid[x][y]->pos_y = &grid[x][y]->draw_pos_y;
            grid[x][y]->size_x = BLOCK_SIZE;
            grid[x][y]->size_y = BLOCK_SIZE;
            grid[x][y]->active = &grid[x][y]->draw_active;
            SDL_FillRect(grid[x][y]->sprite, NULL, SDL_MapRGB(grid[x][y]->sprite->format, 255, 255, 255));
            grid[x][y]->texture = SDL_CreateTextureFromSurface(window->renderer, grid[x][y]->sprite);

            window->add_object(grid[x][y]);
        }
    }

    for (int x = 0; x < NEXT_GRID_SIZE_X; x++) {
        for (int y = 0; y < NEXT_GRID_SIZE_Y; y++) {
            next_grid[x][y] = new graphics_obj;
            next_grid[x][y]->sprite = SDL_CreateRGBSurface(0, BLOCK_SIZE, BLOCK_SIZE, 32, 0, 0, 0, 0);
            next_grid[x][y]->draw_pos_x = x*BLOCK_SIZE+NEXT_OFFSET_X;
            next_grid[x][y]->draw_pos_y = y*BLOCK_SIZE+NEXT_OFFSET_Y;
            next_grid[x][y]->draw_active = false;
            next_grid[x][y]->pos_x = &next_grid[x][y]->draw_pos_x;
            next_grid[x][y]->pos_y = &next_grid[x][y]->draw_pos_y;
            next_grid[x][y]->size_x = BLOCK_SIZE;
            next_grid[x][y]->size_y = BLOCK_SIZE;
            next_grid[x][y]->active = &next_grid[x][y]->draw_active;
            SDL_FillRect(next_grid[x][y]->sprite, NULL, SDL_MapRGB(next_grid[x][y]->sprite->format, 255, 255, 255));
            next_grid[x][y]->texture = SDL_CreateTextureFromSurface(window->renderer, next_grid[x][y]->sprite);

            window->add_object(next_grid[x][y]);
        }
    }

    current = rand() % 7;

    create_tetrominoe(tetrominoe, grid, current);

    // Main loop
    while (quit==false)
    {
        // Read inputs
        while (SDL_PollEvent(&input))
        {
            switch (input.type)
            {
                case SDL_KEYDOWN:
                    switch (input.key.keysym.sym)
                        {
                            case SDLK_LEFT:
                                left = true;
                                break;
                            case SDLK_RIGHT:
                                right = true;
                                break;
                            case SDLK_UP:
                                up = true;
                                break;
                            case SDLK_DOWN:
                                down = true;
                                break;
                            case SDLK_q:
                                quit = true;
                                break;
                        }
                        break;
                case SDL_KEYUP:
                    switch (input.key.keysym.sym)
                        {
                            case SDLK_LEFT:
                                left = false;
                                break;
                            case SDLK_RIGHT:
                                right = false;
                                break;
                            case SDLK_UP:
                                up = false;
                                break;
                            case SDLK_DOWN:
                                down = false;
                                break;
                        }
            }
        }

        if (next == -1) {
            next = rand() % 7;
            create_next_tetrominoe(next_tetrominoe, next_grid, next);
        }

        if (!left && !right && !up && !down) {
            key_pressed = false;
        }

        if (!key_pressed && (left || right || up || down)) {
            if (left) { move_tetrominoe(tetrominoe, grid, MOVE_LEFT); }
            if (right) { move_tetrominoe(tetrominoe, grid, MOVE_RIGHT); }
            if (down) { move_tetrominoe(tetrominoe, grid, MOVE_DOWN); }
            if (up) { rotate_tetrominoe(tetrominoe, grid, 0); }

            key_pressed = true;
        }

        clock_gettime(CLOCK_MONOTONIC, &now);
        timediff = ((now.tv_sec - last_move.tv_sec) * 1000000000) + (now.tv_nsec - last_move.tv_nsec);

        if (timediff > 600000000) {
            if (!move_tetrominoe(tetrominoe, grid, MOVE_DOWN)) {
                get_remove_lines(grid, remove_lines);
                do_remove_lines(grid, remove_lines);
                create_tetrominoe(tetrominoe, grid, next);
                current = next;
                next = -1;
            }

            last_move = now;
        }

        // Redraw screen
        window->draw();
    }

    SDL_Quit();

    delete window;

    for (int x = 0; x < GRID_SIZE_X; x++) {
        for (int y = 0; y < GRID_SIZE_Y; y++) {
            SDL_FreeSurface(grid[x][y]->sprite);
            SDL_DestroyTexture(grid[x][y]->texture);
            delete grid[x][y];
        }
    }

    for (int x = 0; x < NEXT_GRID_SIZE_X; x++) {
        for (int y = 0; y < NEXT_GRID_SIZE_Y; y++) {
            SDL_FreeSurface(next_grid[x][y]->sprite);
            SDL_DestroyTexture(next_grid[x][y]->texture);
            delete next_grid[x][y];
        }
    }

    return;
}

int main (int argc, char *argv[])
{
    tetris();
    return 0;
}

