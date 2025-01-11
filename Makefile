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

CC = gcc

SRC = src/main.c \
      src/homepage/homepage.c \
      src/homepage/init_homepage.c \
      src/homepage/handle_events.c \
      src/homepage/draw_homepage.c \
      src/homepage/events_homepage.c \
      src/homepage/destroy_homepage.c \
      src/login/init_login_page.c \
      src/login/draw_login_page.c \
      src/login/events_login.c \
      src/login/input_user.c \
      src/login/authentification_user.c \
      src/login/destroy_login_page.c \
      src/chatbot/api/api.c \
      src/chatbot/destroy/destroy.c \
      src/chatbot/events/events.c \
      src/chatbot/interface/interface.c \
      src/chatbot/interface/messages.c \
      src/chatbot/interface/init.c \
      src/chatbot/interface/draw.c \
      src/chatbot/interface/input.c \
      src/chatbot/utils.c

LIB = lib/set_functions.c \
      lib/create_functions.c \
      lib/destroy_functions.c

OBJ = $(SRC:.c=.o) $(LIB:.c=.o)

CSFML_FLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system

CURL_FLAGS = -lcurl

JSON_FLAGS = -ljson-c

CPPFLAGS = -I includes/

BIN_NAME = cliz_ai

C_FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

LDFLAGS = -fsanitize=address

all: $(OBJ)
	$(CC) -o $(BIN_NAME) $(OBJ) $(CSFML_FLAGS) $(CURL_FLAGS) $(JSON_FLAGS) $(C_FLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(BIN_NAME)

debug_valgrind: CFLAGS += -g3
debug_valgrind: fclean all

debug_asan: CFLAGS += -g3 -fsanitize=address
debug_asan: LDFLAGS += -fsanitize=address
debug_asan: fclean all

re: fclean all
