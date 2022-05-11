//
// Created by arbel on 1/19/2022.
//

#ifndef ASSIGMENTFIVE_INVALIDDEFINITION_H
#define ASSIGMENTFIVE_INVALIDDEFINITION_H

#include <iostream>

using namespace std;

///
/// An exception class which will be thrown if a there's an invalid definition.
/// No need for "The Big Three" since its an exception class
///
class InvalidDefinition
{

private:
    string fileName;

public:
    /// Constructor
    /// \param str the name of the file
    explicit InvalidDefinition(const string& str);

    /// prints the error
    void printError() const;
};


#endif //ASSIGMENTFIVE_INVALIDDEFINITION_H
