/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:00:46 by sloquet           #+#    #+#             */
/*   Updated: 2021/12/14 02:06:16 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define YEL "\e[0;33m"
#define RED "\e[1;31m"
#define GRE "\e[1;32m"
#define BLUE "\e[1;34m"
#define DASH "--------------------"
#define EMP  "                    "
#define WBNL "\e[0m\n"
#define ___ printf(BLUE DASH DASH DASH WBNL);

void	noleaks(void)
{
	printf(WBNL YEL DASH "--- LEAKS CHECK ---" DASH WBNL); 
	system("leaks a.out");
}

void	test(int n, int you, int std)
{
	if (you == std)
		printf(GRE "%d.OK out %d\n", n, you);
	else
		printf(RED "%d.KO out %d != %d *.* :K :O\n", n, you, std);
	___;
}

void	test_c_s_percent_(void)
{
	int	you;
	int	std;

	ft_printf(YEL ">> here your ft_printf\n");
	printf(YEL ">> standard printf -.-\n");
	printf(YEL "<test_index>.OK out <ft_printf_out>\n");
	printf(YEL "<test_index>.KO out <ft_printf_out> != <printf_out>\n");
	printf(WBNL YEL DASH "-- TEST %%c %%s %%%% --" DASH WBNL); 
	/**/
	you = ft_printf("""""""""""""""""""""""""""""""""""""""");
	std = printf("""""""""""""""""""""""""""""""""""""""");
	test(1, you, std);
	/**/
	you = ft_printf("\r");
	std = printf("\r");
	test(2, you, std);
	/**/
	you = ft_printf("\r\\n\n");
	std = printf("\r\\n\n");
	test(3, you, std);
	/**/
	you = ft_printf("The cow jumped over the moon.\n");
	std = printf("The cow jumped over the moon.\n");
	test(4, you, std);
	/**/
	you = ft_printf("%c%c\n", '4', '2');
	std = printf("%c%c\n", '4', '2');
	test(5, you, std);
	/**/
	you = ft_printf("%c %c| %c%c | %c |\n", 'o', '\042', '\\', 'n', '\0');
	std = printf("%c %c| %c%c | %c |\n", 'o', '\042', '\\', 'n', '\0');
	test(6, you, std);
	/**/
	you = ft_printf("moon%s%c%c%s\n", ".", '8', '\t', "p");
	std = printf("moon%s%c%c%s\n", ".", '8', '\t', "p");
	test(7, you, std);
	/**/
	you = ft_printf("%%\n");
	std = printf("%%\n");
	test(8, you, std);
	/**/
	you = ft_printf("%%%s%%%s%%\n", "%%" "%%" "%%%" "%%%%" "" "%", "%%%%%%%%");
	std = printf("%%%s%%%s%%\n", "%%" "%%" "%%%" "%%%%" "" "%", "%%%%%%%%");
	test(9, you, std);
	/**/
	char *str_null = NULL;
	you = ft_printf("%s\n", str_null);
	std = printf("%s\n", str_null);
	test(10, you, std);
	/**/
	char *str_test = "balançoire";
	you = ft_printf("\\\\%s/\n", str_test);
	std = printf("\\\\%s/\n", str_test);
	test(11, you, std);
	/**/
	you = ft_printf("Vive%spatates%s!%s", " les ", " douces ", "\n");
	std = printf("Vive%spatates%s!%s", " les ", " douces ", "\n");
	test(12, you, std);
}

void	test_d_i_u_(void)
{
	int	you;
	int	std;

	ft_printf(YEL ">> here your ft_printf\n");
	printf(YEL ">> standard printf -.-\n");
	printf(YEL "<test_index>.OK out <ft_printf_out>\n");
	printf(YEL "<test_index>.KO out <ft_printf_out> != <printf_out>\n");
	printf(WBNL YEL DASH "-- TEST %%d %%i %%u --" DASH WBNL); 
	you = ft_printf("d:%d i:%i u:%u\n", CHAR_BIT, CHAR_BIT, CHAR_BIT);
	std = printf("d:%d i:%i u:%u\n", CHAR_BIT, CHAR_BIT, CHAR_BIT);
	test(13, you, std);
	/**/
	you = ft_printf("d:%d i:%i u:%u\n", CHAR_MIN, CHAR_MIN, CHAR_MIN);
	std = printf("d:%d i:%i u:%u\n", CHAR_MIN, CHAR_MIN, CHAR_MIN);
	test(14, you, std);
	/**/
	you = ft_printf("d:%d i:%i u:%u\n", CHAR_MAX, CHAR_MAX, CHAR_MAX);
	std = printf("d:%d i:%i u:%u\n", CHAR_MAX, CHAR_MAX, CHAR_MAX);
	test(15, you, std);
	/**/
	you = ft_printf("d:%d i:%i u:%u\n", UCHAR_MAX, UCHAR_MAX, UCHAR_MAX);
	std = printf("d:%d i:%i u:%u\n", UCHAR_MAX, UCHAR_MAX, UCHAR_MAX);
	test(16, you, std);
	/**/
	you = ft_printf("d:%d i:%i u:%u\n", -1, -1, -1);
	std = printf("d:%d i:%i u:%u\n", -1, -1, -1);
	test(17, you, std);
	/**/
	you = ft_printf("d:%d i:%i u:%u\n", 0, 0, 0);
	std = printf("d:%d i:%i u:%u\n", 0, 0, 0);
	test(18, you, std);
	/**/
	you = ft_printf("d:%d i:%i u:%u\n", -123456789, -123456789, -123456789);
	std = printf("d:%d i:%i u:%u\n", -123456789, -123456789, -123456789);
	test(19, you, std);
	/**/
	you = ft_printf("d:%d i:%i u:%u\n", (-1+(-1))*(-(7)*(-(-((1+1)+1)))), 4, 2);
	std = printf("d:%d i:%i u:%u\n", (-1+(-1))*(-(7)*(-(-((1+1)+1)))), 4, 2);
	test(20, you, std);
	/**/
	you = ft_printf("d:%d i:%i u:%u\n", SCHAR_MIN, SCHAR_MIN, SCHAR_MIN);
	std = printf("d:%d i:%i u:%u\n", SCHAR_MIN, SCHAR_MIN, SCHAR_MIN);
	test(21, you, std);
	/**/
	you = ft_printf("d:%d i:%i u:%u\n", SCHAR_MAX, SCHAR_MAX, SCHAR_MAX);
	std = printf("d:%d i:%i u:%u\n", SCHAR_MAX, SCHAR_MAX, SCHAR_MAX);
	test(22, you, std);
	/**/
	you = ft_printf("d:%d i:%i u:%u\n", SHRT_MIN, SHRT_MIN, SHRT_MIN);
	std = printf("d:%d i:%i u:%u\n", SHRT_MIN, SHRT_MIN, SHRT_MIN);
	test(23, you, std);
	/**/
	you = ft_printf("d:%d i:%i u:%u\n", SHRT_MAX, SHRT_MAX, SHRT_MAX);
	std = printf("d:%d i:%i u:%u\n", SHRT_MAX, SHRT_MAX, SHRT_MAX);
	test(24, you, std);
	/**/
	you = ft_printf("d:%d i:%i u:%u\n", USHRT_MAX, USHRT_MAX, USHRT_MAX);
	std = printf("d:%d i:%i u:%u\n", USHRT_MAX, USHRT_MAX, USHRT_MAX);
	test(25, you, std);
	/**/
	you = ft_printf("d:%d i:%i u:%u\n", INT_MIN, INT_MIN, INT_MIN);
	std = printf("d:%d i:%i u:%u\n", INT_MIN, INT_MIN, INT_MIN);
	test(26, you, std);
	/**/
	you = ft_printf("d:%d i:%i u:%u\n", INT_MAX, INT_MAX, INT_MAX);
	std = printf("d:%d i:%i u:%u\n", INT_MAX, INT_MAX, INT_MAX);
	test(27, you, std);
	/**/
	you = ft_printf("d:%d i:%i u:%u\n", UINT_MAX, UINT_MAX, UINT_MAX);
	std = printf("d:%d i:%i u:%u\n", UINT_MAX, UINT_MAX, UINT_MAX);
	test(28, you, std);
	/**/
	you = ft_printf(".d:%d                    .i:%i\
	                  \n", LONG_MIN, LONG_MIN);
	std = printf("ld:%ld li:%li\n", LONG_MIN, LONG_MIN);
	test(29, you, std);
	/**/
	you = ft_printf(".d:%d                  .i:%i\
		               \n", LONG_MAX, LONG_MAX);
	std = printf("ld:%ld li:%li\n", LONG_MAX, LONG_MAX);
	test(30, you, std);
	/**/
	you = ft_printf(".d:%d .i:%i\n", ULONG_MAX, ULONG_MAX);
	std = printf("ld:%ld li:%li\n", ULONG_MAX, ULONG_MAX);
	test(31, you, std);
	/**/
	you = ft_printf("d:%d i:%i u:%u\n", 00000000052, 00000000052, 00000000052);
	std = printf("d:%d i:%i u:%u\n", 00000000052, 00000000052, 00000000052);
	test(32, you, std);
}

void	test_X_x_p_(void)
{
	int	you;
	int	std;

	ft_printf(YEL ">> here your ft_printf\n");
	printf(YEL ">> standard printf -.-\n");
	printf(YEL "<test_index>.OK out <ft_printf_out>\n");
	printf(YEL "<test_index>.KO out <ft_printf_out> != <printf_out>\n");
	printf(WBNL YEL DASH "-- TEST %%X %%x %%p --" DASH WBNL); 
	you = ft_printf("X:%X x:%x p:%p\n", CHAR_BIT, CHAR_BIT, (void *)CHAR_BIT);
	std = printf("X:%X x:%x p:%p\n", CHAR_BIT, CHAR_BIT, (void *)CHAR_BIT);
	test(33, you, std);
	/**/
	you = ft_printf("X:%X x:%x p:%p\n", CHAR_MIN, CHAR_MIN, (void *)CHAR_MIN);
	std = printf("X:%X x:%x p:%p\n", CHAR_MIN, CHAR_MIN, (void *)CHAR_MIN);
	test(34, you, std);
	/**/
	you = ft_printf("X:%X x:%x p:%p\n", CHAR_MAX, CHAR_MAX, (void *)CHAR_MAX);
	std = printf("X:%X x:%x p:%p\n", CHAR_MAX, CHAR_MAX, (void *)CHAR_MAX);
	test(35, you, std);
	/**/
	you = ft_printf("X:%X x:%x p:%p\n", UCHAR_MAX, UCHAR_MAX, (void *)UCHAR_MAX);
	std = printf("X:%X x:%x p:%p\n", UCHAR_MAX, UCHAR_MAX, (void *)UCHAR_MAX);
	test(36, you, std);
	/**/
	you = ft_printf("X:%X x:%x p:%p\n", -1, -1, (void *)-1);
	std = printf("X:%X x:%x p:%p\n", -1, -1, (void *)-1);
	test(37, you, std);
	/**/
	you = ft_printf("X:%X x:%x p:%p\n", 0, 0, (void *)0);
	std = printf("X:%X x:%x p:%p\n", 0, 0, (void *)0);
	test(38, you, std);
	/**/
	you = ft_printf("X:%X x:%x p:%p\n", -123456789, -123456789, (void *)-123456789);
	std = printf("X:%X x:%x p:%p\n", -123456789, -123456789, (void *)-123456789);
	test(39, you, std);
	/**/
	you = ft_printf("X:%X x:%x p:%p\n", INT_MIN, INT_MIN, (void *)INT_MIN);
	std = printf("X:%X x:%x p:%p\n", INT_MIN, INT_MIN, (void *)INT_MIN);
	test(40, you, std);
	/**/
	you = ft_printf("X:%X x:%x p:%p\n", INT_MAX, INT_MAX, (void *)INT_MAX);
	std = printf("X:%X x:%x p:%p\n", INT_MAX, INT_MAX, (void *)INT_MAX);
	test(41, you, std);
	/**/
	you = ft_printf("X:%X x:%x p:%p\n", UINT_MAX, UINT_MAX, (void *)UINT_MAX);
	std = printf("X:%X x:%x p:%p\n", UINT_MAX, UINT_MAX, (void *)UINT_MAX);
	test(42, you, std);
	/**/
	you = ft_printf("p:%p\n", (void *)LONG_MIN);
	std = printf("p:%p\n", (void *)LONG_MIN);
	test(43, you, std);
	/**/
	you = ft_printf("p:%p\n", (void *)LONG_MAX);
	std = printf("p:%p\n", (void *)LONG_MAX);
	test(44, you, std);
	/**/
	you = ft_printf("p:%p\n", (void *)ULONG_MAX);
	std = printf("p:%p\n", (void *)ULONG_MAX);
	test(45, you, std);
	/**/
	you = ft_printf("p:%p\n", (void *)-LONG_MIN);
	std = printf("p:%p\n", (void *)-LONG_MIN);
	test(46, you, std);
	/**/
	you = ft_printf("p:%p\n", (void *)-LONG_MAX);
	std = printf("p:%p\n", (void *)-LONG_MAX);
	test(46, you, std);
	/**/
	you = ft_printf("p:%p\n", (void *)-ULONG_MAX);
	std = printf("p:%p\n", (void *)-ULONG_MAX);
	test(47, you, std);
	/**/
	char *ptr_null = NULL;
	you = ft_printf("p:%p\n", ptr_null); 
	std = printf("p:%p\n", ptr_null); 
	test(48, you, std);
	/**/
	you = ft_printf("p:%p\n", NULL); 
	std = printf("p:%p\n", NULL); 
	test(49, you, std);
	/**/
	char *ptr_test = "Cassoulet";
	you = ft_printf("p:%p\n", ptr_test); 
	std = printf("p:%p\n", ptr_test); 
	test(50, you, std);
}

int	main(void)
{
	___;
	printf(WBNL WBNL BLUE EMP "   PRINTF TESTER    " EMP WBNL WBNL WBNL); 
	___;
	test_c_s_percent_();
	test_d_i_u_();
	test_X_x_p_();
	atexit(noleaks);
	return (0);
}