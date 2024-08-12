/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 05:13:41 by ychng             #+#    #+#             */
/*   Updated: 2024/08/12 21:09:26 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <stdexcept>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::isprint;
using std::fixed;
using std::setprecision;
using std::stringstream;
using std::numeric_limits;
using std::exception;

ScalarConverter::ScalarConverter()
{
	cout << "ScalarConverter constructed" << endl;
}

ScalarConverter::~ScalarConverter()
{
	cout << "ScalarConveter destructed" << endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	(void)src;
	cout << "ScalarConverter copied" << endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
	if (this != &src)
	{
		(void)src;
		cout << "ScalarConverter assigned" << endl;
	}
	return *this;
}

bool ScalarConverter::convertToInt(const string& src, int& result)
{
	stringstream stream(src);
	long temp;
	if (!(stream >> temp))
		return false;
	if (!(temp >= numeric_limits<int>::min() && temp <= numeric_limits<int>::max()))
		return false;
	result = static_cast<int>(temp);
	return true;
}

bool ScalarConverter::convertToFloat(const string& src, float& result)
{
	stringstream stream(src);
	double temp;
	if (!(stream >> temp))
		return false;
	result = static_cast<float>(temp);
	return true;
}

bool ScalarConverter::convertToDouble(const string& src, double& result)
{
	stringstream stream(src);
	if (!(stream >> result))
		return false;
	return true;
}

bool ScalarConverter::convertToLongLong(const string& src, long long& result)
{
	stringstream stream(src);
	long long temp;
	if (!(stream >> temp))
		return false;
	if (!(temp >= numeric_limits<long long>::min() && temp <= numeric_limits<long long>::max()))
		return false;
	result = temp;
	return true;
}

bool ScalarConverter::isChar(const string& src)
{
	// if it's just the char itself
	// if (src.length() == 1)
		// return true;
	if (src.length() == 3 && src[0] == '\'' && src[2] == '\'')
		return true;
	return false;
}

bool ScalarConverter::isInt(const string& src)
{
	if (src.empty())
		return false;

	size_t i = 0;

	while (i < src.length() && isspace(src[i]))
		i++;
	if (i == src.length())
		return false;
	if (src[i] == '+' || src[i] == '-')
		i++;
	if (i == src.length() || !isdigit(src[i]))
		return false;
	for (size_t j = i; j < src.length(); j++)
	{
		if (!isdigit(src[j]))
			return false;
	}

	try
	{
		long long value;
		convertToLongLong(src, value);
		return value >= numeric_limits<int>::min() && value <= numeric_limits<int>::max();
	}
	catch (const exception &e)
	{
		return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const string& src)
{
	if (src.empty())
		return false;

	size_t i = 0;
	bool digitBeforeDecimal = false;
	bool decimalFound = false;
	bool digitAfterDecimal = false;

	while (i < src.length() && isspace(src[i]))
		i++;
	if (i == src.length())
		return false;
	if (src[i] == '+' || src[i] == '-')
		i++;
	if (i == src.length())
		return false;
	for (; i < src.length() && isdigit(src[i]); i++)
		digitBeforeDecimal = true;
	if (i < src.length() && src[i] == '.')
	{
		decimalFound = true;
		i++;
	}
	for (; i < src.length() && isdigit(src[i]); i++)
		digitAfterDecimal = true;
	if ((i == src.size() - 1) && (src[i] == 'f' || src[i] == 'F') && \
		(digitBeforeDecimal || digitAfterDecimal) && decimalFound)
		return true;
	return false;
}

bool ScalarConverter::isDouble(const string& src)
{
	if (src.empty())
		return false;

	size_t i = 0;
	bool digitBeforeDecimal = false;
	bool decimalFound = false;
	bool digitAfterDecimal = false;
	bool exponentFound = false;
	bool digitAfterExponent = false;

	while (i < src.length() && isspace(src[i]))
		i++;
	if (i == src.length())
		return false;
	if (src[i] == '+' || src[i] == '-')
		i++;
	if (i == src.length())
		return false;
	for (; i < src.length() && isdigit(src[i]); i++)
		digitBeforeDecimal = true;
	if (i < src.length() && src[i] == '.')
	{
		decimalFound = true;
		i++;
	}
	for (; i < src.length() && isdigit(src[i]); i++)
		digitAfterDecimal = true;
	if (i < src.length() && (src[i] == 'e' || src[i] == 'E'))
	{
		exponentFound = true;
		i++;
		if (i < src.length() && (src[i] == '+' || src[i] == '-'))
			i++;
		for (;i < src.length() && isdigit(src[i]); i++)
			digitAfterExponent = true;
	}
	if (i == src.length() && decimalFound && \
		(digitBeforeDecimal || digitAfterDecimal) && \
		(!exponentFound || (exponentFound && digitAfterExponent)))
		return true;
	return false;
}

bool ScalarConverter::isOther(const string& src)
{
	string specials[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	for (int i = 0; i < 6; i++)
	{
		if (src == specials[i])
			return true;
	}
	return false;
}

void ScalarConverter::printChar(const string& str)
{
	char c = str[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		c = str[1];
	if (isprint(c))
		cout << "char: '" << c << "'" << endl;
	else
		cout << "char: Non displayable" << endl;
	cout << "int: " << i << endl;
	cout << "float: " << fixed << setprecision(1) << f << "f" << endl;
	cout << "double: " << d << endl;
}

void ScalarConverter::printInt(const string& str)
{
	char c;
	int i;
	float f;
	double d;

	convertToInt(str, i);
	if (i >= numeric_limits<char>::min() && i <= numeric_limits<char>::max())
	{
		c = static_cast<char>(i);
		if (isprint(c))
			cout << "char: '" << c << "'" << endl;
		else
			cout << "char: Non displayable" << endl;
	}
	else
		cout << "char: impossible" << endl;
	cout << "int: " << i << endl;
	f = static_cast<float>(i);
	cout << "float: " << fixed << setprecision(1) << f << "f" << endl;
	d = static_cast<double>(i);
	cout << "double: " << d << endl;
}

void ScalarConverter::printFloat(const string& str)
{
	char c;
	int i;
	float f;
	double d;

	convertToFloat(str, f);
	if (f >= numeric_limits<char>::min() && f <= numeric_limits<char>::max())
	{
		c = static_cast<char>(f);
		if (isprint(c))
			cout << "char: '" << c << "'" << endl;
		else
			cout << "char: Non displayable" << endl;
	}
	else
		cout << "char: impossible" << endl;

	if (f >= numeric_limits<int>::min() && f <= numeric_limits<int>::max())
	{
		i = static_cast<int>(f);
		cout << "int: " << i << endl;
	}
	else
		cout << "int: impossible" << endl;

	cout << "float: " << fixed << setprecision(1) << f << "f" << endl;

	d = static_cast<double>(f);
	cout << "double: " << d << endl;
}

void ScalarConverter::printDouble(const string& str)
{
	char c;
	int i;
	float f;
	double d;

	convertToDouble(str, d);
	if (d >= numeric_limits<char>::min() && d <= numeric_limits<char>::max())
	{
		c = static_cast<char>(d);
		if (isprint(c))
			cout << "char: '" << c << "'" << endl;
		else
			cout << "char: Non displayable" << endl;
	}
	else
		cout << "char: impossible << endl" << endl;

	if (d >= numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
	{
		i = static_cast<int>(d);
		cout << "int: " << i << endl;
	}
	else
		cout << "int: impossible" << endl;
	f = static_cast<float>(d);
	cout << "float: " << fixed << setprecision(1) << f << "f" << endl;
	cout << "double: " << d << endl;
}

void ScalarConverter::printOther(const string& str)
{
	cout << "char: impossible" << endl;
	cout << "int: impossible" << endl;
	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		cout << "float: " << str << endl;
		string trimmedFloatPostFix = str.substr(0, str.length() - 1);
		cout << "double: " << trimmedFloatPostFix << endl;
	}
	else
	{
		cout << "float: " << str << "f" << endl;
		cout << "double: " << str << endl;
	}
}

void ScalarConverter::convert(const string& str)
{
	if (isChar(str))
		printChar(str);
	else if (isInt(str))
		printInt(str);
	else if (isFloat(str))
		printFloat(str);
	else if (isDouble(str))
		printDouble(str);
	else if (isOther(str))
		printOther(str);
	else
		cout << "Wrong input." << endl;
}