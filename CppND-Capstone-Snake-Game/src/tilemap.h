
#pragma once
#include <string>
#include <map>
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL.h"


class Tilemap {
public:
    static Tilemap* instance() {
    if (_instance == nullptr) {
        _instance = new Tilemap();
    }
    return _instance;
    }

    void init(SDL_Renderer* renderer, int tile_w, int tile_h);
    bool addTile(std::string file_path, std::string id);

    void render(std::string id, int x, int y);

    void fillWith(std::string id, int x, int y, int w, int h);
    void clean();

private:
    static Tilemap* _instance;
    Tilemap() {}
    ~Tilemap() {}
    SDL_Renderer* renderer = nullptr;
    std::map<std::string, SDL_Texture*> tiles;
    int tile_h = 0;
    int tile_w = 0;
};

