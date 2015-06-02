#ifndef MSLEEP_H
#define MSLEEP_H

// cross-platform millisecond sleep function
#ifdef _WIN32
#include <windows.h>
void msleep(unsigned milliseconds) {
  Sleep(milliseconds);
}
#else
#include <unistd.h>
void msleep(unsigned milliseconds) {
  usleep(milliseconds * 1000); // takes microseconds
}
#endif

#endif // MSLEEP_H
