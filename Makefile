NAME			= cub3D
CC				= gcc
CFLAGS			= -g -Wall -Wextra -Werror
MATH_FLAGS		=  -O3 -ffast-math -lm

######################################################## SOURCE FILES ########################################################
##############################################################################################################################
MAIN_SRCS	=	src/main.c \
src/initiate/initiate_mlx.c				src/parsing/check_map.c					src/render/render_mini_map.c \
src/initiate/initiate_map.c				src/parsing/parse_utils.c				src/render/render_enviroment.c \
src/initiate/initiate_player.c			src/parsing/parsing.c					src/render/modify_addrs_img.c \
src/initiate/initiate_ray.c				src/parsing/map_format.c				src/render/modify_addrs_img_minimap.c \
src/initiate/initiate_texture.c			src/parsing/check_map1.c				src/render/modify_addrs_img_doors.c \
src/initiate/initiate_sprites.c			src/parsing/check_map_utils.c			src/render/modify_addrs_img_sprites.c \
src/initiate/initiate_doors.c			src/parsing/parse_colour.c				src/render/render_sprites.c \
										src/parsing/parse_texture.c				src/render/render_utils_2.c \
src/clean/error.c						src/parsing/preparse.c					src/render/render_doors.c \
src/clean/error_init_mlx.c				src/parsing/check_ext.c					src/render/render_utils.c \
src/clean/clear_mlx.c															src/input/input.c \
src/clean/clear_parsing.c														src/input/input_movement.c \
src/input/mouse_move.c
##############################################################################################################################
##############################################################################################################################

MAIN_OBJS = $(MAIN_SRCS:%.c=$(OBJ_F)%.o)

######################################################### LIBRARIES ##########################################################
##############################################################################################################################
LIBFT = ./libs/libft
LIBFT_LIB = $(LIBFT)/libft.a

MINIX11 = ./minilibx-linux
MINIX11_LIB = $(MINIX11)/libmlx_Linux.a
MINIX11_FLAGS = -lXext -lX11
##############################################################################################################################
##############################################################################################################################

OBJ_F   = ./objs/
RM      = rm -rf

GREEN   = \033[0;32m
RESET   = \033[0m


########################################################### RULES ############################################################
##############################################################################################################################
all: $(NAME)

$(NAME): $(MAIN_OBJS)
	@printf "\n"
	@make -C $(LIBFT)
	@printf "$(GREEN)==> Libft compiled ✅\n\n$(RESET)"
	@make -C $(MINIX11)
	@printf "$(GREEN)==> Minilib compiled ✅\n\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(MAIN_OBJS) $(LIBFT_LIB) $(LIB_FLAGS) $(MINIX11_LIB) $(MINIX11_FLAGS) $(MATH_FLAGS)
	@printf "$(GREEN)==> Cub3D compiled ✅\n\n$(RESET)"

$(OBJ_F)%.o: %.c
	@printf "\033[0;33mGenerating cub3D objects... %-33.33s\r" $@
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

libft:
	make -C $(LIBFT)

clean: 
	make clean -C $(LIBFT)
	@printf "$(GREEN)==> Libft Cleaned✅\n\n$(RESET)"
	$(RM) $(OBJ_F)* $(TEST_EXES) $(UNITY_OBJS)
	@printf "$(GREEN)==> Cub3D Cleaned ✅\n\n$(RESET)"

fclean: clean
	make fclean -C $(LIBFT)
	make clean -C $(MINIX11)
	$(RM) $(NAME)
	@printf "$(GREEN)==> Cub3D fully cleaned ✅\n\n$(RESET)"

re: fclean all

norminette:
	norminette src/ libs/

lunch_valgrind:
	valgrind --leak-check=full -s ./cub3D maps/map.cub

lunch:
	./cub3D maps/map.cub

.PHONY: all clean fclean re libft
##############################################################################################################################
##############################################################################################################################
