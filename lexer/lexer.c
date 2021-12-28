
#include "lexer.h"

//Separa un string en tokens
char	**ft_lexer(char *readl)
{
	struct s_tokens tokens;

	tokens.buff = readl;
	tokens.n_tokens = ft_count_tokens(readl);
	tokens.result = malloc(sizeof(char **) * tokens.n_tokens + 1);
	tokens.i = 0;
	while (tokens.i < tokens.n_tokens)
	{
		ft_get_next_token(&tokens);
		tokens.i = tokens.i + 1;
	}
	tokens.result[tokens.i] = NULL;
	return (tokens.result);
}
