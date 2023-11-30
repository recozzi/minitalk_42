# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: recozzi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 21:38:06 by recozzi           #+#    #+#              #
#    Updated: 2023/11/18 21:38:08 by recozzi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

MAKEFLAGS	+=	--silent

NAME		:=	minitalk

CFLAGS		:=	-Wall -Wextra -Werror

SERVER		:=	server.c

CLIENT		:=	client.c

LIBFT		:=	Libft/libft.a

# COLORS ================================================================= #

RED		=	\033[0;91m
GREEN	=	\033[0;92m
YELLOW	=	\033[0;93m
CYAN	=	\033[0;96m
WHITE	=	\033[0;97m

# ======================================================================== #

all: $(NAME)

$(NAME):
	@make -C Libft
	@gcc $(CFLAGS) $(SERVER) $(LIBFT) -o server
	@gcc $(CFLAGS) $(CLIENT) $(LIBFT) -o client
	@echo "$(GREEN)Compiling:$(WHITE) $<"
	@echo "$(YELLOW)- Program Name: $(WHITE)${NAME}"
	@echo "$(YELLOW)- Compiler: $(WHITE)${CC}"
	@echo "$(YELLOW)- Flags: $(WHITE)${CFLAGS}"

clean:
	@make clean -C Libft
	@echo "$(RED)All $(CYAN)$(NAME)$(RED)'s objects removed..."

fclean: clean
	@rm client
	@rm server
	@make fclean -C Libft
	@echo "$(RED)...And $(CYAN)${NAME} $(RED)as been removed."

re: fclean all

.PHONY: all clean fclean re
