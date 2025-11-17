/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imouhtad <imouhtad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:00:03 by imouhtad          #+#    #+#             */
/*   Updated: 2025/11/16 14:47:46 by imouhtad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main (int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	int i = 1;
	while(av[i])
	{
		std::string s = av[i];
		int j = 0;
		while(s[j])
		{
			std::cout << (char)std::toupper(s[j]);
			j++;	
		}
		j = 0;
		i++;
	}
	std::cout << std::endl;
}


