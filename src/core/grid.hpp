/*
 * @Author: serhez <contact.sergiohernandez@gmail.com>
 * @Date: 13-06-2021 04:24
 * @Last Modified by: serhez <contact.sergiohernandez@gmail.com>
 * @Last Modified time: 20-06-2021 16:16
 */

#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <xtensor/xarray.hpp>

// Forward declaration
namespace rules
{
    class Rules;
}

namespace core
{

/**
 * @brief A dynamically shaped square tensor holding each cell's state
 */
typedef xt::xarray<uint_fast8_t> GridState;

/**
 * @brief The coordinates of a cell in the grid, with as many elements as dimensions the grid has
 */
typedef std::vector<uint_fast64_t> GridCell;

/**
 * @brief A square grid which on every update enforces the rules of the automata on its states
 */
class Grid
{
    public:
        /**
         * @ACTIVE_CELL_STATE The active cell state
         */
        static constexpr uint_fast8_t ACTIVE_CELL_STATE = 1;

        /**
         * @INACTIVE_CELL_STATE The inactive cell state
         */
        static constexpr uint_fast8_t INACTIVE_CELL_STATE = 0;

        /**
         * @brief Instantiates a grid
         *
         * @param dimensions The dimensions of the grid
         * @param initial_state A list of grid coordinates pointing to the initial active cells
         * @param rules The evolutionary rules of the grid
         */
        Grid(const uint_fast8_t dimensions, const std::vector<GridCell>& initial_active_cells, const rules::Rules& rules);

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
        GridState getState() const { return m_state; }

    private:
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
