
#ifndef SO_LONG_H
# define SO_LONG_H

#include "../minilibx-linux/mlx.h"
#include <stdio.h>

typedef struct	s_data {
    void	*img;
	char	*addr;
    char    *relative_path;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    int     img_width;
    int     img_height;
    int     x;
    int     y;
}				t_data;

typedef struct	s_win {
	void    *mlx;
    void    *mlx_win;
    t_data  sasuke;
    t_data  grass;
}				t_win;

typedef struct	s_index {
	int i;
    int x;
    int y;
    int j;
    int k;
    int l;
    int c;
    int e;
    int p;
}				t_index;

void	*ft_freetabtabb(int k, char **tab);
char **ft_realoc_tabtab(char **tab, int size);
char **ft_get_map(int fd);
int	ft_map_verif(char **map);

#endif
