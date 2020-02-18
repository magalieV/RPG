##
## EPITECH PROJECT, 2019
## MUL_my_rpg_2018
## File description:
## __Makefile__
##

CC	=	@gcc

MAKEFLAGS	+=	--no-print-directory

RM	=	rm -f

FG	=	-l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio -g3

ECHO		=	/bin/echo -e
DEFAULT		=	"\033[00m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[0;01;033m"
TEAL		=	"\033[1;01;35m"
RED			=	"\033[1;01;31m"
BLUE		=	"\033[1;01;34m"

CFLAGS	+=	-I./include

NAME	=	my_rpg

MINI_LIB	=	src/mini_lib/alloc_memory.c			\
				src/mini_lib/button.c				\
				src/mini_lib/check_pos_object.c		\
				src/mini_lib/create_object.c		\
				src/mini_lib/number.c				\
				src/mini_lib/get_next_line.c		\
				src/mini_lib/my_str_to_word_array.c	\
				src/mini_lib/init_game_board.c		\
				src/mini_lib/destroy.c				\
				src/mini_lib/memory_alloc.c

WIND	=	src/window/init_window.c

CONNEX	=	src/connexion/display_connexion_window.c	\
			src/connexion/get_event_connexion_window.c	\
			src/connexion/connexion_next.c	\
			src/connexion/account.c

MENU	=	src/menu/main_menu.c	\
			src/menu/main_menu_next.c	\
			src/menu/settings/main_settings.c


GAME	=	src/game/main_game.c	\
			src/game/back/display_back.c	\
			src/game/back/load_back_game.c	\
			src/game/back/load_back_game_next.c	\
			src/game/back/moove_cam.c		\
			src/game/back/pause_menu.c	\
			src/game/back/display_stat.c	\
			src/game/animation/display_animation.c	\
			src/game/animation/init_animation.c	\
			src/game/quest/display_quest.c	\
			src/game/back/load_element.c	\
			src/game/element/display_element.c	\
			src/game/gate/moove_word.c	\
			src/game/element/interaction.c	\
			src/game/back/display_and_event/event_of_game.c	\
			src/game/monster/combat.c \
			src/game/particle/clear_texture.c \
			src/game/particle/draw_pixel.c \
			src/game/particle/get_pos.c \
			src/game/particle/my_compute_square_root.c \
			src/game/particle/my_pow.c \
			src/game/particle/particules.c \
			src/game/particle/set_color.c \
			src/game/particle/set_texture_rgba.c	\
			src/game/back/display_other.c	\
			src/game/monster/monster_mvt.c	\
			src/game/monster/all_fight.c	\
			src/game/monster/monster_game.c	\
			src/mini_lib/alloc_memory_next.c	\
			src/game/quest/display_quest_next_next.c	\
			src/game/quest/display_quest_next.c

INVENTORY	= src/game/inventory/main_inventory.c

PNG		=	src/game/quest/init_quest.c	\
			src/game/quest/action_with_png.c

SRCS	=	src/main.c	\
			$(MINI_LIB)	\
			$(WIND)		\
			$(CONNEX)	\
			$(MENU)		\
			$(GAME)		\
			$(INVENTORY)	 \
			$(PNG)

OBJS	=	$(SRCS:.c=.o)

all		:	title $(NAME) endt
			@echo ""

title		:
			@$(ECHO) $(YELLOW)"\n → Projet : RPG\n" $(DEFAULT)

endt:
			@$(ECHO) $(RED)"\n → [RPG CREATE]\n" $(DEFAULT)

$(NAME)		:	$(OBJS)
			@$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(FG) &&			\
			$(ECHO) $(GREEN) "[OK]" $(TEAL) $(NAME) $(DEFAULT) ||	\
			$(ECHO) $(RED) "[KO]" $(TEAL) $(NAME) $(DEFAULT)

.c.o		:
			@$(CC) $(CFLAGS) $(FG) -c $< -o $@ &&				\
			$(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) ||	\
			$(ECHO) $(RED) "[KO]" $(TEAL) $< $(DEFAULT)

tests_run	:
			make -C./tests/ all

clean:
			@$(RM) $(OBJS)

fclean:			clean
			@$(RM) $(NAME)

re		:	fclean all

.PHONY	: all clean fclean re
