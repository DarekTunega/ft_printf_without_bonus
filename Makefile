CC = gcc
NAME = libftprintf.a
MAKE = make
FLAGS = -Wall -Wextra -Werror
SRCS =	./ft_printf.c ./ft_print_uns.c ./ft_printf_helper.c
HEAD = ft_printf.h
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(HEAD)
	@cd libft && $(MAKE) bonus
	@cp libft/libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJS)
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully compiled "libftprintf.a" .\033[0m"

%.o: %.c
	@$(CC) $(FLAGS) -c $<  -o $(<:.c=.o)
	@echo "\033[90m[\033[32mOK\033[90m]\033[34m Compiling $<\033[0m"

clean :
	@rm -f $(OBJS)
	@$(MAKE) clean -C ./libft
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Object FT_PRINTF files deleted\033[0m"

fclean : clean
	@rm -f $(NAME)
	@rm -f libft.a
	@$(MAKE) fclean -C ./libft
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m libftprintf.a deleted.\033[0m"

re : fclean all

.PHONY: all re fclean clean
