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
	@printf "\n$(CY)Compiling FdF...$(RC)\n"
	@sleep 0.5
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) -L $(LIB_DIR) -L $(MLX_DIR) -lft $(MLX_FLAGS)
	mkdir obj
	@printf "\n$(CY)Creating object files folder...$(RC)\n"
	@sleep 0.2
	mv $(OBJ_FILES) obj/
	@printf "$(GR)FdF compiling was successful!$(RC)\n\n"

$(OBJ_FILES): $(SRC_FILES)
	@printf "\n$(CY)Creating objects...$(RC)\n"
	@sleep 0.2
	$(CC) $(CFLAGS) -g -c -I ./includes/ $(SRC_FILES)

$(MLX_LINUX):
	@printf "\n$(CY)Compiling MinilibX...$(RC)\n"
	@sleep 0.2
	@make -C $(MLX_DIR)
	@printf "$(GR)MinilibX compiling was sucessful!$(RC)\n\n"

$(LIBFT):
	@printf "\n$(GR)Compiling libft...$(RC)\n"
	@make -C $(LIB_DIR)
	@printf "$(GR)Libft compiling was sucessful!$(RC)\n\n"

bonus: 		all

re: 		fclean all

rebonus: 	fclean bonus

valgrind:
	@printf "\n$(CY)Initializing valgrind analysis...$(RC)\n"
	@sleep 0.2
	$(VALGRIND) $(VALGRIND_F)
	@printf "\n$(CY)Done!$(RC)\n"
logdel:
			$(RM) $(LOG_FILE)

clean:
	@printf "\n$(YE)Cleaning Libft directory...$(RC)\n"
	@make clean -C $(LIB_DIR)
	@sleep 0.2
	@printf "$(GR)Libft cleaned successfully!$(RC)\n\n"

	@printf "\n$(CY)Removing object folder from directory...$(RC)\n"
	$(RM) -rf $(OBJ_FILES) $(BONUS_OBJ) objs/

fclean: clean
	@printf "\n$(YE)Cleaning everything...$(RC)\n"
	@sleep 0.2
	$(RM) -rf $(NAME) $(BONUS_OBJ) objs/
	@make fclean -C $(LIB_DIR)
	@make clean -C $(MLX_DIR)
	make logdel
	@printf "$(GR)Full clean performed successfully!$(RC)\n\n"

debug:		$(OBJ_FILES) $(LIBFT) $(MLX_LINUX)
			$(CC) -ggdb $(CFLAGS) -o $(NAME) $(OBJ_FILES) -L $(LIB_DIR) -L $(MLX_DIR) -lft $(MLX_FLAGS)
			mkdir obj
			mv $(OBJ_FILES) obj/
eval_debug:
			gdb --args ./fdf landscapes/42.fdf

.PHONY: clean fclean re rebonus all bonus debug eval_debug

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m
