// Copyright 2008 Google Inc. All Rights Reserved.
// Author: scharron@google.com (Samuel Charron)

#include "ccutil.h"

namespace tesseract {

CCUtilMutex::CCUtilMutex() {
#ifdef _WIN32
  mutex_ = CreateMutex(0, FALSE, 0);
#else
  pthread_mutex_init(&mutex_, NULL);
#endif
}

void CCUtilMutex::Lock() {
#ifdef _WIN32
  WaitForSingleObject(mutex_, INFINITE);
#else
  pthread_mutex_lock(&mutex_);
#endif
}

void CCUtilMutex::Unlock() {
#ifdef _WIN32
  ReleaseMutex(mutex_);
#else
  pthread_mutex_unlock(&mutex_);
#endif
}

CCUtilMutex tprintfMutex;  // should remain global
} // namespace tesseract
