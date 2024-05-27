#include <iostream>
#include <vector>
#include <fstream>
#include "json.hpp"

int main() {
    nlohmann::json j;
    j["name"] = "John";
    j["age"] = 30;
    j["city"] = "New York";

    std::ofstream o("person.json");
    o << j << std::endl;

    o.close();

    return 0;
}