/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:12:24 by gmalyana          #+#    #+#             */
/*   Updated: 2025/04/10 18:13:14 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b1("Ghizlane", 1);
	Bureaucrat b2("Amine", 150);
	Bureaucrat b3("Mohamed", 128);
	
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;
	
	b3.incrementGrade();
	std::cout << b3 << std::endl;
	
	b3.decrementGrade();
	std::cout << b3 << std::endl;
	
	try{
		b1.incrementGrade();
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	
	try{
		b2.decrementGrade();
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
}