/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:06:25 by momrane           #+#    #+#             */
/*   Updated: 2024/05/14 14:06:26 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <string>
# include <iostream>

# define reset "\033[0m"
# define red "\033[31m"
# define green "\033[32m"
# define blue "\033[34m"
# define boldred "\033[1m\033[31m"
# define boldgreen "\033[1m\033[32m"
# define boldblue "\033[1m\033[34m"
# define boldyellow "\033[1m\033[33m"

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:
		Contact(void);
		~Contact(void);
		void		fillContact(void);
		void		printLineContact(void) const;
		void		printFullInfos(void) const;
};

#endif