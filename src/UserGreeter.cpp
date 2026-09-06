#include "../include/UserGreeter.h"

void Console::GetUserName()
{
    uid_t uid = geteuid(); 
    struct passwd* pw = getpwuid(uid);
    // first option for setting the username
    if(pw)
    {
        std::string username = pw->pw_name; 
        this->UserName = username;  
    }
    // if first statement fail's this is the failsafe statement 
    else 
    {
        // get's enviroment variable of `USER`
        char* username = std::getenv("USER"); 
        if(username)
        {
            this->UserName = username; 
        }
        else
        {
            // default UserName; 
            // if no username is found.
            // **failsafe**
            this->UserName = "User";
        }

    }
    return; 
}

void Console::WelcomeUser()
{
    std::cout << GREEN << "Welcome Back " <<  RESET << PURPLE << this->UserName << RESET << std::endl; 
    return;
}

