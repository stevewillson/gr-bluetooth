/*
 * Copyright 2022 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(multi_LAP.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(d5feddbf1ed603a301845b4e43080569)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <bluetooth/multi_LAP.h>
// pydoc.h is automatically generated in the build directory
#include <multi_LAP_pydoc.h>

void bind_multi_LAP(py::module& m)
{

    using multi_LAP    = ::gr::bluetooth::multi_LAP;


    py::class_<multi_LAP, gr::bluetooth::multi_block,
        std::shared_ptr<multi_LAP>>(m, "multi_LAP", D(multi_LAP))

        .def(py::init(&multi_LAP::make),
           py::arg("sample_rate"),
           py::arg("center_freq"),
           py::arg("squelch_threshold"),
           D(multi_LAP,make)
        )
        



        ;




}







