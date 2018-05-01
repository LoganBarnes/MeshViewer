#pragma once

#include <vector>

namespace mesh {

struct Mesh
{
    std::vector<float> vertices;
    std::vector<unsigned> indices;

    explicit Mesh(std::vector<float> verts = {}, std::vector<unsigned> idxs = {})
        : vertices(std::move(verts)), indices(std::move(idxs))
    {}
};

} // namespace mesh
