##
## EPITECH PROJECT, 2018
## libmy
## File description:
## Makefile
##

PROJECT	=	Libmy
NAME	=	libmy.a

SRC_DIR	=	sources/

OBJS	=	$(SRCS:.c=.o)

################################################################################

CFLAGS	+=	-Iincludes
CFLAGS	+=	-W -Wall -Wextra

LDFLAGS	+=	-lm

################################################################################

SHELL	=	/bin/bash
PRINT	=	printf "$(PROJECT):\t" ; printf

RESET	=	\033[0m
RED	=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
MAGENTA	=	\033[0;35m
CYAN	=	\033[1;36m

################################################################################

# ---------------------------------------------------------------------------- #
#  Modules                                                                     #
# ---------------------------------------------------------------------------- #

DSA	=	dsa/list/access.c		\
		dsa/list/capacity.c		\
		dsa/list/list.c			\
		dsa/list/modifiers.c		\
		dsa/list/modifiers_pushpop.c	\
		dsa/list/operations.c		\
		dsa/map/access.c		\
		dsa/map/capacity.c		\
		dsa/map/map.c			\
		dsa/map/modifiers.c		\
		dsa/map/operations.c		\
		dsa/queue/access.c		\
		dsa/queue/capacity.c		\
		dsa/queue/modifiers.c		\
		dsa/queue/queue.c		\
		dsa/stack/access.c		\
		dsa/stack/capacity.c		\
		dsa/stack/modifiers.c		\
		dsa/stack/stack.c

FS	=	fs/file_get_contents.c		\
		fs/file_get_lines.c		\
		fs/file_is.c			\
		fs/file_put_contents.c		\
		fs/filesize.c			\
		fs/is_file.c

IOS	=	ios/iss/ignore.c		\
		ios/iss/is_good.c		\
		ios/iss/iss.c			\
		ios/iss/read_bool.c		\
		ios/iss/read_char.c		\
		ios/iss/read_delim.c		\
		ios/iss/read_float.c		\
		ios/iss/read_int.c		\
		ios/iss/read_llong.c		\
		ios/iss/read_long.c		\
		ios/iss/read_short.c

Log	=	log/data.c			\
		log/file.c			\
		log/level.c			\
		log/loggers.c			\
		log/program_name.c		\
		log/write.c

Regex	=	regex/capture.c			\
		regex/create.c			\
		regex/match.c			\
		regex/replace.c			\
		regex/split.c

String	=	string/explode.c		\
		string/implode.c		\
		string/str_empty.c		\
		string/str_pad.c		\
		string/str_repeat.c		\
		string/str_tolower.c		\
		string/str_toupper.c		\
		string/str_trim.c


SRCS	+=	$(addprefix $(SRC_DIR),$(DSA))
SRCS	+=	$(addprefix $(SRC_DIR),$(FS))
SRCS	+=	$(addprefix $(SRC_DIR),$(IOS))
SRCS	+=	$(addprefix $(SRC_DIR),$(Log))
SRCS	+=	$(addprefix $(SRC_DIR),$(Regex))
SRCS	+=	$(addprefix $(SRC_DIR),$(String))


################################################################################

all: $(NAME)

debug: CFLAGS += -g3
debug: $(NAME)

$(NAME): prebuild $(OBJS)
	@ $(PRINT) "$(YELLOW)Building project binary$(RESET)\n"
	@ $(PRINT) "  [  ]  $(BLUE)%b$(RESET)\\r" $(NAME)
	@ (ar rc $(NAME) $(OBJS) && ranlib $(NAME)) && \
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
de: fclean debug

.c.o:
	@ $(PRINT) "  [  ]  $(CYAN)%b$(RESET)\\r" $<
	@ $(CC) -c $< -o $@ $(CFLAGS) && \
	  ($(PRINT) "  [$(GREEN)OK$(RESET)]  $(CYAN)%b$(RESET)\n" $<) || \
	  ($(PRINT) "  [$(RED)XX$(RESET)]  $(CYAN)%b$(RESET)\n" $< ; exit 1)

.PHONY: all debug $(NAME) prebuild clean fclean re de .c.o