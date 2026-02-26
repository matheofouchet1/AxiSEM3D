// -----------------------------------------------------------------------------
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2019 - 2026 by the AxiSEM3D authors
//
// This file is part of the AxiSEM3D library. See the LICENSE file for details.
//
// -----------------------------------------------------------------------------

//  source on element

#ifndef ElementSource_hpp
#define ElementSource_hpp

#include "STF.hpp"

class ElementSource {
  public:
  // constructor
  ElementSource(std::unique_ptr<STF>& stf) : mSTF(std::move(stf)) {
    // nothing
  }

  // destructor
  virtual ~ElementSource() = default;

  // apply source at a time step
  virtual void
  apply(double time) const = 0;

  protected:
  // source-time function
  const std::unique_ptr<STF> mSTF;
};

#endif /* ElementSource_hpp */
