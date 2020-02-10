cmake_minimum_required(VERSION 3.14)
project (BTC_Project LANGUAGES CXX)

#PACKAGES

find_package(nlohmann_json CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(CURL CONFIG REQUIRED)

SET(PROJECT_SOURCE_FILES 
	main.cpp)

#SET(PROJECT_HEADER_FILES)

ADD_EXECUTABLE(btc ${PROJECT_SOURCE_FILES})

#TARGET

target_link_libraries(btc PRIVATE nlohmann_json nlohmann_json::nlohmann_json)
target_link_libraries(btc PRIVATE fmt::fmt fmt::fmt-header-only)
target_link_libraries(btc PRIVATE CURL::libcurl)

