//
// Created by arbel on 1/19/2022.
//

#include "FileNotFound.h"

FileNotFound::FileNotFound(const string &str)
: fileName(str)
{}

void FileNotFound::printError() const
{
    cerr << "ERROR: " << fileName << " does not exist or cannot be opened\n";
}
