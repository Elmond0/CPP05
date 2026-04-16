/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:18:23 by elmondo           #+#    #+#             */
/*   Updated: 2026/04/16 11:58:39 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{

	std::cout << "=== Form creation ===" << std::endl;
	try
	{
		Form a("Tax Return", 50, 30);
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Form grade too high (constructor) ===" << std::endl;
	try
	{
		Form b("Impossible", 0, 10);
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Form grade too low (constructor) ===" << std::endl;
	try
	{
		Form c("Easy", 151, 10);
		std::cout << c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Sign form successfully ===" << std::endl;
	try
	{
		Bureaucrat boss("Alice", 1);
		Form doc("Contract", 50, 30);
		std::cout << boss << std::endl;
		std::cout << doc << std::endl;
		boss.signForm(doc);
		std::cout << doc << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Sign form fail (grade too low) ===" << std::endl;
	try
	{
		Bureaucrat intern("Bob", 150);
		Form doc("Secret File", 10, 5);
		std::cout << intern << std::endl;
		std::cout << doc << std::endl;
		intern.signForm(doc);
		std::cout << doc << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Multiple bureaucrats, one form ===" << std::endl;
	try
	{
		Bureaucrat low("Charlie", 100);
		Bureaucrat high("Diana", 5);
		Form report("Annual Report", 50, 25);
		std::cout << report << std::endl;
		low.signForm(report);
		std::cout << report << std::endl;
		high.signForm(report);
		std::cout << report << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Copy and assignment ===" << std::endl;
	try
	{
		Form original("Original", 42, 21);
		Form copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy:     " << copy << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Sign already signed form ===" << std::endl;
	try
	{
		Bureaucrat boss("Eve", 1);
		Form doc("Memo", 100, 50);
		boss.signForm(doc);
		std::cout << doc << std::endl;
		boss.signForm(doc);
		std::cout << doc << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Boundary: exact grade to sign ===" << std::endl;
	try
	{
		Bureaucrat exact("Frank", 50);
		Form doc("Boundary", 50, 25);
		std::cout << exact << std::endl;
		std::cout << doc << std::endl;
		exact.signForm(doc);
		std::cout << doc << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Boundary: one grade too low to sign ===" << std::endl;
	try
	{
		Bureaucrat almost("Grace", 51);
		Form doc("Restricted", 50, 25);
		std::cout << almost << std::endl;
		std::cout << doc << std::endl;
		almost.signForm(doc);
		std::cout << doc << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Form exec grade too high (constructor) ===" << std::endl;
	try
	{
		Form bad("Bad Exec", 10, 0);
		std::cout << bad << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
