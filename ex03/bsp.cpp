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

  area = bsp_abs((p1.getX().toFloat() * (p2.getY() - p3.getY()).toFloat()
      + p2.getX().toFloat() * (p3.getY() - p1.getY()).toFloat()
      + p3.getX().toFloat() * (p1.getY() - p2.getY()).toFloat()) / 2);
  return (area);
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

  triangleAreaABP = getTriangleArea(a, b, point);
  triangleAreaBCP = getTriangleArea(b, c, point);
  triangleAreaCAP = getTriangleArea(c, a, point);
  triangleArea = getTriangleArea(a, b, c);
  std::cout << triangleAreaABP << std::endl;
  std::cout << triangleAreaBCP << std::endl;
  std::cout << triangleAreaCAP << std::endl;
  std::cout << triangleArea << std::endl;
  if (!triangleAreaABP || !triangleAreaBCP || !triangleAreaCAP)
    return false;
  return (triangleAreaABP + triangleAreaBCP + triangleAreaCAP == triangleArea);
}
