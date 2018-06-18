##
## EPITECH PROJECT, 2018
## libmy
## File description:
## Makefile
##

PROJECT	=	Libmy
NAME	=	libmy.a

SRC_DIR	=	sources/

# ---------------------------------------------------------------------------- #
#  Modules                                                                     #
# ---------------------------------------------------------------------------- #

DSA	=	dsa/circular_buffer/capacity.c				\
		dsa/circular_buffer/circular_buffer.c			\
		dsa/circular_buffer/modifiers.c				\
		dsa/circular_buffer/modifiers_advanced.c		\
		dsa/list/access.c					\
		dsa/list/capacity.c					\
		dsa/list/list.c						\
		dsa/list/modifiers.c					\
		dsa/list/modifiers_pushpop.c				\
		dsa/list/operations.c					\
		dsa/map/access.c					\
		dsa/map/capacity.c					\
		dsa/map/map.c						\
		dsa/map/modifiers.c					\
		dsa/map/operations.c					\
		dsa/queue/access.c					\
		dsa/queue/capacity.c					\
		dsa/queue/modifiers.c					\
		dsa/queue/queue.c					\
		dsa/stack/access.c					\
		dsa/stack/capacity.c					\
		dsa/stack/modifiers.c					\
		dsa/stack/stack.c

FS	=	fs/file_get_contents.c					\
		fs/file_get_lines.c					\
		fs/file_is.c						\
		fs/file_put_contents.c					\
		fs/filesize.c						\
		fs/is_file.c

IOS	=	ios/iss/ignore.c					\
		ios/iss/is_good.c					\
		ios/iss/iss.c						\
		ios/iss/offset.c					\
		ios/iss/read.c						\
		ios/iss/read_bool.c					\
		ios/iss/read_char.c					\
		ios/iss/read_delim.c					\
		ios/iss/read_float.c					\
		ios/iss/read_int.c					\
		ios/iss/read_long.c					\
		ios/iss/read_short.c					\
		ios/iss/read_size.c					\
		ios/oss/offset.c					\
		ios/oss/oss.c						\
		ios/oss/str.c						\
		ios/oss/write.c						\
		ios/oss/write_bool.c					\
		ios/oss/write_char.c					\
		ios/oss/write_float.c					\
		ios/oss/write_int.c					\
		ios/oss/write_long.c					\
		ios/oss/write_short.c					\
		ios/oss/write_size.c

Log	=	log/data.c						\
		log/file.c						\
		log/level.c						\
		log/loggers.c						\
		log/program_name.c					\
		log/write.c

Regex	=	regex/capture.c						\
		regex/create.c						\
		regex/match.c						\
		regex/replace.c						\
		regex/split.c

String	=	string/explode.c					\
		string/implode.c					\
		string/str_empty.c					\
		string/str_pad.c					\
		string/str_repeat.c					\
		string/str_tolower.c					\
		string/str_toupper.c					\
		string/str_trim.c


SRCS	+=	$(addprefix $(SRC_DIR),$(DSA))
SRCS	+=	$(addprefix $(SRC_DIR),$(FS))
SRCS	+=	$(addprefix $(SRC_DIR),$(IOS))
SRCS	+=	$(addprefix $(SRC_DIR),$(Log))
SRCS	+=	$(addprefix $(SRC_DIR),$(Regex))
SRCS	+=	$(addprefix $(SRC_DIR),$(String))


################################################################################

include ./utils.make