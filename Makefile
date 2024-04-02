# The interesting part
NAME = so_long
SRCS = src/
INCLUDES = includes/
CODE = main error env input timedloop \
		data_assets data_sprites \
		display1 display2 display_utils sprite \
		room1 room2 room_utils1 room_utils2 point \
		object_character object_snas object_wall
LIBRARIES = mlx libtf
LIBRARIES_FILES = libtf/libtf.a
LIBRARIES_LINK = mlx
LINK = Xext X11 m z

# It works and I probably won't change it for the rest of my life
C_FILES = $(addsuffix .c,$(addprefix $(SRCS),$(CODE)))
O_FILES = $(addsuffix .o,$(addprefix $(SRCS),$(CODE)))
ifdef DEBUG
CC = cc -Wall -Wextra -Werror -g
else
CC = cc -Wall -Wextra -Werror
endif

all : $(NAME)

$(NAME) : $(O_FILES) $(LIBRARIES)
	$(CC) -o $(NAME) $(O_FILES) $(addprefix -L ,$(LIBRARIES_LINK)) $(addprefix -l ,$(LIBRARIES_LINK) $(LINK)) $(LIBRARIES_FILES)
	@echo "\t\t \e[0;92m\(^o^)/  \e[0;102;30;1m $(NAME) compiled! \e[0;92m \(^o^)/\e[0m"

$(LIBRARIES) :
ifdef DEBUG
	make -C $@ debug || make -C $@
else
	make -C $@
endif
	@echo "\e[30;47;1m  library $@ made!  \e[0m"

%.o : %.c
	$(CC) $(addprefix -I ,$(INCLUDES) $(LIBRARIES)) -c $< -o $@

clean :
	-rm -f $(O_FILES)
	@echo "\e[30;47;1m  clean finished!  \e[0m"

fclean : clean
	$(foreach lib,$(LIBRARIES), make fclean -C $(lib) || make clean -C $(lib); )
	-rm -f $(NAME)
	@echo "\e[30;47;1m  fclean finished!  \e[0m"


re : fclean all

debug :
	make all DEBUG=yes

.PHONY : all debug clean fclean re $(LIBRARIES)
