/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:18:23 by miricci           #+#    #+#             */
/*   Updated: 2026/04/16 11:58:39 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

int main(void)
{

	std::srand(std::time(NULL));

	Intern someRandomIntern;

	std::cout << "=== Intern creates robotomy request ===" << std::endl;
	{
		AForm *rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			try
			{
				Bureaucrat boss("Boss", 1);
				boss.signForm(*rrf);
				boss.executeForm(*rrf);
			}
			catch (std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			delete rrf;
		}
	}

	std::cout << "\n=== Intern creates shrubbery creation ===" << std::endl;
	{
		AForm *scf = someRandomIntern.makeForm("shrubbery creation", "garden");
		if (scf)
		{
			try
			{
				Bureaucrat worker("Alice", 130);
				worker.signForm(*scf);
				worker.executeForm(*scf);
			}
			catch (std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			delete scf;
		}
	}

	std::cout << "\n=== Intern creates presidential pardon ===" << std::endl;
	{
		AForm *ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
		if (ppf)
		{
			try
			{
				Bureaucrat president("Zaphod", 1);
				president.signForm(*ppf);
				president.executeForm(*ppf);
			}
			catch (std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			delete ppf;
		}
	}

	std::cout << "\n=== Intern creates unknown form ===" << std::endl;
	{
		AForm *unknown = someRandomIntern.makeForm("coffee request", "everyone");
		if (unknown)
			delete unknown;
	}

	std::cout << "\n=== Grade too low to sign ===" << std::endl;
	{
		AForm *rrf = someRandomIntern.makeForm("robotomy request", "Target");
		if (rrf)
		{
			try
			{
				Bureaucrat intern("Intern", 150);
				intern.signForm(*rrf);
			}
			catch (std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			delete rrf;
		}
	}

	std::cout << "\n=== Intern copy constructor ===" << std::endl;
	{
		Intern otherIntern(someRandomIntern);
		AForm *form = otherIntern.makeForm("presidential pardon", "Copy Target");
		if (form)
		{
			try
			{
				Bureaucrat boss("Boss2", 1);
				boss.signForm(*form);
				boss.executeForm(*form);
			}
			catch (std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			delete form;
		}
	}

	std::cout << "\n=== Signed but grade too low to execute ===" << std::endl;
	{
		AForm *ppf = someRandomIntern.makeForm("presidential pardon", "Prisoner");
		if (ppf)
		{
			try
			{
				Bureaucrat signer("Signer", 25);
				Bureaucrat executor("Executor", 100);
				signer.signForm(*ppf);
				executor.executeForm(*ppf);
			}
			catch (std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			delete ppf;
		}
	}

	std::cout << "\n=== Execute unsigned form ===" << std::endl;
	{
		AForm *scf = someRandomIntern.makeForm("shrubbery creation", "test");
		if (scf)
		{
			try
			{
				Bureaucrat boss("Boss3", 1);
				boss.executeForm(*scf);
			}
			catch (std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			delete scf;
		}
	}

	std::cout << "\n=== Multiple unknown forms ===" << std::endl;
	{
		AForm *f1 = someRandomIntern.makeForm("vacation request", "me");
		AForm *f2 = someRandomIntern.makeForm("", "nobody");
		if (f1)
			delete f1;
		if (f2)
			delete f2;
	}

	return 0;
}
