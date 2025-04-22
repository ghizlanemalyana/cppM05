/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:57:18 by gmalyana          #+#    #+#             */
/*   Updated: 2025/04/19 21:45:49 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

void ShrubberyCreationForm::executeAction() const{
	std::ofstream outfile((target + "_shrubbery").c_str());
	if (!outfile.is_open()) {
		std::cerr << "Failed to create shrubbery file!" << std::endl;
		return;
	}
	outfile << "       _-_\n"
        << "    /~~   ~~\\\n"
        << " /~~         ~~\\\n"
        << "{               }\n"
        << " \\  _-     -_  /\n"
        << "   ~  \\\\ //  ~\n"
        << "       | |\n"
        << "       | |\n"
        << "      // \\\\\n";
	// outfile << "       _-_-_\n";
	// outfile << "    _-       -_\n";
	// outfile << "  _-             -_\n";
	// outfile << " -                 -\n";
	// outfile << "   -_         _-\n";
	// outfile << "      -_   _-\n";
	// outfile << "         -\n";
	outfile.close();
	std::cout << "Shrubbery created in " << target + "_shrubbery" << std::endl;
}

// outfile << "       _-_\n"
//         << "    /~~   ~~\\\n"
//         << " /~~         ~~\\\n"
//         << "{               }\n"
//         << " \\  _-     -_  /\n"
//         << "   ~  \\\\ //  ~\n"
//         << "_- -   | | _- _\n"
//         << "  _ -  | |   -_\n"
//         << "      // \\\\\n";