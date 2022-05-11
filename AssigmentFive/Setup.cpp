#include <sstream>
#include "Setup.h"
#include <stdlib.h>


Setup::Setup(int argc, char** argv)
: input(), output(), popSize(), xDim(), fDim(), iters()
{
  /// checks validity of input file and throws custom exception if it's not valid
  try{
    checkInit(argc, argv);
  }
  catch(FileNotFound& e){
    e.printError();
    exit(1);
  }
  catch(InvalidDefinition& e){
    e.printError();
    exit(1);
  }
  catch(PopulationDefinition& e){
    e.printError();
    exit(1);
  }
}

bool Setup::checkInit(int argc, char** argv)
{
  /// checks validity - if so, initializes all data members. else - throws exception
  if(argc != 3)
    return false;

  input.open(argv[1]);
  output.open(argv[2]);

  if(!input || !output)
    throw FileNotFound(argv[1]);

  string firstLine;
  if(getline(input, firstLine)) // checks all parameters needed
  {
    stringstream ss(firstLine);
    if(!(ss >> popSize >> xDim >> fDim >> iters)) // tries to initialize data members from the text
      throw InvalidDefinition(argv[1]);

    if(fDim > xDim)
      throw InvalidDefinition(argv[1]);
  }

  int lineCount = 0, numCount = 0;
  string line;

  while(getline(input, line)){ // counts the number of lines
    stringstream ss(line);
    lineCount++;
    double y;
    while(ss >> y){ // counts the dimension of each vector
      numCount++;
    }
    if(numCount != xDim) // vector's dim != stated dim - illegal
      throw PopulationDefinition(argv[1], lineCount + 1);
    numCount = 0;
  }

  if(lineCount != popSize) // number of vectors != stated amount - illegal
    throw PopulationDefinition(argv[1], lineCount);

  else
    return true;
}

double** Setup::makeInit()
{
  /// creates an array of vectors based on init file (after validation)
  double **result;
  result = new double *[popSize];
  for(int x = 0; x < popSize; x++)
    result[x] = new double[xDim];

  input.clear();
  input.seekg(0); // returns to the top of the file after checkInit()

  string line;

  for(int i = -1; i < popSize; i++){
    getline(input, line); // each line is a vector
    stringstream ss(line);    // splitting the line to vector's coordinates

    for(int j = 0; j < xDim; j++)
      if(i != -1)  // skipping first line (not a vector)
        ss >> result[i][j];
      else
        break;
  }
  return result;
}

ofstream &Setup::getOutput()
{
  return this->output;
}

Setup::~Setup()
{
  output.close();
  input.close();
}

int Setup::getXDim() const
{
  return this->xDim;
}

int Setup::getFDim() const
{
  return this->fDim;
}

int Setup::getIterations() const
{
  return this->iters;
}

int Setup::getPopSize() const
{
  return this->popSize;
}