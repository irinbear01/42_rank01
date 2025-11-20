/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaiamsr <khaiamsr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:40:38 by khaiamsr          #+#    #+#             */
/*   Updated: 2025/11/20 15:07:02 by khaiamsr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_rec(unsigned long n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_ptr_rec(n / 16);
	count += ft_print_char("0123456789abcdef"[n % 16]);
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long	addr;
	int				count;

	addr = (unsigned long)ptr;
	if (addr == 0)
		return (ft_print_str("(nil)"));
	count = 0;
	count += ft_print_str("0x");
	count += ft_ptr_rec(addr);
	return (count);
}
