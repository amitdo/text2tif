///////////////////////////////////////////////////////////////////////
// File:        ccutil.h
// Description: ccutil class.
// Author:      Samuel Charron
//
// (C) Copyright 2006, Google Inc.
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
///////////////////////////////////////////////////////////////////////

#ifndef TESSERACT_CCUTIL_CCUTIL_H__
#define TESSERACT_CCUTIL_CCUTIL_H__

#ifdef _WIN32
#include <windows.h>
#else
#include <pthread.h>
#include <semaphore.h>
#endif

namespace tesseract {

class CCUtilMutex {
 public:
  CCUtilMutex();

  void Lock();

  void Unlock();
 private:
#ifdef _WIN32
  HANDLE mutex_;
#else
  pthread_mutex_t mutex_;
#endif
};


extern CCUtilMutex tprintfMutex;  // should remain global
}  // namespace tesseract

#endif  // TESSERACT_CCUTIL_CCUTIL_H__
