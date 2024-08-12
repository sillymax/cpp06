/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 05:39:04 by ychng             #+#    #+#             */
/*   Updated: 2024/08/12 20:39:19 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout << "./convert <value_to_cast>" << endl;
		return 0;
	}
	ScalarConverter::convert(argv[1]);
}
