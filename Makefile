# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/15 17:29:09 by yewen             #+#    #+#              #
#    Updated: 2017/08/24 10:47:22 by jdebladi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = asm
VM = corewar
CC = clang
RM = rm -f
ASMDIR = assembler
VMDIR = vm
LIB = libft.a
LIBDIR = libft
CFLAGS = -Wall -Werror -Wextra -I$(LIBDIR)
ASMSRCS = $(ASMDIR)/main.c \
		  $(ASMDIR)/op.c \
		  $(ASMDIR)/run.c \
		  $(ASMDIR)/read.c \
		  $(ASMDIR)/parse_header.c \
		  $(ASMDIR)/parse_line.c \
		  $(ASMDIR)/parse_line_helper.c \
		  $(ASMDIR)/parse_check_argv.c \
		  $(ASMDIR)/write.c \
		  $(ASMDIR)/write_helper.c \
		  $(ASMDIR)/write_instruction.c \
		  $(ASMDIR)/write_argv.c
VMSRCS = $(VMDIR)/main.c \
		 $(VMDIR)/init.c \
		 $(VMDIR)/ins0.c \
		 $(VMDIR)/ins1.c \
		 $(VMDIR)/ins2.c \
		 $(VMDIR)/ins3.c \
		 $(VMDIR)/mem.c \
		 $(VMDIR)/op.c \
		 $(VMDIR)/parse_arg.c \
		 $(VMDIR)/parse_champ.c \
		 $(VMDIR)/process_check.c \
		 $(VMDIR)/process_read.c \
		 $(VMDIR)/process.c \
		 $(VMDIR)/utils.c \
		 $(VMDIR)/value.c
ASMOBJS = $(ASMSRCS:.c=.o)
VMOBJS = $(VMSRCS:.c=.o)

.PHONY: all clean fclean re

all: $(ASM) $(VM)

%.o: %.c $(ASMDIR)/asm.h $(ASMDIR)/op.h $(VMDIR)/corewar.h $(VMDIR)/op.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBDIR)/$(LIB):
	make -C $(LIBDIR)

$(ASM): $(LIBDIR)/$(LIB) $(ASMOBJS)
	$(CC) $(CFLAGS) $(ASMOBJS) -L$(LIBDIR) -lft -o $@

$(VM): $(LIBDIR)/$(LIB) $(VMOBJS)
	$(CC) $(CFLAGS) $(VMOBJS) -L$(LIBDIR) -lft -o $@

clean:
	make -C $(LIBDIR) clean
	$(RM) $(ASMOBJS)
	$(RM) $(VMOBJS)

fclean: clean
	$(RM) $(LIBDIR)/$(LIB)
	$(RM) $(ASM)
	$(RM) $(VM)

re: fclean
	make
