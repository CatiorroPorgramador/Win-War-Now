#pragma once

void EngineLog(const char* msg, char type=0) {
    printf("[Log] %s\n", msg);
}


class Scene {
public:
    virtual ~Scene(){};

    bool pause;

    virtual void Init() {};
    virtual void Update() {};
    virtual void Draw(sf::RenderWindow*) {};
protected:
};

class GameComponent {
public:
    std::string name;

    bool visible;

    virtual ~GameComponent() {};

    virtual void Init() {};
    virtual void Update() {};
    virtual void Draw(sf::RenderWindow*) {};
};

class Soldier : public GameComponent {
    sf::Texture texture;
    sf::Sprite sprite;

    sf::IntRect sheet_rect;

    sf::Vector2f movement;
    float speed = 3.5;

public:

    void Init() {
        sheet_rect = sf::IntRect(0, 0, 16, 16);

        if (!texture.loadFromFile("assets/soldiers/0.png")) {
            printf("[Error]\n");
        }
        texture.setSmooth(false);

        sprite.setTexture(texture);
        sprite.setTextureRect(sheet_rect);

        sprite.setPosition(30, 30);
        sprite.setScale(3, 3);
    }

    void Update() {
        sprite.move(movement);
    }

    void Draw(sf::RenderWindow *window) {
        window->draw(sprite);
    }
};

class Group {
    std::vector<GameComponent> objects;

public:
    void AddGameComponent(GameComponent game_component) {
        objects.push_back(game_component);
    }

    void RemoveGameComponent(std::string game_name) {
        for (int i{0}; i < objects.size(); ++i) {
            if (objects.at(i).name == game_name) {
                objects;
            }
        }
    }
};

class Block : public GameComponent {
    sf::Sprite sprite;

public:
    sf::Texture texture;
    short opacity = 255;

    void Init(short x) {
        sprite.setTexture(texture);
        sprite.setPosition(x, 600-60);
        sprite.setScale(2.5, 2.5);
    }

    void Update() {
        if (opacity != 255) {
            sprite.setColor(sf::Color(255, 255, 255, opacity));
            opacity++;
        }
    }

    void Draw(sf::RenderWindow *window) {
        window->draw(sprite);
    }

    sf::Sprite GetSprite() {
        return sprite;
    }
};

class GamePlay : public Scene {
    Soldier soldier;

public:

    void Init() {
        soldier.Init();
    }

    void Update() {
        soldier.Update();
    }

    void Draw(sf::RenderWindow *window) {
        soldier.Draw(window);
    }
};