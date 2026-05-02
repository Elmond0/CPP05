/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:43:59 by elmondo           #+#    #+#             */
/*   Updated: 2026/05/02 11:32:57 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("default"), _signed(false), _gradeSign(150), _gradeExec(150) {}

Form::Form(const std::string &name, int gradeSign, int gradeExec)
	: _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	: _name(other._name), _signed(other._signed),
	  _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	return (*this);
}

Form::~Form() {}

std::string Form::getName(void) const
{
	return (_name);
}

bool Form::isSigned(void) const
{
	return (_signed);
}

int Form::getGradeSign(void) const
{
	return (_gradeSign);
}

int Form::getGradeExec(void) const
{
	return (_gradeExec);
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeSign)
		throw GradeTooLowException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

std::ostream &operator<<(std::ostream &o, const Form &f)
{
	o << f.getName() << ", form signed: " << (f.isSigned() ? "yes" : "no")
	  << ", sign grade: " << f.getGradeSign()
	  << ", exec grade: " << f.getGradeExec() << ".";
	return o;
}
