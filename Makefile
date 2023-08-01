# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 14:12:09 by kyoshida          #+#    #+#              #
#    Updated: 2023/07/29 11:42:51 by yoshidakazu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Wextra -Werror
NAME := push_swap
RM := rm -f
FT_PRINTF := ./ft_printf/libftprintf.a
FT_PRINTFDIR := ./ft_printf
SRCS := ft_strlcpy.c\
ft_lstlast.c\
error_handling.c\
sort.c\
swap_command.c\
ft_split.c\
main.c\
sort_utils.c\
reverse_command.c\
rev_rotate_command.c\
lst_utils.c\
sort_big.c\
lstadd_a.c\
ft_atoi2.c\
push_command.c\
sort_min.c\
find.c\
sorted_check.c

OBJS :=$(SRCS:.c=.o)

$(NAME):$(OBJS)
	${MAKE} -C ${FT_PRINTFDIR}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${FT_PRINTF}

all: $(NAME)
	
clean:
	${MAKE} -C ${FT_PRINTFDIR} fclean
	${RM} ${OBJS}

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re