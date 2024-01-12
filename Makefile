NAME = exe

CC = gcc

CFLAGS = -Wall -Wextra -g

SRC = src/so_long.c \
	src/get_map.c	\
	src/map_error.c \
	src/road_error.c \
	src/road_error2.c \
	src/utils.c \
	src/win_init.c \
	src/movement.c \
	src/anim.c \
	src/fight_anim.c \
	src/char_init.c \
	src/ennemies.c

LIB = mlx

MLXDIR = minilibx

OBJ = $(SRC:.c=.o)

OSFLAG 				:=
MLXDIR				:=

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	OSFLAG = -lXext -lX11 -lm -lz
	MLXDIR = minilibx-linux
endif
UNAME_P := $(shell uname -p)
ifneq ($(filter arm%,$(UNAME_P)),)
	OSFLAG = -framework OpenGL -framework AppKit
	MLXDIR = minilibx
endif

all : $(NAME)

src/%.o : src/%.c
	$(CC) $(CFLAGS) -I include -I $(MLXDIR) -c $< -o $@

$(NAME) : $(OBJ)
	make -C libft
	cp libft/libft.a lib
	$(CC) $(CFLAGS) $(OBJ) -I include -L lib -l ft -I $(MLXDIR) -L $(MLXDIR) -l $(LIB) $(OSFLAG) -o $(NAME)

clean :
	make clean -C libft
	rm -rf $(OBJDIR)$(OBJ)

fclean : clean
	make fclean -C libft
	rm -rf $(NAME)

re : fclean all
