#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <sstream>

////////////////////////////////////////////////////////////
/// \brief Helper to transform a line into a case description
///
/// \param line String of space-separated integers
///
/// \return Vector describing the case
////////////////////////////////////////////////////////////
template <typename T>
std::vector<T> line_to_vect(std::string& line) {
    std::vector<T> v;
    std::istringstream iss(line);
    return std::vector<T>(std::istream_iterator<T>(iss), std::istream_iterator<T>());
}

////////////////////////////////////////////////////////////
/// \brief Read a casebase from a file
///
/// \param path Path to the casebase file
///
/// \return The casebase description
////////////////////////////////////////////////////////////
std::vector<std::vector<int>> read_case_base(std::string path) {
    std::ifstream file(path);
    std::vector<std::vector<int>> cb;
    std::string line;

    if (file) {
        while (std::getline(file, line)) {
            cb.push_back(line_to_vect<int>(line));
        }
    }
    return cb;
}

////////////////////////////////////////////////////////////
/// \brief Read the outcomes from a file
///
/// \param path Path to the outcomes file
///
/// \return The outcomes
////////////////////////////////////////////////////////////
std::vector<bool> read_mapping(std::string path) {
    std::ifstream file(path);
    std::vector<bool> v;
    std::string line;
    if (file) {
        while (std::getline(file, line)) {
            v.push_back(bool(std::stoi(line)));
        }
    }
    return v;
}