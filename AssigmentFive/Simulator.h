//
// Created by Paz_m on 14/01/2022.
//

#ifndef ASSIGMENTFIVE__SIMULATOR_H_
#define ASSIGMENTFIVE__SIMULATOR_H_

#include "Element.h"
#include "Setup.h"
#include <cmath>
///
/// Simulator class - run's the simulation
/// No need for Copy C'tur nor = operator since theres only one instance of Simulator
///
class Simulator
{


 private:
  Setup setup;
  int sizePool;
  Element<double>* ePool;
  int fSize;
  int xSize;

 public:
  /// Simulator Constructor
  /// \param argc Number of program arguments
  /// \param argv Char array of parameters names
  Simulator(int argc,char** argv);

  /// Destructor
  ~Simulator();

  /// Ranks the elements by their target vector
  /// \param mat - target vector
  /// \return New rank vector
  int* ParetoRanking(double** mat);

  /// Reorder the elements in the "Element Pool"
  /// \param elements - Array of Elements
  void ElementsReordering(Element<double>* &elements);

  /// Activates ParetoRanking and elements Reordering functions
  void ParetoSorting();


  /// Prints the final target vectors into a file
  /// \param elements - Array of Elements
  void printFile(Element<double>* elements);

  /// Sets the Elements ranks by their position in the pool
  /// \param newRanking - Array of new Ranks
  void elementsReRanking(const int* newRanking);

  /// Creates target matrix
  /// \return target matrix
  double** createFMat();

  /// Creates random vector with double elements
  /// \param p_double - empty double array
  void randomVector(double *&p_double) const;

  /// Creates double element using certain algorithm
  /// \param e - the element from the ePool, the function uses its X array
  /// \param i - index of element from the ePool
  /// \return new Double number
  double createImage(Element<double>& e, int i) const;

  /// Creates new F array ( target array )
  /// \param e - Element from the ePool
  /// \return new array of double elements
  double* createF(Element<double>& e) const;

  /// Creates new X array for a new Element
  /// \param e - Element from the ePool which his X array is used inorder to create new Element
  /// \param randomVect - Random X array
  /// \param p_double new empty Double array
  void randomChildVect(Element<double> &e, double *randomVect, double *&p_double) const;

  /// Main function which starts the simulation
  void go();

  /// Resize the number of Elements in the "Pool"
  /// \param size - new Pool size
  void setPoolSize(int size);

  /// Creates new Elements in the ePool
  /// each one of them will be given random X arrays
  /// from those random x arrays, new f arrays will be created
  void randomizeUpperHalf();

  /// finds the minimum rank of an Element from the given index
  /// \param currentIndex - Current index
  /// \return the minimum index
  int findMin(int& currentIndex) const;

};



#endif //ASSIGMENTFIVE__SIMULATOR_H_
