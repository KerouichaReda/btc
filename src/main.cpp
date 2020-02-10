#include"fmt/format.h"
#include"nlohmann/json.hpp"
#include"curl/curl.h"
#include<iostream>

using json = nlohmann::json;
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}
int main(void)
{
    CURL* curl;
    CURLcode res;
    std::string readBuffer;
    json J;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.coinbase.com/v2/prices/spot?currency=USD");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        J = json::parse(readBuffer);       
        std::string amount = J["data"]["amount"];
        fmt::print("1 btc = {0} $\n", amount);
    }
    return 0;
}

