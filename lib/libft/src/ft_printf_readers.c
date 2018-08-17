/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_readers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmushta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 14:36:19 by kmushta           #+#    #+#             */
/*   Updated: 2017/12/24 14:36:20 by kmushta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_printf_read_flags(const char *format, int *arr)
{
	unsigned int	i;

	i = 0;
	while (1)
	{
		if (*(format + i) == 35)
			*arr = 1;
		else if (*(format + i) == 48)
			*(arr + 1) = 1;
		else if (*(format + i) == 45)
			*(arr + 2) = 1;
		else if (*(format + i) == 43)
			*(arr + 3) = 1;
		else if (*(format + i) == 32)
			*(arr + 4) = 1;
		else
			return (i);
		i++;
	}
}

unsigned int	ft_printf_read_width(const char *format, int *arr)
{
	unsigned int	i;

	i = 0;
	while (*(format + i) > 47 && *(format + i) < 58)
	{
		*(arr + 5) = *(arr + 5) * 10 + *(format + i) - 48;
		i++;
	}
	return (i);
}

unsigned int	ft_printf_read_precision(const char *format, int *arr)
{
	unsigned int	i;

	i = 1;
	if (*format != 46)
		return (0);
	*(arr + 14) = 1;
	while (*(format + i) > 47 && *(format + i) < 58)
	{
		*(arr + 13) = *(arr + 13) * 10 + *(format + i) - 48;
		i++;
	}
	return (i);
}

unsigned int	ft_printf_read_modificators(const char *format, int *arr)
{
	unsigned int	i;

	i = -1;
	while (++i + 1)
		if (*(format + i) == 104 && *(format + i + 1) == 104)
		{
			*(arr + 6) = 1;
			i++;
		}
		else if (*(format + i) == 104)
			*(arr + 7) = 1;
		else if (*(format + i) == 108 && *(format + i + 1) == 108)
		{
			*(arr + 9) = 1;
			i++;
		}
		else if (*(format + i) == 108)
			*(arr + 8) = 1;
		else if (*(format + i) == 106)
			*(arr + 10) = 1;
		else if (*(format + i) == 122)
			*(arr + 11) = 1;
		else
			return (i);
	return (0);
}

int				ft_printf_read_transformation(const char *format, int *arr)
{
	if (*format == 115 || *format == 83 || *format == 112 ||
		*format == 100 || *format == 68 || *format == 105 ||
		*format == 111 || *format == 79 || *format == 117 ||
		*format == 120 || *format == 88 || *format == 99 ||
		*format == 85 || *format == 67 || *format == 37)
	{
		*(arr + 12) = *format;
		return (1);
	}
	return (0);
}
