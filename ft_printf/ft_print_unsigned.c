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
