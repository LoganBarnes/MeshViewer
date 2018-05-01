#include "bind_api.hpp"
#include "mesh/Mesh.hpp"
#include <pybind11/stl.h>
#include <sstream>

namespace pymesh {

void bind_mesh(pybind11::module &m)
{
    {
        auto c = pybind11::class_<mesh::Mesh>(m, "Mesh");

        c.def(pybind11::init<std::vector<float>, std::vector<unsigned>>(),
              R"setdoc(
              A Mesh.
        )setdoc",
              pybind11::arg("vertices") = std::vector<float>(),
              pybind11::arg("indices") = std::vector<unsigned>());

        c.def(pybind11::pickle(
            [](const mesh::Mesh &m) { // __getstate__
                return pybind11::make_tuple(m.vertices, m.indices);
            },
            [](pybind11::tuple t) { // __setstate__
                if (t.size() != 2) {
                    throw std::runtime_error("Invalid state!");
                }
                mesh::Mesh m;
                m.vertices = t[0].cast<std::vector<float>>();
                m.indices = t[1].cast<std::vector<unsigned>>();
                return m;
            }));

        c.def_readwrite("vertices", &mesh::Mesh::vertices);
        c.def_readwrite("indices", &mesh::Mesh::indices);

        c.def("__repr__", [](const mesh::Mesh &mesh) {
            std::stringstream msg;
            msg << "<pymesh.Mesh {[";
            for (auto &f : mesh.vertices) {
                msg << f << ", ";
            }
            msg.seekp(-2, msg.cur);
            msg << "], [";
            for (auto &i : mesh.indices) {
                msg << i << ", ";
            }
            msg.seekp(-2, msg.cur);
            msg << "]}>";
            return msg.str();
        });
    }
}

} // namespace pymesh
