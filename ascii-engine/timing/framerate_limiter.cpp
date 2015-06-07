#include <ascii-engine/util/msleep.h>
#include "framerate_limiter.h"

namespace ae = ascii_engine;

void ae::Framerate_limiter::frame_start() {
  start = clock.now();
}

void ae::Framerate_limiter::frame_end() {
  end_frame_clock();
  if (there_is_residual_time())
    sleep_for_remaining_time();
  else
    end_frame_immediately();
}

void ae::Framerate_limiter::end_frame_clock() {
  end = std::chrono::time_point_cast<ms>(clock.now());
  frame_time = end - start;
}

bool ae::Framerate_limiter::there_is_residual_time() {
  return frame_time.count() < target_dur.count();
}

void ae::Framerate_limiter::sleep_for_remaining_time() {
  ms sleep_length = std::chrono::duration_cast<ms>(target_dur - frame_time);
  msleep(sleep_length.count());
  delta_time = frame_time + sleep_length;
}

void ae::Framerate_limiter::end_frame_immediately() {
  delta_time = frame_time;
}
