/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:20:01 by yena              #+#    #+#             */
/*   Updated: 2023/06/17 18:54:21 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float getDotProduct(Point const a, Point const b) {
  return (a.getX() * b.getX() + a.getY() * b.getY());
}

/**
 * @brief Check if point is in triangle.
 * Calculate the vector of each side of the triangle and the vector from the point to the vertex.
 * If the cross product of the vector of each side and the vector from the point to the vertex is the same direction, the point is in the triangle.
 * @param a
 * @param b
 * @param c
 * @param point
 * @return true if point is in triangle
 */
bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Point ab, bc, ca, ap, bp, cp;
  float dotProdABAP, dotProdBCBP, dotProdCACP;

  ab = Point(b.getX() - a.getX(), b.getY() - a.getY());
  bc = Point(c.getX() - b.getX(), c.getY() - b.getY());
  ca = Point(a.getX() - c.getX(), a.getY() - c.getY());
  ap = Point(point.getX() - a.getX(), point.getY() - a.getY());
  bp = Point(point.getX() - b.getX(), point.getY() - b.getY());
  cp = Point(point.getX() - c.getX(), point.getY() - c.getY());
  dotProdABAP = getDotProduct(ab, ap);
  dotProdBCBP = getDotProduct(bc, bp);
  dotProdCACP = getDotProduct(ca, cp);
  if (dotProdABAP > 0 && dotProdBCBP > 0 && dotProdCACP > 0)
    return true;
  return false;
}
