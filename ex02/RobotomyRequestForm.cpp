/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:26:02 by gmalyana          #+#    #+#             */
/*   Updated: 2025/04/18 21:30:37 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_CPP
#define ROBOTOMYREQUESTFORM_CPP

#include <iostream>
#include "AForm.hpp"

class RobotomyRequedstForm : public AForm {
	private:
		std::string target;
	public:
		RobotomyRequedstForm(const std::string &target);
		void executeAction() const;
};

#endif