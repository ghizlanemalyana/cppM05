/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:44:39 by gmalyana          #+#    #+#             */
/*   Updated: 2025/04/15 17:40:37 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name("titi"), gradeToSign(60), gradeToExecute(30){
	isSigned = false;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute): name(name), gradeToSign(5), gradeToExecute(5){
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Bureaucrat::GradeTooLowException();
	this->isSigned = false;
}
Form::Form(const Form &other): name(other.getName()), gradeToSign(other.getGradeToSign()), gradeToExecute(other.getGradeToExecute()){
	this->isSigned = other.isSigned;
}
Form& Form::operator=(const Form &other){
	if(this != &other){
		this->isSigned = other.getGradeToSign();
	}
	return *this;
}
Form::~Form(){}

bool Form::getIsSigned() const{
	if (isSigned)
		return true;
	else
		return false;
}
std::string Form::getName() const{
	return name;
}
int Form::getGradeToSign() const{
	return gradeToSign;
}
int Form::getGradeToExecute() const{
	return gradeToExecute;
}
const char * Form::GradeTooHighException::what() const throw(){
	return "Grade is too high (minimum is 1)";
}
const char * Form::GradeTooLowException::what() const throw(){
	return "Grade is too low (maximum is 150)";
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign) {
        throw Form::GradeTooLowException();  // This immediately exits the function
    }
    isSigned = true;  // Only reached if grade is sufficient
}
std::ostream& operator<<(std::ostream& os, const Form& form){
	os << form.getName() << ", form grade to sign " << form.getGradeToSign() << ", form grade to execute " << form.getGradeToExecute() << ".";
	return os;
}

