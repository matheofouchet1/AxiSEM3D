// -----------------------------------------------------------------------------
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2019 - 2026 by the AxiSEM3D authors
//
// This file is part of the AxiSEM3D library. See the LICENSE file for details.
//
// -----------------------------------------------------------------------------

//  Clayton-Enquist ABC for solid points

#ifndef ClaytonSolid_hpp
#define ClaytonSolid_hpp

// point
#include <memory>
class SolidPoint;

class ClaytonSolid {
  public:
  // constructor
  ClaytonSolid(const std::shared_ptr<SolidPoint>& sp) : mSolidPoint(sp) {
    // nothing
  }

  // get point
  const std::shared_ptr<SolidPoint>&
  getPoint() const {
    return mSolidPoint;
  }

  // destructor
  virtual ~ClaytonSolid() = default;

  // apply ABC
  virtual void
  apply() const = 0;

  protected:
  // point
  const std::shared_ptr<SolidPoint> mSolidPoint;
};

#endif /* ClaytonSolid_hpp */
