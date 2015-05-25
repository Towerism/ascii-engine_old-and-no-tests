/**********************************
 * author: Martin Fracker, Jr.
 * license: GNU GPL
 * * * * * * * * * * * * * * * * *
 * file: framerate_limiter.h
 * library: ascii-engine
 **********************************/

#ifndef FRAMERATE_LIMITER_H
#define FRAMERATE_LIMITER_H

#include <chrono>
#include <math.h>

namespace ascii_engine {

  struct Framerate_limiter {

    typedef std::chrono::milliseconds ms;
    typedef std::chrono::duration<double> sec;
    typedef std::chrono::steady_clock steady_clock;

    Framerate_limiter(int target) :
      target_fps(target), target_dur(steady_clock::period::den/target) { }

    void frame_start();
    void frame_end();

    double get_delta_time() {
      return std::chrono::duration_cast<sec>(delta_time).count();
    }

  private:

    steady_clock clock;
    int target_fps;
    steady_clock::duration target_dur, frame_time, delta_time;
    steady_clock::time_point start, end;

    void end_frame_clock();
    bool there_is_residual_time();
    void sleep_for_remaining_time();
    void end_frame_immediately();
  };
}

#endif // FRAMERATE_LIMITER_H
