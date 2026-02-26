// -----------------------------------------------------------------------------
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2019 - 2026 by the AxiSEM3D authors
//
// This file is part of the AxiSEM3D library. See the LICENSE file for details.
//
// -----------------------------------------------------------------------------

//  wavefield scanning

#ifndef WavefieldScanning_hpp
#define WavefieldScanning_hpp

#include "numerical.hpp"
class SE_Model;
class Domain;

class WavefieldScanning {
  friend class Domain;

  public:
  // setup
  static void
  setup(double dt, double period, int numTotalSteps, const SE_Model& sem, Domain& domain);

  private:
  std::string mFileName;
  numerical::Real mTolFourierH2 = 0.;
  numerical::Real mRelTolH2 = 0.;
  numerical::Real mAbsTolH2 = 0.;
  int mMaxNumPeaks = 0;
  int mScanningInterval = 0;
};

#endif /* WavefieldScanning_hpp */
