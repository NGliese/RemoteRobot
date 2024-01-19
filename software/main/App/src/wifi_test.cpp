/***********************************************************************************************+
 *  \brief      BRIEF TEXT
 *  \par
 *  \par        @DETAILS
 *
 *
 *  \li         LIMITATION-TO-CLASS
 *  \li         LIMITATION-TO-CLASS
 *
 *  \note       ANY RELEVANT NOTES
 *
 *  \file       wifi_test.cpp
 *  \author     N.G Pedersen <nikolajgliese@tutanota.com>
 *  \version    1.0
 *  \date       2023
 *  \copyright  --
 *
 *
 ***********************************************************************************************/

#include "../include/wifi_test.hpp"
#include "../../Components/wifi/include/WiFi_SAL_esp32.hpp"
#include "../../Components/Timeservice/include/Timeservice.hpp"
#include "../../Components/http/include/esp32_http_sal.hpp"
#include "../../Components/http/include/esp32_http_server.hpp"

//#define DEBUG // default uncommeted

#ifdef DEBUG
static const char* LOG_TAG = "wifi_test";
#endif

wifi_test::wifi_test()
{

}

wifi_test::~wifi_test()
{

}

bool wifi_test::run()
{
    // create the wifi object
    auto wifi = WiFi_SAL_esp32("Drone01", "14Louise");
    // connect to the wifi
    wifi.connect();
    auto SERVER = "192.168.0.189";
    auto PORT = 1880;
    auto HTTP_GET = "/esp32_simple_get_test";
    auto HTTP_POST = "/esp32_simple_post_test";
    auto http = esp32_http_sal(SERVER,PORT);
    while(1)
    {
        std::cout << "wifi status: ... " << std::endl;
        // send a get request
        std::string output;
        http.get(HTTP_GET, output);
        std::cout << "output: " << output << std::endl;
        http.post(HTTP_POST, esp32_http_sal::content_type::TEXT,"hello world");
        // sleep for 1 sec
        Timeservice::wait_sec(1);
    }
    // disconnect from the wifi
    wifi.disconnect();
  
    return true;
}

esp_err_t test_get_handler(httpd_req_t* arg)
{
    std::cout << "test_get_handler" << std::endl;
    esp32_http_server::send_response(arg, "hello world");
    return ESP_OK;
}

esp_err_t test_put_handler(httpd_req_t* arg)
{
    /* Destination buffer for content of HTTP POST request.
     * httpd_req_recv() accepts char* only, but content could
     * as well be any binary data (needs type casting).
     * In case of string data, null termination will be absent, and
     * content length would give length of string */
    char content[100];

    if(esp32_http_server::recieve_request(arg, content, sizeof(content)))
    {
        std::cout << "content: " << content << std::endl;
    }

    std::cout << "test_put_handler" << std::endl;
    return ESP_OK;
}
bool wifi_test::run_http_server()
{
    // create the wifi object
    auto wifi = WiFi_SAL_esp32("Drone01", "14Louise");
    // connect to the wifi
    wifi.connect();

    auto http_server = esp32_http_server();

    http_server.install_get_request("/get_test", &test_get_handler);
    http_server.install_put_request("/put_test", &test_put_handler);
    while(1)
    {
        // sleep for 1 sec
        Timeservice::wait_sec(1);
    }
    return true;
}
