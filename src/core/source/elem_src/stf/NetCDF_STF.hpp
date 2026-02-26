// -----------------------------------------------------------------------------
//
// SPDX-License-Identifier: MIT
// Copyright (C) 2019 - 2026 by the AxiSEM3D authors
//
// This file is part of the AxiSEM3D library. See the LICENSE file for details.
//
// -----------------------------------------------------------------------------

//  netcdf source-time function

#ifndef NetCDF_STF_hpp
#define NetCDF_STF_hpp

#include "STF.hpp"
#include "NetCDF_Reader.hpp"

class NetCDF_STF : public STF {
  public:
  // constructor
  NetCDF_STF(const std::string& fileName,
      const std::string& varTime,
      const std::string& varData,
      int chunkSize,
      PaddingMode padding,
      double left,
      double right);

  // get start time
  double
  getStartTime() const {
    return mTmin;
  }

  // get value
  numerical::Real
  getValue(double time);

  // verbose
  std::string
  verbose() const;

  private:
  // load next buffer chunk
  bool
  loadNextBufferChunk();

  // file
  const std::string mFileName;
  const std::string mVarTime;
  const std::string mVarData;
  int mVarID_Time = -1;
  int mVarID_Data = -1;

  // for verbose
  double mTmin = 0., mTmax = 0.;
  double mVTmin = 0., mVTmax = 0.;
  numerical::Real mVmin = 0., mVmax = 0.;

  // chunk
  int mTotalTimeStepsInFile = 0;
  int mTimeStepOfTimes0 = -1;
  int mTimeStepOfTimesLast = -1;

  // data
  std::vector<double> mTimes;
  std::vector<numerical::Real> mData;

  // padding
  const bool mPadding;
  double mLeftPadding = 0.;
  double mRightPadding = 0.;

  ////////////////// static //////////////////
  // store readers in a static map to avoid opening duplicated files
  std::map<std::string, NetCDF_Reader> sReaders;
};

#endif /* NetCDF_STF_hpp */
