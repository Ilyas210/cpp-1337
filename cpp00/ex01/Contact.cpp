#include "Contact.hpp"

Contact::Contact(void)
{

}

Contact::~Contact(void)
{

}

bool    hasSpace(std::string line)
{
    if (line.empty())
        return true;
    size_t len = line.length();
    for(size_t i = 0; i < len; i++)
    {
        if (std::isspace(line[i]) || !std::isprint(line[i]))
            return true;
    }
    return false;
}

bool    isNumber(std::string line)
{
    if (line.empty())
        return false;
    size_t len = line.length();
    for(size_t i = 0; i < len; i++)
    {
        if (!std::isdigit(line[i]))
            return false;
    }
    return true;
}

static bool allSpaces(std::string line)
{
    if (line.empty())
        return false;
    size_t len = line.length();
    for(size_t i = 0; i < len; i++)
    {
        if (!std::isspace(line[i]))
            return false;
    }
    return true;
}
std::string	Contact::get_firstname(void) const
{
    return (this->_firstname);
}

std::string Contact::get_lastname(void) const
{
    return (this->_lastname);
}

std::string Contact::get_nickname(void) const
{
    return (this->_nickname);
}

std::string Contact::get_phone(void) const
{
    return (this->_phone);
}

std::string Contact::get_secret(void) const
{
    return (this->_secret);
}

bool    Contact::set_firstname(std::string firstn)
{
    if (hasSpace(firstn) || isNumber(firstn))
        return false;
    this->_firstname = firstn;
    return true;
}

bool Contact::set_lastname(std::string lastn)
{
    if (hasSpace(lastn) || isNumber(lastn))
        return false;
    this->_lastname = lastn;
    return true;
}

bool Contact::set_nickname(std::string nickname)
{
     if (hasSpace(nickname) || isNumber(nickname))
        return false;
    this->_nickname = nickname;
    return true;
}

bool Contact::set_phone(std::string phone_number)
{
    if (hasSpace(phone_number) || !isNumber(phone_number))
        return false;
    this->_phone = phone_number;
    return true;
}

bool Contact::set_secret(std::string secret)
{
    if (allSpaces(secret))
        return false;
    this->_secret = secret;
    return true;
}
