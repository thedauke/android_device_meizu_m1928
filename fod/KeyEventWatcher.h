/*
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#ifndef VENDOR_LINEAGE_BIOMETRICS_FINGERPRINT_INSCREEN_V1_1_KEYEVENTWATCHER_H
#define VENDOR_LINEAGE_BIOMETRICS_FINGERPRINT_INSCREEN_V1_1_KEYEVENTWATCHER_H

#include <functional>
#include <string>
#include <pthread.h>
#include <linux/input.h>

namespace vendor {
namespace lineage {
namespace biometrics {
namespace fingerprint {
namespace inscreen {
namespace V1_1 {
namespace implementation {

using WatcherCallback = std::function<void(const std::string&, input_event)>;

class KeyEventWatcher {
  public:
    KeyEventWatcher(const std::string& file, const WatcherCallback& callback);

    std::string mFile;
    WatcherCallback mCallback;

    volatile bool mExit;

    void exit();

  private:
    pthread_t mPoll;
};

}  // namespace implementation
}  // namespace V1_1
}  // namespace inscreen
}  // namespace fingerprint
}  // namespace biometrics
}  // namespace lineage
}  // namespace vendor

#endif  // VENDOR_LINEAGE_BIOMETRICS_FINGERPRINT_INSCREEN_V1_1_KEYEVENTWATCHER_H
