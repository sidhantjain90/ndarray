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

#ifndef LSST_NDARRAY_python_hpp_INCLUDED
#define LSST_NDARRAY_python_hpp_INCLUDED

/**
 *  @file lsst/ndarray/python.hpp
 *  @brief Public header file for ndarray Python support.
 *
 *  \warning Both the main Python C-API header, "Python.h", and the
 *  Numpy C-API headers "arrayobject.h" and "ufuncobject.h" must
 *  be included before ndarray/python.hpp or any of the files in
 *  ndarray/python.
 *
 *  \note This file is not included by the main "lsst/ndarray.hpp" header file.
 */

/** \defgroup PythonGroup Python Support
 *
 *  The ndarray Python support module provides conversion
 *  functions between ndarray objects, notably Array and
 *  Vector, and Python Numpy objects.
 */

/// @internal \defgroup PythonInternalGroup Python Support Internals

#include "Python.h"
#include "lsst/ndarray.hpp"
#include "lsst/ndarray/python/numpy.hpp"
#include "lsst/ndarray/python/ufunctors.hpp"
#include "lsst/ndarray/python/Vector.hpp"

#endif // !LSST_NDARRAY_python_hpp_INCLUDED
