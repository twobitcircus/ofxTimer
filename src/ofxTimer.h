#pragma once
#include "ofMain.h"

class ofxTimer {
public:
  long duration;
  long start_at;

  ofxTimer(long _duration) { set_duration(_duration); }
  ofxTimer() { set_duration(1000); }

  void set_duration(int _duration) {
    duration = _duration;
    start_at = 0;
  }
  void start() {
    start_at = ofGetElapsedTimeMillis();
  }
  void clear() {
    start_at = 0;
  }
  long age() {
    if (start_at == 0) return 0;
    else return ofGetElapsedTimeMillis() - start_at;
  }
  long remaining() {
    return duration - age();
  }
  float normalized_age() {
    return 1.0*age() / duration;
  }
  bool expired() {
    return age() > duration;
  }
  bool active() {
    return start_at != 0 && age() < duration;
  }
};
