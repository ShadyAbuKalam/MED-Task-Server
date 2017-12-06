#include <iostream>
#include <random>
#include <xlnt/xlnt.hpp>
#include <unistd.h>
#include <fstream>
#include <Utility.h>


int main() {


    std::string path = Utility::getCurrentDirectory()+ "/example.xlsx";

    // Generate the excel file if it doesn't exist
    if(!Utility::exists(path))
        Utility::generate(path,10000);
}