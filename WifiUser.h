
#ifndef WIFI_USER_H
#define WIFI_USER_H

#include "spark_wiring.h"
#include "spark_wiring_string.h"
#include "spark_wiring_wifi.h"
#include "spark_wiring_time.h"

class WifiUser {
private:
    String      _name;
    IPAddress   _ip;
    int         _lastTimeConnected;
    int         _lastTimeDisconnected;
    bool        _connected;

public:
    WifiUser(IPAddress ip, String name)
    : _ip(ip),
    _name(name),
    _lastTimeConnected(0),
    _lastTimeDisconnected(0),
    _connected(false) {}

  void setConnected(bool connected) {
    _connected = connected;
    if (_connected) _lastTimeConnected = Time.now();
    else _lastTimeDisconnected = Time.now();
  }

  bool isConnected() {
    return _connected;
  }

  int lastTimeConnected() {
    return _lastTimeConnected;
  }

  int lastTimeDisconnected() {
    return _lastTimeDisconnected;
  }

};

#endif
