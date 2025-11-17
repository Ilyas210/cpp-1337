/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imouhtad <imouhtad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:00:37 by imouhtad          #+#    #+#             */
/*   Updated: 2025/11/15 15:00:37 by imouhtad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
        public:
            PhoneBook(void);
            ~PhoneBook(void);
            void        add(void);
            void        search(void);
            void        get_contacts(void);
        private:
            unsigned int _index;
            Contact _Contacts[8];
            unsigned int _size;
};

#endif