/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catoi.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:22:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/10/11 19:22:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <stdexcept>

int catoi(const char *str) {
	char		*invalidChar;
	const long	value = std::strtol(str, &invalidChar, 10);

	if (*invalidChar)
		throw std::runtime_error("Invalid char");
	if (value < 0)
		throw std::runtime_error("Negative value");
	return (static_cast<int>(value));
}
