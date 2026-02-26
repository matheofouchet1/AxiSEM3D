// -----------------------------------------------------------------------------
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2019 - 2026 by the AxiSEM3D authors
//
// This file is part of the AxiSEM3D library. See the LICENSE file for details.
//
// -----------------------------------------------------------------------------

//  absorbing boundary condition

#include "AbsorbingBoundary.hpp"

// domain
#include "Messaging.hpp"
#include "SolidPoint.hpp"
#include "FluidPoint.hpp"
#include "bstring.hpp"
#include "vector_tools.hpp"

// count info
std::map<std::string, int>
AbsorbingBoundary::countInfo(const Messaging& msg) const {
  std::map<std::string, int> countMap;
  // Clayton in solid
  for (const auto& clayton : mClaytonSolids) {
    if (!msg.pointInSmallerRank(clayton->getPoint())) {
      vector_tools::aggregate(countMap, bstring::typeName(*clayton), 1);
    }
  }
  // Clayton in fluid
  for (const auto& clayton : mClaytonFluids) {
    if (!msg.pointInSmallerRank(clayton->getPoint())) {
      vector_tools::aggregate(countMap, bstring::typeName(*clayton), 1);
    }
  }
  // sponge in solid
  for (const auto& sponge : mSpongeSolids) {
    if (!msg.pointInSmallerRank(sponge->getPoint())) {
      vector_tools::aggregate(countMap, "SpongeSolid", 1);
    }
  }
  // sponge in fluid
  for (const auto& sponge : mSpongeFluids) {
    if (!msg.pointInSmallerRank(sponge->getPoint())) {
      vector_tools::aggregate(countMap, "SpongeFluid", 1);
    }
  }
  return countMap;
}
