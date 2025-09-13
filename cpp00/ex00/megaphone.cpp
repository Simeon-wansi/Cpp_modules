/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:31:52 by sngantch          #+#    #+#             */
/*   Updated: 2025/07/31 19:02:09 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

void	print_upper(char *str)
{
	char	c;

	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			c = (char)toupper(*str);
		else
			c = *str;
		std::cout << c;
		str++;
	}
}

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		av += 1;
		while (*av != NULL)
		{
			print_upper(*av);
			av++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}