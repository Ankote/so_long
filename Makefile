NAME = so_long

NAME_B = so_long_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror 

INCLUDES = libft/libft.a get_next_line/get_next_line.a

FRAMEWORKS = -lmlx -framework OpenGL -framework AppKit
FILES = check_map_utils1.c check_map_utils2.c check_pos.c events.c moving.c read_map.c \
		 check_map.c draw_map.c moving_utils.c so_long.c utils.c
		
FILES_B = check_map_utils1_bonus.c check_map_utils2_bonus.c check_pos_bonus.c events_bonus.c moving_bonus.c read_map_bonus.c \
		 check_map_bonus.c draw_map_bonus.c moving_utils_bonus.c so_long_bonus.c utils_bonus.c

OBJCS = $(FILES:.c=.o)

OBJCS_B = $(FILES_B:.c=.o)

all : $(NAME)

$(NAME) : $(OBJCS)
	@cd libft && $(MAKE)
	@cd get_next_line && $(MAKE)
	@$(CC)  $(OBJCS) $(INCLUDES) $(FRAMEWORKS)  -o $(NAME)

bonus : $(NAME_B)

$(NAME_B) : $(OBJCS_B)
	@cd libft && rm -fr *.o
	@cd get_next_line &&  rm -fr *.o
	@cd libft && $(MAKE)
	@cd get_next_line && $(MAKE)
	@$(CC) $(OBJCS_B) $(INCLUDES) $(FRAMEWORKS) -o $(NAME_B)
%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[0;32m𝘾𝙧𝙚𝙖𝙩𝙞𝙣𝙜 ...\033[0m"
clean :
	@cd libft && rm -fr *.o
	@cd get_next_line &&  rm -fr *.o
	@rm -fr $(OBJCS)
	@rm -fr $(OBJCS_B)
	@echo "\033[0;31m𝑶𝒃𝒋𝒆𝒄𝒕𝒔' 𝒄𝒍𝒆𝒂𝒏𝒆𝒅\033[0m"

fclean : clean
	@rm -rf libft/libft.a
	@rm -rf get_next_line/get_next_line.a
	@rm -fr $(NAME)
	@rm -fr $(NAME_B)
	@echo "\033[1;33m𝙀𝙫𝙚𝙧𝙮𝙩𝙝𝙞𝙣𝙜'𝙨 𝙘𝙡𝙚𝙖𝙣𝙚𝙙\033[0m"
extralib:

re :fclean all bonus
