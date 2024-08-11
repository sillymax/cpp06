/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 05:13:41 by ychng             #+#    #+#             */
/*   Updated: 2024/08/12 06:46:55 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

using std::cout;
using std::endl;
using std::string;
using std::isprint;
using std::fixed;
using std::setprecision;
using std::stoi;
using std::stof;
using std::stod;
using std::numeric_limits;

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
	cout << "ScalarConverter copied" << endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
	cout << "ScalarConverter assigned" << endl;
}

void ScalarConverter::printChar(const string& str) const
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

void ScalarConverter::printInt(const string& str) const
{
	char c;
	int i = stoi(str);
	float f;
	double d;

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

void ScalarConverter::printFloat(const string& str) const
{
	char c;
	int i;
	float f = stof(str);
	double d;

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

void ScalarConverter::printDouble(const string& str) const
{
	char c;
	int i;
	float f;
	double d = stod(str);

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

void ScalarConverter::printOther(const string& str) const
{
	cout << "char: impossible" << endl;
	cout << "int: impossible" << endl;
	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		cout << "float: " << str << endl;
		string trimmedFloatPostFix = str.substr(0, str.length() - 1);
		cout << "double: " << trimmedFloatPostFix << endl;
	}
	cout << "float: " << str << "f" << endl;
	cout << "double: " << str << endl;
}

void ScalarConverter::convert(const string& str)
{}