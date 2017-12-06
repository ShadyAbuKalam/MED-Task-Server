//
// Created by jerry on 12/6/17.
//

#ifndef MED_TASK_SERVER_UTILITY_H
#define MED_TASK_SERVER_UTILITY_H

#define SECONDS_PER_YEAR 360*24*60*60

class Utility {
public:
    static void generate(std::string path,long long samples_count);
    static bool exists(std::string  name );
    static std::string getCurrentDirectory();
};


#endif //MED_TASK_SERVER_UTILITY_H
