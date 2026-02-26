// -----------------------------------------------------------------------------
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2019 - 2026 by the AxiSEM3D authors
//
// This file is part of the AxiSEM3D library. See the LICENSE file for details.
//
// -----------------------------------------------------------------------------

//  solid-fluid boundary condition in 1D

#include "SolidFluidCoupling1D.hpp"
#include "SolidPoint.hpp"

// constructor
SolidFluidCoupling1D::SolidFluidCoupling1D(const std::shared_ptr<SolidPoint>& sp,
    const std::shared_ptr<FluidPoint>& fp,
    double ns_unassmb,
    double nz_unassmb,
    double ns_assmb,
    double nz_assmb,
    double massFluid) :
    SolidFluidCoupling(sp, fp), mNormalS_UnassembledMPI(ns_unassmb),
    mNormalZ_UnassembledMPI(nz_unassmb), mNormalS_AssembledMPI_InvMassFluid(ns_assmb / massFluid),
    mNormalZ_AssembledMPI_InvMassFluid(nz_assmb / massFluid) {
  checkCompatibility(mSolidPoint->getNr());
}
