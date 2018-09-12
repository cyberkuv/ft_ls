# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eonwe <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/18 10:08:46 by eonwe             #+#    #+#              #
#    Updated: 2018/09/10 11:37:56 by eonwe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#compiler
TAG = gcc

#name
NAME = ft_ls

#flags
CFLAGS = -Wall -Wextra -Werror

# Content Folders
LIB_DIR = ./libft/

#Source Files
SRC_FILES = ft_ls.c\
			can_acc.c\
			ft_blocks.c\
			ft_compare.c\
			ft_lsl.c\
			ft_opendir.c\
			inval_opt.c\
			pro_args.c\
			print_dir.c\

# Stating when to focus compilation and clean up
LIBFT = $(addprefix $(LIB_DIR), libft.a)
OBJ = $(SRC_FILES:.c=.o)

all : $(NAME)

#compilation
$(NAME):
	@echo "\033[32;1m                                 [Any Moment Now]\033[32;0"
	@$(TAG) -c $(CFLAGS) $(SRC_FILES)
	@make -C ./libft/
	@echo "\033[33;1m                         [Libft Successfully Compilled]\033[33;0m"
	@$(TAG) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "\033[33;1m=====Successfully Compilled=====\033[33;0m"
	@echo "\033[36;1m========Library Created=========\033[36;0m"
	@echo "\033[32;1m================================\033[32;0m"

# Compiling Libft's directory from the current ft_ls directory and cleaning up
reall:
	@make libft/
	@make clean libft/

# continious clean up
rc :
	@make re
	@make clean

# Deleting After compiling
# Deleting Object files
clean :
	@/bin/rm -rf $(OBJ)
	@/bin/rm -rf ./libft/*.o
	@echo "\033[32;1m================================\033[31;0m"
	@echo "\033[31;1m=======Object fls Deleted=======\033[31;0m"

# Deleting Library
fclean : clean
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf ./libft/*.a
	@echo "\033[34;1m==========Lib Deleted===========\033[31;0m"
	@echo "\033[32;1m================================\033[32;0m"

# Clean up
re : fclean all

# Security
.PHONY : $(NAME), all, clean, fclean, re
