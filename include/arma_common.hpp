// Armadillo internal voodoo to support ARMA_MPPP_TYPE as an element type
// It has to be non-template, cause it's used for function specialization

namespace arma {

// register as supported
template<>
struct is_supported_elem_type<ARMA_MPPP_TYPE> {
	static const bool value = true;
};

// armadillo's memory::acquire/release uses malloc/free for speed, which ignores the constructor
// We override it to use C++'s new/delete.
//
template<>
inline
arma_malloc
ARMA_MPPP_TYPE*
memory::acquire<ARMA_MPPP_TYPE>(const uword n_elem) {
	arma_debug_check(
		( size_t(n_elem) > (std::numeric_limits<size_t>::max() / sizeof(ARMA_MPPP_TYPE)) ),
		"arma::memory::acquire(): requested size is too large"
	);
	return ( new(std::nothrow) ARMA_MPPP_TYPE[n_elem] );
}

template<>
arma_inline
void
memory::release<ARMA_MPPP_TYPE>(ARMA_MPPP_TYPE* mem) {
	delete [] mem;
}

template<>
arma_inline
void
memory::release<const ARMA_MPPP_TYPE>(const ARMA_MPPP_TYPE* mem) {
	delete [] mem;
}

// armadillo uses memcpy to copy memory, we can't do that so we manually copy
//
template<>
arma_hot
arma_inline
void
arrayops::copy<ARMA_MPPP_TYPE>(ARMA_MPPP_TYPE* dest, const ARMA_MPPP_TYPE* src, const uword n_elem) {
	for(uint i = 0; i < n_elem; i++)
		dest[i] = src[i];
}

// conversion from strings 
//
#if ARMA_VERSION_MAJOR > 8 || (ARMA_VERSION_MAJOR == 8 && ARMA_VERSION_MINOR >= 400)
template<>
inline
bool
diskio::convert_token(ARMA_MPPP_TYPE& val, const std::string& token) {
	val = token;
	return true;
}
#endif


} // namespace arma

