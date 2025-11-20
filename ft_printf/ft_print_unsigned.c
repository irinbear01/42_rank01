/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaiamsr <khaiamsr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:40:50 by khaiamsr          #+#    #+#             */
/*   Updated: 2025/11/20 14:40:51 by khaiamsr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	unsigned long	nb;
	int				count;

	nb = n;
	count = 0;
	if (nb >= 10)
		count += ft_print_unsigned(nb / 10);
	count += ft_print_char((nb % 10) + '0');
	return (count);
}
