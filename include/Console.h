#pragma once 

// headers
#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <pwd.h>
#include <cstdlib>
#include <limits.h>
#include <regex>
#include <color.h>
// Colors for terminal output 
// used in Console class


class Console
{
private:
    std::string UserName; 
        
public:
    Console();
    // method for getting username
    void GetUserName(); 

    // method for Welcoming User. 
    void WelcomeUser();
    
    //method for priting The Username > Prompt
    void PrintPrompt();

    //method for taking input and passing it into a vector; 
    std::vector<std::string> ReadInput(); 
}; 