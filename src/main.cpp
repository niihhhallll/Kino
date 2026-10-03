#include "../include/Console.h"
#include "../include/Process.h"

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
        int result = P.ExecuteProcess();
        if (result == 100)
        {
            return 0;
        }
    }
    return 0;
}
