/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:19:32 by yena              #+#    #+#             */
/*   Updated: 2023/06/13 15:53:21 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
  this->_fixed_point_value = 0;
  std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &object) {
  this->_fixed_point_value = object._fixed_point_value;
  std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &ref) {
  if (this != &ref) {
    this->_fixed_point_value = ref._fixed_point_value;
  }
  std::cout << "Assignation operator called" << std::endl;
  return (*this);
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member \033[0;31mfunction"
               " \033[0;35mcalled\033[0m" << std::endl;
  return (this->_fixed_point_value);
}

void Fixed::setRawBits(const int raw_bits) {
  this->_fixed_point_value = raw_bits;
}
