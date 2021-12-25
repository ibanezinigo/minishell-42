CC=gcc
CFLAGS=-Wall -Werror -Wextra
t_lexer_c: 
	$(CC) $(CFLAGS) ./test/test_lexer_count_tokens.c ./lexer/lexer_count_tokens.c ./utils/utils.c ./utils/utils.h
t_lexer: 
	$(CC) $(CFLAGS ) ./test/test_lexer.c ./lexer/lexer.c ./lexer/lexer_count_tokens.c  ./lexer/lexer_get_tokens.c ./utils/utils.c ./utils/utils.h
.PHONY: