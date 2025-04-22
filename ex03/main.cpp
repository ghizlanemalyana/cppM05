/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:54:53 by gmalyana          #+#    #+#             */
/*   Updated: 2025/04/22 17:40:27 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Intern someRandomIntern;
        Bureaucrat boss("Boss", 1);

        std::cout << "\n--- Testing Form Creation ---" << std::endl;
        AForm* forms[4];
        
        // Test valid forms
        forms[0] = someRandomIntern.makeForm("shrubbery creation", "Garden");
        forms[1] = someRandomIntern.makeForm("robotomy request", "Bender");
        forms[2] = someRandomIntern.makeForm("presidential pardon", "Alice");
        
        // Test invalid form
        forms[3] = someRandomIntern.makeForm("fake form", "Nobody");

        std::cout << "\n--- Testing Form Signing/Execution ---" << std::endl;
        for (int i = 0; i < 3; i++) {
            if (forms[i]) {
                boss.signForm(*forms[i]);
                boss.executeForm(*forms[i]);
                delete forms[i];
                std::cout << std::endl;
            }
        }

    } catch (std::exception & e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
