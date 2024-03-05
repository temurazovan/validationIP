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

IpAddress parseIp(std::string ip) {
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

    return result;
}

bool checkSymbols(std::string ip) {
    for (int i = 0; i < ip.length(); i++) {
        if (!isdigit(ip[i]) && ip[i] != '.') {
            return false;
        }
        if (ip[i] == '0' && i + 1 <= ip.length() && ip[i + 1] == '0') {
            return false;
        }
    }

    return true;
}

bool checkParts(IpAddress ipAddress) {
    if (ipAddress.firstSubnet.empty() || ipAddress.secondSubnet.empty() || ipAddress.thirdSubnet.empty()
        || ipAddress.fourthSubnet.empty()) {
        return false;
    }
    int firstOctet = std::stoi(ipAddress.firstSubnet);
    int secondOctet = std::stoi(ipAddress.secondSubnet);
    int thirdOctet = std::stoi(ipAddress.thirdSubnet);
    int fourthOctet = std::stoi(ipAddress.fourthSubnet);


    if (firstOctet > 255 || firstOctet < 0 || secondOctet > 255 || secondOctet < 0 || thirdOctet > 255
            || thirdOctet < 0 || fourthOctet > 255 || fourthOctet < 0) {
        return false;
    }


    return true;
}

int main() {
    std::string ip;
    std::cout << "Enter IP: " << std::endl;
    std::cin >> ip;
    IpAddress octet = parseIp(ip);

    if (checkSymbols(ip) && checkParts(octet) && checkDots(ip)) {
        std::cout << "valid IP";
    }else{
        std::cout << "Invalid IP";
    }

}
