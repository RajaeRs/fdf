NAME = fdf

# HEADER = fdf.h 

# PRINTF = printf/libftprintf.a

SRC =  ./draw/draw_map.c ./draw/iso_projection.c ./draw/line.c \
./read_map/link_point.c ./read_map/get_map.c ./read_map/get_point_info.c \
./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
./libft_utils/ft_bzero.c  ./libft_utils/ft_atoi.c  ./libft_utils/ft_calloc.c  ./libft_utils/ft_split.c \
./libft_utils/ft_strlen.c  ./libft_utils/ft_strncmp.c ./libft_utils/ft_strnstr.c ./libft_utils/ft_substr.c

OBJ = $(SRC:.c=.o)

# $(PRINTF):
# 	make -C printf

%.o: %.c
	cc -Wall -Wextra -O3 -Werror -Imlx -c $< -o $@


$(NAME): $(OBJ) 
	cc -I /usr/local/include  $(OBJ) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean: 
	rm -rf  $(OBJ)

fclean: clean 
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: re clean fclean all printf





 