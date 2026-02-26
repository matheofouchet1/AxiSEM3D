// -----------------------------------------------------------------------------
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2019 - 2026 by the AxiSEM3D authors
//
// This file is part of the AxiSEM3D library. See the LICENSE file for details.
//
// -----------------------------------------------------------------------------

//  polynomial order of spectral elements

#ifndef spectral_hpp
#define spectral_hpp

#ifndef _NPOL
#define _NPOL 4
#endif

namespace spectral {
  // npol
  const int nPol = _NPOL;

  // number of points on an edge
  const int nPntEdge = nPol + 1;

  // number of points in an element
  const int nPntElem = nPntEdge * nPntEdge;

  // shortened alias
  const int nPED = nPntEdge;
  const int nPEM = nPntElem;
} // namespace spectral

#endif /* spectral_hpp */
