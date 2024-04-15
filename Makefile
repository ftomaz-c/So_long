NAME := so_long

SRC :=	src/main.c \
		src/error.c \
		src/init_collectibles.c \
		src/init_game.c \
		src/map_construction.c \
		src/map_construction_utils.c \
		src/map_handling.c \
		src/map_utils.c \
		src/map_validation.c \
		src/mem_mgmt.c \
		src/move_hero.c \
		src/event_handling.c \
		src/so_long_utils.c \
		src/spawn_map.c \
		src/spawn_collectibles.c \
		src/sprite_animation.c \

OBJ := $(SRC:.c=.o)

CC := cc

CFLAGS := -Wall -Wextra -Werror -g

INCLUDES := -I./libs/libft/includes

LIBFT := libs/libft/libft.a

MLX := -Llibs/mlx_linux -lmlx -L/usr/lib -Ilibs/mlx_linux -lXext -lX11 -lm -lz

GREEN := \033[0;32m
CYAN := \033[0;36m
RED := \033[0;31m
NC := \033[0m

all:	$(LIBFT) $(OBJ) $(NAME)

$(LIBFT):
	@echo "$(CYAN)\n# Compiling libft...\n$(NC)"
	@$(MAKE) -C libs/libft || (rm -f $(NAME)  && exit 1)

	@echo "$(CYAN)\n# Compiling $(NAME)...\n$(NC)"
	@echo "cc -Wall -Wextra -Werror -g -I./libs/libft/includes -c *.c -o *.o"

$(OBJ): %.o: %.c
	@echo "$(CYAN)	Compiling $@...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -I/usr/include -Ilibs/mlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(CYAN)\n# Linking $(NAME) with libft...\n$(NC)"
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)
	@echo "$(GREEN)\n###############################$(NC)"
	@echo "$(GREEN)	$(NAME) is ready!$(NC)"
	@echo "$(GREEN)###############################$(NC)"

clean:
	@echo "$(CYAN)\n# Cleaning libft...\n$(NC)"
	$(MAKE) -C libs/libft clean
	@echo "$(CYAN)\n# Cleaning object files...\n$(NC)"
	rm -f $(OBJ)
	@echo "$(GREEN)\n###########################################$(NC)"
	@echo "$(GREEN)	$(NAME) object files cleaned!$(NC)"
	@echo "$(GREEN)###########################################$(NC)"

fclean: clean
	@echo "$(CYAN)\n# Cleaning $(NAME) and libft...\n$(NC)"
	rm -f $(NAME)
	$(MAKE) -C libs/libft fclean
	@echo "$(GREEN)\n########################################$(NC)"
	@echo "$(GREEN)	$(NAME) and libft cleaned!$(NC)"
	@echo "$(GREEN)########################################$(NC)"

re: fclean all

.PHONY: all clean fclean re
