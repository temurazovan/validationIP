#include <iostream>

struct IpAddress {
    std::string firstSubnet;
    std::string secondSubnet;
    std::string thirdSubnet;
    std::string fourthSubnet;
};

bool checkDots(std::string ip) {
    for (char symbol : ip) {
        if (!isdigit(symbol) && symbol != '.'){
            return false;
        }
    }
    for (int i = 0; i < ip.length(); i++){
        int k = 0;
        if (ip[0] == '.' || (ip[i] == '.' && i + 1 <= ip.length() && ip[i + 1] == '.')) {
            return false;
        }
        if (ip[i] == '.') {
            k++;
            if (k != 4) {
                return false;
            }
        }

    }
    return true;
}


int main() {
    std::string ip;
    std::cout << "Enter IP: " << std::endl;
    std::cin >> ip;
    std::cout << checkDots(ip);

}
