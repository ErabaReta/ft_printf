CC = cc
AR = ar rcs
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
CFILES = ft_printf.c printing_functions.c helper_functions.c flags.c flags_bonus.c
OFILES = $(CFILES:.c=.o)
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OFILES)

bonus : $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c  $< -o $@
	$(AR) $(NAME) $@

clean : 
	$(RM) $(OFILES) $(B_OFILES)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus