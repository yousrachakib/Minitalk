CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = client
SNAME = server
PRINTF = printf/printflibft.a

NAME_BONUS = client_bonus
SNAME_BONUS = server_bonus

RM = rm -rf

SRC = client.c utils.c
SRS = server.c utils.c

SRC_BONUS = client_bonus.c utils.c
SRS_BONUS = server_bonus.c utils.c

OBJ = $(SRC:.c=.o)
OBJT = $(SRS:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)
OBJT_BONUS = $(SRS_BONUS:.c=.o)

all : $(PRINTF) $(SNAME) $(NAME) 

${PRINTF} : 
	make -C printf all

$(NAME) : $(OBJ) ${PRINTF}
	$(CC) $(CFLAGS) $(OBJ) printf/libftprintf.a -o $(NAME)

$(SNAME) : $(OBJT) ${PRINTF}
	$(CC) $(CFLAGS) $(OBJT) printf/libftprintf.a -o $(SNAME)

bonus : $(PRINTF) $(SNAME_BONUS) $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) ./printf/libftprintf.a -o $(NAME_BONUS)

$(SNAME_BONUS) : $(OBJT_BONUS)
	$(CC) $(CFLAGS) $(OBJT_BONUS) ./printf/libftprintf.a -o $(SNAME_BONUS)

%.o : %.c minitalk.h minitalk_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
		$(RM) $(OBJ) $(OBJT) $(OBJ_BONUS) $(OBJT_BONUS)
		make -C printf clean
fclean : clean
		$(RM) $(NAME) $(SNAME) $(SNAME_BONUS) $(NAME_BONUS)
		make -C printf fclean