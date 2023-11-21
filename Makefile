NAME = libftprintf.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = ./srcs
SRCS = $(wildcard $(SRC_DIR)/ft*.c)

OBJ_DIR = ./objs
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INCLUDES = -I./includes -I$(LIBFT_DIR)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus:all

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

test: all
	@cc -Wall -Wextra -Werror -Iincludes -g -ILibft main.c -L. libftprintf.a
	@./a.out


.PHONY: all clean fclean re test
