/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrehberg <maxrehberg@posteo.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:33:00 by mrehberg          #+#    #+#             */
/*   Updated: 2022/06/28 13:03:44 by mrehberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include "Libft/libft.h"

int		ft_printf(const char *str, ...);
int		print_decimal(int num);
int		print_string(char *str);
int		print_unsigned(unsigned int num);
int		print_hex(unsigned int num, int flag);
int		print_ptr(unsigned long int num);

#endif