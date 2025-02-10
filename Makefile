NAME = fdf
HEADER = fdf.h 

SRC =  main.c $(addprefix libft_utiles/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isdigit.c ft_split.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_substr.c) \
				$(addprefix get_next_line_fdf/, get_next_line.c get_next_line_utils.c) \
				$(addprefix read/, hex_to_int.c map_size.c map.c) \
				$(addprefix draw/, dda.c projection.c hooks.c utils.c)

SRCM = $(SRC) draw/draw_mondatory.c
SRCB = $(SRC) $(addprefix bonus/, draw_bonus.c key_hooks.c mouse_hook.c)

OBJM = $(SRCM:.c=.o)
OBJB = $(SRCB:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -O3 -Werror
MLX_FLAGS = -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

# Use marker files to track which version was built
.mandatory_built: $(OBJM)
	@rm -f .bonus_built
	$(CC) $(MLX_FLAGS) $(OBJM) -o $(NAME)
	@touch .mandatory_built

.bonus_built: $(OBJB)
	@rm -f .mandatory_built
	$(CC) $(MLX_FLAGS) $(OBJB) -o $(NAME)
	@touch .bonus_built

$(NAME): .mandatory_built

all: $(NAME)

bonus: .bonus_built

clean: 
	rm -rf $(OBJM) $(OBJB) .mandatory_built .bonus_built

fclean: clean 
	rm -rf $(NAME)

re: fclean all

.PHONY: re clean fclean all bonus