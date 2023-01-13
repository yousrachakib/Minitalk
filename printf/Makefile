NAME = libftprintf.a

INC = ft_printf.h

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

AR = ar -rc

SRCS =		ft_printf.c\
			ft_putchar.c\
			ft_putnbr.c\
			ft_putstr.c\
			ft_hexa.c\
			ft_ptr.c\

OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(NAME):$(OBJS) $(INC)
	$(AR) $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean:clean
	@$(RM) $(NAME)

re: fclean all