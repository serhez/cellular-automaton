/*
 * @Author: serhez <contact.sergiohernandez@gmail.com>
 * @Date: 20-06-2021 16:10
 * @Last Modified by: serhez <contact.sergiohernandez@gmail.com>
 * @Last Modified time: 20-06-2021 18:09
 */

#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>
#include "core/grid.hpp"
#include "graphics/two_dimensions_view.hpp"
#include "rules/conway_rules.hpp"

// NOTE: This is a placeholder running the 2D Game of Life (Conway rules)
// NOTE: Ideally, this will manage a GUI to choose dimensions, rules and initial states
int main()
{
    const uint_fast16_t frame_delay = 1000;

    const std::uint_fast8_t dimensions = 2;
    const rules::ConwayRules rules(2);
    const std::vector<core::GridCell> initial_active_cells{ {0, 0}, {0, 2}, {1, 1}, {9, 8}, {8, 8}, {7, 8} };
    core::Grid grid(dimensions, initial_active_cells, rules);

    graphics::TwoDimensionsView view(grid);
    
    sf::RenderWindow window(sf::VideoMode(700, 700), "Loading...");

    while (window.isOpen())
    {
        // Get and process input
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Update the grid and the view
        grid.update();
        view.update(window);

        // Delay the next frame
        std::this_thread::sleep_for(std::chrono::milliseconds(frame_delay));
    }

    return 0;
}
