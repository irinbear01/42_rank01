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
	count = 0;
	count += ft_print_str("0x");
	if (addr == 0)
		count += ft_print_char('0');
	else
		count += ft_ptr_rec(addr);
	return (count);
}
