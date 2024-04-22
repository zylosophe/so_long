##### THE INTERESTING PART #####
NAME = so_long
SRCS = src/
INCLUDES = includes/
CODE =	$(addprefix main/, \
			main error env input input_utils timedloop levels1 levels2 \
		) \
		$(addprefix display/, \
			display1 display2 display_utils sprite text \
		) \
		$(addprefix room/, \
			visual room1 room2 room3 room_utils1 room_utils2 camera \
			pathfinding pathfinding_utils \
			object_character object_snas object_wall object_ketchup object_exit \
			object_firsk object_activablewall  object_ultimateketchup \
		) \
		$(addprefix utils/, \
			point1 point2 map \
		) \
		gameover/gameover
LIBRARIES = mlx libtf
LIBRARIES_FILES = libtf/libtf.a
LIBRARIES_LINK = mlx
LINK = Xext X11 m z
MORE_FLAGS +=
##### END OF THE INTERESTING PART #####


C_FILES = $(addsuffix .c,$(addprefix $(SRCS),$(CODE)))
O_FILES = $(addsuffix .o,$(addprefix $(SRCS),$(CODE)))
ifdef DEBUG
CC = cc -Wall -Wextra -Werror -g $(MORE_FLAGS)
else
CC = cc -Wall -Wextra -Werror $(MORE_FLAGS)
endif


##### PUBLIC RULES #####
all : $(NAME)
	@echo "\t\t \e[0;92m\(^o^)/  \e[0;102;30;1m $(NAME) made! \e[0;92m \(^o^)/\e[0m"

clean :
	@echo "\e[30;47;1m  $(NAME): removing *.o files...  \e[0m"
	-rm -f $(O_FILES)
	@echo "\e[30;47;1m  $(NAME): removing *.o files finished!  \e[0m"

fclean : clean
	@echo "\e[30;47;1m  $(NAME): fclean...  \e[0m"
	$(foreach lib,$(LIBRARIES), make fclean -C $(lib) || make clean -C $(lib); )
	-rm -f $(NAME)
	@echo "\e[30;47;1m  $(NAME): fclean finished!  \e[0m"

re : clean all

debug :
	make all DEBUG=yes


$(NAME) : $(O_FILES) $(LIBRARIES)
	@echo "\e[30;47;1m  $(NAME): linking...  \e[0m"
	$(CC) -o $(NAME) $(O_FILES) $(addprefix -L ,$(LIBRARIES_LINK)) $(addprefix -l ,$(LIBRARIES_LINK) $(LINK)) $(LIBRARIES_FILES)
	@echo "\e[30;47;1m  $(NAME): linked!  \e[0m"

$(LIBRARIES) :
	@echo "\e[30;47;1m  $(NAME): making library $@...  \e[0m"
ifdef DEBUG
	make -C $@ debug || make -C $@
else
	make -C $@
endif
	@echo "\e[30;47;1m  $(NAME): library $@ made!  \e[0m"

%.o : %.c
	$(CC) $(addprefix -I ,$(INCLUDES) $(LIBRARIES)) -c $< -o $@

.PHONY : all debug clean fclean re $(LIBRARIES)
