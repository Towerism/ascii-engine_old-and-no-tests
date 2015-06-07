#ifndef MSLEEP_H
#define MSLEEP_H

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

namespace ascii_engine {

#ifdef _WIN32

  inline void msleep(unsigned milliseconds) {
    Sleep(milliseconds);
  }
#else

  inline void msleep(unsigned milliseconds) {
    usleep(milliseconds * 1000); // takes microseconds
  }
#endif

}

#endif // MSLEEP_H
