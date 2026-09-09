#include <Process.h>
#include <color.h>
#include <redirection.hpp>

int Process::CreateProcess()
{
    char* args[this->ProcessInfo.size() + 1];
                
    for(int i = 0; i < this->ProcessInfo.size();i++)
     {
        args[i] = (char*)this->ProcessInfo[i].c_str();
     }
                
    args[this->ProcessInfo.size()] = NULL;
    execvp(this->ProcessInfo[0].c_str(),args);
}

int Process::ExecuteProcess()
{
            // for cd 
            // If this prints ["cd "] or ["cd
// "], you have hidden characters!

            
            if(this->ProcessInfo[0] == "cd")
            {
                int result = chdir(this->ProcessInfo[1].c_str());
                if (result == 0)
                {
                    return EXIT_SUCCESS;
                }
                else
                {
                    std::cerr << color::RED << "No Directory Found." << color::RESET << std::endl;
                    std::cout.flush(); 
                    return EXIT_FAILURE;
                }
            }
            if(this->ProcessInfo[0] == "exit")
            {
                std::cout << color::YELLOW << "Exiting.." << std::endl; 
                return 100;
            }
        
            pid_t pid = fork(); 
            
            // less than zero means it forking failed. 
            if(pid < 0)
            {
                std::cerr << "Fork Failed" << std::endl; 
                exit(EXIT_FAILURE); 
            }
            // child process
            else if (pid == 0)
            {
                CreateProcess(); 
                
                // if the executation failed 
                // failsafe code
                std::cerr << color::RED << "Command Not Found." << color::RESET << std::endl;
                exit(EXIT_FAILURE); 
            }
            else
            {
                int status; 
                if(waitpid(pid,&status,0) == -1)
                {
                    std::cerr << "waitpid function has failed." << std::endl; 
                    exit(EXIT_FAILURE); 
                }
                if (WIFSIGNALED(status)) {
                    std::cout << "Command Failed." << std::endl; 
                }
            }
            return EXIT_SUCCESS;
}            