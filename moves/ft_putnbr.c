/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zihirri <zihirri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:58:16 by zihirri           #+#    #+#             */
/*   Updated: 2022/02/14 23:21:39 by zihirri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	t;

	t = (long)nb;
	if (t < 0)
	{
		ft_putchar('-');
		t *= -1;
	}
	if (t >= 10)
	{
		ft_putnbr(t / 10);
		ft_putnbr(t % 10);
	}
	else if (t >= 0)
	{
		ft_putchar(t + 48);
	}
}
