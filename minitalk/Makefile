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
WHITE	=	\033[0;97m

# ======================================================================== #

all: $(NAME)

$(NAME):
	@make -C Libft
	@gcc $(CFLAGS) $(SERVER) $(LIBFT) -o server
	@gcc $(CFLAGS) $(CLIENT) $(LIBFT) -o client
	@echo "$(GREEN)Compiling:$(WHITE) server.c"
	@echo "$(GREEN)Compiling:$(WHITE) client.c"
	@echo "$(YELLOW)- Program Name: $(WHITE)${NAME}"
	@echo "$(YELLOW)- Compiler: $(WHITE)${CC}"
	@echo "$(YELLOW)- Flags: $(WHITE)${CFLAGS}"

clean:
	@make clean -C Libft
	@echo "$(RED)All object files removed.$(WHITE)"

fclean: clean
	@rm client
	@rm server
	@make fclean -C Libft

re: fclean all

.PHONY: all clean fclean re
