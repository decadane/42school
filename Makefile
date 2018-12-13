# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 15:46:51 by marvin            #+#    #+#              #
#    Updated: 2018/12/13 15:54:51 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

compile_flags = -Wall -Wextra -Werror

NAME := fillit
source_dirs  := srcs
lib_dirs := includes libft
lib_obj := libft/*.o

search_wildcards := $(addsuffix /*.c,$(source_dirs))
#lib_wildcards := $(addsuffix /*.h,$(lib_dirs))

all: $(NAME)

$(NAME): $(notdir $(patsubst %.c,%.o,$(wildcard $(search_wildcards)))) $(lib_obj)
	gcc $^ -o $@ 

VPATH := $(source_dirs) 

%.o: %.c
	gcc -c -MD $(flags) $(compile_flags) $(addprefix -I,$(source_dirs)) $< $(addprefix -I,$(lib_dirs))

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f *.d

re: fclean all

.PHONY: all clean fclean re

include $(wildcard *.d) 
