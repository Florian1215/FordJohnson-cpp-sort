/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:02:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/03/19 16:02:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


/*  CONSTRUCTOR / DESTRUCTOR ------------------------------------------------ */
PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(char **args) {
	for (int i = 0; args[i] != NULL; ++i)
		_initArray.push_back(new Pair(catoi(args[i])));
}

PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }

PmergeMe::~PmergeMe() {
	for (size_t i = 0; i < _pairArray.size(); ++i)
		delete _pairArray[i];
}

/*  OPERATOR OVERLOADING ---------------------------------------------------- */
PmergeMe	&PmergeMe::operator=(const PmergeMe &rhs) {
	if (this != &rhs)
		this->_initArray = rhs._initArray;
	return (*this);
}

/*  METHOD ------------------------------------------------------------------ */
void	printPairStack(const vecPair &_pairArray) {
	std::cout << "Pair stack: ";
	for (size_t i = 0; i < _pairArray.size(); ++i) {
		std::cout << _pairArray[i] << ", ";
	}
	std::cout << std::endl << std::endl;
}

vecInt	PmergeMe::fordJohnsonSort() {
	if (_initArray.empty())
		throw std::runtime_error("Empty array");
	_pairArray = _initArray;
	_sortPairArray.clear();

	_createAllPairs();
	_fordJohnsonSort();

	return (convertVector(_pairArray));
}

/*  PRIVATE METHOD - Pair --------------------------------------------------- */
void	PmergeMe::_createAllPairs() {
	while (_pairArray.size() > 1)
		_createPairs();
}

void	PmergeMe::_createPairs() {
	for (vecPair::iterator it = _pairArray.begin(); it != _pairArray.end(); ++it) {
		Pair	*pair1 = *it;

		_pairArray.erase(it);
		if (it == _pairArray.end()) {
			_overflowPair.push_back(pair1);
			return ;
		}
		Pair	*pair2 = *it;

		_pairArray.erase(it);
		_pairArray.insert(it, new Pair(pair1, pair2));
	}
	_overflowPair.push_back(NULL);
}

/*  PRIVATE METHOD - Sort --------------------------------------------------- */
void	PmergeMe::_fordJohnsonSort() {
	while (not _pairArray.front()->isBasePair()) {
		_initInsertSort();
		_jacobsthalNumbers();
		_pairArray = _sortPairArray;
		_sortPairArray.clear();
	}
}

void	PmergeMe::_initInsertSort() {
	_sortPairArray.push_back(_pairArray[0]->getPairLow());
	_sortPairArray.push_back(_pairArray[0]->getPairHigh());
	delete _pairArray[0];
	_pairArray.erase(_pairArray.begin());

	for (size_t i = 0; i < _pairArray.size(); ++i) {
		_sortPairArray.push_back(_pairArray[i]->getPairHigh());
		const Pair	*tmp_delete = _pairArray[i];

		_pairArray[i] = _pairArray[i]->getPairLow();
		delete tmp_delete;
	}

	const int	j = _sortPairArray[0]->getNPair() + 1;
	if (_overflowPair[j] != NULL)
		_pairArray.push_back(_overflowPair[j]);
}

void	PmergeMe::_jacobsthalNumbers() {
	int	jacobsthalNumber = 1;
	int	prevJacobsthalNumber = 1;
	int	indexJacobsthal = 1;

	while (!_pairArray.empty()) {
		_insertLowPairs(jacobsthalNumber, prevJacobsthalNumber, indexJacobsthal);
		const int	tpm = jacobsthalNumber;
		jacobsthalNumber = prevJacobsthalNumber * 2 + jacobsthalNumber;
		prevJacobsthalNumber = tpm;
		indexJacobsthal++;
	}
}

void	PmergeMe::_insertLowPairs(const int jacobsthalNumber, const int prevJacobsthalNumber, const int indexJacobsthal) {
	int			i = jacobsthalNumber - (prevJacobsthalNumber + 1);
	int			max = static_cast<int>(std::pow(2, indexJacobsthal)) - 1;
	const int	lowSize = static_cast<int>(_pairArray.size());
	const int	highSize = static_cast<int>(_sortPairArray.size());

	if (max >= highSize)
		max = highSize - 1;
	if (i >= lowSize)
		i = lowSize - 1;
	for (; i >= 0; --i) {
		const int	insert_idx = _binarySearch(_pairArray[i], max);
		_sortPairArray.insert(_sortPairArray.begin() + insert_idx, _pairArray[i]);
		_pairArray.erase(_pairArray.begin() + i);
	}
}

int	PmergeMe::_binarySearch(const Pair *item, int high) const {
	int	low = 0;

	while (low <= high) {
		const int	mid = low + (high - low) / 2;

		if (item->high() >= _sortPairArray[mid]->high()) {
			low = mid + 1;
			if (item->high() == _sortPairArray[mid]->high())
				break ;
		}
		else
			high = mid - 1;
	}
	return (low);
}
