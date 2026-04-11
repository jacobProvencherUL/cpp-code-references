/**
 * \file EmployeException.h
 * \brief 
 * \author etudiant
 * \version 
 * \date 2017-12-01
 */

#ifndef EMPLOYEEXCEPTION_H_
#define EMPLOYEEXCEPTION_H_

#include <stdexcept>

class EmployeException : public std::runtime_error{
public:
	EmployeException(const std::string& p_raison): std::runtime_error(p_raison){}
};

class EmployeDejaPresentException: public EmployeException{
public:
	EmployeDejaPresentException(const std::string& p_raison): EmployeException(p_raison){}
};

class EmployeNonPresentException: public EmployeException{
public:
	EmployeNonPresentException(const std::string& p_raison): EmployeException(p_raison){}
};

#endif /* EMPLOYEEXCEPTION_H_ */
