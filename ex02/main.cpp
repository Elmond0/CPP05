/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:18:23 by elmondo           #+#    #+#             */
/*   Updated: 2026/05/02 16:26:41 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

int main(void)
{

	std::srand(std::time(NULL));

	std::cout << "=== ShrubberyCreationForm ===" << std::endl;
	try
	{
		Bureaucrat worker("Alice", 130);
		ShrubberyCreationForm shrub("home");
		std::cout << shrub << std::endl;
		worker.signForm(shrub);
		worker.executeForm(shrub);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Execute unsigned form ===" << std::endl;
	try
	{
		Bureaucrat boss("Bob", 1);
		RobotomyRequestForm robo("Ford Prefect");
		std::cout << robo << std::endl;
		boss.executeForm(robo);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== RobotomyRequestForm ===" << std::endl;
	try
	{
		Bureaucrat manager("Charlie", 40);
		RobotomyRequestForm robo("Bender");
		std::cout << robo << std::endl;
		manager.signForm(robo);
		manager.executeForm(robo);
		manager.executeForm(robo);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== PresidentialPardonForm ===" << std::endl;
	try
	{
		Bureaucrat president("Diana", 1);
		PresidentialPardonForm pardon("Arthur Dent");
		std::cout << pardon << std::endl;
		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Grade too low to sign ===" << std::endl;
	try
	{
		Bureaucrat intern("Eve", 150);
		PresidentialPardonForm pardon("Trillian");
		intern.signForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Grade too low to execute ===" << std::endl;
	try
	{
		Bureaucrat signer("Frank", 25);
		Bureaucrat executor("Grace", 100);
		PresidentialPardonForm pardon("Zaphod");
		signer.signForm(pardon);
		executor.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Boundary: exact grade to sign and execute ===" << std::endl;
	try
	{
		Bureaucrat exact("Hank", 145);
		ShrubberyCreationForm shrub("park");
		exact.signForm(shrub);
		std::cout << shrub << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Boundary: one too low to sign ===" << std::endl;
	try
	{
		Bureaucrat low("Ivy", 146);
		ShrubberyCreationForm shrub("yard");
		low.signForm(shrub);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Signed but grade too low to execute ===" << std::endl;
	try
	{
		Bureaucrat signer("Jack", 72);
		RobotomyRequestForm robo("Subject");
		signer.signForm(robo);
		signer.executeForm(robo);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Copy form and execute copy ===" << std::endl;
	try
	{
		Bureaucrat boss("Karl", 1);
		PresidentialPardonForm original("Original Target");
		boss.signForm(original);
		PresidentialPardonForm copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy:     " << copy << std::endl;
		boss.executeForm(copy);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Multiple robotomy attempts ===" << std::endl;
	try
	{
		Bureaucrat engineer("Leo", 1);
		RobotomyRequestForm robo("TestBot");
		engineer.signForm(robo);
		engineer.executeForm(robo);
		engineer.executeForm(robo);
		engineer.executeForm(robo);
		engineer.executeForm(robo);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
