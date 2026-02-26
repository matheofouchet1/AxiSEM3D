// -----------------------------------------------------------------------------
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2019 - 2026 by the AxiSEM3D authors
//
// This file is part of the AxiSEM3D library. See the LICENSE file for details.
//
// -----------------------------------------------------------------------------

//  solid-fluid boundary condition

#ifndef SolidFluidBoundary_hpp
#define SolidFluidBoundary_hpp

#include <vector>
#include "SolidFluidCoupling.hpp"

// domain
#include <map>
class Messaging;

class SolidFluidBoundary {
  public:
  // add solid-fluid coupling
  void
  addSolidFluidCoupling(std::unique_ptr<const SolidFluidCoupling>& sf) {
    mSFCs.push_back(std::move(sf));
  }

  // apply solid-fluid coupling
  void
  apply() const {
    for (const std::unique_ptr<const SolidFluidCoupling>& sfc : mSFCs) {
      sfc->apply();
    }
  }

  // count info
  std::map<std::string, int>
  countInfo(const Messaging& msg) const;

  private:
  // solid-fluid coupling pairs
  std::vector<std::unique_ptr<const SolidFluidCoupling>> mSFCs;
};

#endif /* SolidFluidBoundary_hpp */
