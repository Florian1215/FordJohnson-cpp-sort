/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floriang <floriang@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:59:00 by floriang          #+#    #+#             */
/*   Updated: 2024/10/11 17:59:00 by floriang         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP09_02_PAIR_HPP
# define CPP09_02_PAIR_HPP

# include <iostream>

class Pair {
public:
/*  CONSTRUCTOR - DESTRUCTOR ------------------------------------------------ */
	Pair(Pair *pair1, Pair *pair2);
	Pair(int value);
	Pair(const Pair &src);
	~Pair();

/*  OPERATOR OVERLOADING ---------------------------------------------------- */
	Pair		&operator=(const Pair &rhs);

/*  GETTER - SETTER --------------------------------------------------------- */
	Pair 		*getPairHigh() const;
	Pair 		*getPairLow() const;
	bool 		isBasePair() const;
	int			high() const;
	int			getNPair() const;

private:
	Pair();

	Pair		*_pairHigh;
	Pair		*_pairLow;
	bool		 _basePair;
	int		 	_high;
	int			_nPair;
};

std::ostream	&operator<<(std::ostream& os, const Pair *pair);


#endif
