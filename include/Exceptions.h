/**
*   @file   Exceptions.h
*   @brief  Exceptions needed for project
*   @author Erica Nordin
*   @date   Implementation phase due March 13 2017
*/

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
/**
 *@brief thrown for any loading errors
 */
class read_in_error : public std::runtime_error
{
public:
    read_in_error(const char* errMessage) :
        std::runtime_error(errMessage)
        {

        }
};
/**
 *@brief thrown for any coding errors in main.cpp
 */
class wrong_env : public std::invalid_argument
{
public:
    wrong_env(const char* errMessage) :
        std::invalid_argument(errMessage)
        {

        }
};

		  /**
		   *@brief any errors in menu options
		   */
class switchcase_error : public std::invalid_argument
{
public:
    switchcase_error(const char* errMessage) :
        std::invalid_argument(errMessage)
        {
        }
};

/*
class illegal_size_error: public std::runtime_error
{
public:
    illegal_size_error(const char* errMessage) :
        std::runtime_error(errMessage)
    {
    }
};

class widget_operation_failed_error: public std::runtime_error
{
public:
    widget_operation_failed_error(const char* errMessage) :
        std::runtime_error(errMessage)
    {
    }
};

class widget_error: public std::runtime_error
{
public:
    widget_error(const char* errMessage) :
        std::runtime_error(errMessage)
    {
    }
};
*/
#endif // EXCEPTIONS_H
