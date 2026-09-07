#include "../include/Console.h"

Console::Console(){
        // This will provide with the username 
        GetUserName(); 
}

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


// need to refactor this method for printing good quality output's
// right now this is enough 
void Console::WelcomeUser()
{
   std::string BriefIntro = R"(
  _  ___              ____  _   _ 
 | |/ (_)_ __   ___  / ___|| | | |
 | ' /| | '_ \ / _ \ \___ \| |_| |
 | . \| | | | | (_) | ___) |  _  |
 |_|\_\_|_| |_|\___/ |____/|_| |_|
 =================================
 🎬 KinoSH — The Anti-Ai Shell (v0.1)
 ------------------------------------------------
 • Creator:     Nihalllll
 • History:     First Build In september 1 
 • License:     MIT License (Open Source)

 Type 'help' to show commands or 'scene' to view workspace.
)";
    system("clear"); 
    std::cout << color::RED << BriefIntro << color::RESET << std::endl; 
    std::cout << std::endl; 
    return;
}

void Console::PrintPrompt()
{
    char cwd[PATH_MAX]; 
    if(getcwd(cwd,sizeof(cwd)) != nullptr)
    {
        std::cout << color::PURPLE << this->UserName  << color::YELLOW << "~" << color::RESET << color::GREEN << cwd << "> " << color::RESET; 
    }
    else
    {
        std::cout << color::PURPLE << this->UserName << color::RESET; 
    }

    return;
}

std::vector<std::string> Console::ReadInput()
{
    
    std::string Input; 
    // reading the input
    std::getline(std::cin,Input);
    std::string TempInput;
    TempInput.resize(Input.size() + 5);  
    int count = 0; 
    std::vector<std::string> UserInput;
    // ls -la
    Input.push_back('\n'); 
    for(auto c : Input)
    {
        if(c != ' ' || c == '\n')
        {
            if (c == '\n')
            {
                UserInput.push_back(TempInput);
                break; 
            }
            TempInput[count] = c; 
            count++; 
        }
        else
        {
            count = 0;
            UserInput.push_back(TempInput); 
            TempInput.clear(); 
            TempInput.resize(Input.size() + 5); 
        }

    }
    
    return UserInput; 
}
