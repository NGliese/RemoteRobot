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
 *  \file       esp32_http_server.cpp
 *  \author     N.G Pedersen <nikolajgliese@tutanota.com>
 *  \version    1.0
 *  \date       2024
 *  \copyright  --
 *
 *
 ***********************************************************************************************/

#include "../include/esp32_http_server.hpp"

//#define DEBUG // default uncommeted

#ifdef DEBUG
static const char* LOG_TAG = "esp32_http_server";
#endif

esp32_http_server::esp32_http_server() : m_server(NULL)
{
    start_server();
}

esp32_http_server::~esp32_http_server()
{
    stop_server();
}

void esp32_http_server::start_server(void)
{
    #ifdef __ESP32__
    if(m_server == NULL)
    {
        /* Generate default configuration */
        httpd_config_t config = HTTPD_DEFAULT_CONFIG();
        ESP_ERROR_CHECK(httpd_start(&m_server, &config));       
    }
    #endif
}

void esp32_http_server::stop_server(void)
{
    #ifdef __ESP32__
    if(m_server)
    {
        // stop the server
        ESP_ERROR_CHECK(httpd_stop(m_server));       
    }
    #endif
}

bool esp32_http_server::send_response(httpd_req_t *req, const char* response)
{
    #ifdef __ESP32__
    // send the response
    httpd_resp_send(req, response, HTTPD_RESP_USE_STRLEN);
    return true;
    #else
    return false;
    #endif
}

bool esp32_http_server::recieve_request(httpd_req_t *req, char* buffer, size_t buffer_size)
{
    #ifdef __ESP32__
    // create a lambda function MIN which returns the smallest of two values
    #define MIN(a,b) (((a)<(b))?(a):(b))
    /* Truncate if content length larger than the buffer */
    size_t recv_size = MIN(req->content_len, buffer_size);
    // recieve the request
    int ret = httpd_req_recv(req, buffer, recv_size);
    if (ret <= 0) {  /* 0 return value indicates connection closed */
        /* Check if timeout occurred */
        if (ret == HTTPD_SOCK_ERR_TIMEOUT) {
            /* In case of timeout one can choose to retry calling
             * httpd_req_recv(), but to keep it simple, here we
             * respond with an HTTP 408 (Request Timeout) error */
            httpd_resp_send_408(req);
        }
        /* In case of error, returning ESP_FAIL will
         * ensure that the underlying socket is closed */
        return false;
    }
    // send response
    esp32_http_server::send_response(req, "ok");
    return true;
    #else
    return false;
    #endif
}

void esp32_http_server::install_get_request(const char* path, esp_err_t (*handler)(httpd_req_t*), void* handler_arg )
{
    #ifdef __ESP32__
    httpd_uri_t uri_get = {
        .uri       = path,
        .method    = HTTP_GET,
        .handler   = handler,
        .user_ctx  = handler_arg
    };
    httpd_register_uri_handler(m_server, &uri_get);
    #endif
}

void esp32_http_server::install_put_request(const char* path, esp_err_t (*handler)(httpd_req_t*), void* handler_arg )
{
    #ifdef __ESP32__
    httpd_uri_t uri_put = {
        .uri       = path,
        .method    = HTTP_PUT,
        .handler   = handler,
        .user_ctx  = handler_arg
    };
    httpd_register_uri_handler(m_server, &uri_put);
    #endif
}