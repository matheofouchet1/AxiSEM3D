// -----------------------------------------------------------------------------
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2019 - 2026 by the AxiSEM3D authors
//
// This file is part of the AxiSEM3D library. See the LICENSE file for details.
//
// -----------------------------------------------------------------------------

//  axial boundary condition

#ifndef AxialBoundary_hpp
#define AxialBoundary_hpp

// point
#include <memory>
#include <vector>
class SolidPoint;
class FluidPoint;

// domain
class Messaging;

class AxialBoundary {
  public:
  // add solid point
  void
  addPoint(const std::shared_ptr<SolidPoint>& sp) {
    mSolidPoints.push_back(sp);
  }

  // add fluid point
  void
  addPoint(const std::shared_ptr<FluidPoint>& fp) {
    mFluidPoints.push_back(fp);
  }

  // apply axial masking
  void
  apply() const;

  // count info
  void
  countInfo(const Messaging& msg, int& solid, int& fluid) const;

  private:
  // points on axis
  std::vector<std::shared_ptr<SolidPoint>> mSolidPoints;
  std::vector<std::shared_ptr<FluidPoint>> mFluidPoints;
};

#endif /* AxialBoundary_hpp */
