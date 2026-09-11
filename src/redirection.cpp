#include <redirection.hpp>

// the error code for this file is 69 !!

int Redirection::InitRedirection()
{
        auto IsRedirection = false;
        try{
        for(int i = 0; this->ref.size() > i; i++)
        {
            if(this->ref[i] == ">>")
            {
                IsRedirection = true;
                this->ref.at(i) = "\0"; 
                this->filename = this->ref.at(i + 1);  
                NumberOfRe = 2; 
            }

            else if (this->ref[i] == ">")
            {
                IsRedirection = true; 
                this->ref.at(i) = "\0"; 
                this->filename = this->ref.at(i + 1);
                this->ref.at(i + 1) = '\0';  
                NumberOfRe = 1; 
            }
        }
        for(auto a : ref)
        {
            std::cout << a << " " << a.length() << std::endl;
        }
        }
        catch(std::exception& e)
        {
            std::cerr << e.what() << std::endl; 
            return 69; 
        }
        // if it is not a redirection prompt; 
        if(!IsRedirection)
        {
            return 1; 
        }
        // ls -la  hello.txt
        return 0;

}

int Redirection::ReExecute()
{
    try{
    pid_t pid = fork(); 
    
    // forking failed; 
    if(pid < 0)
    {
        std::cerr << "Forking Faild" << std::endl; 
        return 1; 
    }

    else if (pid == 0)
    {
        int Flag = 0; 
        if(NumberOfRe == 1)
        {
            Flag = O_TRUNC; 
        }
        else 
        {
            Flag = O_APPEND; 
        }
        int FileFd = open(filename.c_str(),Flag); 
        
        if(FileFd < 0)
        {
            throw std::runtime_error("Cannot Open File."); 
        }

        if (dup2(FileFd,STDOUT_FILENO) < 0)
        {
            throw std::runtime_error("dup2 Gave an error regarding the Fd Changing."); 
        }
        
        if(close(FileFd) < 0)
        {
            throw std::runtime_error("Cannot Close FileFd(FROM FUNCTION open)."); 
        } 
        
         char* args[ref.size() + 1];
                
         for(int i = 0; i < ref.size();i++)
            {
            args[i] = (char*)ref[i].c_str();
             }
                
            args[ref.size()] = NULL;
            execvp(ref[0].c_str(),args);
            return 0;  
        }
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl; 
        return 69; 
    }
    return 0;
}