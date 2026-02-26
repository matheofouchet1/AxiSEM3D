// -----------------------------------------------------------------------------
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2019 - 2026 by the AxiSEM3D authors
//
// This file is part of the AxiSEM3D library. See the LICENSE file for details.
//
// -----------------------------------------------------------------------------

//  global FFT solvers for core

#ifndef fft_hpp
#define fft_hpp

#include "SolverFFTW.hpp"
#include "spectral.hpp"
#include "numerical.hpp"

namespace fft {
  using numerical::Real;
  using spectral::nPEM;

  // global FFT solvers
  extern SolverFFTW<Real, 1> gFFT_1;
  extern SolverFFTW<Real, 3> gFFT_3;
  extern SolverFFTW<Real, nPEM * 3> gFFT_N3;
  extern SolverFFTW<Real, nPEM * 6> gFFT_N6;
  extern SolverFFTW<Real, nPEM * 9> gFFT_N9;

  // create plans
  void
  createPlans(double timeLimitForPlanning);

  // verbose
  std::string
  verbose(const std::string& stageKey);

  //////////////// internal tools for verbose ////////////////
  namespace internal {
    // statistics for diagnosis and verbose
    void
    statistics(const std::vector<int>& plannedNRs,
        int HOWMANY,
        int& numNR_MaxMPI,
        int& maxNR_MaxMPI,
        int& sumNR_MaxMPI,
        double& memGB_MaxMPI);

    // diagnostic info after creating plans
    void
    diagnosticInfo(const std::vector<int>& plannedNRs, int HOWMANY);

    // verbose
    std::string
    verbose(const std::string& subtitle, const std::vector<int>& plannedNRs, int HOWMANY);
  } // namespace internal
} // namespace fft

#endif /* fftw_hpp */
