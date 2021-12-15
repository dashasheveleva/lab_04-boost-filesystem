// Copyright 2021 Daria <photodoshfy@gmail.com>

#include "broker.hpp"

const size_t TimePosition = 17;
const size_t AccountPosition = 8;
const size_t PositionLength = 8;

Broker::Broker(const std::string& path) {
    if (!path.empty()) {
        if (fs::exists(path)) {
            pathFTP = path;
        }
    } else {
        pathFTP = fs::current_path();
    }
}
std::stringstream Broker::PrintFiles() {
    std::stringstream ss;
    const std::regex re("^(balance)_\\d{8}_\\d{8}");
    for (const fs::directory_entry& x : fs::directory_iterator{pathFTP}) {
        if (fs::is_directory(x.path())) {
            for (const fs::directory_entry& y : fs::directory_iterator{x.path()}) {
                if (y.path().extension() == ".txt" &&
                    y.path().stem().extension() == "" &&
                    std::regex_search(y.path().stem().string(), re)) {
                    ss << std::left << y.path().parent_path().filename().string() << " "
                       << y.path().filename().string() << std::endl;
                    paths.push_back(y.path());
                    accounts.insert(
                            y.path().stem().string().substr(AccountPosition, PositionLength));
                }
            }
        }
    }
    return ss;
}
std::stringstream Broker::PrintAccounts() const {
    std::stringstream ss;
    for (const auto& x : accounts) {
        fs::path max;
        size_t n = 0;
        for (const auto& y : paths) {
            if (x == y.stem().string().substr(AccountPosition, PositionLength)) {
                if ((n < 1) || (y.stem().string().substr(TimePosition, PositionLength) >
                    max.stem().string().substr(TimePosition, PositionLength))) {
                    max = y;
                };
                ++n;
            }
        }
        ss << "broker:" << max.parent_path().filename().string() << " account:"
           << max.stem().string().substr(AccountPosition, PositionLength)
           << " files:" << n << " lastdate:"
           << max.stem().string().substr(TimePosition, PositionLength) << std::endl;
    }
    return ss;
}