#pragma once

struct DelaunayStats
{
  // Delaunay
  int n_flips = 0, n_flips_s = 0, n_flips_t = 0, n_flips_q = 0, n_flips_12 = 0, n_nde = -1;
  bool flip_count = false; // when true: write out stats for different kinds of flips
  std::vector<int> flip_seq;
};

template <typename Scalar>
struct SolveStats
{
  int n_solves = 0, n_g = 0, n_checks = 0;
  double solve_time;
  Scalar cetm_energy = 0;
};

struct StatsParameters
{
  bool flip_count = false;     // when true: collect stats on different types of edge flips
  std::string name = "";       // name of the model that's been tested - for logging purpose
  std::string output_dir = ""; // directory name for genearting all stats
  bool error_log = false;      // when true: write out per-newton iterations stats
  bool print_summary = false;  // when true: add final stats of optimization to summary file
  int log_level = 2;           // controlling detail of console logging
};

struct LineSearchParameters
{
  double c1 = 1e-4;                         // c1 for armijo condition
  double c2 = 0.9;                          // c2 for curvature condition
  bool energy_samples = false;              // This boolean is only used for generating figure 4 in paper
  bool energy_cond = false;                 // when true: use energy decrease as line search stop criterion
  bool do_reduction = false;                // when true: reduce step, if the components of descent direction vary too much
  double descent_dir_max_variation = 1e-10; // threshold for descent direction component max difference to decrease step
  bool do_grad_norm_decrease = true;        // when true: require gradient norm to decrease at each iteration
  double bound_norm_thres = 1e-10;          // threshold to drop gradient decrease requirement when step lambda is below this
  double lambda0 = 1.0;                     // starting lambda value for the line search, normally 1
  bool reset_lambda = true;                 // when true: start with lambda = lambda0 for each newton iteration; if false, start with lambda from the previous
};

struct AlgorithmParameters
{
  int MPFR_PREC = 100;          // precision if done in multiprecision
  bool initial_ptolemy = false; // when true: use ptolemey flips for the first MakeDelaunay  Do we really need this?
  // termination
  double error_eps = 0;         // max angle error tolerance, terminate if below
  double min_lambda = 1e-16;    // terminate if lambda drops below this threshold
  double newton_decr_thres = 0; // terminate if the newton decrement is above this threshold (it is negative)
  int max_itr = 500;            // upper bound for newton iterations
  bool bypass_overlay = false;  // avoid overlay computation
  int layout_root = -1;         // select vertex on boundary as root for constructing spanning tree connecting cones
  bool use_edge_flips = true;   // optimize energy without intrinsic edge flips if false
};

