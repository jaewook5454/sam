// Copyright (c) 2017-2018 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#ifndef DB_HANDLER_4_BASE_H
#define DB_HANDLER_4_BASE_H

#include <pbnjson.hpp>

#include "core/launch_point/handler/db_handler.h"
#include "extensions/webos_base/launch_point/db/db_launch_point_4_base.h"
#include "interface/launch_point/db_handler_interface.h"

class DbHandler4Base: public DbHandlerInterface {
public:
  DbHandler4Base();
  virtual ~DbHandler4Base();

  virtual void Init();
  virtual void HandleDbState(bool connection);
  virtual void ReloadDbData(bool connection);

  virtual bool InsertData(const pbnjson::JValue& json);
  virtual bool UpdateData(const pbnjson::JValue& json);
  virtual bool DeleteData(const pbnjson::JValue& json);

private:
  void OnLaunchPointDbLoaded(const pbnjson::JValue& loaded_db_result);

  DBLaunchPoint4Base launch_point_db_;

  bool db_loaded_;
  unsigned int db_load_count_;
};

#endif
