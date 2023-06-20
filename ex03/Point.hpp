/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:19:48 by yena              #+#    #+#             */
/*   Updated: 2023/06/17 17:28:30 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP02_EX03_POINT_HPP_
#define CPP02_EX03_POINT_HPP_

# include "Fixed.hpp"
# include "font.hpp"

/**
 * @brief Point class
 */
class Point {
 private:
  Fixed const _x;
  Fixed const _y;

 public:
  Point(void);
  Point(const float x, const float y);
  Point(const Point &object);
  Point &operator=(const Point &ref);
  ~Point(void);
  Fixed const &getX(void) const;
  Fixed const &getY(void) const;
};

#endif //CPP02_EX03_POINT_HPP_
