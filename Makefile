# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lucas <lucas@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/05/02 13:33:26 by lucas         #+#    #+#                  #
#    Updated: 2022/05/02 13:33:26 by lucas         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJ_DIR = objs/
SRC_DIR = src/
INC_DIR = include/

SRCS = ft_printf.c\
	   nbr_to_str_utils.c\
	   parse_flags.c\
	   parse_options.c\
	   printf_printchar.c\
	   printf_printhex.c\
	   printf_printnbr.c\
	   printf_printstr.c\
	   printf_utils.c

OBJS = $(SRCS:.c=.o)
OBJS_PREFIXED = $(addprefix $(OBJ_DIR), $(OBJS))

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_INC = $(LIBFT_DIR)include/

CC = gcc
CFLAGS = -Wall -Werror -Wextra

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(INC_DIR)ft_printf_internal.h $(LIBFT_INC)libft.h
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_INC) -c -o $@ $<

$(NAME): $(OBJS_PREFIXED)
	@echo "Making libft!"
	@$(MAKE) all -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)
	@ar -cr $(NAME) $(OBJS_PREFIXED)
	@echo "Done creating archive $(CURDIR)/$(NAME)"

all: $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "Done cleaning $(CURDIR)/$(OBJ_DIR)"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "Done cleaning archive $(CURDIR)/$(NAME)"

re: fclean all

test: all
	@echo "Compiling test"
	@$(CC) test/tests.c $(NAME) $(LIBFT) -o test-exe
	./test-exe

bonus: all

.PHONY: all clean fclean re bonus