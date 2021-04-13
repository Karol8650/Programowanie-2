#include <iostream>
#include <regex>

int main() {

    std::string bridge_of_death = R"("
ARTHUR: Three questions may cross in safety. "
…
"BRIDGEKEEPER: Huh? I-- I don't know that. Auuuuuuuugh! ")";

    std::smatch dopasowania;
    std::regex wzor(R"([^A-Ze\s]\w*a\w*)");
    while (std::regex_search(bridge_of_death, dopasowania, wzor)) {
        std::cout << dopasowania.str() << std::endl;
        bridge_of_death = dopasowania.suffix().str();
    }

}
