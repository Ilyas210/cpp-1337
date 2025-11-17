/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imouhtad <imouhtad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:00:29 by imouhtad          #+#    #+#             */
/*   Updated: 2025/11/15 15:00:29 by imouhtad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

int main(int ac, char **av)
{
    PhoneBook p;
    (void)av;
    if (ac != 1)
    {
        std::cerr << "The Program doesn't accepte any arguments!" << std::endl;
		return (1);
    }
    p.get_contacts();
    return 0;
}