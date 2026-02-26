// -----------------------------------------------------------------------------
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2019 - 2026 by the AxiSEM3D authors
//
// This file is part of the AxiSEM3D library. See the LICENSE file for details.
//
// -----------------------------------------------------------------------------

//  Clayton-Enquist ABC for fluid points

#ifndef ClaytonFluid_hpp
#define ClaytonFluid_hpp

// point
#include <memory>
class FluidPoint;

class ClaytonFluid {
  public:
  // constructor
  ClaytonFluid(const std::shared_ptr<FluidPoint>& fp) : mFluidPoint(fp) {
    // nothing
  }

  // get point
  const std::shared_ptr<FluidPoint>&
  getPoint() const {
    return mFluidPoint;
  }

  // destructor
  virtual ~ClaytonFluid() = default;

  // apply ABC
  virtual void
  apply() const = 0;

  protected:
  // point
  const std::shared_ptr<FluidPoint> mFluidPoint;
};

#endif /* ClaytonFluid_hpp */
