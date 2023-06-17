/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:19:32 by yena              #+#    #+#             */
/*   Updated: 2023/06/17 17:03:34 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP02_FIXED_HPP
#define CPP02_FIXED_HPP

# include <iostream>
# include <cmath>

/**
 * @brief Fixed class
 */
class Fixed {
 private:
  int _fixed_point_value; ///< An integer to store the fixed point value.
  static const int _FRACTIONAL_BITS = 8; ///< A static constant integer to store the number of fractional bits

 public:
  Fixed(void);
  ~Fixed(void);
  Fixed(const int fixed_point_value);
  Fixed(const float floating_point_number);
  Fixed(const Fixed &object);
  Fixed &operator=(const Fixed &ref);
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& ref);

#endif //CPP02_FIXED_HPP
