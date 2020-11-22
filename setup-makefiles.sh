#!/bin/bash
#
#
# SPDX-License-Identifier: Apache-2.0
#

set -e

export DEVICE=m1928
export VENDOR=meizu
export DEVICE_BRINGUP_YEAR=2020

# Load extract_utils and do some sanity checks
MY_DIR="${BASH_SOURCE%/*}"
if [[ ! -d "$MY_DIR" ]]; then MY_DIR="$PWD"; fi

RR_ROOT="$MY_DIR"/../../..

HELPER="$RR_ROOT"/vendor/rr/build/tools/extract_utils.sh
if [ ! -f "$HELPER" ]; then
    echo "Unable to find helper script at $HELPER"
    exit 1
fi
. "$HELPER"

# Initialize the helper
setup_vendor "$DEVICE" "$VENDOR" "$RR_ROOT"

# Copyright headers and guards
write_headers

write_makefiles "${MY_DIR}/proprietary-files.txt"

# Finish
write_footers

# "./../../${VENDOR}/${DEVICE}/setup-makefiles.sh" "$@"