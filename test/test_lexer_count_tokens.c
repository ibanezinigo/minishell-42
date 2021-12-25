#include "../lexer/lexer.h"
#include "../utils/utils.h"
#include <stdio.h>

int	main(void)
{
	printf("Testing tokens counting:\n");

	//BASIC TEST
	printf("Basics test:\n");

	char 	t1[] = "1";
	int		t1r = 1;
	if (ft_count_tokens(t1) != t1r)
		printf("t1 Error\n");
	else
		printf("t1 OK\n");

	char 	t2[] = "1 2";
	int		t2r = 2;
	if (ft_count_tokens(t2) != t2r)
		printf("t2 Error\n");
	else
		printf("t2 OK\n");

	char 	t3[] = "1 2 3";
	int		t3r = 3;
	if (ft_count_tokens(t3) != t3r)
		printf("t3 Error\n");
	else
		printf("t3 OK\n");

	char 	t4[] = "1 2 3 4 ";
	int		t4r = 4;
	if (ft_count_tokens(t4) != t4r)
		printf("t4 Error\n");
	else
		printf("t4 OK\n");


	//QUOTING TEST
	printf("Quoting test:\n");
	char 	t5[] = "\"1\"";
	int		t5r = 1;
	if (ft_count_tokens(t5) != t5r)
		printf("t5 Error\n");
	else
		printf("t5 OK\n");

	char 	t6[] = "\"1\"1";
	int		t6r = 1;
	if (ft_count_tokens(t6) != t6r)
		printf("t6 Error\n");
	else
		printf("t6 OK\n");

	char 	t7[] = "\"1\"\"1\"";
	int		t7r = 1;
	if (ft_count_tokens(t7) != t7r)
		printf("t7 Error\n");
	else
		printf("t7 OK\n");

	char 	t8[] = "\"1\"1 \"2\"";
	int		t8r = 2;
	if (ft_count_tokens(t8) != t8r)
		printf("t8 Error\n");
	else
		printf("t8 OK\n");

	char 	t9[] = "\"1\'\"1 \"2\'\" ";
	int		t9r = 2;
	if (ft_count_tokens(t9) != t9r)
		printf("t9 Error\n");
	else
		printf("t9 OK\n");


	// < << > >> testing
	printf("> < >> << test\n");
	char 	t10[] = "1 > 3";
	int		t10r = 3;
	if (ft_count_tokens(t10) != t10r)
		printf("t10 Error\n");
	else
		printf("t10 OK\n");

	char 	t11[] = "1>>3 ";
	int		t11r = 3;
	if (ft_count_tokens(t11) != t11r)
		printf("t11 Error\n");
	else
		printf("t11 OK\n");

	char 	t12[] = "1 < 3 ";
	int		t12r = 3;
	if (ft_count_tokens(t12) != t12r)
		printf("t12 Error\n");
	else
		printf("t12 OK\n");

	char 	t13[] = "1<<3 ";
	int		t13r = 3;
	if (ft_count_tokens(t13) != t13r)
		printf("t13 Error\n");
	else
		printf("t13 OK\n");

	// | || & && testing
	printf("| || & && testing\n");
	char 	t14[] = "1 2  | 4 5";
	int		t14r = 5;
	if (ft_count_tokens(t14) != t14r)
		printf("t14 Error\n");
	else
		printf("t14 OK\n");

	char 	t140[] = "1 2|4 5";
	int		t140r = 5;
	if (ft_count_tokens(t140) != t140r)
		printf("t14.0 Error\n");
	else
		printf("t14.0 OK\n");

	char 	t141[] = "1 2  || 4 5";
	int		t141r = 5;
	if (ft_count_tokens(t141) != t141r)
		printf("t14.1 Error, %i\n", ft_count_tokens(t141));
	else
		printf("t14.1 OK\n");

	char 	t142[] = "1 2&4 5";
	int		t142r = 5;
	if (ft_count_tokens(t142) != t142r)
		printf("t14.2 Error\n");
	else
		printf("t14.2 OK\n");

	char 	t143[] = "1 2&&4 5";
	int		t143r = 5;
	if (ft_count_tokens(t143) != t143r)
		printf("t14.3 Error, %i\n", ft_count_tokens(t143));
	else
		printf("t14.3 OK\n");

	//Advanced testing
	printf("Advanced Testing\n");
	char 	t15[] = "ls -al a* | grep me > file1";
	int		t15r = 8;
	if (ft_count_tokens(t15) != t15r)
		printf("t15 Error\n");
	else
		printf("t15 OK\n");

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
}
