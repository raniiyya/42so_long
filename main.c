#include "so_long.h"

void validate_chars(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j]) {
            if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P') {
                write(1, "Error\nInvalid map\n", 18);
                exit(1);
            }
            j++;
        }
        i++;
    }
}

void validate_rect(char **map)
{
    int i;

    i = 1;
    while (map[i])
    {
        if (ft_strlen(map[i]) != ft_strlen(map[i - 1])) {
            write(1, "Error\nInvalid map\n", 18);
            exit(1);
        }
        i++;
    }
}
    
void validate_border(char **map)
{
    int i;
    int j;

    j = 0;
    while (map[0][j])
    {
        if (map[0][j] != '1') //checking the 1st line
        {
            write(1, "Error\nInvalid map\n", 18);
            exit(1);
        }
        j++;
    }
    i = 0;
    j = 0;
    while (map[i]) //going to the last line
        i++;
    while (map[i - 1][j])
    {
        if (map[i - 1][j] != '1') //cheching the last line
        {
            write(1, "Error\nInvalid map\n", 18);
            exit(1);
        }
        j++;
    }
    i = 0;
    j = 0;
    while (map[i][j]) //going to the last column i guess
        j++;
    if (map[i][0] != '1' && map[i][j] != '1') //checking the 1st and last column
    {
        write(1, "Error\nInvalid map\n", 18);
        exit(1);
    }
}

void validate_path(char **map)
{
    
}

void validate_map(char **map)
{
    validate_chars(map);
    validate_rect(map);
    validate_border(map);
    validate_path(map);
}

int main(int argc, char **argv)
{
    char **map;

    map = parse_map(map, argv[1]);
    validate_map(map);
    return (0);
}