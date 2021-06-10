#include <iostream>
#include <sstream>
#include <unistd.h>
std::string getOsName()
{
#ifdef _WIN32
    return "Windows 32-bit";
#elif _WIN64
    return "Windows 64-bit";
#elif __APPLE__ || __MACH__
    return "Mac OSX";
#elif __linux__
    return "Linux";
#elif __FreeBSD__
    return "FreeBSD";
    #elif __unix || __unix__
    return "Unix";
    #else
    return "Other";
#endif
}

int main() {
    std::cout << "===================| KASM |=====================" << std::endl;



    while (true) {
        std::cout << ">>>";
        std::stringstream SD;
        std::string binop;
        std::stringstream op;

        std::string keyword;
        std::string statement;
        getline(std::cin, statement);
        SD << statement;
        while (getline(SD, keyword, ';'))
        {
            op << keyword + "\n";
        }
        while (op >> binop) {

            if (binop == "WAIT") {
                int usecs;
                op >> usecs;
                sleep(usecs);
            } else if (binop == "MOV") {
                std::string expr;
                op >> expr;
                if (expr.empty()) {
                    std::cout << "missing handle\n";
                }
                else {
                    if (expr == "%d")
                    {
                        std::cout << "<''' I64 FF '''>\n";
                    }
                    else
                    {
                        float fs = std::stof(expr);
                        std::cout << typeid(fs).name() << std::endl;
                    }
                }
            }
            else if (binop == "MALLOC")
            {
                ssize_t ssize;
                op >> ssize;
                malloc(ssize);
            }
            else if (binop == "")
            {
                std::string
            }
            else if (binop == "CHSUM")
            {
                int hex_fs;
                int hex_next;
                op >> hex_fs;
                op >> hex_next;
                std::cout << hex_fs + hex_next << "\n";
            }
            else if (binop == "LINE")
            {
                std::string FS;
                getline(op, FS);
                std::cout << FS << std::endl;
            }
            else if (binop == "TK")
            {
                std::string stream;
                if (stream == "__SDCMSTR")
                {
                    std::cout << op.str();
                }
                else if (stream == "__STDOUT")
                {
                    std::cout << stdout;
                }
            }
            else if (binop == "I64")
            {
                uint_fast64_t IT;
                op >> IT;
                malloc(IT);
            }
            else if (binop == "OS")
            {
                std::cout << getOsName() + "\n";

            }
            else if (binop == "BR")
            {
               return 1;
            }
            else if (binop == "HSTRY")
            {
                std::cout << op.str() << "\n";
            }
            else {
                std::cout << "undefined reference to ``" + binop + "``" << std::endl;
            }
        }
    }

}
