/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:26:02 by gmalyana          #+#    #+#             */
/*   Updated: 2025/04/19 21:31:45 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), target(target) {}

void RobotomyRequestForm::executeAction() const {
    std::cout << "** BZZZZZT! CRRRACK! WHIRRR! **" << std::endl;
    std::srand(std::time(0));
    bool success = (std::rand() % 2 == 0);
    
    if (success)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy on " << target << " failed. (Critical error)" << std::endl;
}