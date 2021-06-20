/*
 * @Author: Hezser <contact.sergiohernandez@gmail.com>
 * @Date: 20-06-2021 15:04
 * @Last Modified by: Hezser <contact.sergiohernandez@gmail.com>
 * @Last Modified time: 20-06-2021 17:05
 */

#ifndef NEIGHBOURS_HPP
#define NEIGHBOURS_HPP

#include <cstdint>
#include <vector>
#include "../core/grid.hpp"

namespace utils
{

/**
 * @brief Returns the coordinates of the neighbours of a given cell for d dimensions (2d neighbours in total)
 *
 * @param dimensions The number of dimensions
 * @param cell The coordinates of the cell
 * @return The coordinates of the neighbours of a given cell for d dimensions
 */
static std::vector<core::GridCell> getNeighbours(const uint_fast8_t dimensions, const core::GridCell& cell)
{
    std::vector<core::GridCell> neighbours(0, std::vector<uint_fast64_t>(dimensions));
    
    for (uint_fast8_t d = 0; d < dimensions; ++d)
    {
        core::GridCell neighbour_1 = cell;
        core::GridCell neighbour_2 = cell;
        neighbour_1[d] += 1;
        neighbour_2[d] -= 1;
        neighbours.push_back(neighbour_1);
        neighbours.push_back(neighbour_2);
    }

    return neighbours;
}

}  // namespace utils

#endif
