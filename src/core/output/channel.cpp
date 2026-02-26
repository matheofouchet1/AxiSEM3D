// -----------------------------------------------------------------------------
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2019 - 2026 by the AxiSEM3D authors
//
// This file is part of the AxiSEM3D library. See the LICENSE file for details.
//
// -----------------------------------------------------------------------------

//  channels for wavefield output

#include "channel.hpp"
#include "vector_tools.hpp"

using namespace channel;

// constructor
solid::ChannelOptions::ChannelOptions(
    WavefieldCS wcs, const std::vector<std::string>& userChannels) : mWCS(wcs) {
  // standard channels
  for (const std::string& uch : userChannels) {
    bool found = false;
    for (auto iter = solid::gChannelMap.begin(); iter != solid::gChannelMap.end(); iter++) {
      const auto& uchs = std::get<1>(iter->second);
      if (std::find(uchs.begin(), uchs.end(), uch) != uchs.end()) {
        mStdChannels.push_back(iter->first);
        found = true;
      }
    }
    if (!found) {
      throw std::runtime_error("channel::solid::ChannelOptions::"
                               "ChannelOptions || "
                               "Unknown channel for solid: " +
          uch);
    }
  }

  // sort and unique
  vector_tools::sortUnique(mStdChannels);

  // check fields
  mNeedBufferU = false;
  mNeedBufferG = false;
  mNeedBufferE = false;
  mNeedBufferR = false;
  mNeedBufferS = false;
  for (const int& stdch : mStdChannels) {
    const char& c = std::get<0>(solid::gChannelMap.at(stdch)).c_str()[0];
    mNeedBufferU = (c == 'U') || mNeedBufferU;
    mNeedBufferG = (c == 'G') || mNeedBufferG;
    mNeedBufferE = (c == 'E') || mNeedBufferE;
    mNeedBufferR = (c == 'R') || mNeedBufferR;
    mNeedBufferS = (c == 'S') || mNeedBufferS;
  }

  if (!mNeedBufferU && !mNeedBufferG && !mNeedBufferE && !mNeedBufferR && !mNeedBufferS) {
    throw std::runtime_error("channel::solid::ChannelOptions::"
                             "ChannelOptions || "
                             "No channel found for solid.");
  }
}

// constructor
fluid::ChannelOptions::ChannelOptions(
    WavefieldCS wcs, const std::vector<std::string>& userChannels) : mWCS(wcs) {
  // standard channels
  for (const std::string& uch : userChannels) {
    bool found = false;
    for (auto iter = fluid::gChannelMap.begin(); iter != fluid::gChannelMap.end(); iter++) {
      const auto& uchs = std::get<1>(iter->second);
      if (std::find(uchs.begin(), uchs.end(), uch) != uchs.end()) {
        mStdChannels.push_back(iter->first);
        found = true;
      }
    }
    if (!found) {
      throw std::runtime_error("channel::fluid::ChannelOptions::"
                               "ChannelOptions || "
                               "Unknown channel for fluid: " +
          uch);
    }
  }

  // sort and unique
  vector_tools::sortUnique(mStdChannels);

  // check fields
  mNeedBufferX = false;
  mNeedBufferU = false;
  mNeedBufferP = false;
  mNeedBufferD = false;
  for (const int& stdch : mStdChannels) {
    const char& c = std::get<0>(fluid::gChannelMap.at(stdch)).c_str()[0];
    mNeedBufferX = (c == 'X') || mNeedBufferX;
    mNeedBufferU = (c == 'U') || mNeedBufferU;
    mNeedBufferP = (c == 'P') || mNeedBufferP;
    mNeedBufferD = (c == 'D') || mNeedBufferD;
  }

  if (!mNeedBufferX && !mNeedBufferU && !mNeedBufferP && !mNeedBufferD) {
    throw std::runtime_error("channel::fluid::ChannelOptions::"
                             "ChannelOptions || "
                             "No channel found for fluid.");
  }
}
