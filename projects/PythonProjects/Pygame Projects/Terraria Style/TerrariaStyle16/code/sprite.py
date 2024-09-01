import pygame
from pygame.sprite import *
from globals import TILESIZE
from globals import *

class Entity(pygame.sprite.Sprite):
    def __init__(self, groups, image = pygame.Surface((TILESIZE, TILESIZE)), position = (0,0)):
        super().__init__(groups)
        self.image = image
        self.rect = self.image.get_rect(topleft = position)
    def update(self):
        self.rect.x += 1

# Creates a Super Entity from the 1st Entity allowing you to change 1 objects direction
#
# class SuperEntity(Entity):
#    def __init__(self, groups, image=pygame.Surface((TILESIZE, TILESIZE)), position=(0, 0)):
#        super().__init__(groups, image, position)
#    def update(self):
#        self.rect.y += 1
# end
