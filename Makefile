# The interesting part
NAME = test
SRCS = src/
INCLUDES = includes/
CODE = main
LIBRARIES = mlx
LINK=Xext X11 m z

# It works and I probably won't change it for the rest of my life
C_FILES = $(addsuffix .c,$(addprefix $(SRCS),$(CODE)))
O_FILES = $(addsuffix .o,$(addprefix $(SRCS),$(CODE)))
CC = cc -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(O_FILES) $(LIBRARIES)
	$(CC) -o $(NAME) $(O_FILES) $(addprefix -L ,$(LIBRARIES)) $(addprefix -l ,$(LIBRARIES) $(LINK))

$(LIBRARIES) :
	true $(addprefix && make -C ,$(LIBRARIES))

%.o : %.c
	$(CC) $(addprefix -I ,$(INCLUDES) $(LIBRARIES)) -c $< -o $@

clean :
	rm -f $(O_FILES)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re $(LIBRARIES)
