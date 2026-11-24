NAME = chess
CC = cc -I . -I MacroLibX/includes
CFLAGS = 
SRCS = test.c
OBJS = $(SRCS:.c=.o)
HEADER = chess.h

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) $(CFLAGS) MacroLibX/libmlx.so -lSDL2 -o $(NAME)

$(OBJS): $(HEADER)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
