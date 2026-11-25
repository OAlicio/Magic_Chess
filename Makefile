NAME = chess
HEADER_FOLDER = ./includes/
CC = cc -I$(HEADER_FOLDER) -I MacroLibX/includes
CFLAGS = 
SRCS_FOLDER = ./srcs/
SRCS =  $(SRCS_FOLDER)draw.c \
		$(SRCS_FOLDER)game_draw.c \
		$(SRCS_FOLDER)key_handler.c \
		$(SRCS_FOLDER)main.c \
		$(SRCS_FOLDER)main_loop.c \
		$(SRCS_FOLDER)menu_draw.c
OBJS = $(SRCS:.c=.o)
HEADERS = $(HEADER_FOLDER)chess.h \
		 $(HEADER_FOLDER)game.h

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) $(CFLAGS) MacroLibX/libmlx.so -lSDL2 -o $(NAME)

$(OBJS): $(HEADERS) MacroLibX/libmlx.so

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
