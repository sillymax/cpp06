/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 05:12:01 by ychng             #+#    #+#             */
/*   Updated: 2024/08/12 06:48:52 by ychng            ###   ########.fr       */
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

	void printChar(const string& str) const;
	void printInt(const string& str) const;
	void printFloat(const string& str) const;
	void printDouble(const string& str) const;
	void printOther(const string& str) const;

	static void convert(const string& str);

};

#endif
