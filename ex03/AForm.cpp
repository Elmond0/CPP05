/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <elmondo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:43:59 by elmondo           #+#    #+#             */
/*   Updated: 2026/05/02 11:32:34 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("default"), _signed(false), _gradeSign(150), _gradeExec(150) {}

AForm::AForm(const std::string &name, int gradeSign, int gradeExec)
	: _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: _name(other._name), _signed(other._signed),
	  _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	return (*this);
}

AForm::~AForm() {}

std::string AForm::getName(void) const
{
	return (_name);
}

bool AForm::isSigned(void) const
{
	return (_signed);
}

int AForm::getGradeSign(void) const
{
	return (_gradeSign);
}

int AForm::getGradeExec(void) const
{
	return (_gradeExec);
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeSign)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeExec)
		throw GradeTooLowException();
	action();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("form not signed");
}

std::ostream &operator<<(std::ostream &o, const AForm &f)
{
	o << f.getName() << ", form signed: " << (f.isSigned() ? "yes" : "no")
	  << ", sign grade: " << f.getGradeSign()
	  << ", exec grade: " << f.getGradeExec() << ".";
	return o;
}
