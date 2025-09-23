NAME		= fractol
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
MLX42_DIR	= MLX42
MLX42		= $(MLX42_DIR)/build/libmlx42.a
GLFW_FLAGS	= -ldl -lglfw -pthread -lm

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS		= srcs/initialization.c \
				srcs/error_utils.c \
				srcs/rendering.c \
				srcs/math_utils.c \
				srcs/main.c \
				srcs/events.c \
				srcs/fractals.c \
				srcs/utils.c \
				srcs/colors.c \


OBJS_DIR	= objs
OBJS		= $(SRCS:srcs/%.c=$(OBJS_DIR)/%.o)

INCLUDES	= -I ./includes/ \
			  -I ./libft/ \
			  -I ./MLX42/include/

all: $(MLX42) $(LIBFT) $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX42) $(GLFW_FLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: srcs/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	
$(MLX42):
	@cd $(MLX42_DIR) && cmake -B build
	@cd $(MLX42_DIR) && cmake --build build -j4

clean:
	rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
