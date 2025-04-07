#ifndef BEREAUCRAT_HPP
#define BEREAUCRAT_HPP

#include <iostream>

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
	std::string getGrade();
	void setName(std::string name);

	void incrementGrade(void);
	void decrementGrade(void);
};
#endif