NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror 
ARC = ar rc
FILES = check_map_utils1.c check_map_utils2.c check_pos.c events.c moving.c read_map.c \
		 check_map.c draw_map.c moving_utils.c so_long.c utils.c
OBJCS = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJCS)
	@$(CC)  $(OBJCS) libft/libft.a get_next_line/get_next_line.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -fr $(OBJCS)

fclean : clean
	rm -fr $(NAME)

re :fclean all
