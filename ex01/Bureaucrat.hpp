/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:37:30 by gmalyana          #+#    #+#             */
/*   Updated: 2025/04/15 18:03:14 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

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
	void signForm(Form &form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
#endif