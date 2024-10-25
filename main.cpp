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

std::string	isSort(const vecInt &array) {
	for (size_t i = 0; i < array.size() - 1; ++i) {
		if (array[i + 1] < array[i])
			return ("not sort");
	}
	return ("sort");
}

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "./PmergeMe [\\d+]" << std::endl;
	else {
		try {
			PmergeMe	obj(++av);
			vecInt		sortVector = obj.fordJohnsonSort();

			std::cout << isSort(sortVector) << std::endl;
		}
		catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}