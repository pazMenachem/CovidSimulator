//
// Created by Paz_m on 12/01/2022.
//

#ifndef ASSIGMENTFIVE__ELEMENTIMP_H_
#define ASSIGMENTFIVE__ELEMENTIMP_H_

#include "Element.h"


template<class X>
Element<X>::Element()
: xDim(0), fDim(0), xArr(), fArr(), rank(-1)
{}

template<class X>
X *Element<X>::getF() const
{
  return fArr;
}

template<class X>
X *Element<X>::getX() const
{
  return xArr;
}

template<class X>
int Element<X>::getRank() const
{
  return rank;
}

template<class X>
void Element<X>::setF(X *f)
{
  if(!this->fArr)
    this->fArr = new double[fDim];

  for(int i = 0; i < fDim; i++)
    this->fArr[i] = f[i];
}

template<class X>
void Element<X>::setX(X *x)
{
  if(!this->xArr)
    this->xArr = new double[xDim];

  for(int i = 0; i < xDim; i++)
    this->xArr[i] = x[i];
}

template<class X>
void Element<X>::setRank(int r)
{
  this->rank = r;
}

template<class X>
Element<X> &Element<X>::operator=(Element<double> &other) {

  if(&other == this)
    return *this;

  setXDim(other.xDim);
  setFDim(other.fDim);

  if(!this->xArr)
    this->xArr = new double[xDim];
  if(!this->fArr)
    this->fArr = new double[fDim];

  setX(other.xArr);
  setF(other.fArr);
  setRank(other.rank);

  return *this;
}

template<class X>
void Element<X>::setXDim(int dim) {
  this->xDim = dim;
}

template<class X>
void Element<X>::setFDim(int dim) {
  this->fDim = dim;
}
template<class X>
Element<X>::~Element() {
  delete xArr;
  delete fArr;
}

#endif //ASSIGMENTFIVE__ELEMENTIMP_H_
