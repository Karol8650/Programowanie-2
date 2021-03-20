#include <iostream>
#include <regex>
using namespace std;

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
    int splitIP[4];
    int splitSubnetAddress[4];
    while()

}

int main() {

    string IP;
    do {
      cout << "Podaj adres IPv4: ";
      cin >> IP;
  } while(!isValidIP(IP));

    string subnetAddress;
    do {
        cout << "Podaj adres podsieci: ";
        cin >> subnetAddress;
    } while(!isValidSubnetAddress(subnetAddress));

    string subnetMaskAddress = generateSubnetMaskAddress((IP, subnetAddress));
    cout << subnetMaskAddress;







}



