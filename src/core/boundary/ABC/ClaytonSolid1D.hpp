// -----------------------------------------------------------------------------
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2019 - 2026 by the AxiSEM3D authors
//
// This file is part of the AxiSEM3D library. See the LICENSE file for details.
//
// -----------------------------------------------------------------------------

//  Clayton-Enquist ABC for solid points in 1D
//  theta: angle between surface normal and z-axis

#ifndef ClaytonSolid1D_hpp
#define ClaytonSolid1D_hpp

#include "ClaytonSolid.hpp"
#include "numerical.hpp"

class ClaytonSolid1D : public ClaytonSolid {
  public:
  // constructor
  ClaytonSolid1D(const std::shared_ptr<SolidPoint>& sp,
      double rhoVp,
      double rhoVs,
      double area,
      double theta) :
      ClaytonSolid(sp), mRSA_CosT2_p_RPA_SinT2(rhoVs * area * cos(theta) * cos(theta) +
                            rhoVp * area * sin(theta) * sin(theta)),
      mRSA_SinT2_p_RPA_CosT2(
          rhoVs * area * sin(theta) * sin(theta) + rhoVp * area * cos(theta) * cos(theta)),
      mRPA_m_RSA_x_CosT_SinT((rhoVp * area - rhoVs * area) * cos(theta) * sin(theta)),
      mRSA(rhoVs * area) {
    // nothing
  }

  // apply ABC
  void
  apply() const;

  private:
  // RSA = rho * vs * area
  // RPA = rho * vp * area
  // RSA Cos[t]^2 + RPA Sin[t]^2
  const numerical::Real mRSA_CosT2_p_RPA_SinT2;
  // RSA Sin[t]^2 + RPA Cos[t]^2
  const numerical::Real mRSA_SinT2_p_RPA_CosT2;
  // (RPA - RSA) Cos[t] Sin[t]
  const numerical::Real mRPA_m_RSA_x_CosT_SinT;
  // RSA (for transverse component)
  const numerical::Real mRSA;
};

#endif /* ClaytonSolid1D_hpp */
