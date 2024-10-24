/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:59:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/10/11 17:59:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Pair.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
Pair::Pair() : _pairHigh(NULL), _pairLow(NULL), _basePair(false), _high(-1), _nPair(0) { }

Pair::Pair(Pair *pair1, Pair *pair2) : _basePair(false), _nPair(pair1->getNPair() + 1) {
	if (pair1->high() > pair2->high()) {
		_high = pair1->high();
		_pairHigh = pair1;
		_pairLow = pair2;
	}
	else {
		_high = pair2->high();
		_pairHigh = pair2;
		_pairLow = pair1;
	}
}

Pair::Pair(int value) : _pairHigh(NULL), _pairLow(NULL), _basePair(true), _high(value), _nPair(-1) { }

Pair::Pair(const Pair &src) { *this = src; }

Pair::~Pair() {
	delete _pairHigh;
	delete _pairLow;
}


// OPERATOR OVERLOADING --------------------------------------------------------
Pair &Pair::operator=(const Pair &rhs) {
	if (this != &rhs) {
		this->_pairHigh = rhs._pairHigh;
		this->_pairLow = rhs._pairLow;
		this->_basePair = rhs._basePair;
		this->_high = rhs._high;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream& os, const Pair *pair) {
	const char start[4] = {'(', '[', '{', '<'};
	const char end[4] = {')', ']', '}', '>'};

	if (pair == NULL)
		os << "n";
	else if (pair->isBasePair())
		os << pair->high();
	else {
		int	print = pair->getNPair() % 4;

		os << start[print] << " " << pair->getPairLow() << ", " << pair->getPairHigh() << " " << end[print];
	}
	return os;
}


// GETTER - SETTER -------------------------------------------------------------
Pair	*Pair::getPairHigh() const { return (_pairHigh); }

Pair	*Pair::getPairLow() const { return (_pairLow); }

bool	Pair::isBasePair() const { return (_basePair); }

int	Pair::high() const { return (_high); }

int	Pair::getNPair() const { return (_nPair); }
