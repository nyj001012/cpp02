/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:19:48 by yena              #+#    #+#             */
/*   Updated: 2023/06/17 19:18:36 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
}

Point::Point(const Point &object): _x(object.getX()), _y(object.getY()) {
}

Point &Point::operator=(const Point &ref) {
  if (this != &ref) {
    const_cast<Fixed &>(this->_x) = const_cast<Fixed &>(ref.getX());
    const_cast<Fixed &>(this->_y) = const_cast<Fixed &>(ref.getY());
  }
  return (*this);
}

Point::~Point(void) {
}

Fixed const &Point::getX(void) const {
  return (this->_x);
}

Fixed const &Point::getY(void) const {
  return (this->_y);
}
