#include "Game.h"
#include "BoidPawn.h"

Game::Game()
{
    graphicManager = new GraphicManager;
    sceneManager = new SceneManager;
}

void Game::GameLoop()
{
    clear();
    std::vector<Actor*> arrBp;

    for (int i = 0; i < 200; i++)
    {
        BoidPawn* bp = new BoidPawn;
        bp->transform.SetPosition(28 + i, 10);
        arrBp.push_back(bp);
    }

    sceneManager->AddMultActorToScene(arrBp);

    

    while (running)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                running = false;
            }
        }

        graphicManager->DrawScene(sceneManager->GetScene());
    }

    CloseGame();
}

void Game::CloseGame()
{
    graphicManager->~GraphicManager();
    
    //delete player;
    exit;
}