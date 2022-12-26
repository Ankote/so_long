#include "so_long.h"

void floodFill(char **p, int sr, int sc, int base)
{
    // Condition for checking out of bounds
    if (p[sr][sc] != '0' && p[sr][sc] != 'P' && p[sr][sc] != base)
        return;
    p[sr][sc] = 'V'; 
    floodFill(p, sr, sc - 1, base); // left
    floodFill(p, sr + 1, sc, base); // bottom
    floodFill(p, sr - 1, sc, base); // top
    floodFill(p, sr, sc + 1, base); // right
}

int check_path(t_graph *data, int base)
{
    char **p;
    int x;
    int y;

    x = data->x_pos;
    y = data->y_pos;
    p = data->p;
    floodFill(p, y, x, base);
    if (base == 'E')
    {
        if (check_exit(data))
        {
            printf("ERROR!there is no valid path to go the exit.\n");
            return (free(p), 0);
        }   
    }
    else if (base == 'C')
    {
        if (check_coin(data))
        {
            printf("ERROR!there is no valid path to catch all collectibles\n");
            return (free (p), 0);
        } 
    }  
    return (free(p), 1);
}