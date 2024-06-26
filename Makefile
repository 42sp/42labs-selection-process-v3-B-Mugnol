# Program name
NAME	:=	monitoring

# GENERAL OPTIONS
# C Compiler
CC		:=	clang
# Compiler flags
CFLAGS	:=	-Wall -Wextra -Werror
# Removal tool
RM		:=	rm -rf


# PROGRAM
# Header that includes all headers
MASTER_HEADER := master.h
# Headers
HEADER_DIR	:=	inc
HEADER_DIR	+=	src/configuration	src/linked_list	src/utilities src/request
HEADER		:=	monitoring.h	define.h	protocol.h
HEADER		+=	ft_lst.h		cfg.h		utilities.h		request.h
H_INCLUDE	:=	$(addprefix -I, $(HEADER_DIR))

# Source
SRC_DIR		:=	src
SRC_DIR		+=	src/linked_list	src/utilities	src/configuration	src/request
# root
SRC			:=	main.c
SRC			+=	file_handler.c		parsing.c			verifier.c
# request
SRC			+=	request.c			request_http.c
# configuration
SRC			+=	cfg_create.c		cfg_delete.c		cfg_get.c
# utilities
SRC			+=	ft_split.c			ft_strlcpy.c		ft_substr.c			\
				count_lines.c		is_digit_str.c		ft_free_char_matrix.c
# linked_list
SRC			+=	ft_lstnew.c			ft_lstsize.c		ft_lstlast.c		\
				ft_lstadd_front.c	ft_lstadd_back.c	ft_lstdelone.c		\
				ft_lstclear.c		ft_lstiter.c		ft_lstmap.c

# Object
OBJ_DIR		:=	obj
OBJ			:=	$(SRC:%.c=$(OBJ_DIR)/%.o)

# Precompiled header
C_HEADER_DIR	:=	pch
C_HEADER		:=	$(MASTER_HEADER:%.h=$(C_HEADER_DIR)/%.h.gch)
C_INCLUDE		:=	$(addprefix -include-pch , $(C_HEADER))

# Libs
L_INCLUDE	:=	#$(shell curl-config --cflags) $(shell curl-config --libs)

# Inclusions:
INCLUDE		:=	$(C_INCLUDE) $(H_INCLUDE) $(L_INCLUDE)

# vpath
vpath	%.h		$(HEADER_DIR)
vpath	%.h.gch	$(C_HEADER_DIR)
vpath	%.c		$(SRC_DIR)

# -----------------------RULES------------------------------------------------ #
.PHONY: all clean fclean re

# Creates NAME
all: $(NAME)

# Compiles OBJ into the program NAME
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(INCLUDE)

# Compiles SRC into OBJ
$(OBJ): $(OBJ_DIR)/%.o: %.c $(C_HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

# Header precompiling
$(C_HEADER): $(C_HEADER_DIR)/%.h.gch: %.h $(HEADER) | $(C_HEADER_DIR)
	$(CC) $(CFLAGS) -o $@ $< $(H_INCLUDE)

# Directory making
$(OBJ_DIR) $(C_HEADER_DIR):
	@mkdir -p $@

# Clean: removes objects' and precompiled headers' directories
clean:
	@$(RM) $(OBJ_DIR) $(C_HEADER_DIR)

# Full clean: same as 'clean', but removes the generated libs/programs as well
fclean: clean
	@$(RM) $(NAME)

# Remake: full cleans and runs 'all' rule
re: fclean all
