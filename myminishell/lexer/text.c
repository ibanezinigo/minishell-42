/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 14:50:28 by ingonzal          #+#    #+#             */
/*   Updated: 2022/01/04 15:00:25 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"
#include "../../lexer/lexer.h"


int	main(void)
{
	printf("Testing tokens counting:\n");

	//BASIC TEST
	printf("Basics test:\n");

	char 	t10[] = "1";
	char	**t10r = ft_lexer(t10);
	if (ft_strequals(t10r[0],"1"))
		printf("1.0 Ok\n");
	else
		printf("1.0 Error \n");

	char 	t11[] = "1 2 3 4 ";
	char	**t11r = ft_lexer(t11);
	if (ft_strequals(t11r[0],"1") && ft_strequals(t11r[1],"2") && ft_strequals(t11r[2],"3") && ft_strequals(t11r[3],"4"))
		printf("1.1 Ok\n");
	else
		printf("1.1 Error \n");

	printf("Quoting tests\n");

	char 	t20[] = "\"1\" 2 3 4 ";
	char	**t20r = ft_lexer(t20);

	if (ft_strequals(t20r[0],"1") && ft_strequals(t20r[1],"2") && ft_strequals(t20r[2],"3") && ft_strequals(t20r[3],"4"))
		printf("2.0 Ok\n");
	else
		printf("2.0 Error \n");

	char 	t21[] = "\"1\"2 3 4 ";
	char	**t21r = ft_lexer(t21);
	if (ft_strequals(t21r[0],"12") && ft_strequals(t21r[1],"3") && ft_strequals(t21r[2],"4"))
		printf("2.1 Ok\n");
	else
		printf("2.1 Error \n");

	char 	t22[] = "\"1\"\"2\" 3 4 ";
	char	**t22r = ft_lexer(t22);
	if (ft_strequals(t22r[0],"12") && ft_strequals(t22r[1],"3") && ft_strequals(t22r[2],"4"))
		printf("2.2 Ok\n");
	else
		printf("2.2 Error \n");

	char 	t23[] = "\"'1\"\"2'\" 3 4 ";
	char	**t23r = ft_lexer(t23);
	if (ft_strequals(t23r[0],"'12'") && ft_strequals(t23r[1],"3") && ft_strequals(t23r[2],"4"))
		printf("2.3 Ok\n");
	else
		printf("2.3 Error \n");


	char 	t24[] = "\'\"1\"\"2' 3 4 ";
	char	**t24r = ft_lexer(t24);
	if (ft_strequals(t24r[0],"\"1\"\"2") && ft_strequals(t24r[1],"3") && ft_strequals(t24r[2],"4"))
		printf("2.3 Ok\n");
	else
		printf("2.3 Error \n");

	// < << > >> testing
	printf("> < >> << test\n");
	char 	t30[] = "1 > 3";
	char	**t30r = ft_lexer(t30);
	if (ft_strequals(t30r[0],"1") && ft_strequals(t30r[1],">") && ft_strequals(t30r[2],"3"))
		printf("3.0 Ok\n");
	else
		printf("3.0 Error \n");

	char 	t31[] = "1>>3 ";
	char	**t31r = ft_lexer(t31);
	if (ft_strequals(t31r[0],"1") && ft_strequals(t31r[1],">>") && ft_strequals(t31r[2],"3"))
		printf("3.1 Ok\n");
	else
		printf("3.1 Error \n");

	char 	t32[] = "1 < 3 ";
	char	**t32r = ft_lexer(t32);
	if (ft_strequals(t32r[0],"1") && ft_strequals(t32r[1],"<") && ft_strequals(t32r[2],"3"))
		printf("3.2 Ok\n");
	else
		printf("3.2 Error \n");

	char 	t33[] = "1<<3 ";
	char	**t33r = ft_lexer(t33);
	if (ft_strequals(t33r[0],"1") && ft_strequals(t33r[1],"<<") && ft_strequals(t33r[2],"3"))
		printf("3.3 Ok\n");
	else
		printf("3.3 Error \n");

	// | || & && testing
	printf("| || & && testing\n");
	char 	t40[] = "1 2  | 4 5";
	char	**t40r = ft_lexer(t40);
	if (ft_strequals(t40r[0],"1") && ft_strequals(t40r[1],"2") && ft_strequals(t40r[2],"|") && ft_strequals(t40r[3],"4") && ft_strequals(t40r[4],"5"))
		printf("4.0 Ok\n");
	else
		printf("4.0 Error \n");

	char 	t41[] = "1 2|4 5";
	char	**t41r = ft_lexer(t41);
	if (ft_strequals(t41r[0],"1") && ft_strequals(t41r[1],"2") && ft_strequals(t41r[2],"|") && ft_strequals(t41r[3],"4") && ft_strequals(t41r[4],"5"))
		printf("4.1 Ok\n");
	else
		printf("4.1 Error \n");

	char 	t42[] = "1 2  || 4 5";
	char	**t42r = ft_lexer(t42);
	if (ft_strequals(t42r[0],"1") && ft_strequals(t42r[1],"2") && ft_strequals(t42r[2],"||") && ft_strequals(t42r[3],"4") && ft_strequals(t42r[4],"5"))
		printf("4.2 Ok\n");
	else
		printf("4.2 Error \n");

	char 	t43[] = "1 2&4 5";
	char	**t43r = ft_lexer(t43);
	if (ft_strequals(t43r[0],"1") && ft_strequals(t43r[1],"2") && ft_strequals(t43r[2],"&") && ft_strequals(t43r[3],"4") && ft_strequals(t43r[4],"5"))
		printf("4.3 Ok\n");
	else
		printf("4.3 Error \n");

	char 	t44[] = "1 2&&4 5";
	char	**t44r = ft_lexer(t44);
	if (ft_strequals(t44r[0],"1") && ft_strequals(t44r[1],"2") && ft_strequals(t44r[2],"&&") && ft_strequals(t44r[3],"4") && ft_strequals(t44r[4],"5"))
		printf("4.4 Ok\n");
	else
		printf("4.4 Error \n");


	//Advanced testing
	printf("Advanced Testing\n");
	char 	t50[] = "ls -al a* | grep me > file1";
	char	**t50r = ft_lexer(t50);
	if (ft_strequals(t50r[0],"ls") && ft_strequals(t50r[1],"-al") && ft_strequals(t50r[2],"a*") && ft_strequals(t50r[3],"|") && ft_strequals(t50r[4],"grep") && ft_strequals(t50r[5],"me") && ft_strequals(t50r[6],">") && ft_strequals(t50r[7],"file1"))
		printf("5.0 Ok\n");
	else
		printf("5.0 Error \n");

	system("leaks a.out");
/*
	char 	t16[] = "/bin/ls";
	int		t16r = 1;
	if (ft_count_tokens(t16) != t16r)
int	main(void)
{
	printf("Testing tokens counting:\n");

	//BASIC TEST
	printf("Basics test:\n");

	char 	t10[] = "1";
	char	**t10r = ft_lexer(t10);
	if (ft_strequals(t10r[0],"1"))
		printf("1.0 Ok\n");
	else
		printf("1.0 Error \n");

	char 	t11[] = "1 2 3 4 ";
	char	**t11r = ft_lexer(t11);
	if (ft_strequals(t11r[0],"1") && ft_strequals(t11r[1],"2") && ft_strequals(t11r[2],"3") && ft_strequals(t11r[3],"4"))
		printf("1.1 Ok\n");
	else
		printf("1.1 Error \n");

	printf("Quoting tests\n");

	char 	t20[] = "\"1\" 2 3 4 ";
	char	**t20r = ft_lexer(t20);

	if (ft_strequals(t20r[0],"1") && ft_strequals(t20r[1],"2") && ft_strequals(t20r[2],"3") && ft_strequals(t20r[3],"4"))
		printf("2.0 Ok\n");
	else
		printf("2.0 Error \n");

	char 	t21[] = "\"1\"2 3 4 ";
	char	**t21r = ft_lexer(t21);
	if (ft_strequals(t21r[0],"12") && ft_strequals(t21r[1],"3") && ft_strequals(t21r[2],"4"))
		printf("2.1 Ok\n");
	else
		printf("2.1 Error \n");

	char 	t22[] = "\"1\"\"2\" 3 4 ";
	char	**t22r = ft_lexer(t22);
	if (ft_strequals(t22r[0],"12") && ft_strequals(t22r[1],"3") && ft_strequals(t22r[2],"4"))
		printf("2.2 Ok\n");
	else
		printf("2.2 Error \n");

	char 	t23[] = "\"'1\"\"2'\" 3 4 ";
	char	**t23r = ft_lexer(t23);
	if (ft_strequals(t23r[0],"'12'") && ft_strequals(t23r[1],"3") && ft_strequals(t23r[2],"4"))
		printf("2.3 Ok\n");
	else
		printf("2.3 Error \n");


	char 	t24[] = "\'\"1\"\"2' 3 4 ";
	char	**t24r = ft_lexer(t24);
	if (ft_strequals(t24r[0],"\"1\"\"2") && ft_strequals(t24r[1],"3") && ft_strequals(t24r[2],"4"))
		printf("2.3 Ok\n");
	else
		printf("2.3 Error \n");

	// < << > >> testing
	printf("> < >> << test\n");
	char 	t30[] = "1 > 3";
	char	**t30r = ft_lexer(t30);
	if (ft_strequals(t30r[0],"1") && ft_strequals(t30r[1],">") && ft_strequals(t30r[2],"3"))
		printf("3.0 Ok\n");
	else
		printf("3.0 Error \n");

	char 	t31[] = "1>>3 ";
	char	**t31r = ft_lexer(t31);
	if (ft_strequals(t31r[0],"1") && ft_strequals(t31r[1],">>") && ft_strequals(t31r[2],"3"))
		printf("3.1 Ok\n");
	else
		printf("3.1 Error \n");

	char 	t32[] = "1 < 3 ";
	char	**t32r = ft_lexer(t32);
	if (ft_strequals(t32r[0],"1") && ft_strequals(t32r[1],"<") && ft_strequals(t32r[2],"3"))
		printf("3.2 Ok\n");
	else
		printf("3.2 Error \n");

	char 	t33[] = "1<<3 ";
	char	**t33r = ft_lexer(t33);
	if (ft_strequals(t33r[0],"1") && ft_strequals(t33r[1],"<<") && ft_strequals(t33r[2],"3"))
		printf("3.3 Ok\n");
	else
		printf("3.3 Error \n");

	// | || & && testing
	printf("| || & && testing\n");
	char 	t40[] = "1 2  | 4 5";
	char	**t40r = ft_lexer(t40);
	if (ft_strequals(t40r[0],"1") && ft_strequals(t40r[1],"2") && ft_strequals(t40r[2],"|") && ft_strequals(t40r[3],"4") && ft_strequals(t40r[4],"5"))
		printf("4.0 Ok\n");
	else
		printf("4.0 Error \n");

	char 	t41[] = "1 2|4 5";
	char	**t41r = ft_lexer(t41);
	if (ft_strequals(t41r[0],"1") && ft_strequals(t41r[1],"2") && ft_strequals(t41r[2],"|") && ft_strequals(t41r[3],"4") && ft_strequals(t41r[4],"5"))
		printf("4.1 Ok\n");
	else
		printf("4.1 Error \n");

	char 	t42[] = "1 2  || 4 5";
	char	**t42r = ft_lexer(t42);
	if (ft_strequals(t42r[0],"1") && ft_strequals(t42r[1],"2") && ft_strequals(t42r[2],"||") && ft_strequals(t42r[3],"4") && ft_strequals(t42r[4],"5"))
		printf("4.2 Ok\n");
	else
		printf("4.2 Error \n");

	char 	t43[] = "1 2&4 5";
	char	**t43r = ft_lexer(t43);
	if (ft_strequals(t43r[0],"1") && ft_strequals(t43r[1],"2") && ft_strequals(t43r[2],"&") && ft_strequals(t43r[3],"4") && ft_strequals(t43r[4],"5"))
		printf("4.3 Ok\n");
	else
		printf("4.3 Error \n");

	char 	t44[] = "1 2&&4 5";
	char	**t44r = ft_lexer(t44);
	if (ft_strequals(t44r[0],"1") && ft_strequals(t44r[1],"2") && ft_strequals(t44r[2],"&&") && ft_strequals(t44r[3],"4") && ft_strequals(t44r[4],"5"))
		printf("4.4 Ok\n");
	else
		printf("4.4 Error \n");


	//Advanced testing
	printf("Advanced Testing\n");
	char 	t50[] = "ls -al a* | grep me > file1";
	char	**t50r = ft_lexer(t50);
	if (ft_strequals(t50r[0],"ls") && ft_strequals(t50r[1],"-al") && ft_strequals(t50r[2],"a*") && ft_strequals(t50r[3],"|") && ft_strequals(t50r[4],"grep") && ft_strequals(t50r[5],"me") && ft_strequals(t50r[6],">") && ft_strequals(t50r[7],"file1"))
		printf("5.0 Ok\n");
	else
		printf("5.0 Error \n");

	system("leaks a.out");

	char 	t16[] = "/bin/ls";
	int		t16r = 1;
	if (ft_count_tokens(t16) != t16r)
		printf("t16 Error\n");
	else
		printf("t16 OK\n");

	char 	t17[] = "/bin/ls -laF";
	int		t17r = 2;
	if (ft_count_tokens(t17) != t17r)
		printf("t17 Error\n");
	else
		printf("t17 OK\n");

	char 	t18[] = "/bin/ls -l -a -F";
	int		t18r = 4;
	if (ft_count_tokens(t18) != t18r)
		printf("t18 Error\n");
	else
		printf("t18 OK\n");

	char 	t19[] = "echo \"It works\"";
	int		t19r = 2;
	if (ft_count_tokens(t19) != t19r)
		printf("t19 Error\n");
	else
		printf("t19 OK\n");

	char 	t20[] = "echo It works";
	int		t20r = 3;
	if (ft_count_tokens(t20) != t20r)
		printf("t20 Error\n");
	else
		printf("t20 OK\n");

	char 	t21[] = "cd /absolute/path/of/your/choice";
	int		t21r = 2;
	if (ft_count_tokens(t21) != t21r)
		printf("t21 Error\n");
	else
		printf("t21 OK\n");

	char 	t22[] = "cd relative/path/of/your/choice";
	int		t22r = 2;
	if (ft_count_tokens(t22) != t22r)
		printf("t22 Error\n");
	else
		printf("t22 OK\n");

	char 	t23[] = "cd";
	int		t23r = 1;
	if (ft_count_tokens(t23) != t23r)
		printf("t23 Error\n");
	else
		printf("t23 OK\n");

	char 	t24[] = "cd";
	int		t24r = 1;
	if (ft_count_tokens(t24) != t24r)
		printf("t24 Error\n");
	else
		printf("t24 OK\n");

	char 	t25[] = "/bin/pwd";
	int		t25r = 1;
	if (ft_count_tokens(t25) != t25r)
		printf("t25 Error\n");
	else
		printf("t25 OK\n");

	char 	t26[] = "cd -";
	int		t26r = 2;
	if (ft_count_tokens(t26) != t26r)
		printf("t26 Error\n");
	else
		printf("t26 OK\n");

	char 	t27[] = "cd ~/path/of/your/choice";
	int		t27r = 2;
	if (ft_count_tokens(t27) != t27r)
		printf("t27 Error\n");
	else
		printf("t27 OK\n");

	char 	t28[] = "setenv FOO bar";
	int		t28r = 3;
	if (ft_count_tokens(t28) != t28r)
		printf("t28 Error\n");
	else
		printf("t28 OK\n");

	char 	t29[] = "setenv FOO=bar";
	int		t29r = 2;
	if (ft_count_tokens(t29) != t29r)
		printf("t29 Error\n");
	else
		printf("t29 OK\n");

	char 	t30[] = "echo $FOO";
	int		t30r = 2;
	if (ft_count_tokens(t30) != t30r)
		printf("t30 Error\n");
	else
		printf("t30 OK\n");

	char 	t31[] = "setenv PATH \"/bin:/usr/bin\"";
	int		t31r = 3;
	if (ft_count_tokens(t31) != t31r)
		printf("t31 Error\n");
	else
		printf("t31 OK\n");

	char 	t32[] = "setenv PATH=/bin:/usr/bin";
	int		t32r = 2;
	if (ft_count_tokens(t32) != t32r)
		printf("t32 Error\n");
	else
		printf("t32 OK\n");

	char 	t33[] = "";
	int		t33r = 0;
	if (ft_count_tokens(t33) != t33r)
		printf("t33 Error\n");
	else
		printf("t33 OK\n");

	char 	t34[] = " ";
	int		t34r = 0;
	if (ft_count_tokens(t34) != t34r)
		printf("t34 Error\n");
	else
		printf("t34 OK\n");


	char 	t35[] = " \t\t  ";
	int		t35r = 0;
	if (ft_count_tokens(t35) != t35r)
		printf("t35 Error\n");
	else
		printf("t35 OK\n");
*/
	return (0);
}
