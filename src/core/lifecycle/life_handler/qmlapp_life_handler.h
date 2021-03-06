// Copyright (c) 2012-2018 LG Electronics, Inc.
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

#ifndef QMLAPP_LIFE_HANDLER_H_
#define QMLAPP_LIFE_HANDLER_H_

#include "core/lifecycle/life_handler/life_handler_interface.h"

class QmlAppLifeHandler: public AppLifeHandlerInterface
{
public:
    QmlAppLifeHandler();
    virtual ~QmlAppLifeHandler();

    virtual void launch(AppLaunchingItemPtr item);
    virtual void close(AppCloseItemPtr item, std::string& err_text);
    virtual void pause(const std::string& app_id, const pbnjson::JValue& params,
                        std::string& err_text, bool send_life_event = true);
    virtual void clear_handling_item(const std::string& app_id);

    AppLaunchingItemPtr get_lscall_request_item_by_token(const LSMessageToken& token);
    void remove_item_from_lscall_request_list(const std::string& uid);

    void on_service_ready();

private:
    void initialize();
    static bool cb_return_booster_launch(LSHandle* handle, LSMessage* lsmsg, void* user_data);
    static bool cb_return_booster_close(LSHandle* handle, LSMessage* lsmsg, void* user_data);
    static bool cb_on_qml_process_finished(LSHandle* handle, LSMessage* lsmsg, void* user_data);

    static bool qml_process_watcher(LSHandle* handle, LSMessage* lsmsg, void* user_data);

public:
    boost::signals2::signal<void (const std::string& app_id, const std::string& uid, const RuntimeStatus& life_status)> signal_app_life_status_changed;
    boost::signals2::signal<void (const std::string& app_id, const std::string& pid, const std::string& webprocid)> signal_running_app_added;
    boost::signals2::signal<void (const std::string& app_id)> signal_running_app_removed;
    boost::signals2::signal<void (const std::string& uid)> signal_launching_done;

private:
    AppLaunchingItemList m_lscall_request_list;
};

#endif
