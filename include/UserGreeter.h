#pragma once 

// headers
#include <iostream>
#include <string>
#include <unistd.h>
#include <pwd.h>
#include <cstdlib>

// Colors for terminal output 
// used in Console class

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string RESET = "\033[0m";
const std::string PURPLE = "\033[35m";

class Console
{
private:
    std::string UserName = nullptr; 
        
public:
    Console()
    {
        // This will provide with the username 
        GetUserName(); 
    }
    // method for getting username
    void GetUserName(); 

    // method for Welcoming User. 
    void WelcomeUser(); 

}; 