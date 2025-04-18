/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:35:14 by gmalyana          #+#    #+#             */
/*   Updated: 2025/04/18 21:44:14 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): name("titi"), gradeToSign(60), gradeToExecute(30){
	isSigned = false;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute): name(name), gradeToSign(5), gradeToExecute(5){
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Bureaucrat::GradeTooLowException();
	this->isSigned = false;
}
AForm::AForm(const AForm &other): name(other.getName()), gradeToSign(other.getGradeToSign()), gradeToExecute(other.getGradeToExecute()){
	this->isSigned = other.isSigned;
}
AForm& AForm::operator=(const AForm &other){
	if(this != &other){
		this->isSigned = other.getGradeToSign();
	}
	return *this;
}
AForm::~AForm(){}

bool AForm::getIsSigned() const{
	if (isSigned)
		return true;
	else
		return false;
}
std::string AForm::getName() const{
	return name;
}
int AForm::getGradeToSign() const{
	return gradeToSign;
}
int AForm::getGradeToExecute() const{
	return gradeToExecute;
}
const char * AForm::GradeTooHighException::what() const throw(){
	return "Grade is too high (minimum is 1)";
}
const char * AForm::GradeTooLowException::what() const throw(){
	return "Grade is too low (maximum is 150)";
}

void AForm::beSigned(const Bureaucrat &bureaucrat)const {
    if (bureaucrat.getGrade() > gradeToSign) {
        throw AForm::GradeTooLowException();  // This immediately exits the function
    }
    isSigned = true;  // Only reached if grade is sufficient
}
std::ostream& operator<<(std::ostream& os, const AForm& form){
	os << form.getName() << ", form grade to sign " << form.getGradeToSign() << ", form grade to execute " << form.getGradeToExecute() << ".";
	return os;
}
// void AForm::execute(const Bureaucrat &executor) const {
//     if (!_isSigned)
//         throw NotSignedException();  // Custom exception
//     if (executor.getGrade() > _gradeToExecute)
//         throw GradeTooLowException();
//     executeAction();  // Calls the concrete form's action
// }