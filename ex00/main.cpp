/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:18:23 by elmondo           #+#    #+#             */
/*   Updated: 2026/04/16 11:54:08 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{

	std::cout << "=== Construction tests ===" << std::endl;
	try
	{
		Bureaucrat a("Alice", 1);
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b("Bob", 150);
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Grade too high (constructor) ===" << std::endl;
	try
	{
		Bureaucrat c("Charlie", 0);
		std::cout << c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Grade too low (constructor) ===" << std::endl;
	try
	{
		Bureaucrat d("Dave", 151);
		std::cout << d << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Copy constructor ===" << std::endl;
	try
	{
		Bureaucrat original("Eve", 42);
		Bureaucrat copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy:     " << copy << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Assignment operator ===" << std::endl;
	try
	{
		Bureaucrat high("Frank", 10);
		Bureaucrat low("Grace", 100);
		std::cout << "Before: " << low << std::endl;
		low = high;
		std::cout << "After:  " << low << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Increment / Decrement ===" << std::endl;
	try
	{
		Bureaucrat worker("Hank", 50);
		std::cout << worker << std::endl;
		worker.incrementGrade();
		std::cout << "After increment: " << worker << std::endl;
		worker.decrementGrade();
		std::cout << "After decrement: " << worker << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Increment past grade 1 ===" << std::endl;
	try
	{
		Bureaucrat top("Ivy", 1);
		std::cout << top << std::endl;
		top.incrementGrade();
		std::cout << top << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Decrement past grade 150 ===" << std::endl;
	try
	{
		Bureaucrat bottom("Jack", 150);
		std::cout << bottom << std::endl;
		bottom.decrementGrade();
		std::cout << bottom << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Negative grade ===" << std::endl;
	try
	{
		Bureaucrat neg("Karl", -5);
		std::cout << neg << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Default constructor ===" << std::endl;
	try
	{
		Bureaucrat def;
		std::cout << def << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== Multiple increments ===" << std::endl;
	try
	{
		Bureaucrat climber("Leo", 3);
		std::cout << climber << std::endl;
		climber.incrementGrade();
		std::cout << "After 1st increment: " << climber << std::endl;
		climber.incrementGrade();
		std::cout << "After 2nd increment: " << climber << std::endl;
		climber.incrementGrade();
		std::cout << "After 3rd increment: " << climber << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
