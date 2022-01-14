NAME = minishell

CC=gcc

CFLAGS= -fsanitize=address -g3

BUILTIN = ft_cd ft_echo ft_env ft_exit ft_export ft_pwd ft_unset

EXECUTOR = ft_executor_utils ft_executor ft_input ft_output ft_dup

LEXER = lexer_count_tokens lexer_get_tokens_aux lexer_get_tokens lexer

LIST = list_utils list

PARSER = ft_parser

SHEL = ft_shell

SYNTAX = ft_syntaxchecker

UTILS = ft_itoa ft_split ft_utils ft_utils2 ft_utils3 ft_utils4 ft_utils5

SRC = $(addsuffix .c, $(addprefix builtin/, $(BUILTIN))) \
	  $(addsuffix .c, $(addprefix executor/, $(EXECUTOR))) \
	  $(addsuffix .c, $(addprefix lexer/, $(LEXER))) \
	  $(addsuffix .c, $(addprefix list/, $(LIST))) \
	  $(addsuffix .c, $(addprefix parser/, $(PARSER))) \
	  $(addsuffix .c, $(addprefix shel/, $(SHEL))) \
	  $(addsuffix .c, $(addprefix syntax/, $(SYNTAX))) \
	  $(addsuffix .c, $(addprefix utils/, $(UTILS))) \

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lreadline -L ~/.brew/opt/readline/lib 

%.o: %.c
		@${CC} ${CFLAGS} -I ~/.brew/opt/readline/include -I /System/Volumes/Data/sgoinfre/goinfre/Perso/iibanez-/Cursus/3/minishell2/includes -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)

re: fclean all

sanitize:
	gcc ./shell/ft_shell.c ./parser/ft_parser.c ./utils/*.c ./list/*.c  ./syntax/*.c ./lexer/*.c ./executor/*.c ./builtin/*.c  -o minishell -lreadline  -fsanitize=address -g3 -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include
.PHONY: