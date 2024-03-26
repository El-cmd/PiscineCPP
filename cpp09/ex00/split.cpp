#include <iostream>
#include <string>
#include <map>

std::map<std::string, float> split(const std::string& s, char delimiter) {
    std::map<std::string, float> result;
    size_t start = 0;
    size_t delimPos = s.find(delimiter);

    while (delimPos != std::string::npos) {
        std::string pair = s.substr(start, delimPos - start);
        size_t equalPos = pair.find('=');

        if (equalPos != std::string::npos) {
            std::string key = pair.substr(0, equalPos);
            float value = std::stof(pair.substr(equalPos + 1));
            result[key] = value;
        }

        start = delimPos + 1;
        delimPos = s.find(delimiter, start);
    }

    // Handle the last (or only) key-value pair
    std::string lastPair = s.substr(start);
    size_t equalPos = lastPair.find('=');
    if (equalPos != std::string::npos) {
        std::string key = lastPair.substr(0, equalPos);
        float value = std::stof(lastPair.substr(equalPos + 1));
        result[key] = value;
    }

    return result;
}

int main() {
    std::string text = "apple=2.5,banana=3.25,orange=1.75";
    char delimiter = ',';

    std::map<std::string, float> map = split(text, delimiter);

    for (const auto& pair : map) {
        std::cout << pair.first << " = " << pair.second << std::endl;
    }

    return 0;
}