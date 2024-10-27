#include <direct.h> // Include for _chdir
#include <iostream>

int main()
{
    char cwd[1024];

    // Get and print current working directory
    if (_getcwd(cwd, sizeof(cwd)) != NULL)
    {
        std::cout << "Current working directory: " << cwd << std::endl;
    }
    else
    {
        perror("_getcwd() error");
    }

    // Change directory
    if (_chdir("Assignment-8") == 0)
    {
        std::cout << "Directory changed successfully." << std::endl;

        // Get and print new working directory
        if (_getcwd(cwd, sizeof(cwd)) != NULL)
        {
            std::cout << "New working directory: " << cwd << std::endl;
        }
        else
        {
            perror("_getcwd() error");
        }
    }
    else
    {
        perror("_chdir() error");
    }
    return 0;
}
