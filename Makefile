# *********************************************************************************************************** #
#                                                                                                             #
#                                                               :::::::::: ::::::::   :::::::: :::::::::::    #
#    Makefile                                                  :+:       :+:    :+: :+:    :+:    :+:         #
#                                                             +:+       +:+        +:+           +:+          #
#    By: lisika <lisika@myges.fr>                            +#++:++#  +#++:++#++ :#:           +#+           #
#                                                           +#+              +#+ +#+   +#+#    +#+            #
#    Created: 2024/12/29 12:21:31 by lisika                #+#       #+#    #+# #+#    #+#    #+#             #
#    Updated: 2024/12/29 12:21:31 by lisika               ########## ########   ######## ###########          #
#                                                                                                             #
# *********************************************************************************************************** #

CC	=	gcc

SRC	=	src/main.c	\
		src/init/init_window.c	\
		src/homepage/draw_homepage.c	\
		src/homepage/homepage.c	\
		src/events/handle_events.c	\

LIB	=	lib/set_functions.c	\

OBJ	=	$(SRC:.c=.o) $(LIB:.c=.o)

CSFML_FLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system

CFLAGS  =	-Wall -Wextra

CPPFLAGS	=	-I includes/

BIN_NAME	=	cliz_ai

DEBUG_FLAGS =	-g3

all:	$(OBJ)
	$(CC) -o $(BIN_NAME) $(OBJ) $(CSFML_FLAGS) $(CFLAGS) $(DEBUG_FLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(BIN_NAME)

re: fclean all

debug_valgrind: CFLAGS += $(DEBUG_FLAGS)
debug_valgrind: fclean all

debug_asan: CFLAGS += $(DEBUG_FLAGS) -fsanitize=address
debug_asan: LDFLAGS += -fsanitize=address
debug_asan: fclean all

.PHONY: clean fclean re
