#include "Console.h"
#include "Process.h"
#include "redirection.hpp"

int main()
{
    Console Output;
    Output.WelcomeUser();
    
    while(1)
    {
        Output.PrintPrompt(); 
        std::string a; 
        std::vector<std::string> VecInput = Output.ReadInput();
        Process P(VecInput);
        Redirection re(VecInput); 
        re.InitRedirection(); 

        int result = P.ExecuteProcess();        
        if (result == 100)
        {
            return 0;
        }
    }
    return 0;
}