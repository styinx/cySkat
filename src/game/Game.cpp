#include "game/Game.hpp"

#include "cyinput/SDLEventLoop.hpp"

namespace cyskat
{

    Game::Game()
        : m_sdl()
    {
        m_sdl.initSDL(SDL_INIT_EVERYTHING);
        m_sdl.initTTF();

        m_window = std::make_shared<cyvideo::SDLWindow>(
            "cySkat", cymath::Point(50, 50), cymath::Size(600, 400));
        m_renderer =
            std::make_shared<cyvideo::SDLRenderer>(std::make_shared<cyvideo::SDLWindow>(*m_window));

        const String FILENAME = __FILE__;
        const String BASE_DIR = FILENAME.substr(0, FILENAME.find_last_of('/')) + "/../../";
        const String font_dir = BASE_DIR + "resources/fonts/Roboto/Roboto-Regular.ttf";

        m_gui_renderer = std::make_shared<cygui::GUIRenderManager>(m_renderer);
        m_font = std::make_shared<cyvideo::SDLFont>(font_dir, 20);

        m_box.setSize({200, 300});
        m_box.add(std::make_shared<cygui::Button>("Optionen"));
        m_box.add(std::make_shared<cygui::Button>("Zurück"));
        m_box.add(std::make_shared<cygui::Button>("Ende"));

        m_window->show();
    }

    void Game::showMenu()
    {
        m_renderer->clear();
        if(m_state.state != GAME_STATE::MENU)
        {
            m_box.draw();
            m_state.state = GAME_STATE::MENU;
        }
        else
        {
            m_state.resume();
        }
        m_renderer->show();
    }

    void Game::run()
    {
        m_table.reset();

        cyinput::SDLEventLoop loop{};

        auto shared_this = std::make_shared<Game>(*this);

        loop.keyboard()->onKeyDown(
            SDLK_ESCAPE, [&shared_this](const cyinput::KeyCode key) { shared_this->showMenu(); });
        //        loop.onAnySDLEventBegin([&shared_this](const SDL_Event& event)
        //        {
        //            shared_this->m_renderer->clear();
        //
        //            if(event.type == SDL_MOUSEBUTTONDOWN)
        //            {
        //                std::cout << event.button.x << " " << event.button.y << "\n";
        //            }
        //
        //        });
        loop.onAnySDLEventEnd(
            [&shared_this](const SDL_Event& event) { shared_this->m_renderer->show(); });

        loop.run();
    }

}  // namespace cyskat
