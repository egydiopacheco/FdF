NAME 		= fdf
LIBFT 		= libft.a
MLX_LINUX 	= libmlx_Linux.a

LIB_DIR 	= ./libft/
MLX_DIR 	= ./minilibx-linux/
INC_DIR 	= ./include/
SRC_DIR 	= ./src/
OBJ_DIR		= ./obj/

CC 			= clang
CFLAGS 		= -Wall -Wextra -Werror
MLX_FLAGS 	= -lm -lbsd -lmlx -lXext -lX11
CI	 		= -I$(INC_DIR)
VALGRIND 	= valgrind
LOG_FILE	= leak-report.txt
VALGRIND_F 	= --leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			--verbose \
			--log-file=$(LOG_FILE) \
			./fdf maps/42.fdf
RM 			= rm -f
GREEN		= \033[32;1m
RED			= \033[31;1m
YELLOW		= \033[33;1m
CYAN		= \033[36;1m

SRC_FILES 	=	$(SRC_DIR)builder.c \
				$(SRC_DIR)cartesian_plane.c \
				$(SRC_DIR)checkings.c \
				$(SRC_DIR)color_utilities.c \
				$(SRC_DIR)driver.c \
				$(SRC_DIR)draw_line.c \
				$(SRC_DIR)draw_utilities.c \
				$(SRC_DIR)error_handler.c \
				$(SRC_DIR)hotkeys.c \
				$(SRC_DIR)initialize_fdf.c \
				$(SRC_DIR)initialize_pov.c \
				$(SRC_DIR)initialize_color.c \
				$(SRC_DIR)initialize_image.c \
				$(SRC_DIR)initialize_vector.c \
				$(SRC_DIR)initialize_landscape.c \
				$(SRC_DIR)instructions.c \
				$(SRC_DIR)landscape_dimensions.c \
				$(SRC_DIR)parser.c \
				$(SRC_DIR)parser_utilities.c \
				$(SRC_DIR)positioning_utilities.c \
				$(SRC_DIR)projection.c \
				$(SRC_DIR)rasterize.c \
				$(SRC_DIR)redo.c \
				$(SRC_DIR)remove_from_context.c \
				$(SRC_DIR)rotate.c \
				$(SRC_DIR)scale.c \
				$(SRC_DIR)transform.c \
				$(SRC_DIR)translate.c

OBJ_FILES	= $(notdir $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT) $(MLX_LINUX)
	@printf "\n$(CYAN)Compiling FdF...$(CYAN)\n"
	@sleep 0.5
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) -L $(LIB_DIR) -L $(MLX_DIR) -lft $(MLX_FLAGS)
	mkdir obj
	@printf "\n$(CYAN)Creating object files folder...$(CYAN)\n"
	@sleep 0.2
	mv $(OBJ_FILES) obj/
	@printf "$(GREEN)FdF compiling was successful!$(GREEN)\n\n"

$(OBJ_FILES): $(SRC_FILES)
	@printf "\n$(CYAN)Creating objects...$(CYAN)\n"
	@sleep 0.2
	$(CC) $(CFLAGS) -g -c -I ./includes/ $(SRC_FILES)

$(MLX_LINUX):
	@printf "\n$(CYAN)Compiling MinilibX...$(CYAN)\n"
	@sleep 0.2
	@make -C $(MLX_DIR)
	@printf "$(GREEN)MinilibX compiling was sucessful!$(GREEN)\n\n"

$(LIBFT):
	@printf "\n$(YELLOW)Compiling libft...$(YELLOW)\n"
	@make -C $(LIB_DIR)
	@printf "$(GREEN)Libft compiling was sucessful!$(GREEN)\n\n"

bonus: 		all

re: 		fclean all

rebonus: 	fclean bonus

valgrind:
	@printf "\n$(RED)Initializing valgrind analysis...$(RED)\n"
	@sleep 0.2
	$(VALGRIND) $(VALGRIND_F)
	@printf "\n$(GREEN)Done!$(GREEN)\n"
logdel:
			$(RM) $(LOG_FILE)

clean:
	@printf "\n$(BLUE)Cleaning Libft directory...$(BLUE)\n"
	@make clean -C $(LIB_DIR)
	@sleep 0.2
	@printf "$(GREEN)Libft cleaned successfully!$(GREEN)\n\n"

	@printf "\n$(RED)Removing object folder from directory...$(RED)\n"
	$(RM) -rf $(OBJ_FILES) $(BONUS_OBJ) objs/

fclean: clean
	@printf "\n$(BLUE)Cleaning everything...$(BLUE)\n"
	@sleep 0.2
	$(RM) -rf $(NAME) $(BONUS_OBJ) objs/
	@make fclean -C $(LIB_DIR)
	@make clean -C $(MLX_DIR)
	make logdel
	@printf "$(GREEN)Full clean performed successfully!$(GREEN)\n\n"

debug:		$(OBJ_FILES) $(LIBFT) $(MLX_LINUX)
			$(CC) -ggdb $(CFLAGS) -o $(NAME) $(OBJ_FILES) -L $(LIB_DIR) -L $(MLX_DIR) -lft $(MLX_FLAGS)
			mkdir obj
			mv $(OBJ_FILES) obj/
eval_debug:
			gdb --args ./fdf landscapes/42.fdf

.PHONY: clean fclean re rebonus all bonus debug eval_debug


