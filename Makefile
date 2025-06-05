# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/02 15:20:54 by rpaparon          #+#    #+#              #
#    Updated: 2025/06/05 17:38:30 by rpaparon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SOURCES = sources/main.c sources/parsing.c sources/stacks_utils.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -I$(LIBFT_DIR)

RM = rm -rf

GREEN  = \033[1;32m
RED    = \033[1;31m
YELLOW = \033[1;33m
BLUE   = \033[1;34m
CYAN   = \033[1;36m
RESET  = \033[0m
PURPLE = \033[1;35m

.PHONY: all clean fclean re

all: banner $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	@echo "$(CYAN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)✔ $(NAME) compiled successfully!$(RESET)"

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@echo "$(BLUE)Compiling libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --silent

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) $(OBJECTS)
	@$(MAKE) -C $(LIBFT_DIR) clean --silent

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --silent

re: fclean all

banner:
	@echo ""
	@echo "  $(BLUE)#===================================================#$(RESET)"
	@echo "  $(BLUE)#***************************************************#$(RESET)"
	@echo "  $(BLUE)#*                                                 *#$(RESET)"
	@echo "  $(BLUE)#*         ╭━━━╮╱╱╱╱╱╭╮╱╭━━━╮                      *#$(RESET)"
	@echo "  $(BLUE)#*         ┃╭━╮┃╱╱╱╱╱┃┃╱┃╭━╮┃                      *#$(RESET)"
	@echo "  $(BLUE)#*         ┃╰━╯┣╮╭┳━━┫╰━┫╰━━┳╮╭╮╭┳━━┳━━╮           *#$(RESET)"
	@echo "  $(BLUE)#*         ┃╭━━┫┃┃┃━━┫╭╮┣━━╮┃╰╯╰╯┃╭╮┃╭╮┃           *#$(RESET)"
	@echo "  $(BLUE)#*         ┃┃╱╱┃╰╯┣━━┃┃┃┃╰━╯┣╮╭╮╭┫╭╮┃╰╯┃           *#$(RESET)"
	@echo "  $(BLUE)#*         ╰╯╱╱╰━━┻━━┻╯╰┻━━━╯╰╯╰╯╰╯╰┫╭━╯           *#$(RESET)"
	@echo "  $(BLUE)#*         ╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱┃┃             *#$(RESET)"
	@echo "  $(BLUE)#*         ╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╰╯             *#$(RESET)"
	@echo "  $(BLUE)#*                                        🔧🔧🔧...*#$(RESET)"
	@echo "  $(BLUE)#***************************************************#$(RESET)"
	@echo "  $(BLUE)#===================================================#$(RESET)"
	@echo ""