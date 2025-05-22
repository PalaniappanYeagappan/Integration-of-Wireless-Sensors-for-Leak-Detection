
#ifndef NETWORK_MANAGER_H
#define NETWORK_MANAGER_H

class NetworkManager {
  public:
    void connect();
    void sendData(float* data, int count, bool leakDetected);
};

#endif
