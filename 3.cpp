#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <unordered_map>

using namespace std;

unordered_map<string, int> global_map;

void process() {
    unordered_map<string, int> old_values;
    string input;

    while (true) {

        cin >> input;

        if (std::cin.eof()) break;

        if (input == "}") {
            auto a = old_values.begin();
            while (a != old_values.end()) {
                global_map.insert_or_assign(a->first, a->second);
                a++;
            }
            break;
        }

        if (input == "{") process();
        else {
            size_t equals_pos = input.find("=");
            string name = input.substr(0, equals_pos);
            string value = input.substr(equals_pos+1, input.size()-1);

            int value_num = 0;

            try { value_num = stoi(value); }
            catch (const invalid_argument&) { 
                if (global_map.find(value) != global_map.end())
                    value_num = global_map.at(value);
                cout << value_num << endl;
            }

            int old_value = 0;
            if (global_map.find(name) != global_map.end()) 
                old_value = global_map.at(name);

            if (old_values.find(name) == old_values.end())
                old_values.insert_or_assign(name, old_value);
            
            global_map.insert_or_assign(name, value_num);
        }

    }
}

int main() {
    process();
}