package m1928

import (
    "android/soong/android"
)

func init() {
    android.RegisterModuleType("meizu_m1928_fod_hal_binary", fodHalBinaryFactory)
    android.RegisterModuleType("meizu_m1928_light_hal_binary", lightHalBinaryFactory)
}
