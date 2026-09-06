#pragma once 

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>

class Process
{
    public:
        int ExecuteProcess(std::vector<std::string>& ProcessInfo);   
};