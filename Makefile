# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adratini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 18:40:27 by adratini          #+#    #+#              #
#    Updated: 2021/10/09 18:40:29 by adratini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= 	ft_printf.c				\
			ft_hex_treatment.c		\
			ft_int_treatment.c		\
			ft_pointer_treatment.c	\
			ft_printf_utils.c		\
			ft_string_treatment.c	\
			ft_uint_tretment.c		\


OBJS	= ${patsubst %.c,%.o,${SRCS}}

D_FILES = ${patsubst %.c,%.d,${SRCS}}
CFLAGS	= -Wall -Wextra -Werror
OPTFLAGS = -O2

all:	${NAME}

$(NAME): ${OBJS}
		ar rcs ${NAME} $?

%.o : %.c
		cc ${CFLAGS} ${OPTFLAGS} -c $< -o $@ -MD

include ${wildcard ${D_FILES}}

clean:	
	@rm -f ${OBJS} ${D_FILES}

fclean:	clean
		@rm -f ${NAME}

re:		fclean all

.PHONY:	all clean