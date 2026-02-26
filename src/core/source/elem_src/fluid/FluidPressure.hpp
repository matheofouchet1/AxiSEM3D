// -----------------------------------------------------------------------------
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2019 - 2026 by the AxiSEM3D authors
//
// This file is part of the AxiSEM3D library. See the LICENSE file for details.
//
// -----------------------------------------------------------------------------

//  pressure source on fluid element

#ifndef FluidPressure_hpp
#define FluidPressure_hpp

#include "FluidSource.hpp"
#include "eigen_element.hpp"

class FluidPressure : public FluidSource {
  public:
  // constructor
  FluidPressure(std::unique_ptr<STF>& stf,
      const std::shared_ptr<FluidElement>& element,
      const eigen::CMatXN& pattern);

  // apply source at a time step
  void
  apply(double time) const;

  private:
  // source pattern
  const eigen::CMatXN mPattern;

  ////////////////////////////////////////
  //////////////// static ////////////////
  ////////////////////////////////////////

  // workspace
  inline static eigen::CMatXN sPattern = eigen::CMatXN(0, spectral::nPEM);
};

#endif /* FluidPressure_hpp */
