#include <ncursesw/ncurses.h>
#include "map.h"
#include "common.h"

const chtype associated_appearance[] =
{
    ' ' | COLOR_PAIR(COLOR_BLACK_ON_WHITE),
    ' ' | COLOR_PAIR(COLOR_WHITE_ON_BLACK),
    ' ' | COLOR_PAIR(COLOR_BLACK_ON_WHITE),
    'A' | COLOR_PAIR(COLOR_YELLOW_ON_GREEN),
    '#' | COLOR_PAIR(COLOR_BLACK_ON_WHITE),
    '*' | COLOR_PAIR(COLOR_RED_ON_WHITE),
    'c' | COLOR_PAIR(COLOR_BLACK_ON_YELLOW),
    't' | COLOR_PAIR(COLOR_BLACK_ON_YELLOW),
    'T' | COLOR_PAIR(COLOR_BLACK_ON_YELLOW),
    'D' | COLOR_PAIR(COLOR_GREEN_ON_YELLOW),
    '?' | COLOR_PAIR(COLOR_BLACK_ON_WHITE),

    '1' | COLOR_PAIR(COLOR_WHITE_ON_MAGENTA),
    '2' | COLOR_PAIR(COLOR_WHITE_ON_MAGENTA),
    '3' | COLOR_PAIR(COLOR_WHITE_ON_MAGENTA),
    '4' | COLOR_PAIR(COLOR_WHITE_ON_MAGENTA)
};

const chtype map_get_color_char_from_tile(enum tile_t tile)
{
    int index = (int)tile;
    return associated_appearance[index];
}

void map_display(struct map_t *map, WINDOW *window)
{
    wclear(window);

    for(int i=0; i<MAP_VIEW_HEIGHT; i++)
    {
        for(int j=0; j<MAP_VIEW_WIDTH; j++)
        {
            int map_y = map->viewpoint_y + i;
            int map_x = map->viewpoint_x + j;

            enum tile_t tile = map->map[map_y][map_x];
            const chtype color_character = map_get_color_char_from_tile(tile);

            mvwaddch(window, i, j, color_character);
        }
    }

    wrefresh(window);
}