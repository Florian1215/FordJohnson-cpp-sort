/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:17:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/10/24 22:17:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

vecInt	convertVector(const vecPair &pairs) {
	vecInt	sortArray;

	for (vecPair::const_iterator sortPairIt = pairs.begin(); sortPairIt < pairs.end(); ++sortPairIt)
		sortArray.push_back((*sortPairIt)->high());
	return (sortArray);
}
