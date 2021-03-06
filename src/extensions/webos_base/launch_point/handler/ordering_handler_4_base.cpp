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

#include "extensions/webos_base/launch_point/handler/ordering_handler_4_base.h"

#include <boost/bind.hpp>

#include "extensions/webos_base/base_logs.h"
#include "extensions/webos_base/base_settings.h"

OrderingHandler4Base::OrderingHandler4Base() {
}

OrderingHandler4Base::~OrderingHandler4Base() {
}

void OrderingHandler4Base::Init() {
}

void OrderingHandler4Base::HandleDbState(bool connection) {
}

void OrderingHandler4Base::ReloadDbData(bool connection) {
}

void OrderingHandler4Base::MakeLaunchPointsInOrder(const std::vector<LaunchPointPtr>& visible_lps, const pbnjson::JValue& changed_reason) {
  visible_lps_ = visible_lps;
  reorder();
}

int OrderingHandler4Base::InsertLpInOrder(const std::string& lp_id, const pbnjson::JValue& data, int position) {
  return 0;
}

int OrderingHandler4Base::UpdateLpInOrder(const std::string& lp_id, const pbnjson::JValue& data, int position) {
  return 0;
}

void OrderingHandler4Base::DeleteLpInOrder(const std::string& lp_id) {
}

void OrderingHandler4Base::reorder() {
  ordered_list_.clear();
  for (auto it = visible_lps_.begin(); it != visible_lps_.end(); ++it) {
    ordered_list_.push_back(it->get()->LaunchPointId());
  }
  signal_launch_points_ordered_(OrderChangeState::FULL);
}
