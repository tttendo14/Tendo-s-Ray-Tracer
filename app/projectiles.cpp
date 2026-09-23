#include "tuples.hpp"

using namespace tuple;

struct Projectile {
  Tuple position, velocity;
  Projectile(Tuple p, Tuple v) : position(p), velocity(v) {}
  void print() {
    position.print("position");
    velocity.print("velocity");
  }
};

struct Environment {
  Tuple gravity, wind;
  Environment(Tuple g, Tuple w) : gravity(g), wind(w) {}
};

Projectile tick(Environment env, Projectile proj) {
  return Projectile(proj.position + proj.velocity,
                    proj.velocity + env.gravity + env.wind);
}

int main() {

  Projectile proj(Tuple(100.0, 100.0, 50.0, 1.0), Tuple(0.0, 0.0, 0.0, 0.0));
  Environment env(Tuple(0.0, 10.0, 0.0, 0.0), Tuple(2.0, 0.0, 2.0, 0.0));

  int step = 0, numSteps = 20;
  while (step < numSteps) {
    proj.print();
    proj = tick(env, proj);
    step++;
  }

  return 0;
}
