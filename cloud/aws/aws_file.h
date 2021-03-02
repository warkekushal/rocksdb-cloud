//  Copyright (c) 2016-present, Rockset, Inc.  All rights reserved.
//
#pragma once
#ifdef USE_AWS

#include <aws/core/Aws.h>

#include "rocksdb/rocksdb_namespace.h"

namespace ROCKSDB_NAMESPACE {
inline Aws::String ToAwsString(const std::string& s) {
  return Aws::String(s.data(), s.size());
}

inline std::string pathtoName(std::string& s) {
  std::string directory;
  size_t drive_idx = s.find(":\\");
  if (drive_idx != std::string::npos) {
    directory += s.substr(0, drive_idx) + "-";
    s = s.substr(drive_idx + 2, s.size() - drive_idx);
  }
  while (s.find('\\') != std::string::npos) {
    drive_idx = s.find('\\');
    if (drive_idx) directory += s.substr(0, drive_idx) + "-";
    s = s.substr(drive_idx + 1, s.size() - drive_idx - 1);
  }
  if (!s.empty()) {
    directory += s;
  }
  return directory;
}

}  // namespace ROCKSDB_NAMESPACE

#endif /* USE_AWS */
