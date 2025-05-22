
#ifndef LEAK_ANALYZER_H
#define LEAK_ANALYZER_H

class LeakAnalyzer {
  public:
    LeakAnalyzer(float threshold);
    void calibrate(float* baseline);
    bool detect(float* readings);
  private:
    float threshold;
    float* baselineReadings;
};

#endif
