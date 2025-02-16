# Variables
NAME    = bin/fractol
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Iinclude -O3
LIBFT   = lib/libft
MLX     = lib/minilibx-linux
PRINTF  = lib/libft/ft_printf
SRCS    = src/main.c \
          src/algorithm_utilities.c \
          src/complex_operations.c \
          src/event_handling.c \
          src/fractal_calculations.c \
          src/fractal_rendering.c \
          src/fractol_init.c \
		  src/color_algorithms.c \
		  src/complex_init.c \
          src/others.c
OBJS    = $(SRCS:src/%.c=obj/%.o)

# Rules
all: $(NAME)

# Create binary and link the program
$(NAME): $(OBJS)
	@mkdir -p bin
	$(MAKE) -C $(LIBFT) all
	$(MAKE) -C $(PRINTF) all
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -L$(MLX) -lmlx -L$(PRINTF) -lftprintf -lX11 -lXext -lm -o $(NAME)

# Compile sources
obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

# Clean objects
clean:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(PRINTF) clean
	rm -rf obj

# Full clean, including binary
fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(PRINTF) fclean
	rm -rf bin

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
