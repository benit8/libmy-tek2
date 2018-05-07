##
## EPITECH PROJECT, 2018
## libmy
## File description:
## Makefile
##

PROJECT	=	Libmy UT
NAME	=	tests

SRC_DIR	=	sources/

OBJS	=	$(SRCS:.c=.o)

################################################################################

# ---------------------------------------------------------------------------- #
#  Modules                                                                     #
# ---------------------------------------------------------------------------- #

IOS	=	ios/iss.c			\


SRCS	+=	$(addprefix $(SRC_DIR),$(IOS))


################################################################################

CFLAGS	+=	-g3
CFLAGS	+=	-I../includes
CFLAGS	+=	-W -Wall -Wextra

LDFLAGS	+=	-L.. -lmy
LDFLAGS	+=	-lcriterion

################################################################################

SHELL	=	/bin/bash
PRINT	=	printf "$(PROJECT):  " ; printf
CC	=	gcc

RESET	=	\033[0m
RED	=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
MAGENTA	=	\033[0;35m
CYAN	=	\033[1;36m

################################################################################

all: $(NAME)

$(NAME): prebuild $(OBJS)
	@ $(PRINT) "$(YELLOW)Building project binary$(RESET)\n"
	@ $(PRINT) "  [  ]  $(BLUE)%b$(RESET)\\r" $(NAME)
	@ $(CC) -o $(NAME) $(OBJS) $(LDFLAGS) && \
	  ($(PRINT) "  [$(GREEN)OK$(RESET)]  $(CYAN)%b$(RESET)\n" $(NAME) ; exit 0) || \
	  ($(PRINT) "  [$(RED)XX$(RESET)]  $(CYAN)%b$(RESET)\n" $(NAME) ; exit 1)

prebuild:
	@ $(PRINT) "$(YELLOW)%b$(RESET)\n" "Compiling source files"

clean:
	@ $(PRINT) "$(YELLOW)%-40b$(RESET)" "Deleting object files"
	@ $(RM) $(OBJS)
	@ printf "$(GREEN)Done$(RESET)\n"

fclean: clean
	@ $(PRINT) "$(YELLOW)%-40b$(RESET)" "Deleting $(NAME)"
	@ $(RM) $(NAME)
	@ printf "$(GREEN)Done$(RESET)\n"

re: fclean all

.c.o:
	@ $(PRINT) "  [  ]  $(CYAN)%b$(RESET)\\r" $<
	@ $(CC) -c $< -o $@ $(CFLAGS) && \
	  ($(PRINT) "  [$(GREEN)OK$(RESET)]  $(CYAN)%b$(RESET)\n" $<) || \
	  ($(PRINT) "  [$(RED)XX$(RESET)]  $(CYAN)%b$(RESET)\n" $< ; exit 1)

.PHONY: all $(NAME) prebuild clean fclean re .c.o