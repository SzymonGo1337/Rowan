#include <iostream>
#include <fstream>

std::string command, projname;

int main(int argc, char** argv) {
    for(int i = 0; i < argc; i++) {
        //std::cout << argv[i] << "\n";
        command = argv[i];
        if(command == "--init") {
            projname = argv[i + 1];
            std::string test = "mkdir " + projname;
            const char* data = test.c_str();
            system(data);
            std::string test2 = projname + "/.rowan";
            const char* data2 = test2.c_str();
            std::ofstream outFile(data2);
            outFile << "g++ main.cpp -o " << projname;
            outFile.close();
            std::cout << "Project with name: " << projname << " is initialized!\n";
        } else if(command == "--compile") {
            projname = argv[i + 1];
            std::string test = ".rowan";
            const char* data = test.c_str();
            std::string out;
            std::ifstream inFile(data);
            while(std::getline(inFile, out)) {
                std::cout << out << "\n";
            }
            inFile.close();
            const char* data2 = out.c_str();
            system(data2);
            std::cout << "Project with name: " << projname << " is compiled!\n";
        } else if(command == "--delete") {
            projname = argv[i + 1];
            #ifdef _WIN32
                std::string test = "rmdir /S " + projname;
            #else
                std::string test = "rm -rf " + projname;
            #endif
            const char* data = test.c_str();
            system(data);
            std::cout << "Project with name: " << projname << " is deleted!\n";
        }
    }
}