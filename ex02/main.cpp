/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:54:53 by gmalyana          #+#    #+#             */
/*   Updated: 2025/04/19 15:55:57 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main() {
    Bureaucrat ceo("CEO", 1);
    Bureaucrat intern("Intern", 150);

    ShrubberyCreationForm garden("Home");
    RobotomyRequestForm robotomy("Alice");
    PresidentialPardonForm pardon("Bob");

    ceo.signForm(garden);
    ceo.signForm(robotomy);
    ceo.signForm(pardon);

    ceo.executeForm(garden);    // Success (creates "Home_shrubbery")
    intern.executeForm(robotomy); // Fails (grade too low)
    ceo.executeForm(pardon);    // Success (prints pardon message)

    return 0;
}
