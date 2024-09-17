##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

##########################
###	   INFO PROGRAM    ###
##########################

# COMPILER
CC = gcc
AR = ar rc

# BINARY NAME
NAME = libmy.a

# HEADER FILE NAME
HEADER_FILE = includes/lib.h

#CFLAGS
CFLAGS = -g3 -c

# CONVERT *.c => *.o
OFILES = $(CFILES:.c=.o)

# C PROGRAM FILES
CFILES = my_clean_str.c \
		my_putchar.c \
		my_putnbr.c \
		my_putstr.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strdup.c \
		my_strlen.c \
		my_strncmp.c \
		my_swap_16bytes.c \
		my_swap_32bytes.c \
		my_tablen.c \
		my_freetab.c \
		my_str_to_word_array.c \
		my_isalpha.c \
		my_splitstr.c \
		my_findinstr.c \
		my_isnumber.c \
		my_isuppercase.c \
		my_islowercase.c \
		my_strcontains.c \
		my_charcontains.c \
		my_puttab.c \
		my_getnbr.c \
		my_replace_char.c \
		my_putstr_02x.c \
		my_strtol.c


#################################
###	   PROGRAM COMPILATION    ###
#################################

# ALL
all: $(NAME) copy_lib

# COMPILATION FILES
$(NAME): $(OFILES)
	@$(AR) $(NAME) $(OFILES)

# TRAITER EACH FILES
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ $< && \
	echo -e " $(CYAN)=> $(BLUE_BOLD)Compiling with debug\t$(CYAN)$<   \
	$(GREEN_BOLD)[OK]$(NC)" \
	|| echo -e "\n$(RED_BACKGROUND)ERROR COMPILATION$(NC)\t\t$(ORANGE)$<   \
	$(RED)[ERROR]$(NC)\n"

# COPY LIB, LIB.H
copy_lib: $(HEADER_FILE) $(NAME)
	@cp $(HEADER_FILE) ../includes/
	@cp $(NAME) ../

# CLEAN
clean:
	@for obj in $(OFILES); do	\
        echo -e " $(PINK_BOLD)=> $(WHITE_BOLD)Lib clean\t\t\t$(PINK)$$obj   \
		$(GREEN_BOLD)[OK]$(NC)";	\
        rm -f $$obj;	\
    done

# FCLEAN
fclean: clean
	@rm -rf $(NAME)

# RE
re: fclean all

#####   .PHONY   ###
.PHONY: all copy_lib clean fclean re
####################


###########################
###	   PROGRAM STYLE    ###
###########################

RED = \033[31m
GREEN = \033[32m
BLUE = \033[34m
CYAN = \033[36m
WHITE = \033[37m
ORANGE = \033[0;33m
PINK = \033[95m
NC = \033[0m
GREEN_BOLD = \033[1;32m
BLUE_BOLD = \033[1;34m
WHITE_BOLD = \033[1;37m
PINK_BOLD = \033[1;95m
RED_BACKGROUND = \033[41m
