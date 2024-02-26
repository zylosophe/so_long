# The interesting part
NAME = so_long
SRCS = src/
INCLUDES = includes/
CODE = main assets display1 display2 display_utils env error
LIBRARIES = mlx libtf
LIBRARIES_FILES = libtf/libtf.a
LIBRARIES_LINK = mlx
LINK=Xext X11 m z

# It works and I probably won't change it for the rest of my life
C_FILES = $(addsuffix .c,$(addprefix $(SRCS),$(CODE)))
O_FILES = $(addsuffix .o,$(addprefix $(SRCS),$(CODE)))
CC = cc -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) : $(O_FILES) $(LIBRARIES)
	$(CC) -o $(NAME) $(O_FILES) $(addprefix -L ,$(LIBRARIES_LINK)) $(addprefix -l ,$(LIBRARIES_LINK) $(LINK)) $(LIBRARIES_FILES)

$(LIBRARIES) :
	make -C $@

%.o : %.c
	$(CC) $(addprefix -I ,$(INCLUDES) $(LIBRARIES)) -c $< -o $@

clean :
	-true $(addprefix && make clean -C ,$(LIBRARIES))
	-rm -f $(O_FILES)

fclean : clean
	-true $(addprefix && make fclean -C ,$(LIBRARIES))
	-rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re $(LIBRARIES)
