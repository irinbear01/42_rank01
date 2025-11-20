#include "ft_printf.h"

int	ft_handle(char c, va_list *ap)
{
	if (c == 'c')
		return (ft_print_char((char)va_arg(*ap, int)));
	if (c == 's')
		return (ft_print_str(va_arg(*ap, char *)));
	if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(*ap, int)));
	if (c == 'u')
		return (ft_print_unsigned(va_arg(*ap, unsigned int)));
	if (c == 'x')
		return (ft_print_hex(va_arg(*ap, unsigned int), 0));
	if (c == 'X')
		return (ft_print_hex(va_arg(*ap, unsigned int), 1));
	if (c == 'p')
		return (ft_print_ptr(va_arg(*ap, void *)));
	if (c == '%')
		return (ft_print_char('%'));
	return (0);
}
