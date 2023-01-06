CC = cc
CFLAGS = -Wall -Wextra -Werror
PRINTF = printf
NAME = client
SNAME = server
RM = rm -rf
SRC = client.c utils.c
SRS = server.c utils.c
OBJ = $(SRC:.c=.o)
OBJT = $(SRS:.c=.o)

all : $(PRINTF) $(SNAME) $(NAME) 

$(PRINTF) : 
	$(MAKE) -C $(PRINTF)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(SNAME) : $(OBJT)
	$(CC) $(CFLAGS) $(OBJT) ./printf/libftprintf.a -o $(SNAME)

%.o : %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
		$(RM) $(OBJ) $(OBJT)
fclean : clean
		$(RM) $(NAME) $(SNAME)