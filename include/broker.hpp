// Copyright 2021 Daria <photodoshfy@gmail.com>

#ifndef INCLUDE_BROKER_HPP_
#define INCLUDE_BROKER_HPP_

#include <boost/filesystem.hpp>
#include <iomanip>
#include <iostream>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <vector>

namespace fs = boost::filesystem;

class Broker{
private:
    fs::path pathFTP;
    std::set<std::string> accounts;
    std::vector<fs::path> paths;

public:
    explicit Broker(const std::string& path);
    std::stringstream PrintFiles();
    std::stringstream PrintAccounts() const;
};


#endif // INCLUDE_BROKER_HPP_
