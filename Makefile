# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmahlake <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/31 10:19:11 by dmahlake          #+#    #+#              #
#    Updated: 2017/09/27 15:11:06 by dmahlake         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_cd.c\
	  ft_command_found.c\
	  ft_echocommand.c\
	  ft_envirn_cpy.c\
	  ft_main.c\
	  ft_setenv.c\
	  get_next_line.c\
	  ft_unsetenv.c\
	  ft_builtins.c

OBJ = $(SRC:.c=.o)

INC= ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
		@make -C libft
		@$(CC) -o $(NAME) $(CFLAGS)  $(SRC)  $(INC)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re:	fclean all
