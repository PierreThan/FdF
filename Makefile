NAME			= fdf
LIB				= ./libft/
LDFLAGS			= -Llibft
LDLIBS			= -lft
SRC_PATH		= srcs
OBJ_PATH		= objs
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -Iincludes
MLX				= -lmlx -framework OpenGL -framework AppKit
SRC_NAME		= main.c \
				  input_check.c \
				  tab.c \
				  project.c \
				  draw.c \
				  color.c \
				  mlx.c \
				  controls.c \
				  rotate.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))


all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)		:
				 	@mkdir $(OBJ_PATH) 2> /dev/null || true

$(NAME)			:	$(OBJ)
					@make -C $(LIB)
					@$(CC) $(CFLAGS) -o $@ $^ $(LIB)libft.a $(MLX) -fsanitize=address
					@echo "Make $(NAME)$(LOG_GREEN) ✓ $(LOG_NOCOLOR)"

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c
					$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libft clean
	rm -rf $(OBJ_PATH)

fclean: clean
	/bin/rm -rf $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
