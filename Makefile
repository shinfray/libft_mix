# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shinfray <shinfray@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 16:37:12 by shinfray          #+#    #+#              #
#    Updated: 2023/07/31 14:54:03 by shinfray         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                 CONFIG                                       #
################################################################################

.DELETE_ON_ERROR:
.SILENT:

NAME:=	libft.a

SRCS_DIR:= src
BUILD_DIR:= build
INC_DIRS:= include

CFLAGS= -std=c17 -Wall -Wextra -Werror -Wpedantic -pedantic-errors -O3

CFLAGS+=	-Wconversion \
			-Wdouble-promotion \
			-Wfloat-equal \
			-Wformat=2 \
			-Winit-self \
			-fno-common \
			-Wshadow \
			-Wundef \
			-Wunused-macros \
			-Wwrite-strings \
			-Wmissing-prototypes \
			-Wmissing-declarations \
			-Wstrict-prototypes
#			-Wcast-qual \
#			-Wpadded
#
#			gcc flags only
#			-Wformat-overflow \
#			-Wformat-truncation \
#			-Wlogical-op \
#			-Wformat-signedness \
#			-Wduplicated-cond \
#			-Wduplicated-branches \
#			-Walloc-zero

ARFLAGS:= crs

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

EXT:=	.c

FT_CTYPE_SRCS:=		ft_isalnum \
					ft_isalpha \
					ft_isascii \
					ft_isdigit \
					ft_isprint \
					ft_tolower \
					ft_toupper

FT_STDLIB_SRCS:=	ft_atoi \
					ft_calloc

FT_STRING_SRCS:=	ft_bzero \
					ft_memchr \
					ft_memcmp \
					ft_memcpy \
					ft_memmove \
					ft_memset \
					ft_strchr \
					ft_strdup \
					ft_strlcat \
					ft_strlcpy \
					ft_strlen \
					ft_strncmp \
					ft_strnstr \
					ft_strrchr 

LIBFT_SRCS:=		ft_itoa \
					ft_putchar_fd \
					ft_putendl_fd \
					ft_putnbr_fd \
					ft_putstr_fd \
					ft_split \
					ft_striteri \
					ft_strjoin \
					ft_strmapi \
					ft_strtrim \
					ft_substr

FT_LST_SRCS:=		ft_lstadd_back_bonus \
					ft_lstadd_front_bonus \
					ft_lstclear_bonus \
					ft_lstdelone_bonus \
					ft_lstiter_bonus \
					ft_lstlast_bonus \
					ft_lstmap_bonus \
					ft_lstnew_bonus \
					ft_lstsize_bonus

FT_PRINTF_SRCS:=	ft_printf \
					ft_printf_flags \
					ft_printf_hexa

GNL_SRCS:=			get_next_line_bonus \
					get_next_line_utils_bonus

################################################################################
#                                 FORMATING                                    #
################################################################################

SRCS=	${addprefix ${SRCS_DIR}/ft_ctype/,${addsuffix ${EXT},${FT_CTYPE_SRCS}}}
SRCS+=	${addprefix ${SRCS_DIR}/ft_stdlib/,${addsuffix ${EXT},${FT_STDLIB_SRCS}}}
SRCS+=	${addprefix ${SRCS_DIR}/ft_string/,${addsuffix ${EXT},${FT_STRING_SRCS}}}
SRCS+=	${addprefix ${SRCS_DIR}/libft/,${addsuffix ${EXT},${LIBFT_SRCS}}}
SRCS+=	${addprefix ${SRCS_DIR}/ft_lst/,${addsuffix ${EXT},${FT_LST_SRCS}}}
SRCS+=	${addprefix ${SRCS_DIR}/ft_printf/,${addsuffix ${EXT},${FT_PRINTF_SRCS}}}
SRCS+=	${addprefix ${SRCS_DIR}/get_next_line/,${addsuffix ${EXT},${GNL_SRCS}}}

OBJS_DIR:= ${BUILD_DIR}/objs
OBJS:=  ${SRCS:${SRCS_DIR}/%.c=${OBJS_DIR}/%.o}

DEPS_DIR:= ${BUILD_DIR}/deps
DEPS:=	${OBJS:${OBJS_DIR}/%.o=${DEPS_DIR}/%.d}

CPPFLAGS= ${addprefix -I,${INC_DIRS}} -MMD -MP -MF ${@:${OBJS_DIR}/%.o=${DEPS_DIR}/%.d}

RM:=	rm -rf

################################################################################
#                                 MAKEFILE RULES                               #
################################################################################

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${ARFLAGS} $@ ${OBJS}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	mkdir -p ${dir $@}
	mkdir -p ${dir ${@:${OBJS_DIR}/%.o=${DEPS_DIR}/%.d}}
	${CC} ${CPPFLAGS} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${BUILD_DIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

-include ${DEPS}
