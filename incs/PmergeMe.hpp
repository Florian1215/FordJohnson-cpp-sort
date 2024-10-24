/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:02:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/03/19 16:02:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

// INCLUDE ---------------------------------------------------------------------
# include <iostream>
# include <cstdlib>
# include <algorithm>
# include <cmath>
# include <ctime>
# include <iomanip>
# include <stdexcept>
# include <vector>

# include "Pair.hpp"


// PROTOTYPE ------------------------------------------------------------------
typedef std::vector<int>	vecInt;
typedef std::vector<Pair *>	vecPair;

int		catoi(char *str);
vecInt	convertVector(const vecPair &pairs);


class PmergeMe {
public:
// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
	explicit PmergeMe(char **args);
	PmergeMe(const PmergeMe &src);
	~PmergeMe();

// OPERATOR OVERLOADING --------------------------------------------------------
	PmergeMe	&operator=(const PmergeMe &rhs);

// METHOD ----------------------------------------------------------------------
	vecInt		fordJohnsonSort();

private:
	PmergeMe();
	void		_createAllPairs();
	void		_createPairs();
	void		_fordJohnsonSort();
	void		_initInsertSort();
	void		_jacobsthalNumbers();
	void		_insertLowPairs(int jacobsthalNumber, int prevJacobsthalNumber, int indexJacobsthal);
	int			_binarySearch(Pair *item, int high);
	vecPair		_initArray;
	vecPair		_pairArray;
	vecPair		_sortPairArray;
	vecPair		_overflowPair;
};

#endif
