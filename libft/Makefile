# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eonwe <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/29 10:45:38 by eonwe             #+#    #+#              #
#    Updated: 2018/09/04 13:23:57 by eonwe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
TAG		= gcc

# Lib Name
NAME	= libft.a

# Compilation Flags
CFLAGS	= -Wall -Werror -Wextra

# Source Files
SRC		= ft_memccpy.c\
		ft_bzero.c\
		ft_atoi.c\
		ft_memchr.c\
		ft_strrchr.c\
		ft_isalnum.c\
		ft_memcmp.c\
		ft_strchr.c\
		ft_isalpha.c\
		ft_memcpy.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_tolower.c\
		ft_islower.c\
		ft_isascii.c\
		ft_memmove.c\
		ft_strcpy.c\
		ft_toupper.c\
		ft_isupper.c\
		ft_isdigit.c\
		ft_memset.c\
		ft_strlen.c\
		ft_nbrlen.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_strlcat.c\
		ft_isprint.c\
		ft_strdup.c\
		ft_strncpy.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_itoa.c\
		ft_wdsort.c\
		ft_strsplit.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstsize.c\
		ft_lstswap.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstjoin.c\
		ft_strnlen.c\
		ft_strrev.c\
		ft_itoa_base.c\
		ft_printf.c\
	  	ft_mod.c\
	  	ft_type.c\
	 	add_width.c\
	  	ft_wstr.c\
	  	wrt_nbr.c\
		ft_lstfree.c\
	  	ft_lltoa.c\
	  	ft_ultoa.c\
	  	ft_lltoah.c\
	  	ft_lltoao.c\
	  	ft_base.c\
	  	no_print.c\
	  	fll_zero.c\
	  	ft_putnstr.c\
	  	ft_wnstrlen.c\
	  	ft_wp.c\
	  	ft_fmt.c\
	  	ft_str_chr.c\
	  	ft_putnwstr.c\
	  	ft_putwstr.c\

# Creating Object Files	
OBJ = $(SRC:.c=.o)

all : $(NAME)

# Compilation
$(NAME) : 
	@$(TAG) $(CFLAG) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[33;1m=====Successfully Compilled=====\033[33;0m"
	@echo "\033[36;1m========Library Created=========\033[36;0m"
	@echo "\033[32;1m================================\033[32;0m"

# Deleting After Compiling
# Delelting Object Files
clean:
	@/bin/rm -rf $(OBJ)
	@echo "\033[32;1m================================\033[31;0m"
	@echo "\033[31;1m=======Object fls Deleted=======\033[31;0m"

# Deleting Library
fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\033[34;1m==========Lib Deleted===========\033[31;0m"
	@echo "\033[32;1m================================\033[32;0m"

# Clean  up
re: fclean all

# Security
.PHONY: all, clean, fclean, re
