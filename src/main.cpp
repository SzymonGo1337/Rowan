#include <iostream>
#include <fstream>

std::string prefix = "[36m[ROWAN][0m ";
std::string command, projname;

const char* program = R"(#include <iostream>

int main() {
    std::cout << "Program\n";
    std::cin.get();
})";

int main(int argc, char** argv) {
    #ifdef _WIN32
        system("Setlocal");
    #endif
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
            outFile << "g++ " + projname + "/main.cpp -o " << projname << "/" << projname;
            outFile.close();
            std::string test3 = projname + "/main.cpp";
            const char* data3 = test3.c_str();
            std::ofstream outFile2(data3);
            outFile2 << program;
            outFile2.close();
            std::cout << prefix << "Project with name: " << "[33m" << projname << "[0m" << " is initialized!\n";
        } else if(command == "--compile") {
            projname = argv[i + 1];
            std::string test = projname + "/.rowan";
            const char* data = test.c_str();
            std::string out;
            std::ifstream inFile(data);
            while(std::getline(inFile, out)) {
                std::cout << prefix << out << "\n";
            }
            inFile.close();
            const char* data2 = out.c_str();
            system(data2);
        } else if(command == "--run") {
            projname = argv[i + 1];
            #ifdef _WIN32
                std::string test = "start " + projname + "/" + projname + ".exe";
            #else
                std::string test = "./" + projname + "/" + projname;
            #endif
            const char* data = test.c_str();
            system(data);
            std::cout << prefix << "Program from project: " << "[33m" << projname << "[0m" << " is closed!\n";
        } else if(command == "--delete") {
            projname = argv[i + 1];
            #ifdef _WIN32
                std::string test = "rmdir /S " + projname;
            #else
                std::string test = "rm -rf " + projname;
            #endif
            const char* data = test.c_str();
            system(data);
            std::cout << prefix << "Project with name: " << "[33m" << projname << "[0m" << " is deleted!\n";
        }
    }
}