
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
	t_data	still;
	t_data	walk;
	t_data	walk2;
	t_data	fight;
	t_data	fight2;
	t_data	fight3;
}				t_anim;

typedef struct	s_ennemies {
	t_data	frame1;
	t_data	frame2;
	t_data	frame3;
	t_data	frame4;
	t_data	frame5;
	t_data	dead;
	t_data	dead2;
	t_data	dead3;
	int		state;
	int		x;
	int		y;
}				t_ennemies;

typedef struct	s_player {
	t_anim	front;
	t_anim	back;
	t_anim	left;
	t_anim	right;
	int		x;
	int		y;
}				t_player;

typedef struct	s_win {
	void		*mlx;
    void		*mlx_win;
	char		**map;
	int			y;
	int			x;
	int			c_count;
	int			loop;
	int			anim_count;
	int			keycode;
	int			moove;
	t_player	player;
	t_ennemies	ennemies;
	t_data		obstacle;
	t_data		bg;
	t_data		escape;
	t_data		collectible;
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
}				t_coords;

typedef struct s_character
{
	int			C;
	t_coords	*N_coords;
	t_coords	*P_coords;
	t_coords	*E_coords;
	t_coords	*C_coords;

}				t_character;

t_character	*ft_char_shearch(char **map, t_character **character);
t_coords	*ft_newlstcoords(int x, int y, t_coords *coords);
t_coords	*ft_collectible_check(t_coords *P_coords, t_coords *coords, char **newmap);
t_coords	*ft_zero_check(t_character character, char **map, char **newmap);
t_coords	*ft_get_coords(char **map, int c);
t_data		ft_get_image_transparance(void *mlx, t_data bg, char *path);
void		*ft_freetabtabb(int k, char **tab);
void		ft_print_tabtab(char **tab);
void		ft_print_coords(t_coords *lst);
void		ft_tabtablen(char **tab, t_win *win);
void		ft_win_init(t_win *win);
void		ft_put_walkanim(t_win *win);
void		ft_put_fight_anim(t_win *win);
void		ft_put_deadanim(t_win *win);
void		ft_close_game(t_win *win, char *str);
void		ft_freecoords(t_coords *coords);
void		ft_new_map(char **map, char **newmap);
char		**ft_realoc_tabtab(char **tab, int size);
char		**ft_get_map(int fd);
char		**ft_map_verif(char *file, t_win *win);
int			ft_road_error(char **map, char **newmap, t_character *character);
int			ft_hook(int keycode, t_win *win);
int			ft_print_character(t_win *win, void *img, char c);
int			ft_check_moove(t_win *win);
int			ft_loop_hook(t_win *win);

#endif
