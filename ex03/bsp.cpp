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

/**
 * @brief Get absolute value.
 * @param a
 * @return
 */
float bsp_abs(float a) {
  if (a < 0)
    return (a * -1);
  return (a);
}

/**
 * Calculate triangle area.
 * @param p1
 * @param p2
 * @param p3
 * @return area of triangle
 */
float getTriangleArea(Point const p1, Point const p2, Point const p3) {
  float area;

  area = bsp_abs(((p1.getX() * p2.getY()
      + p2.getX() * p3.getY()
      + p3.getX() * p1.getY())
      - (p2.getX() * p1.getY()
          + p3.getX() * p2.getY()
          + p1.getX() * p3.getY())).toFloat()) / 2;
  return (area);
}

/**
 * Check if point is on A, B, C
 * Calculate cross product of vector OA & OP, OB & OP, OC & OP. (O means origin).
 * If cross product is 0, then sine value of OA OP is 0.
 * That means the angle between OA and OP is 0.
 * @param a
 * @param b
 * @param c
 * @param point
 * @return
 */
bool is_on_side(Point const a, Point const b, Point const c, Point const point) {

  float crossProductAP, crossProductBP, crossProductCP;

  crossProductAP = (a.getX() * point.getY() - point.getX() * a.getY()).toFloat();
  crossProductBP = (b.getX() * point.getY() - point.getX() * b.getY()).toFloat();
  crossProductCP = (c.getX() * point.getY() - point.getX() * c.getY()).toFloat();
  if (!crossProductAP)
    return (true);
  else if (!crossProductBP)
    return (true);
  else if (!crossProductCP)
    return (true);
  else
    return (false);
}

/**
 * @brief Check if point is in triangle.
 * Calculate area of triangle consist of ABP, BCP, CAP.
 * If areaABP + areaBCP + areaCAP is same with area of triangle ABC,
 * then point P is inside the triangle.
 * But if one of area is 0, then P is on the side AB or BC or CA, and return false.
 * @param a
 * @param b
 * @param c
 * @param point
 * @return true if point is in triangle
 */
bool bsp(Point const a, Point const b, Point const c, Point const point) {
  float triangleAreaABP, triangleAreaBCP, triangleAreaCAP, triangleArea;

  if (is_on_side(a, b, c, point))
    return (false);
  triangleAreaABP = getTriangleArea(a, b, point);
  triangleAreaBCP = getTriangleArea(b, c, point);
  triangleAreaCAP = getTriangleArea(c, a, point);
  triangleArea = getTriangleArea(a, b, c);
  return (triangleAreaABP + triangleAreaBCP + triangleAreaCAP == triangleArea);
}
