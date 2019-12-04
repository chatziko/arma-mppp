#pragma once

#include <armadillo>
#include <mp++/mp++.hpp>

// Armadillo can be only configured for _non-template_ types cause it requires specializing template functions.
// So we do it for a _fixed_ SSize, which should be set in ARMA_MPPP_SSIZE (defaults to 1).
//
// Hack:
// The reason for having ARMA_MPPP_SSIZE as a macro is that, if the user needs multiple SSizes in the same program, he can re-set ARMA_MPPP_SSIZE
// and re-include arma_integer.hpp/arma_rational.hpp manually (they are not protected by include guards, only this file is).
// Maybe there's some moderm C++ way of doing this...

#ifndef ARMA_MPPP_SSIZE
#define ARMA_MPPP_SSIZE 1
#endif

#include "arma_integer.hpp"
#include "arma_rational.hpp"
