#ifndef FRAMERATE_LIMITER_H
#define FRAMERATE_LIMITER_H

#include <chrono>
#include <math.h>

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

namespace ascii_engine {
  struct Framerate_limiter {
    typedef std::chrono::milliseconds ms;
    typedef std::chrono::duration<double> sec;
    typedef std::chrono::steady_clock steady_clock;

    Framerate_limiter(int target) : 
      target_fps(target), target_dur(steady_clock::period::den/target) { }
    void frame_start() {
      start = clock.now();
    }
    void frame_end() {
      end = std::chrono::time_point_cast<ms>(clock.now());
      frame_time = end - start;
      if (frame_time.count() < target_dur.count()) {
        ms sleep_length = std::chrono::duration_cast<ms>(target_dur - frame_time);
        msleep(sleep_length.count());
        delta_time = frame_time + sleep_length;
      } else {
        delta_time = frame_time;
      }
    }
    double get_delta_time() { return std::chrono::duration_cast<sec>(delta_time).count(); }
    private:
    steady_clock clock;
    int target_fps;
    steady_clock::duration target_dur, frame_time, delta_time;
    steady_clock::time_point start, end;
  };
}

#endif // FRAMERATE_LIMITER_H
