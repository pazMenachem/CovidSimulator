//
// Created by Paz_m on 12/01/2022.
//

#ifndef ASSIGMENTFIVE__ELEMENT_H_
#define ASSIGMENTFIVE__ELEMENT_H_

#include <iostream>
///
/// Element is a generic class which holds a variable array (X array) and target array (F array)
/// further more, each Element has its rank.
/// There is no need for Copy C'tur - default one is good enough
/// X class have to implement the operator = inorder to use the class Element

template<class X>
class Element
{

 private:
  int xDim; // dimension of variables vector
  int fDim; // dimension of images vector
  X* xArr;
  X* fArr;
  int rank;

 public:

  /// Element Constructor
  Element();

  /// returns the F array
  X* getF() const;

  /// returns the X array
  X* getX() const;

  /// returns the element rank
  int getRank() const;

  /// Sets new X dimension for the Element
  /// \param dim - the dimension which will be settled
  void setXDim(int dim);

  /// Sets new F dimension for the Element
  /// \param dim - the dimension which will be settled
  void setFDim(int dim);

  /// Sets new F array
  /// \param f - the new F array which will be settled
  void setF(X* f);

  /// Sets new X array
  /// \param X - the new F array which will be settled
  void setX(X* x);

  /// Sets the new rank of the Element
  /// \param r - the new rank
  void setRank(int r);

  /// = operator
  /// \param other the element which his fields will be copied
  /// \return "New" element
  Element<X>& operator=(Element<double> &other);

  /// Destructor
  ~Element();
};


#include "ElementImp.h"

#endif //ASSIGMENTFIVE__ELEMENT_H_
