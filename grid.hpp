/*
 * @Author: Hezser <contact.sergiohernandez@gmail.com>
 * @Date: 13-06-2021 04:24
 * @Last Modified by: Hezser <contact.sergiohernandez@gmail.com>
 * @Last Modified time: 13-06-2021 20:06
 */

#ifndef GRID_HPP
#define GRID_HPP

#include <xtensor/xarray.hpp>

namespace core
{

// Forward declaration
class Grid;

/**
 * @brief A dynamically shaped tensor holding each cell's state (0=inactive, 1=active)
 */
typedef xt::xarray<uint_fast8_t> GridState;

/**
 * @brief Updates a cell in the grid enforcing the rules
 *
 * @param current_state The current state of the grid (read-only)
 * @param new_state The new state of the grid that must be changed to enforce the rules
 * @param cell The coordinates of the cell to update in the grid
 * @return True on success, false otherwise
 */
typedef std::function<bool(const Grid&, Grid&, const std::vector<int_fast64_t>)> CellUpdateFunction;

class Grid
{
    public:
        /**
         * @brief Instantiates a grid
         *
         * @param dimensions The dimensions of the grid
         * @param initial_state The initial state of the grid, describing the initial active cells
         * @param rules The evolutionary rules of the grid
         * @param max_rule_radius The maximum radius from which a cell can become active from any other active cell, given all rules
         */
        Grid(uint_fast8_t dimensions, GridState initial_state, CellUpdateFunction rules, uint_fast8_t max_rule_radius) noexcept;

        /**
         * @brief Destructs the grid
         *
         */
        ~Grid() noexcept;

        /**
         * @brief Updates the grid one time step
         *
         * @return True on sucess, false otherwise
         */
        bool update();

        /**
         * @brief State getter
         *
         * @return The current state
         */
        GridState state() const { return m_state; }

    private:
        /**
         * @RESIZE The number of elements to add to each dimension of the grid when resizing
         */
        static constexpr uint_fast64_t RESIZE = 1000;

        /**
         * @m_d The dimensions of the grid
         */
        const uint_fast8_t m_d;

        /**
         * @m_rules The evolutionary rules of the grid
         */
        const CellUpdateFunction m_rules;

        /**
         * @m_max_rule_radius The maximum radius from which a cell can become active from any other active cell, given all rules
         */
        const uint_fast8_t m_max_rule_radius;

        /**
         * @m_state The current state of the grid, which holds which cells are currently active
         */
        GridState m_state;
};

}  // namespace core

#endif
