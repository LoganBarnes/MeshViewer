#pragma once

#include <pybind11/pybind11.h>

namespace pymesh {

void bind_mesh(pybind11::module &m);

} // namespace pymesh