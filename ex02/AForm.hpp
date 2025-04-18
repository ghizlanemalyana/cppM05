/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:35:39 by gmalyana          #+#    #+#             */
/*   Updated: 2025/04/18 21:41:36 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
	private:
		const std::string name; // Name of the form
		bool isSigned; // Indicates if the form is signed
		const int gradeToSign; // Minimum grade needed to sign
		const int gradeToExecute; // Minimum grade needed to execute

	public:
		AForm();
		AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm();

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

	void beSigned(const Bureaucrat &bureaucrat) const;
	// to make the class abstruct
	virtual void executeAction() const = 0;
	void execute(const Bureaucrat &executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif