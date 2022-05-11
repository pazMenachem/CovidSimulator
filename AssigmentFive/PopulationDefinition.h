//
// Created by arbel on 1/19/2022.
//

#ifndef ASSIGMENTFIVE_POPULATIONDEFINITION_H
#define ASSIGMENTFIVE_POPULATIONDEFINITION_H

#include <iostream>

using namespace std;

///
/// An exception class which will be thrown if a there's a miss match between the population definitions.
/// No need for "The Big Three" since its an exception class
///
class PopulationDefinition
{

private:
    string fileName;
    int line;

public:
    /// Constructor
    /// \param str name of the file
    /// \param n number of line which the error occur
    PopulationDefinition(const string& str, int n);

    /// Prints the error
    void printError() const;
};


#endif //ASSIGMENTFIVE_POPULATIONDEFINITION_H
