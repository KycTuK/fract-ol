NAME		:=	fractol

MDIR		:=	.
HDIR		:=	$(MDIR)/inc
SDIR		:=	$(MDIR)/src
ODIR		:=	$(MDIR)/.obj
DDIR		:=	$(MDIR)/.dep

HDR_LIST	:=	fractol
SRC_LIST	:=	fractol
SRC_LIST	+=	ft_draw \
				ft_hooks \
				ft_draw_circle \
				ft_draw_rectangle

LIB			:=	mlx
MLX_LIB		:=	libmlx.dylib
MLX_DIR		:=	$(MDIR)/minilibx
MLX_HDIR	:=	$(MLX_DIR)
MLX			:=	$(MLX_DIR)/$(MLX_LIB)

CC			:=	gcc
# CFLAGS		:=	-Wall -Wextra -Werror
OPT_FLAGS	:=	-O3
DBG_FLAGS	:=	-g
MLX_FLAGS	:=	-framework OpenGL -framework AppKit
AR			:=	ar rcs 
RM			:=	rm -f
CFLAGS		+=	$(OPT_FLAGS) 
#CFLAGS		+=	$(DBG_FLAGS) 


#m ft
LIBRARIES	=	$(addprefix -L, $(MDIR)) \
				$(addprefix -l, $(LIB))
				

INC			=	$(HDIR) $(MLX_HDIR)
INCLUDES	=	$(addprefix -I, $(INC))

# COLORS
GREEN		=	\033[0;32m
RED			=	\033[0;31m
RESET		=	\033[0m

DEP_FLAGS	=	-MT $@ -MMD -MP -MF $(DDIR)/$*.d

HDR			:=	$(addprefix $(HDIR)/, $(HDR_LIST:=.h))
SRC			:=	$(addprefix $(SDIR)/, $(SRC_LIST:=.c))
OBJ			:=	$(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRC))
DEP			:=	$(patsubst $(SDIR)/%.c, $(DDIR)/%.d, $(SRC))

# $(ODIR)		:
# 				@mkdir -p $(ODIR)
# $(DDIR)		:
# 				@mkdir -p $(DDIR)

$(ODIR)/%.o	:	$(SDIR)/%.c $(HDR) | $(ODIR) $(DDIR)
				@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all			:	$(NAME)
				@echo "$(NAME): $(GREEN)$(NAME) was created successfully!$(RESET)"

$(NAME)		:	$(MLX) $(OBJ) Makefile $(HDR)
				@cp $(MLX) $(MDIR)/$(MLX_LIB)
				@$(CC) $(CFLAGS) $(LIBRARIES) $(MLX_FLAGS) -o $(NAME) $(OBJ) 
#				minilibx_opengl/libmlx.a
#				mlx_macos/libmlx.dylib
#				$(MLX)
#				$(MLX_FLAGS) 
#				$(LIBRARIES)

$(MLX)		:	
				@$(MAKE) -sC $(MLX_DIR)
				@echo "$(NAME): $(GREEN)$(MLX) was created successfully!$(RESET)"

clean		:
				@$(RM) $(OBJ)
				@echo "$(NAME): $(RED)$(OBJ) were deleted$(RESET)"
				@$(MAKE) -sC $(MLX_DIR) clean
#				@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
#				@if [ -d $(ODIR) ]; then rmdir $(ODIR); fi
#				@if [ -d $(DDIR) ]; then rmdir $(DDIR); fi

fclean		: 	clean
				@rm -f $(MLX_LIB)
				@echo "$(NAME): $(RED)$(MLX_LIB) was deleted$(RESET)"
				@rm -f $(NAME)
				@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
#				@rm -f $(LIBFT)
#				@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"

re			:
				@$(MAKE) fclean
				@$(MAKE) all

.PHONY		:	all clean fclean re