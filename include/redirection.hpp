#pragma once 
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <vector>
#include <string>
#include "Process.h"

class Redirection
{
    private:
        std::vector<std::string>& ref;
        std::string filename;
        int NumberOfRe; 
    public:
        Redirection(std::vector<std::string>& ref) : ref(ref){}
        int InitRedirection(); 
        int ReExecute(); 
        

};