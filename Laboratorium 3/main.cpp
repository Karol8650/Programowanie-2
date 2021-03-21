#include <iostream>
#include <regex>

using namespace std;

string decimalToBinary(int *number) {
    string binary;
    bool isOneFound = false;
    for(int i = 0; i < 4; i++) {
        for(int k = 128; k > 0; k /= 2) {
            if(number[i] / k) {
                isOneFound = true;
                binary += '1';
                number[i] -= k;
            }
            else if(isOneFound) {
                binary += '0';
            }
        }
        binary += '.';
    }
    binary.erase(binary.length() - 1);
    return binary;
}

// split string into splitTab[]
void splitString (string str, int *splitTab) {
    size_t pos;
    string token;
    int counter = 0;
    // size_t is an unsigned integral type
    // npos is used to indicate no matches
    while ((pos = str.find('.')) != string::npos) {
        token = str.substr(0, pos);
        splitTab[counter++] = atoi(token.c_str());
        str.erase(0, pos + 1);
    }

}

bool isValidIP (string IP) {
    if(regex_match(IP, regex("((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])[.]){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])")))
        return true;
    return false;
}

bool isValidSubnetAddress (string subnetAddress) {
    if(regex_match(subnetAddress,regex("((254|252|248|240|224|192|128|0)([.]0){3})|(255[.](254|252|248|240|224|192|128|0)([.]0){2})|((255[.]){2}(254|252|248|240|224|192|128|0)[.]0)|((255[.]){3}(254|252|248|240|224|192|128|0))")))
        return true;
    return false;
}

string generateSubnetMaskAddress (string IP, string subnetAddress) {
    int splitIP[4] = {0};
    int splitSubnetAddress[4] = {0};

    splitString(IP, splitIP);
    splitString(subnetAddress, splitSubnetAddress);

    string str;
    stringstream ss;
    string splitSubnetMaskAddress;
    for (int i = 0; i < 4; i++) {
        ss << (splitIP[i] & splitSubnetAddress[i]);
        ss << ".";
    }
    splitSubnetMaskAddress = ss.str();
    splitSubnetMaskAddress.erase(splitSubnetMaskAddress.length() - 1);

    return splitSubnetMaskAddress;
}

void binarySubnetMaskAddress (string subnetMaskAddress) {
    int splitSubnetMaskAddress[4] = {0};
    splitString(subnetMaskAddress, splitSubnetMaskAddress);
    string binary = decimalToBinary(splitSubnetMaskAddress);
    cout << binary << endl;
}

void hexadecimalSubnetMaskAddress (string subnetMaskAddress) {
    int splitSubnetMaskAddress[4] = {0};
    splitString(subnetMaskAddress, splitSubnetMaskAddress);
    for (int i = 0; i < 4; i++) {
        printf("%X", splitSubnetMaskAddress[i]);
        if(i != 3)
            printf(".");
    }
}



int main() {

    string IP;
    do {
      cout << "Podaj adres IPv4:";
      cin >> IP;
  } while(!isValidIP(IP));

    string subnetAddress;
    do {
        cout << "Podaj adres podsieci:";
        cin >> subnetAddress;
    } while(!isValidSubnetAddress(subnetAddress));

    string subnetMaskAddress = generateSubnetMaskAddress(IP, subnetAddress);
    cout << subnetMaskAddress << endl;

    binarySubnetMaskAddress(subnetMaskAddress);
    hexadecimalSubnetMaskAddress(subnetMaskAddress);

}



