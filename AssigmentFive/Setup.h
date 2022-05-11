//
// Created by Paz_m on 14/01/2022.
//

#ifndef ASSIGMENTFIVE__SETUP_H_
#define ASSIGMENTFIVE__SETUP_H_

#include <iostream>
#include <fstream>
#include "FileNotFound.h"
#include "InvalidDefinition.h"
#include "PopulationDefinition.h"

using namespace std;

/// class to get all the info for the simulation from files
class Setup
{
 private:
  ifstream input;
  ofstream output;
  int popSize;  // number of elements
  int xDim;     // dimension of variable vector
  int fDim;     // dimension of images vector
  int iters;    // number of iterations

 public:
  /// NO NEED FOR OPERATOR=, COPY C'TOR - DEFAULT IS SUFFICIENT
  Setup(int argc, char** argv);

  /// Checks whether the arguments are valid
  /// Will throw an exception if one of the arguments is not
  /// \param argc Number of program arguments
  /// \param argv Char array of parameters names
  /// \return True - if valid, False - if not
  bool checkInit(int argc, char** argv);

  /// Reads the program arguments and creates a new X matrix
  /// \return new matrix
  double** makeInit();

  /// \return Out put field
  ofstream& getOutput();

  /// setup Destructor, closes files.
  ~Setup();

  /// \return X array dimension
  int getXDim() const;

  /// \return F array dimension
  int getFDim() const;

  /// \return Amount of Iteration the program has been given
  int getIterations() const;

  /// \return Elements pool size
  int getPopSize() const;
};
#endif //ASSIGMENTFIVE__SETUP_H_
