#include "Console.h"
#include <Process.h>
int main()
{
    Console Output;
    Output.WelcomeUser();
    
    while(1)
    {
        Output.PrintPrompt(); 
        std::string a; 
        std::vector<std::string> VecInput = Output.ReadInput();
        Process P; 
        P.ExecuteProcess(VecInput);        
    }
    return 0;
}