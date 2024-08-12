/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 05:12:01 by ychng             #+#    #+#             */
/*   Updated: 2024/08/12 20:33:24 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

using std::string;

class ScalarConverter
{
public:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& src);
	ScalarConverter& operator=(const ScalarConverter& src);

	static bool convertToInt(const string& str, int& result);
	static bool convertToFloat(const string& str, float& result);
	static bool convertToDouble(const string& str, double& result);
	static bool convertToLongLong(const string& src, long long& result);

	static bool isChar(const string& str);
	static bool isInt(const string& str);
	static bool isFloat(const string& str);
	static bool isDouble(const string& str);
	static bool isOther(const string& str);

	static void printChar(const string& str);
	static void printInt(const string& str);
	static void printFloat(const string& str);
	static void printDouble(const string& str);
	static void printOther(const string& str);

	static void convert(const string& str);

};

#endif
