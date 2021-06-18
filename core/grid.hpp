/*
 * @Author: Hezser <contact.sergiohernandez@gmail.com>
 * @Date: 13-06-2021 04:24
 * @Last Modified by: Hezser <contact.sergiohernandez@gmail.com>
 * @Last Modified time: 18-06-2021 16:41
 */

#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <xtensor/xarray.hpp>
#include "../rules/rules.hpp"

namespace core
{

/**
 * @brief A dynamically shaped square tensor holding each cell's state (0=inactive, 1=active)
 */
typedef xt::xarray<uint_fast8_t> GridState;

/**
 * @brief A square grid which on every update enforces the rules of the automata on its states
 */
class Grid
{
    public:
        /**
         * @brief Instantiates a grid
         *
         * @param dimensions The dimensions of the grid
         * @param initial_state A list of grid coordinates pointing to the initial active cells
         * @param rules The evolutionary rules of the grid
         */
        Grid(const uint_fast8_t dimensions, const std::vector<std::vector<uint_fast64_t>> initial_active_cells, const rules::Rules& rules);

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
         * @ACTIVE_CELL_STATE The active cell state
         */
        static constexpr uint_fast8_t ACTIVE_CELL_STATE = 1;

        /**
         * @INACTIVE_CELL_STATE The inactive cell state
         */
        static constexpr uint_fast8_t INACTIVE_CELL_STATE = 0;

        /**
         * @RESIZE The number of cells to add as padding to both ends of each dimension of the grid when resizing
         */
        static constexpr uint_fast64_t RESIZE_PADDING = 10;

        /**
         * @m_d The dimensions of the grid
         */
        const uint_fast8_t m_d;

        /**
         * @m_rules The evolutionary rules of the grid
         */
        const rules::Rules& m_rules;

        /**
         * @m_size The current size of each of the grid's dimensions (since the grid is square)
         */
        uint_fast64_t m_size;

        /**
         * @m_state The current state of the grid, which holds which cells are currently active
         */
        GridState m_state;
};

}  // namespace core

#endif