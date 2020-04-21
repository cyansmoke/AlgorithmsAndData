#include <iostream>
#include <string>
#include "support/map.h"
#include "support/List.h"

using namespace std;

class Encoder {
private:
    List<bool> encodedString;
    map<char, float, List<bool>> map;
    List<bool> codeList;
    List<pair<char, float>> probabilityList;

    void set_codes(size_t indexL, size_t indexR) {
        if (indexR - indexL == 2) {
            codeList.insertLast(false);
            map.set_value2(probabilityList.getDataAt(indexL).first, codeList);
            codeList.deleteLast();
            codeList.insertLast(true);
            map.set_value2(probabilityList.getDataAt(indexR - 1).first, codeList);
            codeList.deleteLast();
            return;
        }
        if (indexR - indexL == 1) {
            map.set_value2(probabilityList.getDataAt(indexL).first, codeList);
            return;
        }
        float dS = 0, sum = 0;
        for (int i = indexL; i < indexR; i++) {
            dS += probabilityList.getDataAt(i).second;
        }
        dS /= 2;
        size_t newIndex = indexL;
        for (int i = indexL; i < probabilityList.getSize(); i++) {
            sum += probabilityList.getDataAt(i).second;
            newIndex++;
            if (sum >= dS) {
                break;
            }
        }
        codeList.insertLast(false);
        set_codes(indexL, newIndex);
        codeList.deleteLast();
        codeList.insertLast(true);
        set_codes(newIndex, indexR);
        codeList.deleteLast();
    }

public:
    string inputString;

    Encoder() = default;

    void showInfo() {
        if (inputString.empty())
            throw runtime_error("Original string is not set");
        cout << "Input string: ";
        cout << inputString << endl;
        cout << "Encoded string: ";
        encodedString.print();
        cout << '\n';
        cout << "Count of input chars: " << inputString.length() << " bits" << endl;
        cout << "Size of input string: " << inputString.length() * 8 << " bits" << endl;
        cout << "Size of encoded string: " << encodedString.getSize() << " bits" << endl;
        cout << "Compression coef: " << (float) encodedString.getSize() / (inputString.length() * 8) << endl;
        cout << "Symbol" << "\t" << "Probability" << "\t" << "Encoding" << endl;
        List<bool> ls;
        for (int i = 0; i < probabilityList.getSize(); i++) {
            cout << " \"" << probabilityList.getDataAt(i).first << "\"\t    "
                 << map.find_value1(probabilityList.getDataAt(i).first)
                 << "         ";
            map.find_value2(probabilityList.getDataAt(i).first).print();
            cout << endl;
        }
    }

    List<bool> getEncodedString() {
        return encodedString;
    }

    void setStringForShannon(string str) {
        if (str.empty())
            throw runtime_error("Original string is not set");
        inputString = str;
        for (char i : inputString) {
            map.insert(i, float(1) / inputString.length(), float(1) / inputString.length());
        }
        for (char i : inputString) {
            probabilityList.insertAndSort(i, map.find_value1(i));
        }
        if (probabilityList.getSize() == 1) {
            codeList.insertLast(false);
            map.set_value2(inputString.at(0), codeList);
        } else
            set_codes(0, probabilityList.getSize());
        List<bool> ls;
        for (char i : inputString) {
            encodedString.insertListInBack(map.find_value2(i));
        }
    }

    List<char> decode(string str) {
        if (inputString.empty()) throw "Input string is not set";
        string encoded_string_to_decode = str;
        if (encoded_string_to_decode.empty()) throw "Decoded string is not set";
        List<char> decoded_string;
        List<bool> temp_code;
        for (char i : encoded_string_to_decode) {
            temp_code.insertLast(i - 48);
            if (map.code_in_dict(temp_code)) {
                decoded_string.insertLast(map.find_key(temp_code));
                temp_code.clear();
            }
        }
        if (!temp_code.isEmpty()) {
            throw "Decoded string is not correct";
        }
        return decoded_string;
    }
};