SRCS = ft_printf.c\
	   nbr_to_str_utils.c\
	   parse_flags.c\
	   parse_options.c\
	   printf_ltoa.c\
	   printf_printchar.c\
	   printf_printhex.c\
	   printf_printnbr.c\
	   printf_printstr.c\
	   printf_utils.c\
	   ul_to_hex.c

NAME = libftprintf.a

LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

%.o : %.c
	@echo "Compiling: $<"
	@$(CC) $(FLAGS) -c $<

$(NAME): $(OBJS)
	@echo "Making libft!"
	@$(MAKE) all bonus -C ./libft
	@cp $(LIBFT) $(NAME)
	@ar -cr $(NAME) $(OBJS)
	@echo "Done creating archive"

all: $(NAME)

clean:
	@$(MAKE) clean -C ./libft
	@rm -f $(OBJS)
	@echo "Done cleaning objects"

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME)
	@echo "Done cleaning archive"

re: fclean all

test: all
	@echo "Compiling test"
	@$(CC) test/tests.c $(NAME) $(LIBFT) -o test-exe
	./test-exe

bonus: $(OBJS_B)
	@ar -cr $(NAME) $(OBJS_B)
	@echo "Done adding bonus objects to archive"
