#include "api/bind_api.hpp"

PYBIND11_MODULE(pymesh, m)
{
    m.doc() = R"setdoc(
        PyMesh
        ------
    )setdoc";

    pymesh::bind_mesh(m);

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
