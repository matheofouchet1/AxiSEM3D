// -----------------------------------------------------------------------------
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2019 - 2026 by the AxiSEM3D authors
//
// This file is part of the AxiSEM3D library. See the LICENSE file for details.
//
// -----------------------------------------------------------------------------

//  source on fluid element

#ifndef FluidSource_hpp
#define FluidSource_hpp

#include "ElementSource.hpp"
class FluidElement;

class FluidSource : public ElementSource {
  public:
  // constructor
  FluidSource(std::unique_ptr<STF>& stf, const std::shared_ptr<const FluidElement>& element) :
      ElementSource(stf), mElement(element) {
    // nothing
  }

  // destructor
  virtual ~FluidSource() = default;

  protected:
  // element pointer
  const std::shared_ptr<const FluidElement> mElement;
};

#endif /* FluidSource_hpp */
