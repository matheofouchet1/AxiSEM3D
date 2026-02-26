// -----------------------------------------------------------------------------
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2019 - 2026 by the AxiSEM3D authors
//
// This file is part of the AxiSEM3D library. See the LICENSE file for details.
//
// -----------------------------------------------------------------------------

//  solid-fluid boundary condition

#include "SolidFluidBoundary.hpp"

// domain
#include "Messaging.hpp"
#include "SolidPoint.hpp"
#include "bstring.hpp"
#include "vector_tools.hpp"

// count info
std::map<std::string, int>
SolidFluidBoundary::countInfo(const Messaging& msg) const {
  std::map<std::string, int> countMap;
  for (const auto& sfc : mSFCs) {
    if (!msg.pointInSmallerRank(sfc->getSolidPoint())) {
      vector_tools::aggregate(countMap, bstring::typeName(*sfc), 1);
    }
  }
  return countMap;
}
