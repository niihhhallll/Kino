#include <Process.h>
#include <color.h>
int Process::ExecuteProcess(std::vector<std::string>& ProcessInfo)
{
            // for cd 
            // If this prints ["cd "] or ["cd
// "], you have hidden characters!

            if(ProcessInfo[0][0] == 'c' && ProcessInfo[0][1] == 'd')
            {
                int result = chdir(ProcessInfo[1].c_str());
                if (result == 0)
                {
                    return EXIT_SUCCESS;
                }
                else
                {
                    std::cerr << color::RED << "No Directory Found." << color::RESET << std::endl;
                    return EXIT_FAILURE;
                }
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
                char* args[ProcessInfo.size() + 1];
                
                for(int i = 0; i < ProcessInfo.size();i++)
                {
                    args[i] = (char*)ProcessInfo[i].c_str();
                }
                
                args[ProcessInfo.size()] = NULL;
                execvp(ProcessInfo[0].c_str(),args);
                
                // if the executation failed 
                // failsafe code
                std::cerr << color::RED << "Command Not Found." << color::RESET << std::endl;
                std::cerr << "To Install " << args[0] << " Do sudo apt install " << args[0] << "." << std::endl;
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