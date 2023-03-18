#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unistd.h>

void hack(const char *path) {
    FILE *crackme = fopen(path, "r+");

    printf("%d", crackme == nullptr);

    unsigned char str[] = {0xEB, 0x74};

    fwrite (str, 1, sizeof (str), crackme);

    fclose(crackme);
}

int main(int argc, char **argv) {
    hack(argv[1]);

    sf::RenderWindow window(sf::VideoMode(918, 762), "Crack");sf::Music music;
    
    if (!music.openFromFile("r1ckr011.ogg"))
        return -1; // error
    music.play();

    sf::Texture texture;
    sf::Sprite sprite;
    sprite.scale(sf::Vector2f(3.0f, 3.0f));

    char name[22] = {0};
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        for(int i = 0; i < 26; i++) {
            sprintf(name, "Pictures/%d-0000.jpg", i);

            if (!texture.loadFromFile(name)) {
                return -1;
            }

            sprite.setTexture(texture);
            window.draw(sprite);
            window.display();

            usleep(100000);
        }

    }

    return 0;
}