CC=gcc
CFLAGS=-Wall -Werror -Wextra

minishell:
	gcc executor/*.c lexer/*.c shell/*.c utils/*.c list/*.c  parser/*.c -o minishell -lreadline -fsanitize=address -g3
t_lexer_c: 
	$(CC) $(CFLAGS) ./test/test_lexer_count_tokens.c ./lexer/lexer_count_tokens.c ./utils/utils.c ./utils/utils.h
t_lexer: 
	$(CC) $(CFLAGS ) ./test/test_lexer.c ./lexer/lexer.c ./lexer/lexer_count_tokens.c  ./lexer/lexer_get_tokens.c ./utils/utils.c ./utils/utils.h
.PHONY: