#include <iostream>
#include <string>
#include <curl.h>

// Function to perform HTTP GET request
std::string httpGetRequest(const std::string& url) {
    CURL *curl;
    CURLcode res;
    std::string response;

    // Initialize CURL
    curl = curl_easy_init();
    if (curl) {
        // Set the URL
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        // Set the write callback function
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [](char* ptr, size_t size, size_t nmemb, std::string* data) -> size_t {
            data->append(ptr, size * nmemb);
            return size * nmemb;
        });
        // Set the response string
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        // Perform the request
        res = curl_easy_perform(curl);
        // Check for errors
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        // Clean up
        curl_easy_cleanup(curl);
    }

    return response;
}

int main() {
    // Base URL
    std::string baseUrl = "https://smnd.sk/ttravnicek/citaj.php?appid=Tajn3hE5lo&data=";
    // Number of times to repeat
    int repeatCount = 10; // Change this to the desired repeat count

    // Loop to open the website on repeat
    for (int i = 1; i <= repeatCount; ++i) {
        std::string url = baseUrl + std::to_string(i);
        std::cout << "Opening: " << url << std::endl;
        // Perform HTTP GET request
        std::string response = httpGetRequest(url);
        // Print the response (optional)
        std::cout << "Response: " << response << std::endl;
    }

    return 0;
}
