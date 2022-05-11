//
// Created by arbel on 1/19/2022.
//

#include "InvalidDefinition.h"

InvalidDefinition::InvalidDefinition(const string &str)
: fileName(str)
{}

void InvalidDefinition::printError() const
{
    cerr << "ERROR: simulation definition in " << fileName << " is invalid\n";
}
