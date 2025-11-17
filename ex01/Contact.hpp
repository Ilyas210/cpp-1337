/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imouhtad <imouhtad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:00:21 by imouhtad          #+#    #+#             */
/*   Updated: 2025/11/15 15:38:58 by imouhtad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	private:
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _phone;
		std::string _secret;
	public:
		Contact(void);
		~Contact(void);
		
		std::string	get_firstname(void) const;
		std::string	get_lastname(void) const;
		std::string	get_nickname(void) const;
		std::string	get_phone(void) const;
		std::string	get_secret(void) const;
		
		bool		set_firstname(std::string fn);
		bool		set_lastname(std::string ln);
		bool		set_nickname(std::string nickname);
		bool		set_phone(std::string p);
		bool 		set_secret(std::string secret);
};

#endif
