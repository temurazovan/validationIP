#include <iostream>

struct IpAddress {
    std::string firstSubnet;
    std::string secondSubnet;
    std::string thirdSubnet;
    std::string fourthSubnet;
};

bool checkDots(std::string ip) {
    for (char symbol: ip) {
        if (!isdigit(symbol) && symbol != '.') {
            return false;
        }
    }
    int k = 0;
    for (int i = 0; i <= ip.length(); i++) {
        if (ip[0] == '.' || (ip[i] == '.' && i + 1 <= ip.length() && ip[i + 1] == '.')) {
            return false;
        }
        if (ip[i] == '.') {
            k++;
            if (k > 3) {
                return false;
            }
        }

    }
    return true;
}

void parseIp(std::string ip) {
    IpAddress result;
    int dotCount = 0;

    for (char symbol: ip) {

        if (symbol == '.') {
            dotCount++;
            continue;
        }
        if (dotCount == 0) {
            result.firstSubnet += symbol;
        }
        if (dotCount == 1) {
            result.secondSubnet += symbol;
        }
        if (dotCount == 2) {
            result.thirdSubnet += symbol;
        }
        if (dotCount == 3) {
            result.fourthSubnet += symbol;
        }

    }

}

bool checkSymbols(std::string ip) {
    for (int i; i <= ip.length(); i++) {
        if (!isdigit(ip[i]) && ip[i] != '.') {
            return false;
        }
        if (ip[i] == '.' && ip[i+1] != '.') {
            return false;
        }
    }

    return true;
}

bool checkParts(std::string str) {
    IpAddress octet;
    int firstOctet = std::stoi(octet.firstSubnet);
    int secondOctet = std::stoi(octet.secondSubnet);
    int thirdOctet = std::stoi(octet.thirdSubnet);
    int fourthOctet = std::stoi(octet.fourthSubnet);

    if (firstOctet >= 255 && secondOctet >= 255 && thirdOctet >= 255 && fourthOctet >= 255) {
        return false;
    }


    return true;
}

int main() {
    std::string ip;
    std::cout << "Enter IP: " << std::endl;
    std::cin >> ip;

    std::cout << checkSymbols(ip);

}
