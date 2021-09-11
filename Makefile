NAME		:=	a.out

MDIR		:=	.
HDIR		:=	$(MDIR)/inc
SDIR		:=	$(MDIR)/src
ODIR		:=	$(MDIR)/.obj
DDIR		:=	$(MDIR)/.dep

HDR_LIST	:=	fractol
SRC_LIST	:=	fractol

MLX_DIR		:= $(MDIR)/mlx_macos
MLX_LIB		:= libmlx.dylib
MLX_HDIR	:= $(MLX_DIR)
MLX			= $(MLX_DIR)/$(MLX_LIB)

# CC			:=	gcc
# CFLAGS		:=	-Wall -Wextra -Werror
OPT_FLAGS	:=	-O3
DBG_FLAGS	:=	-g
MLX_FLAGS	:=	-framework OpenGL -framework AppKit
AR			:=	ar rcs 
RM			:=	rm -f
CFLAGS		+=	$(OPT_FLAGS) $(DBG_FLAGS)

LIB			=	mlx
#m ft
LIBRARIES	=	$(addprefix -l, $(LIB)) \
				$(addprefix -L, $(MLX_DIR))

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

$(ODIR)		:
				@mkdir -p $(ODIR)
$(DDIR)		:
				@mkdir -p $(DDIR)

$(ODIR)/%.o	:	$(SDIR)/%.c $(HDR) | $(ODIR) $(DDIR)
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME)		:	$(OBJ) Makefile $(HDR)
				$(CC) $(CFLAGS) $(LIBRARIES) $(MLX_FLAGS) -o $(NAME) $(OBJ)
#$(MLX)

all			:	$(NAME)

# $(MLX)		:
# 				@$(MAKE) -sC $(MLX_DIR)

clean		:
				$(RM) $(OBJ)
#				@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
				@$(MAKE) -sC $(MLX_DIR) clean
				@if [ -d $(ODIR) ]; then rmdir $(ODIR); fi
				@if [ -d $(DDIR) ]; then rmdir $(DDIR); fi

fclean		: 	clean
				@rm -f $(MLX_LIB)
				@echo "$(NAME): $(RED)$(MLX_LIB) was deleted$(RESET)"
#				@rm -f $(LIBFT)
#				@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
				@rm -f $(NAME)
				@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re			:
				@$(MAKE) fclean
				@$(MAKE) all

.PHONY		:	all clean fclean re