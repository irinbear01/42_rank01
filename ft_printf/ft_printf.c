/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaiamsr <khaiamsr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:40:56 by khaiamsr          #+#    #+#             */
/*   Updated: 2025/11/20 15:08:11 by khaiamsr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_handle(format[i], &ap);
		}
		else
			count += ft_print_char(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int				len_ft;
// 	int				len_real;
// 	int				n = -2147483648;
// 	unsigned int	u = 4294967295u;
// 	void			*ptr = &n;

// 	//%c
// 	ft_printf("==== %%c test ====\n");
// 	ft_printf("ft : %c %c %c\n", 'A', 'B', 'C');
// 	printf("rl : %c %c %c\n\n", 'A', 'B', 'C');
// 	//%s 
// 	ft_printf("==== %%s test ====\n");
// 	ft_printf("ft : %s %s %s\n", "Hello", "World", "");
// 	printf("rl : %s %s %s\n", "Hello", "World", "");
// 	ft_printf("ft NULL : %s\n", NULL);
//     printf("rl NULL : %s\n\n", (char *)NULL);
// 	//%d %i
// 	ft_printf("==== %%d / %%i test ====\n");
// 	len_ft = ft_printf("ft : %d %i %d\n", 0, 42, -1234);
// 	len_real = printf("rl : %d %i %d\n", 0, 42, -1234);
// 	printf("len ft = %d, len rl = %d\n", len_ft, len_real);
// 	len_ft = ft_printf("ft INT_MIN : %d\n", n);
//     len_real = printf("rl INT_MIN : %d\n", n);
//     printf("\n");
//     printf("len ft = %d, len rl = %d\n\n", len_ft, len_real);
// 	//%u
// 	ft_printf("==== %%u test ====\n");
// 	len_ft = ft_printf("ft : %u %u %u\n", 0u, 1u, u);
// 	len_real = printf("rl : %u %u %u\n", 0u, 1u, u);
// 	printf("len ft = %d, len rl = %d\n\n", len_ft, len_real);
// 	//%x และ %X
// 	ft_printf("==== %%x / %%X test ====\n");
// 	len_ft = ft_printf("ft : %x %x %X %X\n", 0u, 255u, 255u, u);
// 	len_real = printf("rl : %x %x %X %X\n", 0u, 255u, 255u, u);
// 	printf("len ft = %d, len rl = %d\n\n", len_ft, len_real);
// 	// %p
// 	ft_printf("==== %%p test ====\n");
// 	len_ft = ft_printf("ft : %p %p\n", ptr, NULL);
// 	len_real = printf("rl : %p %p\n", ptr, NULL);
// 	printf("len ft = %d, len rl = %d\n\n", len_ft, len_real);
// 	// %%
// 	ft_printf("==== %%%% test ====\n");
// 	len_ft = ft_printf("ft : A%%B%%C\n");
// 	len_real = printf("rl : A%%B%%C\n");
// 	printf("len ft = %d, len rl = %d\n", len_ft, len_real);
// }