/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:19:32 by yena              #+#    #+#             */
/*   Updated: 2023/06/17 16:31:09 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
  std::cout << "Default constructor called" << std::endl;
  this->_fixed_point_value = 0;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &object) {
  std::cout << "Copy constructor called" << std::endl;
  this->_fixed_point_value = object.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &ref) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->_fixed_point_value = ref.getRawBits();
  return (*this);
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return (this->_fixed_point_value);
}

void Fixed::setRawBits(const int raw_bits) {
  this->_fixed_point_value = raw_bits;
}
