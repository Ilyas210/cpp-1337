/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imouhtad <imouhtad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:00:33 by imouhtad          #+#    #+#             */
/*   Updated: 2025/11/15 15:00:33 by imouhtad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
   this->_index = 0;
   this->_size = 0;
    std::cout << "welcome !! Created an empty phonebook for up to 8 contacts"
    << std::endl;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "good luck !" << std::endl;
}

static bool    isNumber1(std::string line)
{
    if (line.empty())
        return false;
    size_t len = line.length();
    int sum = 0;
    for(size_t i = 0; i < len; i++)
    {
        if (!std::isdigit(line[i]))
            return false;
        sum += (line[i] - 48);
        if (sum < 0 || sum > 7)
            return false;
    }
    return true;
}

static std::string getPrompt(std::string message)
{
    std::string prompt;

    std::cout << message;
    if(!std::getline(std::cin, prompt))
    {
        std::cout << std::endl;
        exit(1);
    }
    return prompt;
}
void PhoneBook::get_contacts()
{
    std::string prompt;
    std::cout << "Valid Prompts: ADD, SEARCH, and EXIT" << std::endl;
    while(true)
    {
        prompt = getPrompt("prompt-> ");
        if (!prompt.compare("ADD"))
            PhoneBook::add();
        else if (!prompt.compare("SEARCH"))
            PhoneBook::search();
        else if (!prompt.compare("EXIT"))
            break;
        else
            std::cerr << "Error : Invalid Prompt" << std::endl;
    }
}

void PhoneBook::add(void)
{
    Contact contact;

    std::string prompt;
    prompt = getPrompt("What's your first name? : ");
    while(!contact.set_firstname(prompt))
    {
        std::cerr << "Invalid first name. try again!" << std::endl;
        prompt = getPrompt("What's your first name? : ");
    }

    prompt = getPrompt("What's your last name? : ");
    while(!contact.set_lastname(prompt))
    {
        std::cerr << "Invalid last name. try again!" << std::endl;
        prompt = getPrompt("What's your last name? : ");
    }

    prompt = getPrompt("What's your nickname? : ");
    while(!contact.set_nickname(prompt))
    {
        std::cerr << "Invalid nickname. try again!" << std::endl;
        prompt = getPrompt("What's your nickname? : ");
    }

    prompt = getPrompt("What's your phone number? : ");
    while(!contact.set_phone(prompt))
    {
        std::cerr << "Invalid phone number. try again!" << std::endl;
        prompt = getPrompt("What's your phone number? : ");
    }

    prompt = getPrompt("What's your darkest secret? : ");
    while(!contact.set_secret(prompt))
    {
        std::cerr << "Invalid darkest secret. try again!" << std::endl;
        prompt = getPrompt("What's your darkest secret? : ");
    }

    _Contacts[_index] = contact;
    _index = (_index + 1) % 8;
    if (_size < 8)
        _size++;
}

static void    displayboundary()
{
    for(int i = 0; i < 4; i++)
    {
        if (i == 0)
            std::cout << "+";
        std::cout << "----------+";
        if (i == 3)
            std::cout << std::endl;
    }
}

static void displayRight(std::string txt, unsigned int width)
{
    unsigned int len;
    unsigned int left;

    len = txt.length();
    left = width - len;
    std::cout << std::setw(left)  << "" << txt;
}

static void	displayContent(std::string txt)
{
	if (txt.length() <= 10)
		displayRight(txt, 10);
	else 
	{
		for (int i = 0; i < 9; i++)
			std::cout << txt.at(i);
		std::cout << ".";
	}
}

void PhoneBook::search()
{
    std::string     prompt;
    unsigned int    index;

    displayboundary();
    std::cout << "|";
    displayRight("index", 10);
    std::cout << "|";
    displayRight("first name", 10);
    std::cout << "|";
    displayRight("last name", 10);
    std::cout << "|";
    displayRight("nickname", 10);
    std::cout << "|" << std::endl;
    for(unsigned int i = 0 ; i < _size ; i++)
    {
        displayboundary();
        std::cout << "|";
        std::string s = "";
        s += static_cast<char>('0' + i);
        displayContent(s);
        std::cout << "|";
        displayContent(_Contacts[i].get_firstname());
         std::cout << "|";
        displayContent(_Contacts[i].get_lastname());
         std::cout << "|";
        displayContent(_Contacts[i].get_nickname());
        std::cout << "|";
        std::cout << std::endl;
    }
    displayboundary();
    prompt = getPrompt("Enter an index between 0-7 : ");
    if (!isNumber1(prompt))
        std::cerr << "invalid index. Must be between 0 to 7" << std::endl;
    else
    {
        index = atoi(prompt.c_str());
        if (index < 8 && index < _size)
        {
            std::cout << "first name    : " << _Contacts[index].get_firstname() << std::endl;
			std::cout << "last name     : " << _Contacts[index].get_lastname() << std::endl;
			std::cout << "nickname      : " << _Contacts[index].get_nickname() << std::endl;
			std::cout << "phone number  : " << _Contacts[index].get_phone() << std::endl;
			std::cout << "darkest secret: " << _Contacts[index].get_secret() << std::endl;
        }
        else
        {
            std::cerr << static_cast<unsigned int>(index) << " does not have any contact yet." << std::endl;
        }
    }
}