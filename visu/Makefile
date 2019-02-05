#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <erli@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 14:34:35 by erli              #+#    #+#              #
#    Updated: 2019/02/05 21:38:50 by erli             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=		visu

SRCSDIR		=		./srcs
OBJSDIR		=		./objs

SRCS		=		main.c

OBJS		=		$(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))

CC			=		gcc -g

CFLAG		=		-Wall -Werror -Wextra

INCL		=		-I includes/ -I libft/includes/

RM			=		rm -f

FRAMEWORK	=		-framework OpenGL -framework AppKit

LIB			=		libft/libft.a

LIBMLX		=		minilibx_macos/libmlx.a

all			:		$(NAME)

$(NAME)		:		$(OBJS) $(LIB) $(LIBMLX) includes/lem_in.h
					$(CC) $(CFLAG) $(INCL) $(OBJS) $(LIB) $(LIBMLX) $(FRAMEWORK) \
					-o $(NAME)

$(LIB)		:		
					make -C libft/

$(LIBMLX)	:
					make -C minilibx_macos/

$(OBJSDIR)/%.o	:	$(SRCSDIR)/%.c includes/lem_in.h
					@mkdir -p $(OBJSDIR)
					$(CC) -c $(CFLAG) $(INCL) -c $< -o $@

clean		:
					$(RM) $(OBJS)

fclean		:		clean
					$(RM) $(NAME)

re			:		
					@make fclean
					@make all

delsav		:
					$(RM) *~
					$(RM) */*~
					$(RM) \#*\#
					$(RM) */\#*\#

reset		:		
					@make fclean
					@make delsav
					@rm -Rf objs

.PHONY		:		clean fclean re delsav reset
