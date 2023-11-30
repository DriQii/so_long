NAME = exe

CC = gcc

CFLAGS = -Wall -Wextra -g

SRC = src/so_long.c \
	src/get_map.c	\
	src/map_error.c

LIB = mlx

MLXDIR = minilibx-linux

OBJ = $(SRC:.c=.o)

all : $(NAME)

src/%.o : src/%.c
	$(CC) $(CFLAGS) -I include -L lib -l ft -I $(MLXDIR) -L $(MLXDIR) -l $(LIB) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -I include -L lib -l ft -I $(MLXDIR) -L $(MLXDIR) -l $(LIB) -l Xext -l X11 -l m -l z -o $(NAME)

clean :
	rm -rf $(OBJDIR)$(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
