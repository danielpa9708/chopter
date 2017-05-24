#include "Chopter.hpp"

Chopter::Chopter(int x, int y, int width, int height) {
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
  this->vspeed = 0;
  this->hspeed = 1;
}

void Chopter::resetPosition() {
  x = 0;
}

void Chopter::updateSpeed() {
  if (status == fly) {
    vspeed -= 1;
  } else {
    vspeed += 2;
  }
}

void Chopter::updatePosition() {
  x += hspeed;
  y += vspeed;
}

void Chopter::setStatus(Status status) {
  this->status = status;
}

void Chopter::move(bool fuel) {
  setStatus(fuel ? fly : fall);
  updateSpeed();
  updatePosition();
};