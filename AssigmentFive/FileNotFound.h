#ifndef ASSIGMENTFIVE_FILENOTFOUND_H
#define ASSIGMENTFIVE_FILENOTFOUND_H

#include <iostream>

using namespace std;

///
/// An exception class which will be thrown if a file won't be found.
/// No need for "The Big Three" since its an exception class
///
class FileNotFound
{

private:
    string fileName;

public:
    /// Constructor
    /// \param str the name of the file
    explicit FileNotFound(const string& str);

    /// prints the error
    void printError() const;
};


#endif //ASSIGMENTFIVE_FILENOTFOUND_H
