#ifndef PRECOND_VIOLATED_EXCEP_
#define PRECOND_VIOLATED_EXCEP_

#include <stdexcept>
#include <string>

using namespace std;
class PrecondViolatedExcep : public logic_error {
public:
    explicit PrecondViolatedExcep(const string &message = "");
};

#include "PrecondViolatedExcep.cpp"

#endif
