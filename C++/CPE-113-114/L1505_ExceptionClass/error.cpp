#include "error.h"
#include <iostream>
#include <string>
using namespace std;

error::error(string msg) : message(msg) {}

string error::getMessage(){return(message);}
