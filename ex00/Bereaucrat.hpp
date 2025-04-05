#ifndef BEREAUCRAT_HPP
#define BEREAUCRAT_HPP

#include <iostream>

class Bereaucrat{
	private:
		const std::string name;
		int grade;
	public:
	class GradeTooHighException : public std::exception{
		public:
			virtual const char * what() const throw(){
				return "Grade is too high (minimum is 1)";
			}
	};
	class GradeTooLowException : public std::exception{
		public:
			virtual const char * what() const throw {
				return "Grade is too low (maximum is 150)";
	};
	std::string getGrade():
	void setName(std::string name);

	void incrementGrade(void);
	void decrementGrade(void);
};
#endif