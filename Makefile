NAME = so_long.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
ARC = ar rc
FILES = check_map_utils1.c check_map_utils2.c check_pos.c events.c moving.c read_map.c \
		 check_map.c draw_map.c moving_utils.c so_long.c utils.c draw_map.c
OBJCS = $(FILES:.c=.o)

all : $(OBJCS)
	$(ARC) $(NAME) $(OBJCS)

%.o : %.c
	$(ARC) $(NAME) $(OBJCS)

clean :
	rm -fr $(OBJCS)

fclean :
	rm -fr $(NAME)

re :fclean all
