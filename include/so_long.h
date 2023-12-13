
#ifndef SO_LONG_H
# define SO_LONG_H

#include "../include/mlx.h"
#include <stdio.h>

typedef struct	s_data {
    void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    int     img_width;
    int     img_height;

}				t_data;
typedef struct	s_anim {
	t_data	front;
	t_data	frontW;
	t_data	frontW2;
	t_data	back;
	t_data	backW;
	t_data	backW2;
	t_data	left;
	t_data	leftW;
	t_data	leftW2;
	t_data	right;
	t_data	rightW;
	t_data	rightW2;
	int		x;
	int		y;
}				t_anim;

typedef struct	s_win {
	void	*mlx;
    void	*mlx_win;
	char	**map;
	int		y;
	int		x;
	int		c_count;
	int		loop;
	int		anim_count;
	int		keycode;
	t_anim	kakashi;
	t_anim	naruto;
	t_data	obstacle;
	t_data	bg;
	t_data	escape;
}				t_win;

typedef struct	s_index {
	int	i;
	int	x;
	int	y;
	int	j;
	int	k;
	int	l;
	int	c;
	int	e;
	int	p;
}				t_index;

typedef struct s_coords
{
	int		x;
	int		y;
	void	*next;
}	t_coords;

typedef struct s_character
{
	int			C;
	t_coords	*C_coords;
	t_coords	*P_coords;
	t_coords	*E_coords;

}	t_character;

void		*ft_freetabtabb(int k, char **tab);
char		**ft_realoc_tabtab(char **tab, int size);
char		**ft_get_map(int fd);
char		**ft_map_verif(char *file, t_win *win);
t_coords	*ft_newlstcoords(int x, int y, t_coords *coords);
t_character	*ft_char_shearch(char **map, t_character **character);
t_coords	*ft_collectible_check(t_coords *P_coords, t_coords *C_coords, char **newmap);
char		**ft_new_map(char **map);
t_coords	*ft_zero_check(t_character character, char **map, char **newmap);
int			ft_road_error(char **map, char **newmap, t_character *character);
void		ft_print_tabtab(char **tab);
void		ft_print_coords(t_coords *lst);
void		ft_print_tabtab(char **tab);
void		ft_tabtablen(t_win *win);
void		ft_win_init(t_win *win);
int			ft_hook(int keycode, t_win *win);
t_data		ft_get_image_transparance(void *mlx, t_data bg, char *path);
int			ft_print_character(t_win *win, void *img, char c);
int			ft_loop_hook(t_win *win);
#endif
