/**
 * Copyright (C) 2011 Eric Huang
 *
 * This file is part of rectpack.
 *
 * rectpack is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * rectpack is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with rectpack. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DIMENSIONS_H
#define DIMENSIONS_H

#include "Integer.h"
#include <iostream>

class Component;
class Dimensions;
class RDimensions;

class Dimensions {
  friend std::ostream& operator<<(std::ostream& os, const Dimensions& d);

 public:
  Dimensions();
  Dimensions(const Dimensions& d);
  Dimensions(const RDimensions& d);
  Dimensions(UInt nWidth, UInt nHeight, UInt nLength);
  Dimensions(const Component* c);
  void initialize(UInt nWidth, UInt nHeight, UInt nLength);
  void initMax();
  void initMin();
  void print(std::ostream& os) const;
  void print() const;
  bool canFit(int nWidth, int nHeight, int nLength) const;
  ~Dimensions();
  bool square() const;
  const Dimensions& operator=(const Dimensions& d);
  bool operator<(const Dimensions& d) const;
  bool operator>(const Dimensions& d) const;
  bool operator==(const Dimensions& d) const;
  bool operator!=(const Dimensions& d) const;
  bool rotatedEqual(const Dimensions& d) const;
  void rotate();
  void setArea();
  float ratioW() const;
  float ratioH() const;
  float ratioL() const;
  UInt m_nWidth;
  UInt m_nHeight;
  UInt m_nLength;
  UInt m_nMinDim;
  UInt m_nArea;
  DimsFunctor *m_pRotation; // Represents the current rotation of the rectangle.
};

std::ostream& operator<<(std::ostream& os, const Dimensions& d);

#endif // DIMENSIONS_H
