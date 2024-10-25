/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:04:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/03/19 16:04:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>

void		printArgs(char **argsv);
std::string	isSort(const vecInt &array);
void		printVector(const vecInt &array);

int	main(const int argc, char **argv)
{
	if (argc == 1)
		std::cout << "./PmergeMe [\\d+]" << std::endl;
	else {
		++argv;
		printArgs(argv);

		std::cout << std::endl;

		try {
			PmergeMe		obj(argv);
			const vecInt	sortVector = obj.fordJohnsonSort();

			std::cout << isSort(sortVector) << ": ";
			printVector(sortVector);
		}
		catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}

void	printArgs(char **argsv) {
	std::cout << "args: { ";
	for (int i = 0; argsv[i] != NULL; ++i) {
		std::cout << argsv[i];
		if (argsv[i + 1] != NULL)
			std::cout << ", ";
	}
	std::cout << " }" << std::endl;
}

std::string	isSort(const vecInt &array) {
	for (size_t i = 0; i < array.size() - 1; ++i) {
		if (array[i + 1] < array[i])
			return ("not sort");
	}
	return ("sort");
}

void	printVector(const vecInt &array) {
	std::cout << "{ ";
	for (size_t i = 0; i < array.size(); ++i) {
		std::cout << array[i];
		if (i != array.size() - 1)
			std::cout << ", ";
	}
	std::cout << " }" << std::endl;
}
