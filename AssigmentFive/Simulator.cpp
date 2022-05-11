//
// Created by Paz_m on 14/01/2022.
//
#include "Simulator.h"
#include <stdlib.h>

Simulator::Simulator(int argc, char **argv)
:setup(argc,argv), sizePool(setup.getPopSize()), ePool(new Element<double>[sizePool * 2]),
fSize(setup.getFDim()), xSize(setup.getXDim())
{
  for(int i = 0; i < sizePool*2; i++){
    ePool[i].setXDim(xSize);
    ePool[i].setFDim(fSize);
  }
}

void Simulator::ElementsReordering(Element<double>* &elements)
{
  Element<double> minEle;
  Element<double> tmp;

  int minIndex, i;
  for(i = 0; i < sizePool; i++)
  {

    minIndex = findMin(i);
    minEle = elements[minIndex];

    tmp = elements[i];
    elements[i] = minEle;
    elements[minIndex] = tmp;

  }
}

void Simulator::ParetoSorting()
{
  double** fMat = createFMat();
  int* ranks = ParetoRanking(fMat);

  elementsReRanking(ranks);
  ElementsReordering(ePool);

  for(int i = 0; i<sizePool; i++)
    delete[] fMat[i];
  delete[] fMat;
  delete[] ranks;

}

void Simulator::elementsReRanking(const int* newRanking)
{
  for(int i = 0; i<sizePool; i++)
    ePool[i].setRank(newRanking[i]);
}

void Simulator::printFile(Element<double> *elements) {
  int row,col;
  ofstream& writeHere = setup.getOutput();
  for(row = 0; row < sizePool; row++)
  {
    for(col = 0; col < fSize; col++)
    {
      if(col + 1 == fSize)
        writeHere << elements[row].getF()[col];
      else
        writeHere << elements[row].getF()[col] << ' ';
    }
    writeHere << endl;
  }
}

double** Simulator::createFMat()
{
  double** matrix = new double*[sizePool];
  int i;

  for(i = 0; i<sizePool; i++)
    matrix[i] = new double[fSize];

  for(int row = 0; row < sizePool; row++)
    for(int col = 0; col < fSize; col++)
      matrix[row][col] = ePool[row].getF()[col];

  return matrix;
}

void Simulator::randomVector(double * &p_double) const
{
  srand(time(0));

  for(int i = 0; i < xSize; i++){
    double sum = 0;
    for(int j = 0; j < 10; j++){
      double x = rand();
      x /= RAND_MAX;
      sum += x;
    }
    p_double[i] = (sum / 9);
  }
}

double Simulator::createImage(Element<double>& e, int i) const
{
  double sum = 0;
  for (int j = 0; j < xSize; j++) {
    sum += pow(e.getX()[j] - i - 1, 2.0);
  }
  return sum;
}

double* Simulator::createF(Element<double>& e) const
{
  double* f = new double[fSize];
  for (int i = 0; i < fSize; i++) {
    f[i] = createImage(e, i);
  }
  return f;
}

void Simulator::randomChildVect(Element<double> &e, double *randomVect, double *&p_double) const
{
  for (int i = 0; i < xSize; i++)
    p_double[i] = e.getX()[i] + randomVect[i];
}

void Simulator::go()
{
  double** matrix = setup.makeInit();
  for(int i = 0; i < sizePool; i++){
    ePool[i].setX(matrix[i]);
    ePool[i].setF(createF(ePool[i]));
  }

  for(int i = 0; i<sizePool; i++)
    delete matrix[i];
  delete[] matrix;

  ParetoSorting();
  setPoolSize(sizePool * 2);

  for(int i = 0; i < setup.getIterations(); i++){
    randomizeUpperHalf();
    ParetoSorting();
  }
  printFile(this->ePool);
}

void Simulator::setPoolSize(int size)
{
  this->sizePool = size;
}

void Simulator::randomizeUpperHalf()
{
  double* random = new double[xSize];
  double* newChild = new double[xSize];
  double* newF;
  int halfSize = sizePool / 2;

  for(int i = halfSize; i < sizePool; i++){
    randomVector(random);
    randomChildVect(ePool[i - halfSize], random, newChild);
    ePool[i].setX(newChild);
    newF = createF(ePool[i]);
    ePool[i].setF(newF);
  }

  delete[] newF;
  delete[] random;
  delete[] newChild;
}

int Simulator::findMin(int& currentIndex) const {
  int minIndex = currentIndex;
  for(int i = currentIndex; i<sizePool; i++)
    if(ePool[i].getRank() < ePool[minIndex].getRank())
      minIndex = i;
  return minIndex;
}

int *Simulator::ParetoRanking(double **mat)
{
  int* ranks = new int[sizePool];
  for(int i = 0; i < sizePool; i++)
    ranks[i] = 0;

  for(int curr = 0; curr < sizePool; curr++){
    bool smaller = false;
    for(int next = 0; next < sizePool; next++){
      for(int i = 0; i < fSize; i++){
        if(curr != next){
          if(mat[curr][i] <= mat[next][i]){
            if(mat[curr][i] < mat[next][i]){
              smaller = true;
            }
          }
          else{
            smaller = false;
            break;
          }
        }
      }
      if(smaller)
        ranks[next]++;

      smaller = false;
    }
  }
  return ranks;
}

Simulator::~Simulator()
{
  delete[] ePool;
}
