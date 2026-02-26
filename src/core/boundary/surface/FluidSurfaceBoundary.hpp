// -----------------------------------------------------------------------------
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2019 - 2026 by the AxiSEM3D authors
//
// This file is part of the AxiSEM3D library. See the LICENSE file for details.
//
// -----------------------------------------------------------------------------

//  stress-free boundary condition on fluid

#ifndef FluidSurfaceBoundary_hpp
#define FluidSurfaceBoundary_hpp

// point
#include <memory>
#include <vector>
class FluidPoint;

// domain
class Messaging;

class FluidSurfaceBoundary {
  public:
  // add fluid point
  void
  addPoint(const std::shared_ptr<FluidPoint>& fp) {
    mFluidPoints.push_back(fp);
  }

  // apply stress-free boundary condition on fluid
  void
  apply() const;

  // count info
  int
  countInfo(const Messaging& msg) const;

  private:
  // points on surface
  std::vector<std::shared_ptr<FluidPoint>> mFluidPoints;
};

#endif /* FluidSurfaceBoundary_hpp */
