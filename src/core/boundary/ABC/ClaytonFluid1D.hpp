// -----------------------------------------------------------------------------
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2019 - 2026 by the AxiSEM3D authors
//
// This file is part of the AxiSEM3D library. See the LICENSE file for details.
//
// -----------------------------------------------------------------------------

//  Clayton-Enquist ABC for fluid points in 1D

#ifndef ClaytonFluid1D_hpp
#define ClaytonFluid1D_hpp

#include "ClaytonFluid.hpp"
#include "numerical.hpp"

class ClaytonFluid1D : public ClaytonFluid {
  public:
  // constructor
  ClaytonFluid1D(const std::shared_ptr<FluidPoint>& fp, double rhoVp, double area) :
      ClaytonFluid(fp), mAreaOverRhoVp(area / rhoVp) {
    // nothing
  }

  // apply ABC
  void
  apply() const;

  private:
  // area / (rho * vp)
  const numerical::Real mAreaOverRhoVp;
};

#endif /* ClaytonFluid1D_hpp */
