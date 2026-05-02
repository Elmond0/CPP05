/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:00:00 by elmondo           #+#    #+#             */
/*   Updated: 2026/05/02 11:31:50 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern() {}

AForm *Intern::createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	const std::string names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"};
	AForm *(*creators[])(const std::string &) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential};

	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			AForm *form = creators[i](target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}
	std::cout << "Intern can't create \"" << name << "\": unknown form." << std::endl;
	return NULL;
}
