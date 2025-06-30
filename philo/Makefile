# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/04 12:51:09 by dgargant          #+#    #+#              #
#    Updated: 2025/06/30 12:46:04 by dgargant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	   = philo

CC          = cc

CFLAGS      = -Wall -Wextra -Werror -I$(INC)

INC         = includes/

OBJS_DIR    = objs/

# Colores
RED         = \033[0;31m
GREEN       = \033[0;92m
CYAN        = \033[0;96m
BLUE        = \033[0;34m
PURPLE      = \033[0;95m
YELLOW      = \033[0;93m
RESET       = \033[0m
BOLD_CYAN   = \033[1;96m

SRCS_DIR    = src/

SRCS_FILES := \
	philo.c\
	$(addprefix Parsing/, parsing_init.c	parsing_overflow.c) \
	$(addprefix Utils/, ft_calloc.c	time_manager.c) \
	$(addprefix Lifestyle/, death_parade.c	philo_life.c) \
	$(addprefix Actions/, forks.c	printer.c) \

OBJS_FILES  = $(SRCS_FILES:.c=.o)

SRCS        = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS        = $(addprefix $(OBJS_DIR), $(OBJS_FILES))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling $(BLUE)$(NAME)$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\n$(GREEN)$(NAME) compiled!$(RESET)"
	@echo "$(BOLD_CYAN)\n------------\n| Done! 👌 |\n------------$(RESET)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@[ -d $(dir $@) ] || mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)
	@echo "$(GREEN)$(NAME)$(YELLOW) cleaned$(RESET)"

re: fclean all

.PHONY: all clean fclean re
.SILENT: all clean fclean
