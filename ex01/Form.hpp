/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:44:43 by gmalyana          #+#    #+#             */
/*   Updated: 2025/04/15 18:05:50 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	private:
		const std::string name; // Name of the form
		bool isSigned; // Indicates if the form is signed
		const int gradeToSign; // Minimum grade needed to sign
		const int gradeToExecute; // Minimum grade needed to execute

	public:
		Form();
		Form(const std::string name, const int gradeToSign, const int gradeToExecute);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	class GradeTooHighException : public std::exception{
		public:
			virtual const char * what() const throw();
	};
	class GradeTooLowException : public std::exception{
		public:
			virtual const char * what () const throw();
	};

	void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif