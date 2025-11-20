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
