#pragma once 

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>

class Process
{
    private:
        std::vector<std::string>& ProcessInfo; 
    public:

        Process(std::vector<std::string>& ProcessInfo) : ProcessInfo(ProcessInfo){} 
        int ExecuteProcess();   
        int CreateProcess(); 
};