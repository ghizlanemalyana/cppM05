/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:37:21 by gmalyana          #+#    #+#             */
/*   Updated: 2025/04/15 17:58:40 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


Bureaucrat::Bureaucrat(): name("ghizlane"){
	grade = 128;
}
Bureaucrat::Bureaucrat(const std::string name, int grade): name(name){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.getName()){
	this->grade = other.grade;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other){
	if (this != &other){
		this->grade = other.grade;
	}
	return *this;
}
Bureaucrat::~Bureaucrat(){}

const std::string Bureaucrat::getName() const{
	return name;
}
int Bureaucrat::getGrade() const{
	return grade;
}
void Bureaucrat::incrementGrade(){
	if (grade -1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade--;
}

void Bureaucrat::decrementGrade(){
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade++;
}
const char * Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade is too high (minimum is 1)";
}

const char * Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade is too low (maximum is 150)";
}
void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signs " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " cannot sign " << form.getName() << " because: " << e.what() << std::endl;
	}
}
// void Bureaucrat::signForm(const Form &form){
//     try {
//         form.beSigned(*this);  // Try to sign
//         std::cout << name << " signed " << form.getName() << std::endl;
//     } catch (const std::exception &e) {
//         std::cout << name << " couldn't sign " << form.getName() 
//                   << " because " << e.what() << std::endl;
//     }
// }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat){
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}