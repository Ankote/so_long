#include "so_long.h"

void floodFill(char **p, int sr, int sc, int base)
{
    // Condition for checking out of bounds
    if (p[sr][sc] != '0' && p[sr][sc] != 'P' && p[sr][sc] != base && p[sr][sc] != 'C')
        return;
    p[sr][sc] = 'V'; 
    floodFill(p, sr, sc - 1, base); // left
    floodFill(p, sr + 1, sc, base); // bottom
    floodFill(p, sr - 1, sc, base); // top
    floodFill(p, sr, sc + 1, base); // right
}

static int check_exist(char **p, int base)
{
    int i;
    int j;

    i = 0;
    while(p[i])
    {
        j = 0;
        while (p[i][j])
        {
            if(p[i][j] == base)
                return  (0);
            j ++;
        }
        i++;
    }
     return (1);
}
   
int check_path(t_graph *data, int base)
{
    char **p;
    int x;
    int y;

    x = data->x_pos;
    y = data->y_pos;
    p = ft_split(data->map, '\n');
    floodFill(p, y, x, base);
    if (base == 'E')
    {
        if (!check_exist(p, 'E'))
        {
            printf("ERROR!\nthere is no valid path to go the exit.\n");
            return (free(p), 0);
        }  
    }
    else if (base == 'C')
    {
        if (!check_exist(p, 'C'))
        {
            printf("ERROR!\nthere is no valid path to catch all collectibles\n");
            return (free (p), 0);
        }
    }  
    return (free(p), 1);
}