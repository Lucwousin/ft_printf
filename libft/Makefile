SRCS = ft_atoi.c\
	   ft_bzero.c\
	   ft_calloc.c\
	   ft_isalnum.c\
	   ft_isalpha.c\
	   ft_isascii.c\
	   ft_isdigit.c\
	   ft_isprint.c\
	   ft_itoa.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_memcpy.c\
	   ft_memmove.c\
	   ft_memset.c\
	   ft_putchar_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c\
	   ft_putstr_fd.c\
	   ft_simple_math.c\
	   ft_split.c\
	   ft_strchr.c\
	   ft_strdup.c\
	   ft_striteri.c\
	   ft_strjoin.c\
	   ft_strlcat.c\
	   ft_strlcpy.c\
	   ft_strlen.c\
	   ft_strmapi.c\
	   ft_strncmp.c\
	   ft_strnstr.c\
	   ft_strrchr.c\
	   ft_strtrim.c\
	   ft_substr.c\
	   ft_tolower.c\
	   ft_toupper.c

SRCS_B = ft_lstadd_back.c\
		 ft_lstadd_front.c\
		 ft_lstclear.c\
		 ft_lstdelone.c\
		 ft_lstiter.c\
		 ft_lstlast.c\
		 ft_lstmap.c\
		 ft_lstnew.c\
		 ft_lstsize.c

NAME = libft.a

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

%.o : %.c
	@echo "Compiling: $<"
	@$(CC) $(FLAGS) -c $<

$(NAME): $(OBJS)
	@ar -cr $(NAME) $(OBJS)
	@echo "Done creating archive"

all: $(NAME)

clean:
	@rm -f $(OBJS) $(OBJS_B)
	@echo "Done cleaning objects"

fclean: clean
	@rm -f $(NAME)
	@echo "Done cleaning archive"

re: fclean all

bonus: $(OBJS_B)
	@ar -cr $(NAME) $(OBJS_B)
	@echo "Done adding bonus objects to archive"
