NAME = exe

CC = gcc

CFLAGS = -Wall -Wextra

SRC = src/so_long.c \
	src/get_next_line.c \
	src/get_next_line_utils.c \
	src/utils.c

LIB = mlx

MLXDIR = minilibx-linux

OBJ = $(SRC:.c=.o)

all : $(NAME)

src/%.o : src/%.c
	$(CC) $(CFLAGS) -I $(MLXDIR) -L $(MLXDIR) -l $(LIB) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -I $(MLXDIR) -L $(MLXDIR) -l $(LIB) -l Xext -l X11 -l m -l z -o $(NAME)

clean :
	rm -rf $(OBJDIR)$(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all