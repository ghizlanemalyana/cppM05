/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bereaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:18:10 by gmalyana          #+#    #+#             */
/*   Updated: 2025/04/08 18:19:58 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bereaucrat.hpp"

Bureaucrat::Bureaucrat(){
	this->name = "ghizlane";
	this->grade = 128;
}
Bureaucrat::Bureaucrat(const std::string name, int grade): name(name){
	if (grade < 1)
		Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		Bureaucrat::GradeTooLowException();
	this->grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other){
	this->name = other.name;
	this->grade = other.grade;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
	if (this != &other){
		this->name = other.name;
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
	if (grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade--;
}

void Bureaucrat::decrementGrade(){
	if (grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat){
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}