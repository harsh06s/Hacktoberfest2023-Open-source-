#include <iostream>
#include <string>
#include <unordered_map>

bool areAnagrams(const std::string& str1, const std::string& str2) {
    if (str1.length() != str2.length()) {
        return false; // If the lengths are different, they can't be anagrams.
    }

    std::unordered_map<char, int> charCount;

    // Count characters in the first string
    for (char c : str1) {
        charCount[c]++;
    }

    // Decrement the character count for the second string
    for (char c : str2) {
        if (charCount.find(c) == charCount.end() || charCount[c] == 0) {
            return false; // If the character is not in the map or its count is already 0, they can't be anagrams.
        }
        charCount[c]--;
    }

    return true; // If all characters are accounted for, they are anagrams.
}

int main() {
    std::string str1, str2;

    std::cout << "Enter the first string: ";
    std::cin >> str1;

    std::cout << "Enter the second string: ";
    std::cin >> str2;

    if (areAnagrams(str1, str2)) {
        std::cout << "The two strings are anagrams.\n";
    } else {
        std::cout << "The two strings are not anagrams.\n";
    }

    return 0;
}
