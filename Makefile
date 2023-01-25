NAME = fdf

# HEADER = fdf.h 

# PRINTF = printf/libftprintf.a

SRC =  main.c $(addprefix libft_utiles/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isdigit.c ft_split.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_substr.c) \
				$(addprefix get_next_line/, get_next_line.c get_next_line_utils.c) \
				$(addprefix read/, hex_to_int.c map_size.c map.c) \
				$(addprefix draw/, dda.c projection.c hooks.c utils.c)

SRCM = $(SRC) draw/draw_mondatory.c

SRCB = $(SRC) $(addprefix bonus/, draw_bonus.c key_hooks.c mouse_hook.c)

# OBJ  = $(SRC)

OBJM = $(SRCM:.c=.o)

OBJB = $(SRCB:.c=.o)

# $(PRINTF):
# 	make -C printf

%.o: %.c
	cc -Wall -Wextra -O3 -Werror -Imlx -c $< -o $@


$(NAME): $(OBJB) 
	cc -I /usr/local/include  $(OBJB) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

# bonus: $(NAME)

clean: 
	rm -rf  $(OBJB)

fclean: clean 
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: re clean fclean all printf





 