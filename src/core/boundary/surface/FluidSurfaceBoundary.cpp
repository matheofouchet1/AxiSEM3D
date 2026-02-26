// -----------------------------------------------------------------------------
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2019 - 2026 by the AxiSEM3D authors
//
// This file is part of the AxiSEM3D library. See the LICENSE file for details.
//
// -----------------------------------------------------------------------------

//  stress-free boundary condition on fluid

#include "FluidSurfaceBoundary.hpp"

// point
#include "FluidPoint.hpp"

// domain
#include "Messaging.hpp"

// apply stress-free boundary condition on fluid
void
FluidSurfaceBoundary::apply() const {
  // pressure ≡ 0 or accel ≡ 0
  // so, veloc = disp = everything ≡ 0
  for (const std::shared_ptr<FluidPoint>& fp : mFluidPoints) {
    fp->getFields().mStiff.setZero();
  }
}

// count info
int
FluidSurfaceBoundary::countInfo(const Messaging& msg) const {
  int count = 0;
  for (const auto& point : mFluidPoints) {
    if (!msg.pointInSmallerRank(point)) {
      count++;
    }
  }
  return count;
}
