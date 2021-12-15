#include "broker.hpp"

int main() {
    Broker vd("/home/daria/CLionProjects/lab_04/misc/ftp");
    std::cout << vd.PrintFiles().str();
    std::cout << vd.PrintAccounts().str();
    return 0;
}
