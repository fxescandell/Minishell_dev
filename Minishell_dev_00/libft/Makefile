NAME        := libft.a
BUILD_DIR   := build
SRC_DIR		:= src
INC_DIR		:= include

# ***************************   Colores   ************************************ #
# **************************************************************************** #

DEF_COLOR   = \033[0;39m
GREEN       = \033[0;92m
RED         = \033[0;91m
BLUE        = \033[0;94m
CYAN        = \033[0;96m

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#

SRCS        := 	ft_isalpha.c ft_isdigit.c ft_isalnum.c\
				ft_isascii.c ft_isprint.c ft_strlen.c\
				ft_memset.c ft_bzero.c ft_memcpy.c\
				ft_memmove.c ft_strlcpy.c ft_strlcat.c\
				ft_toupper.c ft_tolower.c ft_strchr.c\
				ft_strrchr.c ft_strncmp.c ft_strcmp.c ft_memchr.c\
				ft_memcmp.c ft_strnstr.c ft_atoi.c\
				ft_calloc.c ft_strdup.c ft_substr.c\
				ft_strjoin.c ft_strtrim.c ft_split.c\
				ft_itoa.c ft_strmapi.c ft_striteri.c\
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
				ft_lstmap.c

# Archivos de ft_printf
SRCS_PRINTF	:=	printf/ft_printf.c printf/ft_printf_utils_1.c printf/ft_printf_utils_2.c

# Archivos de get_next_line (versión bonus para múltiples FD)
SRCS_GNL	:=	gnl/get_next_line.c gnl/get_next_line_utils.c

# Rutas completas
SRC_FILES	= $(addprefix $(SRC_DIR)/, $(SRCS))

OBJS		:= $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
OBJS_PRINTF	:= $(addprefix $(BUILD_DIR)/, $(SRCS_PRINTF:.c=.o))
OBJS_GNL	:= $(addprefix $(BUILD_DIR)/, $(SRCS_GNL:.c=.o))
ALL_OBJS	:= $(OBJS) $(OBJS_PRINTF) $(OBJS_GNL)

CC          := clang
CFLAGS      := -Wall -Wextra -Werror
INCLUDES	:= -I$(INC_DIR)

RM          := rm -f
MAKEFLAGS	:= --no-print-directory

# Progress variables
TOTAL_OBJS  := $(words $(ALL_OBJS))
PROGRESS_FILE := .build_progress

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#

all: $(NAME)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR)/printf
	@mkdir -p $(BUILD_DIR)/gnl

$(NAME): $(ALL_OBJS)
	@ar rcs $(NAME) $(ALL_OBJS)
	@rm -f $(PROGRESS_FILE)
	@printf "\n"
	@echo "${GREEN} ✓ Libft library created successfully!${DEF_COLOR}"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/libft.h Makefile | $(BUILD_DIR)
	@if [ ! -f $(PROGRESS_FILE) ]; then echo "0" > $(PROGRESS_FILE); fi
	@N=$$(cat $(PROGRESS_FILE)); N=$$((N + 1)); echo $$N > $(PROGRESS_FILE); \
	PERCENT=$$((N * 100 / $(TOTAL_OBJS))); \
	if [ $$N -eq $(TOTAL_OBJS) ]; then \
		printf "\r${CYAN}📚 Libft [██████████████████████████████████████████████████] 100%%${DEF_COLOR}                    "; \
	else \
		BAR_LEN=$$((PERCENT / 2)); \
		EMPTY_LEN=$$((50 - BAR_LEN)); \
		printf "\r${CYAN}📚 Libft ["; \
		i=0; while [ $$i -lt $$BAR_LEN ]; do printf "█"; i=$$((i + 1)); done; \
		i=0; while [ $$i -lt $$EMPTY_LEN ]; do printf "░"; i=$$((i + 1)); done; \
		printf "] %3d%% (%d/%d)${DEF_COLOR}" $$PERCENT $$N $(TOTAL_OBJS); \
	fi
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) -r $(BUILD_DIR) 2>/dev/null || true
	@rm -f $(PROGRESS_FILE)

fclean: clean
	@$(RM) $(NAME) 2>/dev/null || true
	@echo " ● Libft build directory removed."

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
