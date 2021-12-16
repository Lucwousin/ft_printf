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

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = gcc
CFLAGS = -Wall -Werror -Wextra

$(OBJS_DIR)%.o : %.c
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS_PREFIXED)
	@echo "Making libft!"
	@$(MAKE) all bonus -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)
	@ar -cr $(NAME) $(OBJS_PREFIXED)
	@echo "Done creating archive $(CURDIR)/$(NAME)"

all: $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)
	@echo "Done cleaning $(CURDIR)/$(OBJS_DIR)"

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
