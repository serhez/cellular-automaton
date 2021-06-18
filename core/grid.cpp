/*
 * @Author: Hezser <contact.sergiohernandez@gmail.com>
 * @Date: 13-06-2021 04:24
 * @Last Modified by: Hezser <contact.sergiohernandez@gmail.com>
 * @Last Modified time: 18-06-2021 16:52
 */

#include "grid.hpp"
#include "../rules/rules.hpp"

using namespace core;

Grid::Grid(const uint_fast8_t dimensions, const std::vector<std::vector<uint_fast64_t>> initial_active_cells, const rules::Rules rules)
    : m_d{dimensions}, m_rules{rules}
{
    // Find max dimension size
    m_size = 0;
    for (uint_fast64_t i = 0; i < initial_active_cells.size(); ++i)
    {
        uint_fast64_t max_coord = *std::min_element(initial_active_cells[i].begin(), initial_active_cells[i].end())
        if (m_size < max_coord)
        {
            m_size = max_coord;
        }
    }
    m_size += 2 * (m_rules.inactive_radius + RESIZE_PADDING);

    // Create seed state from active cells
    m_state = xt::xarray<uint_fast8_t>::from_shape({m_d, m_size});
    m_state.fill(INACTIVE_CELL_STATE);
    for (uint_fast64_t i = 0; i < initial_active_cells.size(); ++i)
    {
        m_state[initial_active_cells[i]] = ACTIVE_CELL_STATE;
    }
}

bool Grid::update()
{
    // Copy the GridState to enforce rules
    GridState new_state(m_state.shape());
    std::copy(m_state.crbegin(), m_state.crend(), new_state.begin());

    // Enforce the rules in each cell of the grid
    std::vector<uint_fast64_t> coord(m_d, 0);
    while(true)
    {
        if (!m_rules.applyToCell(m_state, new_state, coord)) return false;

        // Go to next coord or break if we have traversed all coords
        uint_fast8_t i = 0;
        while (i < m_d && coord[i] == m_size - 1) ++i;
        if (i == m_d) 
        {
            if (!m_rules.applyToCell(m_state, new_state, coord)) return false;
            break;
        }
        for (uint_fast8_t j = 0; j < i; ++j) coord[j] = 0;
        coord[i] += 1;
    }

    // Make the copy the current state
    m_state = new_state;

    // Check if there are enough inactive cells in the grid at the ends of each dimension
    bool must_resize = false;
    uint_fast64_t resize = m_rules.inactive_radius + RESIZE_PADDING; 

    if (resize > 0)
    {
        std::vector<uint_fast64_t> coord(m_d, 0);
        while(true)
        {
            if (m_state[coord] == ACTIVE_CELL_STATE)
            {
                must_resize = true;
                break;
            }

            // Go to next coord or break if we have traversed all coords
            uint_fast8_t i = 0;
            while (i < m_d && coord[i] == m_size - 1) ++i;
            if (i == m_d) 
            {
                if (m_state[coord] == ACTIVE_CELL_STATE)
                {
                    must_resize = true;
                }
                break;
            }
            for (uint_fast8_t j = 0; j < i; ++j) coord[j] = 0;
            coord[i] = coord[i] == resize - 1 ? m_size - resize : coord[i] + 1;
        }
    }

    // Resize the current state if needed
    if (must_resize)
    {
        uint_fast64_t resize_end = resize + m_size;
        m_size += 2 * resize;

        GridState resized_state = xt::xarray<uint_fast8_t>::from_shape({m_d, m_size});
        resized_state.fill(INACTIVE_CELL_STATE);

        std::vector<uint_fast64_t> coord(m_d, resize);
        while(true)
        {
            resized_state[coord] = m_state[coord];

            // Go to next coord or break if we have traversed all coords
            uint_fast8_t i = 0;
            while (i < m_d && coord[i] == resize_end - 1) ++i;
            if (i == m_d) 
            {
                resized_state[coord] = m_state[coord];
                break;
            }
            for (uint_fast8_t j = 0; j < i; ++j) coord[j] = resize;
            coord[i] += 1;
        }

        m_state = resized_state;
    }

    return true;
}
