/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 00:36:30 by ychng             #+#    #+#             */
/*   Updated: 2024/08/13 01:08:30 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

using std::cout;
using std::endl;

Serializer::Serializer()
{
	cout << "Serializer constructed" << endl;
}

Serializer::~Serializer()
{
	cout << "Serializer destructed" << endl;
}

Serializer::Serializer(const Serializer& src)
{
	(void)src;
	cout << "Seralizer copied" << endl;
}

Serializer& Serializer::operator=(const Serializer& src)
{
	if (this != &src)
	{
		(void)src;
		cout << "Serializer assigned" << endl;
	}
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}


Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}