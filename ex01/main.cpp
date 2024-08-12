/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 00:52:27 by ychng             #+#    #+#             */
/*   Updated: 2024/08/13 01:09:40 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Data first;
	first.name = "Max";
	first.age = 21;
	first.next = NULL;
	
	// Data second;

	uintptr_t raw = Serializer::serialize(&first);
	Data* decodedData = Serializer::deserialize(raw);
	
	if (decodedData == &first)
		cout << "Successful the data are a match." << endl;
	else
		cout << "Failed the data doest not match." << endl;
}

