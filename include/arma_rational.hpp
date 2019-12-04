// Set ARMA_MPP_TYPE to the desired type to configure (it has to be non-template, cause it's used for function specialization)
#undef ARMA_MPPP_TYPE
#define ARMA_MPPP_TYPE mppp::rational<ARMA_MPPP_SSIZE>


// Configuration specific to rational
namespace arma {

// register rational<ARMA_MPPP_SIZE> as a real type.
template<>
struct arma_real_only<ARMA_MPPP_TYPE> {
	typedef ARMA_MPPP_TYPE result;
};

// use direct_dot_arma (generic dot product implementation) for direct_dot<ARMA_MPPP_TYPE>
//
template<>
arma_hot inline ARMA_MPPP_TYPE op_dot::direct_dot<ARMA_MPPP_TYPE>(const uword n_elem, const ARMA_MPPP_TYPE* const A, const ARMA_MPPP_TYPE* const B) {
	return op_dot::direct_dot_arma<ARMA_MPPP_TYPE>(n_elem, A, B);
}

// for abs
//
template<>
arma_inline ARMA_MPPP_TYPE eop_aux::arma_abs<ARMA_MPPP_TYPE>(const ARMA_MPPP_TYPE x) {
	return mppp::abs(x);
}

} // namespace arma


// Common configuration is done by including arma_common.hpp
#include "arma_common.hpp"