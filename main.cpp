#include <uWS/uWS.h>
#include <iostream>
#include <thread>
#include <algorithm>

#define REMOTE_URI "wss://127.0.0.1:3000"

int main(int argc, char* argv[]) {
  (void) argc; (void) argv;
  uWS::Hub h;
  uWS::Group<uWS::CLIENT> *ssl_group = h.createGroup<uWS::CLIENT>(uWS::PERMESSAGE_DEFLATE);
  ssl_group->onConnection([](uWS::WebSocket<uWS::CLIENT>* ws, uWS::HttpRequest http_request) {
    std::cout << "Connection established: " << ws->getAddress().address << ":" << ws->getAddress().port << std::endl;
  });
  h.connect(REMOTE_URI, nullptr, {}, 5000, ssl_group);
  h.run();

  return EXIT_SUCCESS;
}
