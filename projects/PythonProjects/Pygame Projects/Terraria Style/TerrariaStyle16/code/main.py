import pygame
import sys
from globals import *
from scene import Scene

class Game:
    def __init__(self):
        pygame.init()
        pygame.display.set_caption('Terraria Style')
        self.screen = pygame.display.set_mode((SCREENWIDTH, SCREENHEIGHT))
        self.clock = pygame.time.Clock()
        self.level = True

        self.scene = Scene(self)

    def run(self):
        while self.level:
            self.update()
            self.draw()
        self.close()

    def update(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.level = False
        self.scene.update()
        pygame.display.update()
        self.clock.tick(FPS)

    def draw(self):
        self.scene.draw()

    def close(self):
        pygame.quit()
        sys.exit()

if __name__ == "__main__":
    game = Game()
    game.run()