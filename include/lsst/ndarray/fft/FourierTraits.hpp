/* 
 * LSST Data Management System
 * Copyright 2008, 2009, 2010 LSST Corporation.
 * 
 * This product includes software developed by the
 * LSST Project (http://www.lsst.org/).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the LSST License Statement and 
 * the GNU General Public License along with this program.  If not, 
 * see <http://www.lsstcorp.org/LegalNotices/>.
 */

#ifndef LSST_NDARRAY_FFT_FourierTraits_hpp_INCLUDED
#define LSST_NDARRAY_FFT_FourierTraits_hpp_INCLUDED

/** 
 *  @file lsst/ndarray/fft/FourierTraits.hpp
 *
 *  @brief Traits classes to handle real-data and complex-data FFTs in a template-friendly way.
 */

#include <complex>
#include <boost/shared_ptr.hpp>

#include "lsst/ndarray/fft_fwd.hpp"

namespace lsst { namespace ndarray {
/// \cond INTERNAL
namespace detail {

/**
 *  @internal @ingroup FFTInternalGroup
 *  @brief A traits class that defines x- and k-space data types and k-space array sizes.
 */
template <typename T, bool IsConst>
struct FourierTraits {
    BOOST_STATIC_ASSERT(sizeof(T) < 0);
};

/// \cond SPECIALIZATIONS

template <typename T>
struct FourierTraits<T,false> {
    typedef T ElementX;
    typedef std::complex<T> ElementK;

    static inline int computeLastDimensionSize(int n) { return n/2 + 1; }
};

template <typename T>
struct FourierTraits<T,true> {
    typedef T ElementX;
    typedef std::complex<typename boost::remove_const<T>::type> const ElementK;

    static inline int computeLastDimensionSize(int n) { return n/2 + 1; }
};

template <typename U>
struct FourierTraits<std::complex<U>,false> {
    typedef std::complex<U> ElementX;
    typedef std::complex<U> ElementK;

    static inline int computeLastDimensionSize(int n) { return n; }
};

template <typename U>
struct FourierTraits<std::complex<U> const,true> {
    typedef std::complex<U> const ElementX;
    typedef std::complex<U> const ElementK;

    static inline int computeLastDimensionSize(int n) { return n; }
};

/// \endcond

} // namespace lsst::ndarray::detail
/// \endcond
}} // namespace lsst::ndarray

#endif // !LSST_NDARRAY_FFT_FourierTraits_hpp_INCLUDED
