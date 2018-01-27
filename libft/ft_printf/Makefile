# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 16:39:52 by gsmith            #+#    #+#              #
#    Updated: 2017/12/06 16:31:48 by gsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
COMP=clang
FLAG=-Wall -Wextra -Werror
SRCS=ft_printf.c ft_error.c ft_format.c convert_c.c convert_s.c \
	 convert_percent.c convert_p.c read_digits1.c read_digits2.c \
	 read_udigits1.c read_udigits2.c convert_d.c convert_u.c convert_o.c \
	 convert_x.c
OBJS=$(SRCS:.c=.o)
LIBFT_DIR=../libft/
LIBFT_LIB=../libft/libft.a
ERASE_LINE='\r\033[K'
NC='\033[0m'
RED='\033[0;31m'
LRED='\033[1;31m'
LBLUE='\033[1;34m'
GREEN='\033[0;32m'
LGREEN='\033[1;32m'
ORANGE='\033[0;33m'
YELLOW='\033[1;33m'

all: $(NAME)

$(NAME): $(OBJS)
	@printf $(ERASE_LINE)"[$(NAME)]"$(LGREEN)"Compiling done.\n"$(NC)
	@make -C $(LIBFT_DIR)
	@printf $(ERASE_LINE)"[$(NAME)]"$(ORANGE)"Cloning libft.a to $(NAME)..."$(NC)
	@cp $(LIBFT_LIB) $(NAME)
	@printf $(ERASE_LINE)"[$(NAME)]"$(YELLOW)"$(NAME) cloned.\n"$(NC)
	@printf "[$(NAME)]"$(LBLUE)"Adding .o files to $(NAME)..."$(NC)
	@ar rsc $(NAME) $(OBJS)
	@printf $(ERASE_LINE)"[$(NAME)]"$(LGREEN)"$(NAME) updated.\n"$(NC)
	@printf $(ERASE_LINE)"[$(NAME)]"$(LGREEN)"$(NAME) indexed.\n"$(NC)

%.o: %.c
	@printf $(ERASE_LINE)"[$(NAME)]"$(LBLUE)"Compiling $<..."$(NC)
	@$(COMP) $(FLAG) -I $(LIBFT_DIR) -o $@ -c $<

test: all
	$(COMP) main.c -L. -lftprintf
	./a.out | cat -e

clean:
	@make -C $(LIBFT_DIR) clean
	@printf "[$(NAME)]"$(RED)"Cleaning .o files..."$(NC)
	@rm -f $(OBJS)
	@printf $(ERASE_LINE)"[$(NAME)]"$(LRED)".o files cleaned.\n"$(NC)

fclean:
	@make -C $(LIBFT_DIR) fclean
	@printf "[$(NAME)]"$(RED)"Cleaning .o files..."$(NC)
	@rm -f $(OBJS)
	@printf $(ERASE_LINE)"[$(NAME)]"$(LRED)".o files cleaned.\n"$(NC)
	@printf "[$(NAME)]"$(RED)"Cleaning $(NAME) file..."$(NC)
	@rm -f $(NAME)
	@printf $(ERASE_LINE)"[$(NAME)]"$(LRED)"$(NAME) cleaned.\n"$(NC)

re: fclean all
