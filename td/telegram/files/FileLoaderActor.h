//
// Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com) 2014-2024
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#pragma once

#include "td/telegram/files/FileLocation.h"
#include "td/telegram/files/ResourceState.h"
#include "td/telegram/net/NetQuery.h"

#include "td/actor/actor.h"

namespace td {

class ResourceManager;

class FileLoaderActor : public NetQueryCallback {
 public:
  virtual void set_resource_manager(ActorShared<ResourceManager> resource_manager) = 0;
  virtual void update_priority(int8 priority) = 0;
  virtual void update_resources(const ResourceState &other) = 0;

  // TODO: existence of these two functions is a dirty hack. Refactoring is highly appreciated
  virtual void update_local_file_location(const LocalFileLocation &local) {
  }
  virtual void update_downloaded_part(int64 offset, int64 limit, int64 max_resource_limit) {
  }
};

}  // namespace td
