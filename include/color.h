#pragma once 
#include <string>

// this header file is for colors
// and color's functions and methods 
namespace color{
    const std::string RESET        = "\033[0m";
    const std::string BOLD         = "\033[1m";
    const std::string DIM          = "\033[2m";
    const std::string ITALIC       = "\033[3m";
    const std::string UNDERLINE    = "\033[4m";
    const std::string BLINK        = "\033[5m";
    const std::string REVERSE      = "\033[7m";
    const std::string HIDDEN       = "\033[8m";
    const std::string RED          = "\033[31m";
    const std::string STRIKETHROUGH= "\033[9m";

    const std::string BLACK        = "\033[30m";
    const std::string GREEN        = "\033[32m";
    const std::string YELLOW       = "\033[33m";
    const std::string BLUE         = "\033[34m";
    const std::string PURPLE      = "\033[35m";
    const std::string CYAN         = "\033[36m";
    const std::string WHITE        = "\033[37m";
}