#include "App.h"


int main(int argc, char **args) {
    std::vector<std::string> argv;
    argv.reserve(argc);
    for(int i=0; i<argc; ++i)
    {
        argv.emplace_back(args[i]);
    }

    App app;
    return app.Run(argv);
}
