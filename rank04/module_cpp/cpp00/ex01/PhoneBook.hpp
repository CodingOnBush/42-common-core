/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momrane <momrane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:06:23 by momrane           #+#    #+#             */
/*   Updated: 2024/05/14 14:06:24 by momrane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

# define reset "\033[0m"
# define red "\033[31m"
# define green "\033[32m"
# define blue "\033[34m"
# define boldred "\033[1m\033[31m"
# define boldgreen "\033[1m\033[32m"
# define boldblue "\033[1m\033[34m"
# define boldyellow "\033[1m\033[33m"

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_added;
		void	_printPhoneBook(void);
		void	_addContact(void);
		void	_searchContact(void);
	
	public:
		PhoneBook();
		~PhoneBook();
		void	launchApp(void);
};

#endif