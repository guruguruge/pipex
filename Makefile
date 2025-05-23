# /* ************************************************************************** */
# /*                                                                            */
# /*                                                        :::      ::::::::   */
# /*   Makefile                                           :+:      :+:    :+:   */
# /*                                                    +:+ +:+         +:+     */
# /*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
# /*                                                +#+#+#+#+#+   +#+           */
# /*   Created: 2025-05-19 12:22:58 by sguruge           #+#    #+#             */
# /*   Updated: 2025-05-19 12:22:58 by sguruge          ###   ########.fr       */
# /*                                                                            */
# /* ************************************************************************** */

NAME = pipex
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra 
INCLUDES = -Iincludes

SRCS = \
	ft_strlen.c \
	ft_strncmp.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strdup.c\
	ft_split.c \
	ft_calloc.c \
	ft_memset.c\
	handle_error.c \
	cleanup.c \
	execute_cmds_utils.c \
	execute_cmds.c \
	cleanup.c \
	find_path.c \
	main.c



OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
