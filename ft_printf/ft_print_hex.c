/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaiamsr <khaiamsr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:40:03 by khaiamsr          #+#    #+#             */
/*   Updated: 2025/11/20 14:40:05 by khaiamsr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_rec(unsigned int n, const char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_hex_rec(n / 16, base);
	count += ft_print_char(base[n % 16]);
	return (count);
}

int	ft_print_hex(unsigned int n, int uppercase)
{
	const char	*base;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	return (ft_hex_rec(n, base));
}
