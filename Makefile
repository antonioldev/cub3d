NAME    		= cub3D
CC      		= gcc
LFLAGS  		= -lgcov
CFLAGS  		= -g -Wall -Wextra -Werror

ifdef COV
    CFLAGS += -fprofile-arcs -ftest-coverage
endif

MAIN_SRCS	=	src/main.c \
				src/initiate/initiate_mlx.c \
				src/initiate/initiate_map.c \
				src/initiate/initiate_player.c \
				src/initiate/initiate_ray.c \
				src/initiate/initiate_texture.c \
				src/initiate/initiate_sprites.c \
				src/initiate/initiate_doors.c \
				src/parsing/check_map.c \
				src/parsing/parsing.c \
				src/render/refresh_win.c \
				src/render/render_mini_map.c \
				src/render/raycasting.c \
				src/render/render_enviroment.c \
				src/render/modify_addrs_img.c \
				src/render/modify_addrs_img_minimap.c \
				src/render/render_sprites.c \
				src/render/render_doors.c \
				src/input/input.c \
				src/input/input_movement.c \
				src/clean/error.c \
				src/clean/error_init_mlx.c \
				src/clean/clear_mlx.c \
				src/parsing/map_format.c \
				src/parsing/check_map1.c \
				src/parsing/check_map_utils.c \
				src/clean/clear_parsing.c \
				src/parsing/parse_colour.c \
				src/parsing/parse_texture.c

TEST_SRCS := $(shell find tests/unit/ -type f -name '*_test.c')
TEST_EXES = $(TEST_SRCS:.c=)

COVERAGE_FILES = *.gcda *.gcno *.info coverage_report

MAIN_OBJS = $(MAIN_SRCS:%.c=$(OBJ_F)%.o)
TEST_OBJS = $(filter-out $(OBJ_F)src/main.o, $(MAIN_OBJS))

LIBFT = ./libs/libft
LIBFT_LIB = $(LIBFT)/libft.a
LIB_FLAGS = -lreadline -ltinfo

MINIX11 = ./minilibx-linux
MINIX11_LIB = $(MINIX11)/libmlx_Linux.a
MINIX11_FLAGS = -lXext -lX11

UNITY_ROOT = tests/libs/unity
UNITY_SRCS = $(UNITY_ROOT)/unity.c
UNITY_OBJS = $(UNITY_SRCS:.c=.o)

OBJ_F   = ./objs/
RM      = rm -rf

GREEN   = \033[0;32m
RESET   = \033[0m

all: $(NAME)

$(NAME): $(MAIN_OBJS)
	@printf "\n"
	@make -C $(LIBFT)
	@printf "$(GREEN)==> Libft compiled ✅\n\n$(RESET)"
	@make -C $(MINIX11)
	@printf "$(GREEN)==> Minilib compiled ✅\n\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(MAIN_OBJS) $(LIBFT_LIB) $(LIB_FLAGS) $(MINIX11_LIB) $(MINIX11_FLAGS) -O3 -ffast-math -lm
	@printf "$(GREEN)==> Cub3D compiled ✅\n\n$(RESET)"

$(OBJ_F)%.o: %.c
	@printf "\033[0;33mGenerating cub3D objects... %-33.33s\r" $@
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

libft:
	make -C $(LIBFT)

test: $(NAME) $(TEST_EXES)

$(UNITY_ROOT)/%.o: $(UNITY_ROOT)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_EXES): % : %.c $(UNITY_OBJS)
	$(CC) $(CFLAGS) -I$(UNITY_ROOT) -Isrc -o $@ $< $(UNITY_OBJS) $(TEST_OBJS) \
	$(LIBFT_LIB) $(LIB_FLAGS) $(LFLAGS)

run_tests: re test $(TEST_EXES)
	@for test in $^; do \
		echo Running $$test; \
		./$$test; \
	done

coverage: run_tests
	lcov --rc branch_coverage=1 --capture --directory . --output-file coverage.info
	lcov --rc branch_coverage=1 --remove coverage.info 'tests/libs/*' --output-file coverage_filtered.info
	genhtml --rc branch_coverage=1 coverage_filtered.info --output-directory coverage_report

coverage_clean:
	$(RM) $(COVERAGE_FILES) $(COVERAGE_DIR) coverage_report/ tests/libs/*/*.gcda tests/libs/*/*.gcno tests/unit/*/*.gcda tests/unit/*/*.gcno

clean: coverage_clean
	make clean -C $(LIBFT)
	@printf "$(GREEN)==> Libft Cleaned✅\n\n$(RESET)"
	$(RM) $(OBJ_F)* $(TEST_EXES) $(UNITY_OBJS)
	@printf "$(GREEN)==> Cub3D Cleaned ✅\n\n$(RESET)"

fclean: clean coverage_clean
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

.PHONY: all clean fclean re libft test run_tests coverage coverage_clean