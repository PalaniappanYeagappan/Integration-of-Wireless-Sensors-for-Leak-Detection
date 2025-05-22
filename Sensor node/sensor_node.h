
#ifndef SENSOR_NODE_H
#define SENSOR_NODE_H

class SensorNode {
  public:
    SensorNode(int count);
    void initialize();
    float* readAll();
  private:
    int count;
    float* pressures;
};

#endif
