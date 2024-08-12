/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychng <ychng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 01:27:17 by ychng             #+#    #+#             */
/*   Updated: 2024/08/13 01:57:53 by ychng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <stdexcept>

using std::cout;
using std::endl;
using std::exception;

Base* generate(void)
{
	short randomNum = rand() % 3;
	
	if (randomNum == 0)
		return new A();
	else if (randomNum == 1)
		return new B();
	else
		return new C();
	cout << "Random function not working." << endl;
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		cout << "A" << endl;
	else if (dynamic_cast<B*>(p))
		cout << "B" << endl;
	else if (dynamic_cast<C*>(p))
		cout << "C" << endl;
	else
		cout << "Fail" << endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		cout << "A" << endl;
	}
	catch (const exception& e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		cout << "B" << endl;
	}
	catch (const exception& e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		cout << "C" << endl;
	}
	catch (const exception& e) {}
}

int main()
{
	Base* p;
	for (int i = 0; i < 5; i++)
	{
		cout << "Random [" << i << "]" << endl;
		p = generate();
		cout << "PTR: ";
		identify(p);
		cout << "REF: ";
		identify(*p);
		delete p;
		cout << endl;
	}
}
