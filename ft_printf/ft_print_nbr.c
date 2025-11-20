#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_print_char('-');
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_print_nbr(nb / 10);
	count += ft_print_char((nb % 10) + '0');
	return (count);
}
