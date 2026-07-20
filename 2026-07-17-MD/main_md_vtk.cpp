// main_md.cpp
// g++ -std=c++23 particle.cpp main_md.cpp
#include "particle.h"
#include "integrator.h"
#include "collider.h"
#include "boundary.h"
#include "vtk_exporter.h"
#include <vector>

void initial_conditions(std::vector<Particle> & particles);

int main(int argc, char **argv) {
  std::vector<Particle> bodies;
  bodies.resize(1); // only one particle for now

  // parameters
  std::map<std::string, double> p;
  p["T0"] = 0.0;
  p["TF"] = 100.8767;
  p["DT"] = 0.01;
  p["G"] = -9.81;

  // Force collider
  Collider collider(p);

  // Time initialization
  TimeIntegrator integrator(p["DT"]);

  // Boundary conditions
  Boundary bc(2.345, 0.0, 0.0, 0.0, 0.95); // RMAX, CX, CY, CZ, EN

  // initial conditions and properties
  initial_conditions(bodies);
  collider.computeForces(bodies); // force at t = 0
  integrator.startIntegration(bodies); // start integration algorithm
  std::cout << p["T0"] << "\t";
  bodies[0].print();
  std::cout << "\n";

  // Create VTK exporter
  VTKExporter vtk_exporter("output");
  vtk_exporter.reset_counter();

  // Time iteration
  const int niter = int((p["TF"] - p["T0"])/p["DT"]);
  for(int ii = 1; ii < niter; ++ii) {
    collider.computeForces(bodies);
    integrator.timeStep(bodies);
    bc.apply(bodies);
    double time = p["T0"] + ii*p["DT"];
    std::cout << time << "\t";
    bodies[0].print();
    std::cout << "\n";
    if (ii % 10 == 0) {
      vtk_exporter.write_frame(bodies, ii*p["DT"]);
    }
  }

  return 0;
}

void initial_conditions(std::vector<Particle> & particles)
{
  particles[0].R[2] = 2.1;//0.987;  // z is upwards, x to the right
  particles[0].V[0] = 4.9876;//12.987; // z is upwards, x to the right
  particles[0].V[2] = 0.0; //4.9876; //3.987; // z is upwards, x to the right
  particles[0].rad  = 0.103;
  particles[0].mass = 0.337;
}
