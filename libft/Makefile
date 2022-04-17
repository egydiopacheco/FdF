# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/11 13:37:45 by epacheco          #+#    #+#              #
#    Updated: 2021/09/17 12:03:52 by epacheco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libft.a
CC		:= clang
CFLAGS	:= -Wall -Wextra -Werror -I. -c
RM		:= rm -f
HEADERS := libft.h
AR		:= ar rcs

SRC_FILES =  ft_atoi.c	ft_bzero.c		ft_calloc.c		ft_isalpha.c	\
		ft_isalnum.c	ft_isascii.c	ft_isdigit.c	ft_isprint.c	\
		ft_strchr.c		ft_strdup.c		ft_strlcat.c	ft_strlcpy.c	\
		ft_strlen.c		ft_strrchr.c	ft_strncmp.c	ft_strnstr.c	\
		ft_memchr.c		ft_memcpy.c		ft_memset.c		ft_memmove.c	\
		ft_memcmp.c		ft_tolower.c	ft_toupper.c	ft_substr.c		\
		ft_strjoin.c	ft_strtrim.c	ft_split.c		ft_itoa.c		\
		ft_strmapi.c	ft_striteri.c	ft_putchar_fd.c	ft_putendl_fd.c	\
		ft_putnbr_fd.c	ft_putstr_fd.c	ft_atoi_base.c	ft_strcmp.c	get_next_line.c	\
		ft_split_count.c ft_absolute_value.c ft_max_value_between.c \
		ft_min_value_between.c

SRC_OBJ = $(SRC_FILES:%.c=%.o)

BONUS_FILES = ft_lstnew.c			ft_lstadd_front.c	ft_lstsize.c	\
			  ft_lstlast.c			ft_lstadd_back.c	ft_lstdelone.c	\
			  ft_lstclear.c			ft_lstiter.c		ft_lstmap.c
BONUS_OBJ = $(BONUS_FILES:%.c=%.o)

$(NAME): $(SRC_OBJ) $(HEADERS)
	$(AR) $(NAME) $(SRC_OBJ)

$(BONUS_OBJ):
	$(CC) $(CFLAGS) $(BONUS_FILES)

all: $(NAME)

clean:
	$(RM) $(SRC_OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

bonus: $(NAME) $(BONUS_OBJ)
	$(AR) $(NAME) $(BONUS_OBJ)

.PHONY: all clean fclean re bonus rebonus
