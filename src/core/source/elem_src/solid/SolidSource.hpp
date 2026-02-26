// -----------------------------------------------------------------------------
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2019 - 2026 by the AxiSEM3D authors
//
// This file is part of the AxiSEM3D library. See the LICENSE file for details.
//
// -----------------------------------------------------------------------------

//  source on solid element

#ifndef SolidSource_hpp
#define SolidSource_hpp

#include "ElementSource.hpp"
class SolidElement;

class SolidSource : public ElementSource {
  public:
  // constructor
  SolidSource(std::unique_ptr<STF>& stf, const std::shared_ptr<const SolidElement>& element) :
      ElementSource(stf), mElement(element) {
    // nothing
  }

  // destructor
  virtual ~SolidSource() = default;

  protected:
  // element pointer
  const std::shared_ptr<const SolidElement> mElement;
};

#endif /* SolidSource_hpp */
