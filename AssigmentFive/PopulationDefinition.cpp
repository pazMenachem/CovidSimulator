//
// Created by arbel on 1/19/2022.
//

#include "PopulationDefinition.h"

PopulationDefinition::PopulationDefinition(const string &str, int n)
: fileName(str), line(n)
{}

void PopulationDefinition::printError() const
{
    cerr << "ERROR: population definition in " << fileName << " at line " << line << " is invalid\n";
}