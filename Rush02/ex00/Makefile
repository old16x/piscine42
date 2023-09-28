NAME		=	rush-02

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3

SRCS		=	main.c \
				parsing/parse_file.c \
				parsing/parse_string.c \
				print_nbr/print_nbr.c \
				print_nbr/search_in_dictionary.c \
				utils/char_type.c \
				utils/dict.c \
				utils/error.c \
				utils/node.c \
				utils/print.c \
				utils/string.c \
				utils/string_alloc.c \
				utils/strs_linked_list.c \

OBJS_FOLDER	=	objects
OBJS		=	$(addprefix $(OBJS_FOLDER)/,$(SRCS:.c=.o))

HEADERS		=	headers

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(NAME) has been successfully created."

$(OBJS_FOLDER)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(HEADERS) -c -o $@ $<

valgrind: $(NAME)
	@valgrind --leak-check=full --track-origins=yes ./$(NAME) $(ARGS1) $(ARGS2)


clean:
	@rm -rf $(OBJS_FOLDER)
	@echo "object files and directories have been removed."

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) and object files have been removed."

re: fclean all
