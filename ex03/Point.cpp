/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:19:48 by yena              #+#    #+#             */
/*   Updated: 2023/06/17 17:30:29 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) {
  this->_x = Fixed(0.0);
  this->_y = Fixed(0.0);
}

Point::Point(const float x, const float y) {
  this->_x = Fixed(x);
  this->_y = Fixed(y);
}

Point::Point(const Point &object) {
  *this = object;
}

Point &Point::operator=(const Point &ref) {
  this->_x = ref.getX();
  this->_y = ref.getY();
  return *this;
}

Point::~Point(void) {
}

Fixed const &Point::getX(void) const {
  return this->_x;
}

Fixed const &Point::getY(void) const {
  return this->_y;
}
