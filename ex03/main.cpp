/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:19:43 by yena              #+#    #+#             */
/*   Updated: 2023/06/17 19:42:52 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int getCoordinates(std::string name, float &x, float &y) {
  std::cout << "Enter the x and y coordinates of point "
            << name << ":" << std::endl;
  std::cout << "x: ";
  std::cin >> x;
  if (std::cin.fail()) {
    std::cout << F_RED << "Invalid input" << FB_DEFAULT << std::endl;
    return (1);
  }
  std::cout << "y: ";
  std::cin >> y;
  if (std::cin.fail()) {
    std::cout << F_RED << "Invalid input" << FB_DEFAULT << std::endl;
    return (1);
  }
  return (0);
}

int main(void) {
  float ax, ay, bx, by, cx, cy, px, py;
  Point a, b, c, point;

  if (getCoordinates("A", ax, ay)
      || getCoordinates("B", bx, by)
      || getCoordinates("C", cx, cy)
      || getCoordinates("P", px, py))
    return (1);
  a = Point(ax, ay);
  b = Point(bx, by);
  c = Point(cx, cy);
  point = Point(px, py);
  if (bsp(a, b, c, point))
    std::cout << "The point is " << F_CYAN << "inside" << FB_DEFAULT
              << " the triangle" << std::endl;
  else
    std::cout << "The point is " << F_MAGENTA << "outside" << FB_DEFAULT
              << " the triangle" << std::endl;
  return (0);
}
