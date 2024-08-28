# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artberna <artberna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 13:40:40 by artberna          #+#    #+#              #
#    Updated: 2024/08/16 16:25:26 by artberna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************
#                                    MAIN                                     *
#******************************************************************************

NAME = so_long
HEADER = so_long.h

#******************************************************************************
#                                 DIRECTORIES                                 *
#******************************************************************************

OBJ_DEP_DIR = obj_dep/
SRC_DIR = src/
MY_LIBRARY = my_library
MINILIBX = minilibx

#******************************************************************************
#                       SOURCES, OBJECTS & DEPENDENCIES                       *
#******************************************************************************

SO_LONG_SRC = main manage_input utils check_map is_accesible render_game handle_input init_sprites

SO_LONG_FLS = $(addsuffix .c, $(SO_LONG_SRC))

SRC = $(SO_LONG_FLS)

OBJ = $(addprefix $(OBJ_DEP_DIR), $(SRC:.c=.o))

OBJF = .cache_exists

DEP = $(addprefix $(OBJ_DEP_DIR), $(OBJ:.o=.d))

#******************************************************************************
#                                INSTRUCTIONS                                 *
#******************************************************************************

CC = cc -g3
FLAGS = -Wall -Wextra -Werror -I.
EXE_FLAGS = -lX11 -lXext
RM = rm -rf
AR = ar rcs
LIB_FLAGS = -L./$(MY_LIBRARY) -l:my_library.a
MINILIBX_FLAGS = -L./$(MINILIBX) -l:libmlx.a

#******************************************************************************
#                                  COLORS                                     *
#******************************************************************************

RESET = \033[0m
ROSE = \033[1;38;5;225m
VIOLET = \033[1;38;5;55m
VERT = \033[1;38;5;85m
BLEU = \033[1;34m

#******************************************************************************
#                                COMPILATION                                  *
#******************************************************************************

all : $(NAME)
	@echo "$(ROSE)COMPILATION FINISHED, $(NAME) IS CREATED!$(RESET)"

$(NAME) : $(OBJ) | $(MY_LIBRARY)/my_library.a $(MINILIBX)/libmlx.a
	@$(CC) $(FLAGS) $(EXE_FLAGS) $(OBJ) $(LIB_FLAGS) $(MINILIBX_FLAGS) -o $(NAME)

$(MY_LIBRARY)/my_library.a :
	@make -C $(MY_LIBRARY)

$(MINILIBX)/libmlx.a :
	@make -C $(MINILIBX)

$(OBJ_DEP_DIR)%.o: %.c $(HEADER) | $(OBJF)
	@$(CC) $(FLAGS) -MMD -MP -c $< -o $@
	@echo "$(BLEU)Compiling $< to $@.$(RESET)"

$(OBJF):
	@mkdir -p $(OBJ_DEP_DIR)

clean :
	@$(RM) $(OBJ_DEP_DIR)
	@make clean -C $(MY_LIBRARY)
	@make clean -C $(MINILIBX)
	@echo "$(VIOLET)Suppressing objects & dependencies files of $(NAME).$(RESET)"

fclean : clean
	@$(RM) $(NAME)
	@rm -f $(MY_LIBRARY)/my_library.a
	@rm -f $(MINILIBX)/libmlx.a
	@echo "$(VERT)Suppressing archives $(MY_LIBRARY).a.$(RESET)"
	@echo "$(VERT)Suppressing archives $(NAME).$(RESET)"

re : fclean all

-include $(DEP)

.PHONY : re fclean clean all
