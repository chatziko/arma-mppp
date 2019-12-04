// Set ARMA_MPP_TYPE to the desired type to configure (it has to be non-template, cause it's used for function specialization)
#undef ARMA_MPPP_TYPE
#define ARMA_MPPP_TYPE mppp::integer<ARMA_MPPP_SSIZE>


// Configuration specific to integer
namespace arma {

// register integer<ARMA_MPPP_SIZE> both as an integral and a singed integral type
template<>
struct arma_integral_only<ARMA_MPPP_TYPE> {
	typedef ARMA_MPPP_TYPE result;
};
template<>
struct arma_signed_integral_only<ARMA_MPPP_TYPE> {
	typedef ARMA_MPPP_TYPE result;
};

// for abs
//
template<>
arma_inline ARMA_MPPP_TYPE eop_aux::arma_abs<ARMA_MPPP_TYPE>(const ARMA_MPPP_TYPE x) {
	return mppp::abs(x);
}

} // namespace arma


// Common configuration is done by including arma_common.hpp
#include "arma_common.hpp"