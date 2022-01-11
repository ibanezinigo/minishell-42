CC=gcc
CFLAGS=-Wall -Werror -Wextra

minishell:
	gcc ./shell/ft_shell.c ./parser/ft_parser.c ./utils/*.c ./list/*.c  ./syntax/*.c ./lexer/*.c ./executor/*.c ./builtin/*.c  -o minishell -lreadline -Wall -Werror -Wextra
sanitize:
	gcc ./shell/ft_shell.c ./parser/ft_parser.c ./utils/*.c ./list/*.c  ./syntax/*.c ./lexer/*.c ./executor/*.c ./builtin/*.c  -o minishell -lreadline -Wall -Werror -Wextra -fsanitize=address -g3
.PHONY: