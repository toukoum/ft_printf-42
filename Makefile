NAME = libftprintf.a

SRC = ft_printf.c ft_convert_base.c ft_convert_base2.c ft_itoa_boost.c
OBJ = $(SRC:.c=.o)

DEPS = ft_printf.h

LIBFT = libft/libft.a
LIBFT_DIR = libft
LIBFT_BASE = libft.a

INCLUDES = -I libft/

CC = cc
CFLAGS = -Wall -Werror -Wextra

RED=\033[0;31m
ROSE=\033[0;95m
GREEN=\033[0;32m
NC=\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(ROSE)Compiling libft...$(NC)"
	make -C $(LIBFT_DIR)
	@echo "$(ROSE)Creating library $(NAME)...$(NC)"
	cp $(LIBFT) .
	ar -x $(LIBFT_BASE)
	ar rcs $(NAME) $(OBJ) *.o
	@echo "$(GREEN)Library $(NAME) created$(NC)"
	rm -f $(LIBFT_BASE) *.o

%.o: %.c $(DEPS)
	@echo "$(GREEN)Compiling $<...$(NC)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus:all

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	rm -f $(OBJ)

fclean: clean
	@echo "$(RED)Cleaning library $(NAME)...$(NC)"
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
