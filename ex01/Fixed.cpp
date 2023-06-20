/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:19:32 by yena              #+#    #+#             */
/*   Updated: 2023/06/17 16:31:24 by yena             ###   ########.fr       */
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

Fixed::Fixed(const int fixed_point_value) {
  std::cout << "Int constructor called" << std::endl;
  this->_fixed_point_value = fixed_point_value << this->_FRACTIONAL_BITS;
}

Fixed::Fixed(const float floating_point_number) {
  std::cout << "Float constructor called" << std::endl;
  this->_fixed_point_value = roundf(
      floating_point_number * (1 << this->_FRACTIONAL_BITS)
  );
}

Fixed::Fixed(const Fixed &object) {
  std::cout << "Copy constructor called" << std::endl;
  *this = object;
}

Fixed &Fixed::operator=(const Fixed &ref) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->_fixed_point_value = ref.getRawBits();
  return (*this);
}

int Fixed::getRawBits() const {
  return (this->_fixed_point_value);
}

void Fixed::setRawBits(const int raw_bits) {
  this->_fixed_point_value = raw_bits;
}

/**
 * convert the fixed-point value to a floating-point value
 * @return floating-point value of _fixed_point_value;
 */
float Fixed::toFloat(void) const {
  return ((float) this->_fixed_point_value
      / (float) (1 << this->_FRACTIONAL_BITS));
}

/**
 * convert the fixed-point value to an integer value
 * @return integer value of _fixed_point_value
 */
int Fixed::toInt(void) const {
  return (this->_fixed_point_value >> this->_FRACTIONAL_BITS);
}

std::ostream &operator<<(std::ostream &os, const Fixed &ref) {
  os << ref.toFloat();
  return os;
}
