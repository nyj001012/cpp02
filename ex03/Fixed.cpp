/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:19:32 by yena              #+#    #+#             */
/*   Updated: 2023/06/17 17:17:33 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
  this->_fixed_point_value = 0;
}

Fixed::~Fixed() {
}

Fixed::Fixed(const int fixed_point_value) {
  this->_fixed_point_value = fixed_point_value << this->_FRACTIONAL_BITS;
}

Fixed::Fixed(const float floating_point_number) {
  this->_fixed_point_value = roundf(
      floating_point_number * (1 << this->_FRACTIONAL_BITS)
  );
}

Fixed::Fixed(const Fixed &object) {
  *this = object;
}

Fixed &Fixed::operator=(const Fixed &ref) {
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

Fixed Fixed::operator++(void) {
  this->_fixed_point_value++;
  return (*this);
}

Fixed Fixed::operator--(void) {
  this->_fixed_point_value--;
  return (*this);
}

Fixed Fixed::operator++(int) {
  Fixed before_increment(*this);
  operator++();
  return (before_increment);
}

Fixed Fixed::operator--(int) {
  Fixed before_decrement(*this);
  operator--();
  return (before_decrement);
}

bool Fixed::operator>(const Fixed &ref) const {
  return (this->_fixed_point_value > ref.getRawBits());
}

bool Fixed::operator<(const Fixed &ref) const {
  return (this->_fixed_point_value < ref.getRawBits());
}

bool Fixed::operator>=(const Fixed &ref) const {
  return (this->_fixed_point_value >= ref.getRawBits());
}

bool Fixed::operator<=(const Fixed &ref) const {
  return (this->_fixed_point_value <= ref.getRawBits());
}

bool Fixed::operator==(const Fixed &ref) const {
  return (this->_fixed_point_value == ref.getRawBits());
}

bool Fixed::operator!=(const Fixed &ref) const {
  return (this->_fixed_point_value != ref.getRawBits());
}

Fixed Fixed::operator+(const Fixed &ref) const {
  return (Fixed(this->toFloat() + ref.toFloat()));
}

Fixed Fixed::operator-(const Fixed &ref) const {
  return (Fixed(this->toFloat() - ref.toFloat()));
}

Fixed Fixed::operator*(const Fixed &ref) const {
  return (Fixed(this->toFloat() * ref.toFloat()));
}

Fixed Fixed::operator/(const Fixed &ref) const {
  return (Fixed(this->toFloat() / ref.toFloat()));
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
  return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  return (a > b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return (a < b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return (a > b ? a : b);
}

std::ostream &operator<<(std::ostream &os, const Fixed &ref) {
  os << ref.toFloat();
  return os;
}
