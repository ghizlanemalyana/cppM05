#ifndef BEREAUCRAT_HPP
#define BEREAUCRAT_HPP

#include <iostream>
#include <string>

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
			virtual const char * what() const throw(){
				return "Grade is too high (minimum is 1)";
			}
	};
	class GradeTooLowException : public std::exception{
		public:
			virtual const char * what() const throw(){
				return "Grade is too low (maximum is 150)";
			}
	};
	int getGrade() const;
	const std::string getName() const; // is it nececcery to use &?

	void incrementGrade();
	void decrementGrade();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
#endif