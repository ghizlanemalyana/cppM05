/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:55:14 by gmalyana          #+#    #+#             */
/*   Updated: 2025/04/22 18:15:40 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {};

Intern::Intern(const Intern &other){
	*this = other;
}

Intern &Intern::operator=(const Intern &other){
	(void)other;// protection if this == &other
	return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubbery(const std::string &target) {
	return new ShrubberyCreationForm(target);
}
AForm* Intern::createRobotomy(const std::string &target) {
	return new RobotomyRequestForm(target);
}
AForm* Intern::createPresidential(const std::string &target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target){
	AForm* (Intern::*createForms[])(const std::string &target) = {&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPresidential};
	std::string forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	
	for (int i = 0; i < 3; i++){
		if (formName == forms[i]){
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*createForms[i])(target);
		}
	}
	std::cout << "Intern can't create " << formName << std::endl;
	return nullptr;
}