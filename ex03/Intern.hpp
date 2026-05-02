/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:00:00 by elmondo           #+#    #+#             */
/*   Updated: 2026/05/02 11:32:34 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>

class AForm;

class Intern
{
public:
	Intern(void);
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	AForm *makeForm(const std::string &name, const std::string &target);

private:
	static AForm *createShrubbery(const std::string &target);
	static AForm *createRobotomy(const std::string &target);
	static AForm *createPresidential(const std::string &target);
};

#endif
