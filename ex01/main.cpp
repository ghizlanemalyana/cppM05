/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:38:39 by gmalyana          #+#    #+#             */
/*   Updated: 2025/04/15 17:53:50 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat bureaucrat("Ghizlane", 5);
	Form form("Form1", 10, 20);

	std::cout << bureaucrat << std::endl;
	std::cout << form << std::endl;

	try
	{
		form.beSigned(bureaucrat);
		std::cout << "Form signed successfully!" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}