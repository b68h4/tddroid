//
// Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com) 2014-2020
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#pragma once

#include "td/telegram/logevent/SecretChatEvent.h"
#include "td/telegram/SecretChatActor.h"
#include "td/telegram/SecretChatId.h"

#include "td/telegram/secret_api.h"
#include "td/telegram/telegram_api.h"

#include "td/actor/actor.h"
#include "td/actor/PromiseFuture.h"

#include "td/utils/common.h"
#include "td/utils/Time.h"

#include <map>
#include <utility>

namespace td {

struct BinlogEvent;

class SecretChatsManager : public Actor {
 public:
  explicit SecretChatsManager(ActorShared<> parent);

  // Proxy query to corrensponding SecretChatActor.
  // Look for more info in SecretChatActor.h
  void on_update_chat(tl_object_ptr<telegram_api::updateEncryption> update);
  void on_new_message(tl_object_ptr<telegram_api::EncryptedMessage> &&message_ptr, Promise<Unit> &&promise);

  void create_chat(int32 user_id, int64 user_access_hash, Promise<SecretChatId> promise);
  void cancel_chat(SecretChatId, Promise<> promise);
  void send_message(SecretChatId secret_chat_id, tl_object_ptr<secret_api::decryptedMessage> message,
                    tl_object_ptr<telegram_api::InputEncryptedFile> file, Promise<> promise);
  void send_message_action(SecretChatId secret_chat_id, tl_object_ptr<secret_api::SendMessageAction> action);
  void send_read_history(SecretChatId secret_chat_id, int32 date, Promise<> promise);
  void send_open_message(SecretChatId secret_chat_id, int64 random_id, Promise<> promise);
  void delete_messages(SecretChatId secret_chat_id, vector<int64> random_ids, Promise<> promise);
  void delete_all_messages(SecretChatId secret_chat_id, Promise<> promise);
  void notify_screenshot_taken(SecretChatId secret_chat_id, Promise<> promise);
  void send_set_ttl_message(SecretChatId secret_chat_id, int32 ttl, int64 random_id, Promise<> promise);

  // Binlog replay
  void replay_binlog_event(BinlogEvent &&binlog_event);
  void binlog_replay_finish();

 private:
  bool binlog_replay_finish_flag_ = false;
  bool dummy_mode_ = false;
  bool close_flag_ = false;
  ActorShared<> parent_;
  std::map<int32, ActorOwn<SecretChatActor>> id_to_actor_;

  bool is_online_{false};

  std::vector<std::pair<Timestamp, telegram_api::object_ptr<telegram_api::updateEncryption>>> pending_chat_updates_;
  void flush_pending_chat_updates();
  void do_update_chat(tl_object_ptr<telegram_api::updateEncryption> update);

  void replay_inbound_message(unique_ptr<log_event::InboundSecretMessage> message);
  void add_inbound_message(unique_ptr<log_event::InboundSecretMessage> message);
  void replay_outbound_message(unique_ptr<log_event::OutboundSecretMessage> message);
  void replay_close_chat(unique_ptr<log_event::CloseSecretChat> message);
  void replay_create_chat(unique_ptr<log_event::CreateSecretChat> message);

  unique_ptr<SecretChatActor::Context> make_secret_chat_context(int32 id);
  ActorId<SecretChatActor> get_chat_actor(int32 id);
  ActorId<SecretChatActor> create_chat_actor(int32 id);
  ActorId<SecretChatActor> create_chat_actor_impl(int32 id, bool can_be_empty);

  void start_up() override;
  void hangup() override;
  void hangup_shared() override;
  void timeout_expired() override;

  void on_online(bool is_online);
};
}  // namespace td
