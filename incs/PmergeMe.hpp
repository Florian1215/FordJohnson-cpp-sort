/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:02:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/10/25 01:59:02 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

/*  INCLUDE ----------------------------------------------------------------- */
# include <algorithm>
# include <cmath>
# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>
# include <stdexcept>
# include <vector>

# include "Pair.hpp"


/*  PROTOTYPE --------------------------------------------------------------- */
typedef std::vector<int>	vecInt;
typedef std::vector<Pair *>	vecPair;

int		catoi(const char *str);
vecInt	convertVector(const vecPair &pairs);


class PmergeMe {
public:
/*  CONSTRUCTOR - DESTRUCTOR ------------------------------------------------ */
	explicit PmergeMe(char **args);
	PmergeMe(const PmergeMe &src);
	~PmergeMe();

/*  OPERATOR OVERLOADING ---------------------------------------------------- */
	PmergeMe	&operator=(const PmergeMe &rhs);

/*  METHOD ------------------------------------------------------------------ */
	vecInt		fordJohnsonSort();

private:
	PmergeMe();
	void		_createAllPairs();
	void		_createPairs();
	void		_fordJohnsonSort();
	void		_initInsertSort();
	void		_jacobsthalNumbers();
	void		_insertLowPairs(int jacobsthalNumber, int prevJacobsthalNumber, int indexJacobsthal);
	int			_binarySearch(const Pair *item, int high) const;
	vecPair		_initArray;
	vecPair		_pairArray;
	vecPair		_sortPairArray;
	vecPair		_overflowPair;
};

#endif
