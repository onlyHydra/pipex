# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schiper <schiper@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 19:24:08 by schiper           #+#    #+#              #
#    Updated: 2025/02/04 04:00:07 by schiper          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g 

SRCDIR = src
INCDIR = headers
LIBDIR = import
OBJDIR = src

LIBFT = $(LIBDIR)/libft

SRCS = $(shell find $(SRCDIR) -name "*.c" ! -name "*_bonus.c")
SRCSBNS = $(shell find $(SRCDIR) -name "*.c" ! -name "pipex.c")
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJSBNS = $(SRCSBNS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
NAME = pipex
NAMEBNS = pipex_bonus
INCLUDES = -I$(INCDIR) -I$(LIBFT)

LIBS = -L$(LIBFT) -lft

all: $(NAME)

bonus: $(NAMEBNS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	
$(NAMEBNS): $(OBJSBNS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJSBNS) $(LIBS) -o $(NAMEBNS)

clean:
	find $(OBJDIR) -name "*.o" -delete
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAMEBNS)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re bonus









































