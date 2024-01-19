#ifndef main_Components_http_include_esp32_http_server_hpp
#define main_Components_http_include_esp32_http_server_hpp
/*------------------------------------------------------------------------------+
 |   		 	C L A S S   I N F O R M A T I O N                               |
 +------------------------------------------------------------------------------+
 |  ToDo: check auto generated function comment
 |
 |  Function Name:  esp32_http_server.hpp
 |
 |  Author       :  Nikolaj Gliese Pedersen
 |  Email 	     :  <nikolajgliese@tutanota.com>
 |
 |  Description  :  This class, esp32_http_server.hpp, is designed as:
 |                  - A http server for the esp32 chip
 |
 |
 |
 |
 |
 |
 |  version       : 1.0
 |
 |  Return Value  :   return_type
 |
 +-----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------+
 |   		 					Includes                     		            |
 +------------------------------------------------------------------------------*/

/*----------------- DEFAULT INCLUDE -------------------------------------------*/

/*-----------------------------------------------------------------------------*/

#include <iostream>
#ifdef __ESP32__
#include <esp_http_server.h>

#else
typedef void* httpd_handle_t;
typedef void* httpd_req_t;
typedef int esp_err_t;
#endif
/*------------------------------------------------------------------------------+
 |                               Typedef                                        |
 +------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------+
 |   		 					 Class                     		                |
 +------------------------------------------------------------------------------*/


class esp32_http_server {

      public:
      esp32_http_server(void);
      esp32_http_server(esp32_http_server const & src) = delete; // Deleted copy constructor
      esp32_http_server& operator=(esp32_http_server const & rhs) = delete; // Deleted copy assignment operator
      esp32_http_server(esp32_http_server && src) = delete; // Deleted move constructor
      esp32_http_server& operator=(esp32_http_server && rhs) = delete; // Deleted move assignment operator

      ~esp32_http_server(void);
      // install put and get request
      void install_get_request(const char* path, esp_err_t (*handler)(httpd_req_t*), void* handler_arg = NULL);
      void install_put_request(const char* path, esp_err_t (*handler)(httpd_req_t*), void* handler_arg = NULL);

      void start_server(void);
      void stop_server(void);
      static bool send_response(httpd_req_t *req, const char* response);
      static bool recieve_request(httpd_req_t *req, char* buffer, size_t buffer_size);
      private:
 

      // install the http server
      httpd_handle_t m_server;
      };

#endif /*main_Components_http_include_esp32_http_server_hpp*/