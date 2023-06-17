/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:20:01 by yena              #+#    #+#             */
/*   Updated: 2023/06/17 19:40:49 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float getDotProduct(Point const a, Point const b) {
  Fixed dotProduct;

  dotProduct = a.getX() * b.getX() + a.getY() * b.getY();
  return (dotProduct.toFloat());
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
  Fixed dotProdABAP, dotProdBCBP, dotProdCACP;

  ab = Point((b.getX() - a.getX()).toFloat(), (b.getY() - a.getY()).toFloat());
  bc = Point((c.getX() - b.getX()).toFloat(), (c.getY() - b.getY()).toFloat());
  ca = Point((a.getX() - c.getX()).toFloat(), (a.getY() - c.getY()).toFloat());
  ap = Point((point.getX() - a.getX()).toFloat(),
             (point.getY() - a.getY()).toFloat());
  bp = Point((point.getX() - b.getX()).toFloat(),
             (point.getY() - b.getY()).toFloat());
  cp = Point((point.getX() - c.getX()).toFloat(),
             (point.getY() - c.getY()).toFloat());
  dotProdABAP = getDotProduct(ab, ap);
  dotProdBCBP = getDotProduct(bc, bp);
  dotProdCACP = getDotProduct(ca, cp);
  if (dotProdABAP > 0 && dotProdBCBP > 0 && dotProdCACP > 0)
    return true;
  return false;
}
