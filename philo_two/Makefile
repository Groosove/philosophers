# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flavon <flavon@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/19 11:15:56 by flavon            #+#    #+#              #
#    Updated: 2020/11/21 16:59:28 by flavon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_two

SRCS = main.c libft_utils.c philo_two.c philo_utils.c

INCLUDE = philo_two.h

OBJ_PATH = obj/

OBJ = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

FLAG = -Wall -Wextra -Werror
CC = gcc
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) -I $(INCLUDE) $(SRCS) -o $(NAME) -pthread

$(OBJ_PATH)%.o: %.c
	@test -d $(OBJ_PATH) || mkdir $(OBJ_PATH)
	$(CC) $(FLAG) -I $(INCLUDE) -c $< -o $@

clean:
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re