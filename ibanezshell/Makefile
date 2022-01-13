CC=gcc
CFLAGS=-Wall -Werror -Wextra

minishell:
	gcc ./shell/ft_shell.c ./parser/ft_parser.c ./utils/*.c ./list/*.c  ./syntax/*.c ./lexer/*.c ./executor/*.c ./builtin/*.c  -o minishell  -lreadline -Wall -Werror -Wextra -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include
sanitize:
	gcc ./shell/ft_shell.c ./parser/ft_parser.c ./utils/*.c ./list/*.c  ./syntax/*.c ./lexer/*.c ./executor/*.c ./builtin/*.c  -o minishell -lreadline  -fsanitize=address -g3 -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include
.PHONY: