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

# BINARY NAME
NAME = corewar

#CFLAGS
CFLAGS = -g3 -Wall

# LIBRARY BINARY NAME
LIB_NAME = libmy.a

# CONVERT *.c => *.o
OFILES = $(CFILES:.c=.o)

# C PROGRAM FILES
CFILES = 	main.c \
			src/ass_function/add.c \
			src/ass_function/aff.c \
			src/ass_function/and.c \
			src/ass_function/fork.c \
			src/ass_function/ld.c \
			src/ass_function/ldi.c \
			src/ass_function/lfork.c \
			src/ass_function/live.c \
			src/ass_function/lld.c \
			src/ass_function/lldi.c \
			src/ass_function/or.c \
			src/ass_function/st.c \
			src/ass_function/sti.c \
			src/ass_function/sub.c \
			src/ass_function/xor.c \
			src/ass_function/zjmp.c \
			src/ass_function/attack.c \
			src/parsing.c \
			src/parsing_robot/init_robot.c \
			src/parsing_robot/parsing_robot.c \
			src/parsing_robot/parsing_info_robot.c \
			src/parsing_robot/parsing_option_flag.c \
			src/parsing_robot/handle_option_flag.c \
			src/parsing_robot/loop_instructions_robot.c \
			src/map.c \
			src/convert_hexa_to_bin.c \
			src/convert_hexa_to_decimal.c \
			src/convert_decimal_to_bin.c \
			src/split_binary_string.c \
			src/define_content_codingbytes.c \
			src/convert_bin_to_decimal.c


#################################
###	   PROGRAM COMPILATION    ###
#################################

# ALL
all: author	\
	lib_compilation	\
	warning_compilation \
	$(NAME)	\
	warning_binary_name \

# AUTHOR DESCRIPTION
author:
	@echo -e "\n\
	 $(WHITE_BOLD)---------------------------------\n\
	 |                               |\n\
	 |  MAKEFILE MADE BY => L3yser   |\n\
	 |     Github: L3yserEpitech     |\n\
	 |                               |\n\
	 ---------------------------------\n$(NC)"

# LIB COMPILATION
lib_compilation:
	@echo -e "$(BLUE_BACKGROUND)  >> LIB COMPILATION <<  $(NC)"
	@make --no-print-directory -C basics

# WARNING TEXT COMPILATION
warning_compilation:
	@echo -e "\n$(BLUE_BACKGROUND)  >> PROGRAM COMPILATION <<  $(NC)"

# COMPILATION FILES
$(NAME): $(OFILES)
	@$(CC) -o $(NAME) $(OFILES) $(LIB_NAME)

# TRAITER EACH FILES
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< && \
	echo -e " $(CYAN_BOLD)=> $(BLUE_BOLD)Compiling with debug\t$(CYAN)$<   \
	$(GREEN_BOLD)[OK]$(NC)" \
	|| echo -e "\n$(RED_BACKGROUND)ERROR COMPILATION$(NC)\t$(ORANGE)$<   \
	$(RED)[ERROR]$(NC)\n"

# WARNING COMPILATION IS FINISH WITH THE BINARY NAME
warning_binary_name:
	@echo -e "\n$(GREEN_BACKGROUND) $(BLACK)COMPILED PROGRAM =>>> $(NAME)$(NC)"

# CLEAN OFILES, VGCORE, CLEAN LIBRARY OFILES
clean:
	@echo -e "\n$(BLUE_BACKGROUND)  >> CLEAN <<  $(NC)"
	@for obj in $(OFILES); do	\
        echo -e " $(PINK_BOLD)=> $(WHITE_BOLD)Program clean\t\t$(PINK)$$obj   \
		$(GREEN_BOLD)[OK]$(NC)";	\
        rm -f $$obj;	\
    done
	@make --no-print-directory clean -C basics
	@rm -f vgcore.* $(OBJ) *.gch

# FCLEAN PROGRAM, LIBRARY
fclean: clean
	@rm -rf $(LIB_NAME)
	@echo -e " $(PINK_BOLD)=> $(WHITE_BOLD)Remove lib binary\t\t$(PINK)\
	$(LIB_NAME)   $(GREEN_BOLD)[OK]$(NC)"
	@$(clean) rm -f $(NAME)
	@make --no-print-directory fclean -C basics
	@echo -e " $(PINK_BOLD)=> $(WHITE_BOLD)Remove program binary\t\
	$(PINK)$(LIB_NAME)   $(GREEN_BOLD)[OK]$(NC)"

# MAKE RE
re: fclean all

#####   .PHONY   ###
.PHONY : 	all author lib_compilation warning_compilation \
			warning_binary_name clen fclean re
####################


###########################
###	   PROGRAM STYLE    ###
###########################

RED_BACKGROUND = \033[41m
GREEN_BACKGROUND = \033[42m
BLUE_BACKGROUND = \033[44m
BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
ORANGE = \033[0;33m
PINK = \033[95m
NC = \033[0m
GREEN_BOLD = \033[1;32m
BLUE_BOLD = \033[1;34m
CYAN_BOLD = \033[1;36m
WHITE_BOLD = \033[1;37m
PINK_BOLD = \033[1;95m
