/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:34:53 by gmalyana          #+#    #+#             */
/*   Updated: 2025/04/19 15:42:16 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat{
	private:
		const std::string name;
		int grade; 
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

	class GradeTooHighException : public std::exception{
		public:
			virtual const char * what() const throw();
	};
	class GradeTooLowException : public std::exception{
		public:
			virtual const char * what() const throw();
	};
	int getGrade() const;
	const std::string getName() const; // is it nececcery to use &?

	void incrementGrade();
	void decrementGrade();
	void signForm(AForm &form);
	void executeForm(const AForm &form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
#endif