//
// Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com) 2014-2020
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include <td/telegram/td_json_client.h>

#define EXPORT __attribute__ ((visibility ("default")))

extern "C" {

EXPORT void *_td_json_client_create() {
  return td_json_client_create();
}

EXPORT void _td_json_client_send(void *client, const char *request) {
  return td_json_client_send(client, request);
}

EXPORT const char *_td_json_client_receive(void *client, double timeout) {
  return td_json_client_receive(client, timeout);
}

EXPORT const char *_td_json_client_execute(void *client, const char *request) {
  return td_json_client_execute(client, request);
}

EXPORT void _td_json_client_destroy(void *client) {
  return td_json_client_destroy(client);
}

}