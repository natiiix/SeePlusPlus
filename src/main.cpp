#include "h/Processor.hpp"
#include "h/misc.hpp"

int main(int argc, char* argv[])
{
    Processor proc;

    for (int i = 1; i < argc; i++)
    {
        if (proc.LoadProgram(argv[i]))
            proc.ExecuteProgram();
        else
            return -1;
    }

    return 0;
}
