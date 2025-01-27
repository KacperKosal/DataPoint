cmake_minimum_required(VERSION 3.29)
project(EnergyDataAnalyzer)

set(CMAKE_CXX_STANDARD 26)

add_executable(EnergyDataAnalyzer main.cpp
        Headers/EnergyData.hpp
        Headers/DateTime.hpp
        Sources/DateTime.cpp
        Sources/EnergyData.cpp
        Headers/Year.hpp
        Sources/Year.cpp
        Headers/Month.hpp
        Sources/Month.cpp
        Headers/Day.hpp
        Headers/Time.hpp
        Sources/Time.cpp
        Headers/Data.hpp
        Sources/Data.cpp
        Headers/Quarter.hpp
        Sources/Quarter.cpp
        Sources/Day.cpp
        Headers/EnergyAnalyzer.hpp
        "Sources/EnergyAnalyzer.cpp"
        Headers/CommandParser.hpp
        Sources/CommandParser.cpp)