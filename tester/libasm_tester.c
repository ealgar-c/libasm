/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:02:38 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/11/11 20:34:32 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libasm_tester.h"

int	test_strlen(void) {
	char *tests[] = {
		"pipo say hi",
		"",
		"\n\t\n",
		"a",
		"piiiiiiiiipo hi",	
	};
	int	ret_val = 0;

	printf(TITLE_ANSI "\tTesting strlen...\n" NC_ANSI);
	int strings_nb = sizeof(tests) / sizeof(char *);
	for (int i = 0; i < strings_nb ; i++) {
		char	*str = tests[i];
		int		expected_output = strlen(str);
		int		obtained_output = ft_strlen(str);

		printf("%i. ", i + 1);
		if (expected_output == obtained_output)
			printf(GREEN_ANSI "OK!\n" NC_ANSI);
		else {
			printf(RED_ANSI "KO!\n" NC_ANSI);
			printf("\texpected: %i, obtained: %i\n", expected_output, obtained_output);
			ret_val = i + 1;
		}
	}
	return (ret_val);
}

int test_strcpy(void) {
	char *tests[] = {
		"pipo say hi",
		"",
		"\n\t\n",
		"a",
		"piiiiiiiiipo hi",	
	};
	int	ret_val = 0;

	printf(TITLE_ANSI "\tTesting strcpy...\n" NC_ANSI);
	int strings_nb = sizeof(tests) / sizeof(char *);
	for (int i = 0; i < strings_nb ; i++) {
		char	*str = tests[i];
		char	test_ptr[100];

		void	*expected_output = strcpy(test_ptr, str);
		void	*obtained_output = ft_strcpy(test_ptr, str);

		printf("%i. ", i + 1);
		if (expected_output == obtained_output)
			printf(GREEN_ANSI "RETURN VALUE OK!" NC_ANSI ", ");
		else {
			printf(RED_ANSI "RETURN VALUE KO!\n" NC_ANSI);
			printf("\texpected: %p, obtained: %p\n", expected_output, obtained_output);
			ret_val = i + 1;
		}

		char expected_dst[100];
		char obtained_dst[100];
		strcpy(expected_dst, str);
		ft_strcpy(obtained_dst, str);
		
		if (strcmp(expected_dst, obtained_dst) == 0)
			printf(GREEN_ANSI "COPY OK!\n" NC_ANSI);
		else {
			printf(RED_ANSI "COPY KO!\n" NC_ANSI);
			printf("\texpected: %s, obtained: %s\n", expected_dst, obtained_dst);
			ret_val = i + 1;
		}
	}
	return ret_val;
}

int	test_strcmp(void) {
	char *tests1[] = {
		"pipo say hi",
		"",
		"\n",
		"abbc",
		"piiiiiiiiipo hi",	
	};
	char *tests2[] = {
		"pipo say hi",
		"h",
		"\n\t\n",
		"abc",
		"piii1iiiiipo hi",	
	};
	int	ret_val = 0;

	printf(TITLE_ANSI "\tTesting strcmp...\n" NC_ANSI);
	int strings_nb = sizeof(tests1) / sizeof(char *);
	for (int i = 0; i < strings_nb ; i++) {
		char	*str1 = tests1[i];
		char	*str2 = tests2[i];
		int		expected_output = strcmp(str1, str2);
		int		obtained_output = ft_strcmp(str1, str2);

		printf("%i. ", i + 1);
		if (expected_output == obtained_output)
			printf(GREEN_ANSI "OK!\n" NC_ANSI);
		else {
			printf(RED_ANSI "KO!\n" NC_ANSI);
			printf("\texpected: %i, obtained: %i\n", expected_output, obtained_output);
			ret_val = i + 1;
		}
	}
	return (ret_val);
}

int	test_write(void) {
	char *tests[] = {
		"pipo say hi",
		"",
		"\n",
		"abbc",
		"piiiiiiiiipo hi",
		NULL,
	};
	int fds[] = {
		-1,
		open(".tests.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644),
		42,
	};
	int strings_nb = sizeof(tests) / sizeof(char *);
	int fds_nb = sizeof(fds) / sizeof(int);

	printf(TITLE_ANSI "\tTesting write...\n" NC_ANSI);
	for (int i = 0; i < strings_nb; i++) {
		char	*str = tests[i];
		for (int j = 0; j < fds_nb; j++) {
			printf("\t\"%s\" (fd: %i)\n%i. ", str, fds[j], i + 1);
			errno = 0;
			size_t size = str ? strlen(str) : 100;
			int expected_ret_val = write(fds[j], str, size);
			int expected_errno = errno;
			errno = 0;
			int	obtained_ret_val = ft_write(fds[j], str, size);
			int obtained_errno = errno;
			if (expected_errno == obtained_errno)
				printf(GREEN_ANSI "ERRNO OK!, " NC_ANSI);
			else {
				printf(RED_ANSI "ERRNO KO!: " NC_ANSI);
				printf("\texpected: %i, obtained: %i\n", expected_errno, obtained_errno);
			}
			if (expected_ret_val == obtained_ret_val)
				printf(GREEN_ANSI "RET. VALUE OK!\n " NC_ANSI);
			else {
				printf(RED_ANSI "RET. VALUE KO!: " NC_ANSI);
				printf("\texpected: %i, obtained: %i\n", expected_ret_val, obtained_ret_val);
			}
		}
	}
	return 0;
}

int main(void) {
	printf(TITLE_ANSI "\t\tSTARTING LIBASM TESTS \n\n" NC_ANSI);
	int	rv_strlen = test_strlen();
	int	rv_strcpy = test_strcpy();
	int	rv_strcmp = test_strcmp();
	int	rv_write = test_write();
	printf("%i, %i, %i, %i\n", rv_strcpy, rv_strlen, rv_strcmp, rv_write);
	return 0;
}
