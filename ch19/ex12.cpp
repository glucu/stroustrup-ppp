#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

class File_handle {
public:
    explicit File_handle(const std::string &file_name)
        : m_file_name{file_name},
          m_ifs{std::ifstream{m_file_name.c_str()}}
    { 
        if(!m_ifs) {
            std::cerr << "File_handle: Failed to open file " << file_name << '\n';
        }
        else {
            std::cout << file_name << " file opened\n";
        }
    }

    ~File_handle()
    {
        if(m_ifs.is_open()) {
            m_ifs.close();
            std::cout << m_file_name << " closed\n";
        }
    }

private:
    std::string m_file_name;
    std::ifstream m_ifs;
};

int main(int argc, const char *argv[])
{
    if(argc != 2) {
        std::cerr << "Usage: <file name> " << argv[0] << '\n';
        return EXIT_FAILURE;
    }

    const std::string file_name =  argv[1];
    File_handle fh{file_name};

    return EXIT_SUCCESS;
}
