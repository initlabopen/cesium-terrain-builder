#ifndef BOUNDS_HPP
#define BOUNDS_HPP

#include "geo-types.hpp"


class Bounds {
public:
  Bounds() {
    bounds[0] = bounds[1] = bounds[2] = bounds[3] = 0;
  }

  Bounds(double minx, double miny, double maxx, double maxy) {
    setBounds(minx, miny, maxx, maxy);
  }

  inline void setBounds(double minx, double miny, double maxx, double maxy) {
    bounds[0] = minx;
    bounds[1] = miny;
    bounds[2] = maxx;
    bounds[3] = maxy;
  }

  inline double getMinX() const {
    return bounds[0];
  }
  inline double getMinY() const {
    return bounds[1];
  }
  inline double getMaxX() const {
    return bounds[2];
  }
  inline double getMaxY() const {
    return bounds[3];
  }

  inline void setMinX(double newValue) {
    bounds[0] = newValue;
  }
  inline void setMinY(double newValue) {
    bounds[1] = newValue;
  }
  inline void setMaxX(double newValue) {
    bounds[2] = newValue;
  }
  inline void setMaxY(double newValue) {
    bounds[3] = newValue;
  }

  inline LatLon
  getLowerLeft() const {
    return LatLon(getMinX(), getMinY());
  }
  inline LatLon
  getLowerRight() const {
    return LatLon(getMaxX(), getMinY());
  }
  inline LatLon
  getUpperRight() const {
    return LatLon(getMaxX(), getMaxY());
  }
  inline LatLon
  getUpperLeft() const {
    return LatLon(getMinX(), getMaxY());
  }

  inline double getWidth() const {
    return getMaxX() - getMinX();
  }

  inline double getHeight() const {
    return getMaxY() - getMinY();
  }

  inline Bounds * getSW() const {
    return new Bounds(getMinX(),
                      getMinY(),
                      getMinX() + (getWidth() / 2),
                      getMinY() + (getHeight() / 2));
  }
  inline Bounds * getNW() const {
    return new Bounds(getMinX(),
                      getMaxY() - (getHeight() / 2),
                      getMinX() + (getWidth() / 2),
                      getMaxY());
  }
  inline Bounds * getNE() const {
    return new Bounds(getMaxX() - (getWidth() / 2),
                      getMaxY() - (getHeight() / 2),
                      getMaxX(),
                      getMaxY());
  }
  inline Bounds * getSE() const {
    return new Bounds(getMaxX() - (getWidth() / 2),
                      getMinY(),
                      getMaxX(),
                      getMinY() + (getHeight() / 2));
  }
  
  inline bool overlaps(const Bounds *other) const {
    return overlaps(*other);
  }

  inline bool overlaps(const Bounds &other) const {
    // see
    // <http://stackoverflow.com/questions/306316/determine-if-two-rectangles-overlap-each-other>
    return getMinX() < other.getMaxX() && other.getMinX() < getMaxX() &&
           getMinY() < other.getMaxY() && other.getMinX() < getMaxY();
  }
  
private:
  double bounds[4];
};

#endif /* BOUNDS_HPP */