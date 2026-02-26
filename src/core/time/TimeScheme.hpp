// -----------------------------------------------------------------------------
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2019 - 2026 by the AxiSEM3D authors
//
// This file is part of the AxiSEM3D library. See the LICENSE file for details.
//
// -----------------------------------------------------------------------------

//  time scheme

#ifndef TimeScheme_hpp
#define TimeScheme_hpp

// domain
class Domain;
#include <memory>

// verbose
class SimpleTimer;
#include <map>
#include <vector>

class TimeScheme {
  public:
  // constructor
  TimeScheme(int verboseInterval, int stabilityInterval) :
      mVerboseInterval(verboseInterval), mStabilityInterval(stabilityInterval) {
    // nothing
  }

  // destructor
  virtual ~TimeScheme() = default;

  //////////////////// time and domain ////////////////////
  // set time
  void
  setTime(double t0, double dt, int numTimeSteps) {
    mT0 = t0;
    mDt = dt;
    mNumTimeSteps = numTimeSteps;
  }

  // get number of time steps
  int
  getNumTimeSteps() const {
    return mNumTimeSteps;
  }

  // get t0
  double
  getT0() const {
    return mT0;
  }

  // get t1
  double
  getT1() const {
    return mT0 + mNumTimeSteps * mDt;
  }

  // set domain
  void
  setDomain(const std::shared_ptr<const Domain>& domain) {
    mDomain = domain;
  }

  //////////////////// timeloop ////////////////////
  // solve
  virtual void
  solve() const = 0;

  protected:
  // verbose begin
  void
  verboseBegin(const std::string& tsName) const;
  // verbose iteration
  void
  verboseIter(double elapsed, int tstep, double t) const;
  // verbose end
  void
  verboseEnd(const std::string& tsName, double elapsed, double t) const;

  //////////////////// data ////////////////////
  protected:
  // intervals
  const int mVerboseInterval;
  const int mStabilityInterval;

  // time
  double mT0 = 0.;
  double mDt = 0.;
  int mNumTimeSteps = 0;

  // domain
  std::shared_ptr<const Domain> mDomain = nullptr;

  ////////////////////////////////////////
  //////////////// static ////////////////
  ////////////////////////////////////////

  // report loop timers
  static void
  reportLoopTimers(
      const std::vector<std::string>& timerNames, const std::map<std::string, SimpleTimer>& timers);
};

#endif /* TimeScheme_hpp */
