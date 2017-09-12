# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yewen <yewen@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 11:58:20 by yewen             #+#    #+#              #
#    Updated: 2017/08/18 23:38:39 by yewen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = clang
CFLAGS = -I. -Ift_printf -Ift_parser -Wall -Werror -Wextra
HFILES = libft.h \
		 ft_list.h \
		 get_next_line.h \
		 lst.h \
		 rb.h \
		 ft_printf/printflocal.h \
		 ft_array.h
RM = rm -f
SRCS = ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strlen.c \
	   ft_strdup.c \
	   ft_strcpy.c \
	   ft_strncpy.c \
	   ft_strcat.c \
	   ft_strncat.c \
	   ft_strlcat.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strstr.c \
	   ft_strnstr.c \
	   ft_strcmp.c \
	   ft_strncmp.c \
	   ft_atoi.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_memalloc.c \
	   ft_memdel.c \
	   ft_strnew.c \
	   ft_strdel.c \
	   ft_strclr.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strequ.c \
	   ft_strnequ.c \
	   ft_strsub.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_strsplit.c \
	   ft_itoa.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putendl.c \
	   ft_putnbr.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_lstadd.c \
	   ft_lstdel.c \
	   ft_lstdelone.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_lstnew.c \
	   ft_strsplit_free.c \
	   ft_strndup.c \
	   ft_strnlen.c \
	   get_next_line.c \
	   ft_qsort.c \
	   ft_strrev.c \
	   ft_wcslen.c \
	   ft_isint.c \
	   ft_count_chars.c \
	   ft_try.c \
	   ft_del.c \
	   ft_pushback.c \
	   ft_trim.c \
	   ft_deltab.c \
	   ft_lstend.c \
	   ft_lstsize.c \
	   ft_lstadd_end.c \
	   ft_strjoinfree.c \
	   ft_endian.c \
	   ft_array.c \
	   ft_printf/ft_vdprintf.c \
	   ft_printf/ft_dprintf.c \
	   ft_printf/ft_printf.c \
	   ft_printf/ft_asprintf.c \
	   ft_printf/ft_vasprintf.c \
	   ft_printf/get_arg.c \
	   ft_printf/parse.c \
	   ft_printf/parse_flags.c \
	   ft_printf/parse_type.c \
	   ft_printf/parse_type_helper.c \
	   ft_printf/pf_number.c \
	   ft_printf/pf_print.c \
	   ft_printf/aspf_print.c \
	   ft_printf/ujtoa.c \
	   ft_printf/ultoa.c \
	   ft_printf/wctostr.c \
	   ft_printf/wstostr.c \
	   lst_init.c \
	   lst_new_node.c \
	   lst_iter.c \
	   lst_insert.c \
	   lst_delete.c \
	   lst_remove.c \
	   lst_push.c \
	   lst_push_back.c \
	   lst_pop.c \
	   lst_search.c \
	   lst_reverse.c \
	   lst_sort.c \
	   lst_issorted.c \
	   lst_rotate.c \
	   lst_reverse_rotate.c \
	   lst_swap.c \
	   lst_destroy.c \
	   rb.c \
	   rb_delete.c \
	   rb_destroy.c \
	   rb_init.c \
	   rb_insert.c \
	   rb_search.c \
	   rb_util.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c $(HFILES)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "Compiling $@"
	@ar -rc $@ $^
	ranlib $@

clean:
	@echo "Removing objects"
	@$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
