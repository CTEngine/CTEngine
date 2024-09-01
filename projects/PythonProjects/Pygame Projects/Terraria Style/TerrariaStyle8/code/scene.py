import pygame
from globals import *
from sprite import Entity
from player import Player
from texturedata import solo_texture_data, atlas_texture_data

class Scene:
    def __init__(self, app):
        self.app = app

        # player_texture = pygame.image.load('../graphics/player/player.png').convert_alpha()
        # player_texture = pygame.transform.scale(player_texture, (TILESIZE, TILESIZE))
        self.solo_textures = self.gen_solo_textures()
        self.atlas_textures = self.gen_atlas_textures('Pygame Projects/Terraria Style/TerrariaStyle8/graphics/player/player.png')

        self.sprites = pygame.sprite.Group()
        self.entity = Entity([self.sprites], image=self.atlas_textures['grass'])
        Entity([self.sprites], position=(100,100), image=self.solo_textures['player_static'])
        Entity([self.sprites], position=(200,200))

        self.player = Player([self.sprites])

    def gen_solo_textures(self) -> dict:
        textures = {}

        for name, data in solo_texture_data.items():
            textures[name] = pygame.transform.scale(pygame.image.load(data['file_path']).convert_alpha(), (data['size']))

        return textures
    def gen_atlas_textures(self, filepath):
        textures = {}
        atlas_img = pygame.transform.scale(pygame.image.load(filepath).convert_alpha(), (TILESIZE*16, TILESIZE*16))

        for name, data in atlas_texture_data.items():
            textures[name] = pygame.Surface.subsurface(atlas_img, pygame.Rect(data['position'], data['size']))
        return textures
    def update(self):
        self.sprites.update()
        # self.entity.rect.x += 1
    def draw(self):
        self.app.screen.fill("lightblue")
        self.sprites.draw(self.app.screen)